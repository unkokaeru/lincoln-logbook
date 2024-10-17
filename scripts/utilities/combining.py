"""combining.py: Combining utilities."""

from pathlib import Path

from .file_handling import save_file


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
