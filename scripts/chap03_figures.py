"""Sketchy (hand-drawn style) figures for Chapter 03: Control Flow.

Usage, from anywhere in the repo:

    python scripts/chap03_figures.py

This writes three PNG files into the chapter's figures folder:

    figures/for_loop_order.png    the order in which a for loop runs its parts
    figures/switch_fallthrough.png   what happens with and without break
    figures/break_continue.png    where break and continue jump to

Re-render the chapter afterwards (quarto render chap_03.qmd).
Drawing helpers and fonts: see sketch.py.
"""

import argparse
from pathlib import Path

from sketch import MUTED, NAVY, REPO_ROOT, arrow, box, new_canvas, note, render, step_label

FIGURE_DIR = REPO_ROOT / "sec-01-cpp-basics" / "03-control-flow" / "figures"


def for_loop_order_figure():
    """for (init; condition; end-expression) body: 1, then 2-3-4 repeatedly."""
    fig, ax = new_canvas(11, 3.6)
    y = 2.0
    init = box(ax, 1.25, y, "1. init\nint i{1}", width=2.0, height=0.95, fontsize=15)
    cond = box(ax, 4.15, y, "2. condition\ni <= 10", "named", width=2.1, height=0.95,
               fontsize=15)
    body = box(ax, 7.0, y, "3. loop body", width=1.9, height=0.95, fontsize=15)
    end = box(ax, 9.7, y, "4. end-expr\n++i", width=1.9, height=0.95, fontsize=15)
    after = box(ax, 4.15, 0.45, "after the loop", "object", width=2.3, height=0.55,
                fontsize=15)

    arrow(ax, (1.25, y), (4.15, y), init, cond)
    arrow(ax, (4.15, y), (7.0, y), cond, body)
    step_label(ax, 5.55, y + 0.3, "true")
    arrow(ax, (7.0, y), (9.7, y), body, end)
    arrow(ax, (9.7, y), (4.15, y), end, cond, bend=0.45)
    step_label(ax, 6.9, 3.35, "then back to 2")
    arrow(ax, (4.15, y), (4.15, 0.45), cond, after)
    step_label(ax, 4.6, 1.05, "false")
    note(ax, 0.3, 0.45, "init runs only once", color=MUTED)
    return fig


def switch_fallthrough_figure():
    """Without break, execution falls through the cases below the match."""
    fig, ax = new_canvas(11, 4.6)
    labels = ["case 1:\nOne", "case 2:\nTwo", "case 3:\nThree", "default:\nUnknown"]
    xs = [2.5, 4.75, 7.0, 9.25]

    def row(y, title, runs):
        note(ax, 0.2, y, title, color=NAVY)
        patches = []
        for x, label, ran in zip(xs, labels, runs):
            patches.append(box(ax, x, y, label, "named" if ran else "memory",
                               width=1.6, height=0.9, fontsize=15))
        arrow(ax, (xs[1], y + 0.95), (xs[1], y), None, patches[1])
        step_label(ax, xs[1] + 0.7, y + 0.8, "x == 2")
        return patches

    top = row(3.3, "no break", [False, True, True, True])
    arrow(ax, (xs[1], 3.3), (xs[2], 3.3), top[1], top[2])
    arrow(ax, (xs[2], 3.3), (xs[3], 3.3), top[2], top[3])
    step_label(ax, 8.1, 4.1, "falls through!")

    bottom = row(1.45, "with break", [False, True, False, False])
    after = box(ax, 8.1, 0.35, "after the switch", "object", width=2.4, height=0.55,
                fontsize=15)
    arrow(ax, (xs[1], 1.45), (8.1, 0.35), bottom[1], after, bend=0.25)
    step_label(ax, 5.2, 0.35, "break: jump out")
    return fig


def break_continue_figure():
    """break leaves the loop; continue skips to the next iteration."""
    fig, ax = new_canvas(11, 4.0)

    def panel(x0, title, keyword):
        note(ax, x0 + 2.6, 3.7, title, ha="center", color=NAVY)
        cond = box(ax, x0 + 1.5, 2.75, "loop condition", "named", width=2.4, height=0.6,
                   fontsize=15)
        body = box(ax, x0 + 1.5, 1.45, f"... {keyword}; ...", width=2.4, height=0.6,
                   fontsize=15)
        after = box(ax, x0 + 3.9, 0.35, "after the loop", "object", width=2.2,
                    height=0.55, fontsize=15)
        arrow(ax, (x0 + 1.5, 2.75), (x0 + 1.5, 1.45), cond, body)
        step_label(ax, x0 + 1.9, 2.1, "true")
        arrow(ax, (x0 + 1.5, 2.75), (x0 + 3.9, 0.35), cond, after, bend=-0.25)
        step_label(ax, x0 + 3.9, 2.35, "false")
        return cond, body, after

    cond, body, after = panel(0.2, "break: leave the loop now", "break")
    arrow(ax, (1.7, 1.45), (4.1, 0.35), body, after)

    cond, body, after = panel(5.8, "continue: skip to the next iteration", "continue")
    arrow(ax, (6.1, 1.45), (6.1, 2.75), bend=-0.9)  # around the left side
    step_label(ax, 5.95, 2.1, "continue")
    return fig


FIGURES = {
    "for_loop_order.png": for_loop_order_figure,
    "switch_fallthrough.png": switch_fallthrough_figure,
    "break_continue.png": break_continue_figure,
}

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--outdir", type=Path, default=FIGURE_DIR,
                        help=f"where to write the PNG files (default: {FIGURE_DIR})")
    render(FIGURES, parser.parse_args().outdir)
