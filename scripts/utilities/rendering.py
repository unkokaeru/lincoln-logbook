"""rendering.py: Rendering utilities."""

from pathlib import Path
from typing import Any

import jinja2


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
