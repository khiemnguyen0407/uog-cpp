"""Sketchy (hand-drawn style) figure for Chapter 06: Function Templates.

Usage, from anywhere in the repo:

    python scripts/chap06_figures.py

This writes one PNG file into the chapter's figures folder:

    figures/template_instantiation.png   one template, one function per type

Re-render the chapter afterwards (quarto render chap_06.qmd).
Drawing helpers and fonts: see sketch.py.
"""

import argparse
from pathlib import Path

from sketch import NAVY, REPO_ROOT, arrow, box, new_canvas, note, render, step_label

FIGURE_DIR = REPO_ROOT / "sec-02-cpp-intermediate" / "06-function-template" / "figures"


def template_instantiation_figure():
    """The template is a stencil; the compiler stamps out real functions."""
    fig, ax = new_canvas(11, 3.9)
    template = box(ax, 2.1, 1.9, "template <typename T>\nT max(T x, T y)", "header",
                   width=3.6, height=1.2, fontsize=16)
    as_int = box(ax, 8.4, 2.9, "int max(int x, int y)", "named", width=4.4, height=0.7,
                 fontsize=16)
    as_double = box(ax, 8.4, 0.9, "double max(double x, double y)", "named", width=4.4,
                    height=0.7, fontsize=15)

    arrow(ax, (2.1, 1.9), (8.4, 2.9), template, as_int)
    arrow(ax, (2.1, 1.9), (8.4, 0.9), template, as_double)
    step_label(ax, 4.95, 2.85, "max(1, 2)")
    step_label(ax, 4.95, 2.5, "T = int")
    step_label(ax, 4.95, 1.25, "max(1.5, 2.5)")
    step_label(ax, 4.95, 0.9, "T = double")

    note(ax, 2.1, 3.55, "the template: a stencil", ha="center", color=NAVY)
    note(ax, 8.4, 3.65, "real functions, made when needed", ha="center", color=NAVY)
    return fig


FIGURES = {
    "template_instantiation.png": template_instantiation_figure,
}

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--outdir", type=Path, default=FIGURE_DIR,
                        help=f"where to write the PNG file (default: {FIGURE_DIR})")
    render(FIGURES, parser.parse_args().outdir)
