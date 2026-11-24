"""Sketchy (hand-drawn style) figures for Chapter 12: More on Classes.

Usage, from anywhere in the repo:

    python scripts/chap12_figures.py

This writes three PNG files into the chapter's figures folder:

    figures/method_chaining.png     each call returns the same object
    figures/object_lifetimes.png    constructors and destructors on a timeline
    figures/shallow_copy.png        two objects, one heap int, two deletes

Re-render the chapter afterwards (quarto render chap_12.qmd).
Drawing helpers and fonts: see sketch.py.
"""

import argparse
from pathlib import Path

from sketch import MUTED, NAVY, REPO_ROOT, arrow, box, new_canvas, note, render, step_label

FIGURE_DIR = REPO_ROOT / "sec-03-oop" / "12-classes-more" / "figures"


def method_chaining_figure():
    """calc.add(5).add(-3).mult(4): every call returns *this, i.e. calc."""
    fig, ax = new_canvas(11, 3.0)
    note(ax, 5.5, 2.75, "calc.add(5).add(-3).mult(4);", ha="center", color=NAVY, size=20)
    calls = ["calc.add(5)", ".add(-3)", ".mult(4)"]
    values = ["calc is 47", "calc is 44", "calc is 176"]
    xs = [2.0, 5.5, 9.0]
    previous = None
    for x, call, value in zip(xs, calls, values):
        patch = box(ax, x, 1.5, call, "named", width=2.4, height=0.7, fontsize=17)
        step_label(ax, x, 0.85, value)
        if previous:
            arrow(ax, (x - 3.5, 1.5), (x, 1.5), previous, patch)
            step_label(ax, x - 1.75, 1.85, "returns calc")
        previous = patch
    note(ax, 5.5, 0.25, "return *this; hands back the same object, ready for the next call",
         ha="center", color=MUTED, size=14)
    return fig


def object_lifetimes_figure():
    """destructor_example.cpp on a timeline."""
    fig, ax = new_canvas(11, 3.6)
    note(ax, 0.3, 3.3, "time ->", color=MUTED, size=16)
    rows = [("simple1", 1.4, 10.4, 2.6), ("simple2", 2.9, 5.1, 1.75), ("simple3", 6.1, 9.1, 0.9)]
    for name, start, end, y in rows:
        note(ax, start - 0.15, y, name, ha="right", color=NAVY, size=15)
        ax.plot([start, end], [y, y], color=NAVY, linewidth=6, solid_capstyle="round")
        step_label(ax, start, y + 0.32, "constructor")
        step_label(ax, end, y + 0.32, "destructor")
    note(ax, 4.0, 0.25, "simple2 dies at the end of its block", ha="center", color=MUTED,
         size=14)
    note(ax, 8.9, 0.25, "last constructed, first destroyed", ha="center", color=MUTED,
         size=14)
    return fig


def shallow_copy_figure():
    """IntBox b{a}; copies the pointer, not the int."""
    fig, ax = new_canvas(11, 3.4)
    note(ax, 5.5, 3.15, "IntBox a{42};     IntBox b{a};", ha="center", color=NAVY, size=19)
    a = box(ax, 1.6, 2.1, "a.data", "named", width=2.0, height=0.7, fontsize=17)
    b = box(ax, 1.6, 0.8, "b.data", "named", width=2.0, height=0.7, fontsize=17)
    heap = box(ax, 6.0, 1.45, "42", "named", width=1.4, height=0.9, fontsize=22)
    arrow(ax, (1.6, 2.1), (6.0, 1.45), a, heap)
    arrow(ax, (1.6, 0.8), (6.0, 1.45), b, heap)
    step_label(ax, 6.0, 0.65, "one int on the heap")
    note(ax, 7.4, 2.3, "the implicit copy constructor copies", color=MUTED, size=14)
    note(ax, 7.4, 1.95, "the address, not the int", color=MUTED, size=14)
    note(ax, 7.4, 1.25, "~IntBox() runs twice:", color=MUTED, size=14)
    note(ax, 7.4, 0.9, "delete, then delete again!", color=MUTED, size=14)
    return fig


FIGURES = {
    "method_chaining.png": method_chaining_figure,
    "object_lifetimes.png": object_lifetimes_figure,
    "shallow_copy.png": shallow_copy_figure,
}

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--outdir", type=Path, default=FIGURE_DIR,
                        help=f"where to write the PNG files (default: {FIGURE_DIR})")
    render(FIGURES, parser.parse_args().outdir)
