"""Sketchy (hand-drawn style) figures for Chapter 07: Compound Types and References.

Usage, from anywhere in the repo:

    python scripts/chap07_figures.py

This writes three PNG files into the chapter's figures folder:

    figures/lvalue_rvalue.png       an lvalue is an object; an rvalue is a value
    figures/reference_alias.png     a reference is a second name for an object
    figures/value_vs_reference.png  pass by value copies; pass by reference doesn't

Re-render the chapter afterwards (quarto render chap_07.qmd).
Drawing helpers and fonts: see sketch.py.
"""

import argparse
from pathlib import Path

from sketch import MUTED, NAVY, REPO_ROOT, arrow, box, new_canvas, note, render, step_label

FIGURE_DIR = REPO_ROOT / "sec-02-cpp-intermediate" / "07-compound-types-references" / "figures"


def named_cell(ax, x, y, name, value, address=None, tag_y=None):
    """A memory box holding `value`, with a name tag above it."""
    cell = box(ax, x, y, value, "named", width=1.3, height=0.8, fontsize=20)
    if address:
        step_label(ax, x, y - 0.65, address)
    if name:
        tag_y = tag_y or y + 1.2
        tag = box(ax, x, tag_y, name, "object", width=1.1, height=0.5, fontsize=16)
        arrow(ax, (x, tag_y), (x, y + 0.42), tag)
    return cell


def lvalue_rvalue_figure():
    """x = 5: the left side is an object, the right side is just a value."""
    fig, ax = new_canvas(11, 3.6)
    note(ax, 5.5, 3.3, "x = 5;", ha="center", color=NAVY, size=22)

    named_cell(ax, 2.6, 1.3, "x", "5", address="lives at 0x7ffc...a4")
    note(ax, 2.6, 0.2, "lvalue: an object with an identity", ha="center", color=NAVY)

    value = box(ax, 8.4, 1.3, "5", "memory", width=1.3, height=0.8, fontsize=20)
    note(ax, 8.4, 0.2, "rvalue: just a value, gone after use", ha="center", color=NAVY)

    arrow(ax, (8.4, 1.3), (2.6, 1.3), value, None)
    step_label(ax, 5.5, 2.0, "the value 5 is copied")
    step_label(ax, 5.5, 1.65, "into the object x")
    return fig


def reference_alias_figure():
    """int& ref{x}: one object, two names."""
    fig, ax = new_canvas(11, 3.2)
    note(ax, 5.5, 2.95, "int x{42};     int& ref{x};", ha="center", color=NAVY, size=19)
    cell = box(ax, 5.5, 0.9, "42", "named", width=1.4, height=0.8, fontsize=22)
    x_tag = box(ax, 3.6, 2.05, "x", "object", width=1.1, height=0.5, fontsize=16)
    r_tag = box(ax, 7.4, 2.05, "ref", "object", width=1.1, height=0.5, fontsize=16)
    arrow(ax, (3.6, 2.05), (5.5, 0.9), x_tag, cell)
    arrow(ax, (7.4, 2.05), (5.5, 0.9), r_tag, cell)
    note(ax, 8.4, 0.9, "one object, two names:", color=MUTED)
    note(ax, 8.4, 0.5, "change one, you change both", color=MUTED)
    return fig


def value_vs_reference_figure():
    """Passing x to f(double v) versus f(double& r)."""
    fig, ax = new_canvas(11, 3.8)

    note(ax, 2.75, 3.5, "pass by value: void f(double v)", ha="center", color=NAVY)
    named_cell(ax, 1.6, 1.4, "x (main)", "42", tag_y=2.6)
    named_cell(ax, 3.9, 1.4, "v (f)", "42", tag_y=2.6)
    step_label(ax, 2.75, 0.5, "two objects: v is a copy")

    note(ax, 8.25, 3.5, "pass by reference: void f(double& r)", ha="center", color=NAVY)
    cell = box(ax, 8.25, 1.4, "42", "named", width=1.3, height=0.8, fontsize=20)
    x_tag = box(ax, 7.1, 2.6, "x (main)", "object", width=1.5, height=0.5, fontsize=15)
    r_tag = box(ax, 9.4, 2.6, "r (f)", "object", width=1.5, height=0.5, fontsize=15)
    arrow(ax, (7.1, 2.6), (8.25, 1.4), x_tag, cell)
    arrow(ax, (9.4, 2.6), (8.25, 1.4), r_tag, cell)
    step_label(ax, 8.25, 0.5, "one object: no copy")

    ax.plot([5.5, 5.5], [0.3, 3.3], color=MUTED, linewidth=1.5, linestyle=":")
    return fig


FIGURES = {
    "lvalue_rvalue.png": lvalue_rvalue_figure,
    "reference_alias.png": reference_alias_figure,
    "value_vs_reference.png": value_vs_reference_figure,
}

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--outdir", type=Path, default=FIGURE_DIR,
                        help=f"where to write the PNG files (default: {FIGURE_DIR})")
    render(FIGURES, parser.parse_args().outdir)
