"""processing.py: Processing utilities."""

import re

from ..config.constants import Constants


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
