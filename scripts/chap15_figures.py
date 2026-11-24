"""Sketchy (hand-drawn style) figures for Chapter 15: Virtual Functions and Polymorphism.

Usage, from anywhere in the repo:

    python scripts/chap15_figures.py

This writes three PNG files into the chapter's figures folder:

    figures/base_view.png         a Base reference sees only the Base part
    figures/virtual_dispatch.png  how a virtual call finds the right function
    figures/object_slicing.png    copying a Derived into a Base slices it

Re-render the chapter afterwards (quarto render chap_15.qmd).
Drawing helpers and fonts: see sketch.py.
"""

import argparse
from pathlib import Path

from matplotlib.patches import FancyBboxPatch

from sketch import (HEADER_EDGE, HEADER_FILL, MUTED, NAVY, REPO_ROOT, arrow, box,
                    new_canvas, note, render, step_label)

FIGURE_DIR = REPO_ROOT / "sec-03-oop" / "15-virtual-functions" / "figures"


def derived_object(ax, x0, y0, title="a Derived object"):
    """A dashed frame holding a Base part and a Derived part; returns both."""
    ax.add_patch(FancyBboxPatch((x0, y0), 3.6, 2.2,
                                boxstyle="round,pad=0.02,rounding_size=0.2",
                                facecolor=HEADER_FILL, edgecolor=HEADER_EDGE,
                                linestyle="--", linewidth=2))
    note(ax, x0 + 0.2, y0 + 1.95, title, color=NAVY, size=14)
    base = box(ax, x0 + 1.8, y0 + 1.2, "Base part", "named", width=3.0, height=0.55,
               fontsize=15)
    derived = box(ax, x0 + 1.8, y0 + 0.5, "Derived part", "source", width=3.0,
                  height=0.55, fontsize=15)
    return base, derived


def base_view_figure():
    """Base& base_ref{derived}: through it, only the Base part is visible."""
    fig, ax = new_canvas(11, 3.4)
    note(ax, 5.5, 3.15, "Base& base_ref{derived};", ha="center", color=NAVY, size=19)
    ref = box(ax, 1.6, 1.6, "base_ref", "object", width=2.0, height=0.65, fontsize=16)
    base, _ = derived_object(ax, 4.6, 0.4)
    arrow(ax, (1.6, 1.6), (6.4, 1.6), ref, base)
    note(ax, 8.6, 2.0, "base_ref only knows", color=MUTED, size=14)
    note(ax, 8.6, 1.65, "about the Base part, so", color=MUTED, size=14)
    note(ax, 8.6, 1.3, "it calls Base::get_name()...", color=MUTED, size=14)
    note(ax, 8.6, 0.8, "...unless get_name()", color=MUTED, size=14)
    note(ax, 8.6, 0.45, "is virtual", color=MUTED, size=14)
    return fig


def virtual_dispatch_figure():
    """animal.speak() through a virtual table."""
    fig, ax = new_canvas(11, 3.8)
    note(ax, 5.5, 3.55, "const Animal& animal{felix};   animal.speak();", ha="center",
         color=NAVY, size=17)
    call = box(ax, 1.4, 1.8, "animal.speak()", "object", width=2.2, height=0.65,
               fontsize=15)
    obj = box(ax, 4.3, 1.8, "felix (a Cat)\nhidden vptr", "named", width=2.2, height=1.0,
              fontsize=15)
    table = box(ax, 7.4, 1.8, "Cat's table\nspeak -> Cat::speak", "source", width=2.8,
                height=1.0, fontsize=14)
    func = box(ax, 10.1, 1.8, "Meow", "program", width=1.3, height=0.65, fontsize=16)
    arrow(ax, (1.4, 1.8), (4.3, 1.8), call, obj)
    arrow(ax, (4.3, 1.8), (7.4, 1.8), obj, table)
    arrow(ax, (7.4, 1.8), (10.1, 1.8), table, func)
    step_label(ax, 2.85, 2.75, "follow the object's")
    step_label(ax, 5.85, 2.75, "pointer to its class's table")
    note(ax, 5.5, 0.35, "the choice happens while the program runs, so the actual "
         "object decides", ha="center", color=MUTED, size=14)
    return fig


def object_slicing_figure():
    """Base copy{derived}; only the Base part is copied."""
    fig, ax = new_canvas(11, 3.4)
    note(ax, 5.5, 3.15, "Base copy{derived};", ha="center", color=NAVY, size=19)
    base, derived = derived_object(ax, 0.6, 0.4, "derived")
    copy = box(ax, 8.6, 1.6, "copy:\na whole Base,\nnothing more", "named", width=2.8,
               height=1.3, fontsize=15)
    arrow(ax, (2.4, 1.6), (8.6, 1.6), base, copy)
    step_label(ax, 6.0, 2.3, "only the Base part")
    step_label(ax, 6.0, 1.98, "is copied")
    note(ax, 2.4, 0.15, "the Derived part is sliced off", ha="center", color=MUTED,
         size=14)
    return fig


FIGURES = {
    "base_view.png": base_view_figure,
    "virtual_dispatch.png": virtual_dispatch_figure,
    "object_slicing.png": object_slicing_figure,
}

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--outdir", type=Path, default=FIGURE_DIR,
                        help=f"where to write the PNG files (default: {FIGURE_DIR})")
    render(FIGURES, parser.parse_args().outdir)
