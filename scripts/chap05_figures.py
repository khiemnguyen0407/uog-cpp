"""Sketchy (hand-drawn style) figures for Chapter 05: Function Overloading.

Usage, from anywhere in the repo:

    python scripts/chap05_figures.py

This writes two PNG files into the chapter's figures folder:

    figures/overload_resolution.png   how the compiler picks an overload
    figures/default_arguments.png     the compiler fills in missing arguments

Re-render the chapter afterwards (quarto render chap_05.qmd).
Drawing helpers and fonts: see sketch.py.
"""

import argparse
from pathlib import Path

from sketch import MUTED, NAVY, REPO_ROOT, arrow, box, new_canvas, note, render, step_label

FIGURE_DIR = REPO_ROOT / "sec-02-cpp-intermediate" / "05-function-overloading" / "figures"


def overload_resolution_figure():
    """add(1, 2): candidates -> viable functions -> best match."""
    fig, ax = new_canvas(11, 4.4)
    note(ax, 5.5, 4.1, "the call:   add(1, 2)", ha="center", color=NAVY, size=19)

    xs = [1.9, 5.5, 9.2]
    for x, title in zip(xs, ["1. candidates", "2. viable", "3. best match"]):
        note(ax, x, 3.45, title, ha="center", color=NAVY)

    w, h = 2.9, 0.62
    c1 = box(ax, xs[0], 2.65, "add(int, int)", width=w, height=h, fontsize=15)
    c2 = box(ax, xs[0], 1.75, "add(double, double)", width=w, height=h, fontsize=15)
    c3 = box(ax, xs[0], 0.85, "add(double, double, double)", "memory", width=w,
             height=h, fontsize=13)
    v1 = box(ax, xs[1], 2.65, "add(int, int)", width=w, height=h, fontsize=15)
    v2 = box(ax, xs[1], 1.75, "add(double, double)", width=w, height=h, fontsize=15)
    best = box(ax, xs[2], 2.65, "add(int, int)", "program", width=2.6, height=h,
               fontsize=15)

    arrow(ax, (xs[0], 2.65), (xs[1], 2.65), c1, v1)
    arrow(ax, (xs[0], 1.75), (xs[1], 1.75), c2, v2)
    arrow(ax, (xs[1], 2.65), (xs[2], 2.65), v1, best)
    step_label(ax, xs[1], 0.85, "needs 3 arguments: out")
    step_label(ax, xs[2], 1.95, "exact match")
    step_label(ax, xs[2], 1.6, "beats a conversion")
    note(ax, xs[1], 0.3, "the double version needs int -> double conversions: viable, but worse", ha="center",
         color=MUTED, size=14)
    return fig


def default_arguments_figure():
    """print(3) is compiled as print(3, 4)."""
    fig, ax = new_canvas(11, 2.7)
    note(ax, 5.5, 2.35, "void print(int x, int y = 4);", ha="center", color=NAVY, size=18)
    written = box(ax, 2.3, 1.15, "print(3);", width=2.6, height=0.7, fontsize=18)
    compiled = box(ax, 8.7, 1.15, "print(3, 4);", "named", width=2.8, height=0.7,
                   fontsize=18)
    arrow(ax, (2.3, 1.15), (8.7, 1.15), written, compiled)
    step_label(ax, 5.5, 1.5, "the compiler fills in")
    step_label(ax, 5.5, 0.8, "the default")
    note(ax, 2.3, 0.35, "what you write", ha="center")
    note(ax, 8.7, 0.35, "what gets compiled", ha="center")
    return fig


FIGURES = {
    "overload_resolution.png": overload_resolution_figure,
    "default_arguments.png": default_arguments_figure,
}

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--outdir", type=Path, default=FIGURE_DIR,
                        help=f"where to write the PNG files (default: {FIGURE_DIR})")
    render(FIGURES, parser.parse_args().outdir)
