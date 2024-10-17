"""generate_logbook.py: Generate a logbook based on config and cpp/md files."""

import datetime
import os
import re
from pathlib import Path
from typing import Any, Literal

import jinja2
import yaml

from config.constants import Constants


def load_yaml(yaml_path: Path) -> dict[str, Any]:
    """
    Load the YAML file.

    Parameters
    ----------
    yaml_path : Path
        Path to the YAML file.

    Returns
    -------
    dict[str, Any]
        The YAML file as a dictionary.
    """
    with open(yaml_path, "r") as file:
        return yaml.load(file, Loader=yaml.FullLoader)


def parse_cpp_files(folder_path: Path) -> dict[str, str]:
    """
    Parse the C++ files in the folder.

    Parameters
    ----------
    folder_path : Path
        Path to the folder containing the C++ files.

    Returns
    -------
    dict[str, str]
        The C++ files as a dictionary.
    """
    cpp_files = {}

    for file_path in folder_path.glob("*.cpp"):
        with open(file_path, "r") as file:
            cpp_files[file_path.stem] = file.read()

    return cpp_files


def save_file(file_path: Path, content: str) -> None:
    """
    Save the content to the file.

    Parameters
    ----------
    file_path : Path
        Path to the file.
    content : str
        Content to save in the file.
    """
    # Create any necessary directories
    file_path.parent.mkdir(parents=True, exist_ok=True)

    # Save the content to the file
    with open(file_path, "w") as file:
        file.write(content)


def render_template(template_path: Path, context: dict[str, Any]) -> str:
    """
    Render the template with the context.

    Parameters
    ----------
    template_path : Path
        Path to the template.
    context : dict[str, Any]
        Context to render the template.

    Returns
    -------
    str
        Rendered template.
    """
    with open(template_path, "r") as file:
        template = jinja2.Template(file.read())

    return template.render(context)


def combine_logbook(markdown_path: Path, logbook_path: Path) -> None:
    """
    Combine the logbook from the markdown files.

    Parameters
    ----------
    markdown_path : Path
        Path to the markdown files.
    logbook_path : Path
        Path to save the logbook to.
    """
    combined_content = ""

    # Combine the cover
    cover_path = markdown_path / "cover.md"
    with open(cover_path, "r") as file:
        combined_content += file.read() + "\n\n"

    # Combine the contents
    contents_path = markdown_path / "contents.md"
    with open(contents_path, "r") as file:
        combined_content += file.read() + "\n\n"

    # Combine the weeks
    weeks_path = markdown_path / "weeks"
    for week_file in sorted(weeks_path.glob("*.md")):
        with open(week_file, "r") as file:
            combined_content += file.read() + "\n\n"

    # Combine the references
    references_path = markdown_path / "references.md"
    with open(references_path, "r") as file:
        combined_content += file.read() + "\n\n"

    # Save the combined content to the logbook
    save_file(logbook_path, combined_content)


def generate_logbook_cover(
    cover_path: Path, template_path: Path, config: dict[str, dict[str, str]]
) -> None:
    """
    Generate the cover of the logbook.

    Parameters
    ----------
    cover_path : Path
        Path to the cover file.
    template_path : Path
        Path to the template to use.
    config : dict[str, dict[str, str]]
        Config to generate the cover.
    """
    cover = render_template(template_path, config)
    save_file(cover_path, cover)


