"""markdown.py: Generate Markdown files for the logbook."""

import datetime
from pathlib import Path
from typing import Any, Literal

from ..config.constants import Constants
from ..utilities.file_handling import save_file
from ..utilities.rendering import render_template
from .processing import process_cpp_code_for_comments


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
