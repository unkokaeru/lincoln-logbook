"""file_handling.py: File handling utilities."""

from pathlib import Path
from typing import Any

import yaml


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