def process_cpp_code_for_comments(
    cpp_code_lines: list[str],
) -> dict[str, list[tuple[str, str]]] | str:
    """
    Process the C++ code to extract answer comments and related code. If the code
    contains no answer comments, the function returns the entire code as a string.

    Parameters
    ----------
    cpp_code_lines : list[str]
        List of C++ code lines.

    Returns
    -------
    dict[str, list[tuple[str, str]]]
        A dictionary where keys are task identifiers and values are lists of tuples
        containing comments and associated code.

    Notes
    -----
    The function processes the C++ code line by line, looking for block comments
    and inline comments that contain the string "ANSWER". It extracts the comment
    identifier and content, and associates it with the code that follows the comment.
    If the code contains no answer comments, the function returns the entire code as a string.
    """
    task_comments: dict[str, list[tuple[str, str]]] = {}
    current_code_lines: list[str] = []
    current_comment_lines: list[str] = []
    line_count: int = 0

    while line_count < len(cpp_code_lines):
        line = cpp_code_lines[line_count].strip()

        # Check for comments
        if line.startswith(Constants.BLOCK_COMMENT_START):
            line_count += 1  # Skip the start of the block comment

            # Collect the comment lines
            while line_count < len(cpp_code_lines):
                if cpp_code_lines[line_count].strip() == Constants.COMMENT_END:
                    break

                comment_content = cpp_code_lines[line_count].strip(
                    f"{Constants.BLOCK_COMMENT_MIDDLE} "
                )
                current_comment_lines.append(comment_content)
                line_count += 1

            # Process the comment lines
            if current_comment_lines and current_comment_lines[0].startswith(
                Constants.ANSWER_KEYWORD
            ):
                # Fetch the comment id from the first line
                first_comment_line = current_comment_lines[0]
                comment_id = first_comment_line.strip(
                    f"{Constants.ANSWER_KEYWORD}{Constants.ANSWER_ID_DELIMITERS} :"
                )
                comment_id = comment_id.replace(" ", "_").replace(".", "_")
                task_comments.setdefault(comment_id, [])

                # Fetch the comment content from the remaining lines
                comment_content = ""
                for comment_line in current_comment_lines[1:]:
                    if comment_line.startswith(Constants.CODE_COMMENT_DELIMITER):
                        comment_line_count = current_comment_lines.index(comment_line)
                        while comment_line_count < len(current_comment_lines):
                            current_comment_line = current_comment_lines[
                                comment_line_count
                            ]
                            comment_content += current_comment_line + "\n"
                            comment_line_count += 1

                            if current_comment_line == Constants.CODE_COMMENT_DELIMITER:
                                break

                    else:
                        comment_content += comment_line + " "

                task_comments.setdefault(comment_id, [])
                task_comments[comment_id].append(
                    (comment_content, "\n".join(current_code_lines))
                )

            # Reset for the next line
            current_code_lines = []
            current_comment_lines = []
            line_count += 1
            continue

        # Check for inline comments
        elif line.startswith(Constants.INLINE_COMMENT_START):
            match = re.match(Constants.INLINE_ANSWER_COMMENT, line.strip("/* "))
            if match:
                comment_id = f"task_{match.group(1)}_{match.group(2)}"  # Extract the id
                comment_content = match.group(3).strip()  # Extract the comment

                task_comments.setdefault(comment_id, [])
                task_comments[comment_id].append(
                    (comment_content, "\n".join(current_code_lines))
                )

            # Reset for the next line
            current_code_lines = []
            current_comment_lines = []
            line_count += 1
            continue

        # If it's a line of code, add it to current_code_lines
        else:
            current_code_lines.append(line)
            line_count += 1
            continue

    # If there are no answer comments, return the entire code as a string
    if not task_comments:
        return "\n".join(cpp_code_lines)
    else:
        return task_comments


def generate_week_context(
    WEEKS_PATH: Path, logbook_start_date: str, cpp_files: list[dict[str, str]]
) -> dict[str, dict[str, Constants.WEEK_ANNOTATION]]:
    """
    Generate the context for the weeks.

    Parameters
    ----------
    WEEKS_PATH : Path
        Path to the weeks folder.
    logbook_start_date : str
        Start date of the logbook.
    cpp_files : list[dict[str, str]]
        C++ files to generate the context.

    Returns
    -------
    dict[str, dict[str, WEEK_TYPE_ANNOTATION]]
        Context for the weeks.

    Raises
    ------
    ValueError
        If the task type is not valid, should be unreachable.

    Notes
    -----
    The context is generated based on the names of the C++ files,
    assuming the following format: `category-topic-name.cpp`, where
    `category` is split into `type` (extra, e, or lab, l) and `number`,
    `topic` is the topic of the task, and `name` is the name of the task.
    For example, `l01-variables-introduction.cpp` is a lab task with
    number 1, topic "variables", and task name "introduction".
    """
    context: dict[str, dict[str, Constants.WEEK_ANNOTATION]] = {"weeks": {}}
    start_date = datetime.datetime.strptime(logbook_start_date, Constants.DATE_FORMAT)

    for week_index, weekly_cpp_files in enumerate(cpp_files, start=1):
        week_key = str(week_index)
        week_start_date = start_date + datetime.timedelta(weeks=week_index - 1)
        week_end_date = week_start_date + datetime.timedelta(weeks=1)

        week_folder_path = WEEKS_PATH / f"week {week_index}"
        reflection_path = week_folder_path / "reflection.md"

        if reflection_path.exists():
            with open(reflection_path, "r") as file:
                reflection_content = file.read()
        else:
            reflection_content = ""

        context["weeks"][week_key] = {
            "number": week_key,
            "start_date": week_start_date.strftime(Constants.DATE_FORMAT),
            "end_date": week_end_date.strftime(Constants.DATE_FORMAT),
            "reflection": reflection_content,
            "tasks": {
                "lab": {},
                "extra": {},
            },
        }

        for cpp_file_name, code in weekly_cpp_files.items():
            task_category, task_topic, task_name = cpp_file_name.split("-")

            task_type: Literal["lab", "extra"] = (
                "extra" if task_category[0].lower() == "e" else "lab"
            )
            task_number = task_category[1:]
            task_topic = task_topic.replace("_", " ").title()
            task_name = task_name.replace("_", " ").title()

            tasks_dict = context["weeks"][week_key]["tasks"]

            if type(tasks_dict) is not dict:
                raise ValueError("Task type is not valid.")  # Should be unreachable

            tasks_dict[task_type][task_number] = {
                "topic": task_topic,
                "name": task_name,
                "code": process_cpp_code_for_comments(code.splitlines()),
            }

        if type(tasks_dict) is not dict:
            raise ValueError("Task type is not valid.")  # Should be unreachable

        # Sort tasks in alphabetical order by task number
        for task_type in tasks_dict:
            tasks_dict[task_type] = dict(sorted(tasks_dict[task_type].items()))

    return context


