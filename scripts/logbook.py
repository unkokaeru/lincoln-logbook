"""logbook.py: Generate a logbook based on config and cpp/md files."""

import os
from pathlib import Path

from .generation.markdown import (
    generate_logbook_contents,
    generate_logbook_cover,
    generate_logbook_references,
    generate_logbook_weeks,
    generate_week_context,
)  # TODO: Fix project organisation
from .utilities.combining import combine_logbook
from .utilities.file_handling import load_yaml
from .utilities.parsing import parse_cpp_files


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
