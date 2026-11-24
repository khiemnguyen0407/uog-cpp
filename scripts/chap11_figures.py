"""Sketchy (hand-drawn style) figures for Chapter 11: Classes.

Usage, from anywhere in the repo:

    python scripts/chap11_figures.py

This writes two PNG files into the chapter's figures folder:

    figures/construction_steps.png   what happens when an object is created
    figures/copy_constructor.png     a copy is a new, independent object

Re-render the chapter afterwards (quarto render chap_11.qmd).
The chapter also uses private-vs-public.jpg, which is not generated here.
Drawing helpers and fonts: see sketch.py.
"""

import argparse
from pathlib import Path

from sketch import MUTED, NAVY, REPO_ROOT, arrow, box, new_canvas, note, render, step_label

FIGURE_DIR = REPO_ROOT / "sec-03-oop" / "11-classes" / "figures"


def construction_steps_figure():
    """Foo foo{6}; memory first, then members, then the constructor body."""
    fig, ax = new_canvas(11, 3.9)
    note(ax, 5.5, 3.65, "Foo foo{6};", ha="center", color=NAVY, size=20)
    steps = [
        ("1. memory", "set aside\n(no values yet)"),
        ("2. members", "initialized,\nin declaration order"),
        ("3. body", "the constructor's\n{ ... } runs"),
        ("4. ready", "a consistent,\nusable object"),
    ]
    xs = [1.4, 4.1, 6.8, 9.5]
    previous = None
    for x, (title, detail) in zip(xs, steps):
        kind = "program" if title.startswith("4") else "named"
        patch = box(ax, x, 2.45, title, kind, width=2.2, height=0.75, fontsize=17)
        step_label(ax, x, 1.55, detail)
        if previous:
            arrow(ax, (x - 2.7, 2.45), (x, 2.45), previous, patch)
        previous = patch
    note(ax, 4.1, 0.55, "for each member: initializer list, else default member", ha="center",
         color=MUTED, size=13)
    note(ax, 4.1, 0.2, "initializer, else uninitialized (garbage)", ha="center",
         color=MUTED, size=13)
    note(ax, 8.15, 0.4, "the constructor doesn't create the object:\nit sets it up",
         ha="center", color=MUTED, size=13)
    return fig


def copy_constructor_figure():
    """Fraction f_copy{f}; a new object, initialized from an existing one."""
    fig, ax = new_canvas(11, 3.0)
    note(ax, 5.5, 2.75, "Fraction f{5, 3};      Fraction f_copy{f};", ha="center",
         color=NAVY, size=19)
    f = box(ax, 1.8, 1.35, "f\n5 / 3", "named", width=2.0, height=1.0, fontsize=18)
    copy = box(ax, 5.5, 1.35, "copy\nconstructor", "source", width=2.4, height=1.0,
               fontsize=16)
    f_copy = box(ax, 9.2, 1.35, "f_copy\n5 / 3", "named", width=2.0, height=1.0, fontsize=18)
    arrow(ax, (1.8, 1.35), (5.5, 1.35), f, copy)
    arrow(ax, (5.5, 1.35), (9.2, 1.35), copy, f_copy)
    note(ax, 5.5, 0.35, "two separate objects: changing one never changes the other",
         ha="center", color=MUTED, size=14)
    return fig


FIGURES = {
    "construction_steps.png": construction_steps_figure,
    "copy_constructor.png": copy_constructor_figure,
}

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--outdir", type=Path, default=FIGURE_DIR,
                        help=f"where to write the PNG files (default: {FIGURE_DIR})")
    render(FIGURES, parser.parse_args().outdir)
