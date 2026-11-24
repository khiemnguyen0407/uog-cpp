"""Sketchy (hand-drawn style) figures for Chapter 13: Operator Overloading.

Usage, from anywhere in the repo:

    python scripts/chap13_figures.py

This writes two PNG files into the chapter's figures folder:

    figures/operator_as_function.png   a + b is really a function call
    figures/output_chaining.png        how std::cout << p1 << " and " << p2 works

Re-render the chapter afterwards (quarto render chap_13.qmd).
Drawing helpers and fonts: see sketch.py.
"""

import argparse
from pathlib import Path

from sketch import MUTED, NAVY, REPO_ROOT, arrow, box, new_canvas, note, render, step_label

FIGURE_DIR = REPO_ROOT / "sec-03-oop" / "13-operator-overloading" / "figures"


def operator_as_function_figure():
    """a + b becomes operator+(a, b), or a.operator+(b)."""
    fig, ax = new_canvas(11, 3.3)
    source = box(ax, 1.6, 1.6, "a + b", "named", width=2.0, height=0.9, fontsize=24)
    normal = box(ax, 7.4, 2.45, "operator+(a, b)", "source", width=3.6, height=0.75,
                 fontsize=18)
    member = box(ax, 7.4, 0.75, "a.operator+(b)", "source", width=3.6, height=0.75,
                 fontsize=18)
    arrow(ax, (1.6, 1.6), (7.4, 2.45), source, normal)
    arrow(ax, (1.6, 1.6), (7.4, 0.75), source, member)
    step_label(ax, 4.0, 2.55, "non-member (normal or friend)")
    step_label(ax, 4.0, 0.65, "member of a's class")
    note(ax, 9.4, 1.6, "the compiler picks the version you wrote",
         ha="right", color=MUTED, size=14)
    return fig


def output_chaining_figure():
    """((std::cout << p1) << " and ") << p2: each << returns std::cout."""
    fig, ax = new_canvas(11, 3.4)
    note(ax, 5.5, 3.15, 'std::cout << p1 << " and " << p2;', ha="center", color=NAVY,
         size=20)
    steps = ['std::cout << p1', '... << " and "', '... << p2']
    xs = [1.7, 5.5, 9.3]
    previous = None
    for x, text in zip(xs, steps):
        patch = box(ax, x, 1.75, text, "named", width=2.6, height=0.75, fontsize=16)
        if previous:
            arrow(ax, (x - 3.8, 1.75), (x, 1.75), previous, patch)
            step_label(ax, x - 1.9, 2.45, "returns std::cout")
        previous = patch
    note(ax, 5.5, 0.85, "operator<< prints, then returns the stream it was given,",
         ha="center", color=MUTED, size=14)
    note(ax, 5.5, 0.5, "so the next << has a stream to work with", ha="center",
         color=MUTED, size=14)
    return fig


FIGURES = {
    "operator_as_function.png": operator_as_function_figure,
    "output_chaining.png": output_chaining_figure,
}

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--outdir", type=Path, default=FIGURE_DIR,
                        help=f"where to write the PNG files (default: {FIGURE_DIR})")
    render(FIGURES, parser.parse_args().outdir)
