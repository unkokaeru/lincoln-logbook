"""parsing.py: Parsing utilities."""

from pathlib import Path


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
