"""constants.py: Constants for the logbook generator."""

from typing import Literal


class Constants:
    """Constants for the logbook generator."""

    # Type hints
    TASK_ANNOTATION = dict[str, str | dict[str, list[tuple[str, str]]]]
    WEEK_ANNOTATION = dict[
        str, str | dict[Literal["lab", "extra"], dict[str, TASK_ANNOTATION]]
    ]

    # Formatting
    DATE_FORMAT = "%Y-%m-%d"
    ANSWER_KEYWORD = "ANSWER"
    INLINE_COMMENT_START = "/*"
    BLOCK_COMMENT_START = "/**"
    BLOCK_COMMENT_MIDDLE = "*"
    COMMENT_END = "*/"
    ANSWER_ID_DELIMITERS = "()"
    INLINE_ANSWER_COMMENT = f"{ANSWER_KEYWORD} {r'\(Task (\d+).(\d+)\): (.+)'}"
    CODE_COMMENT_DELIMITER = "```"