def generate_logbook_contents(
    contents_path: Path,
    template_path: Path,
    context: dict[str, Any],
) -> None:
    """
    Generate the contents of the logbook.

    Parameters
    ----------
    contents_path : Path
        Path to the contents file.
    template_path : Path
        Path to the template to use.
    context : dict[str, Any]
        Context to generate the contents.
    """
    contents = render_template(template_path, context)
    save_file(contents_path, contents)


def generate_logbook_weeks(
    weeks_path: Path,
    template_path: Path,
    context: dict[str, Any],
) -> None:
    """
    Generate the weeks of the logbook.

    Parameters
    ----------
    weeks_path : Path
        Path to save the weeks to.
    template_path : Path
        Path to the template to use.
    context : dict[str, Any]
        Context to generate the weeks.
    """
    # For each week in the context, loop through and make a variable for each task's code
    for week, week_context in context["weeks"].items():
        week_content = render_template(template_path, week_context)
        save_file(weeks_path / f"week-{week}.md", week_content)


def generate_logbook_references(
    references_path: Path,
    template_path: Path,
    references: list[dict[str, str]],
) -> None:
    """
    Generate the references of the logbook.

    Parameters
    ----------
    references_path : Path
        Path to save the references to.
    template_path : Path
        Path to the template to use.
    references : list[dict[str, str]]
        References to generate the references.
    """
    references_content = render_template(template_path, {"references": references})
    save_file(references_path, references_content)


def main() -> None:
    """Generate a logbook based on config and cpp/md files."""
    # Paths
    PROJECT_PATH = Path(__file__).resolve().parent.parent
    CONFIG_PATH = PROJECT_PATH / "config" / "config.yaml"
    REFERENCES_PATH = PROJECT_PATH / "config" / "references.yaml"
    WEEKS_PATH = PROJECT_PATH / "weeks"
    MARKDOWN_PATH = PROJECT_PATH / "markdown"
    RENDER_PATH = PROJECT_PATH / "renders"
    TEMPLATES_PATH = PROJECT_PATH / "templates"

    # Load the config and references
    config: dict[str, dict[str, str]] = load_yaml(CONFIG_PATH)
    references: list[dict[str, str]] = load_yaml(REFERENCES_PATH)["references"]

    # Parse the C++ files for each week
    weeks = sorted(os.listdir(WEEKS_PATH))
    cpp_files = [parse_cpp_files(WEEKS_PATH / week) for week in weeks]

    # Generate the logbook cover
    generate_logbook_cover(
        MARKDOWN_PATH / "cover.md",
        TEMPLATES_PATH / "cover.md.j2",
        config,
    )

    # Generate the logbook contents
    week_context = generate_week_context(
        WEEKS_PATH,
        config["university"]["start"],
        cpp_files,
    )
    generate_logbook_contents(
        MARKDOWN_PATH / "contents.md",
        TEMPLATES_PATH / "contents.md.j2",
        week_context,
    )
    generate_logbook_weeks(
        MARKDOWN_PATH / "weeks",
        TEMPLATES_PATH / "week.md.j2",
        week_context,
    )

    # Generate the logbook references
    generate_logbook_references(
        MARKDOWN_PATH / "references.md",
        TEMPLATES_PATH / "references.md.j2",
        references,
    )

    # Combine the logbook
    combine_logbook(MARKDOWN_PATH, RENDER_PATH / "logbook.md")


if __name__ == "__main__":
    main()
