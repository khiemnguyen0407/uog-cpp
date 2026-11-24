"""Sketchy (hand-drawn style) figures for Chapter 09: Dynamic Memory Allocation.

Usage, from anywhere in the repo:

    python scripts/chap09_figures.py

This writes three PNG files into the chapter's figures folder:

    figures/stack_vs_heap.png    a pointer on the stack, its object on the heap
    figures/memory_leak.png      the pointer dies, the heap object stays behind
    figures/dynamic_array.png    new int[n]: one block of n ints on the heap

Re-render the chapter afterwards (quarto render chap_09.qmd).
Drawing helpers and fonts: see sketch.py.
"""

import argparse
from pathlib import Path

from matplotlib.patches import FancyBboxPatch

from sketch import (HEADER_EDGE, HEADER_FILL, MUTED, NAVY, REPO_ROOT, arrow, box,
                    new_canvas, note, render, step_label)

FIGURE_DIR = REPO_ROOT / "sec-02-cpp-intermediate" / "09-dynamic-allocation" / "figures"


def region(ax, x0, y0, width, height, title, detail):
    """A labelled memory region (the stack or the heap)."""
    ax.add_patch(FancyBboxPatch(
        (x0, y0), width, height, boxstyle="round,pad=0.02,rounding_size=0.2",
        facecolor=HEADER_FILL, edgecolor=HEADER_EDGE, linestyle="--", linewidth=2))
    note(ax, x0 + 0.25, y0 + height - 0.3, title, color=NAVY, size=18)
    note(ax, x0 + 0.25, y0 + 0.3, detail, color=MUTED, size=14)


def stack_vs_heap_figure():
    """int* ptr{new int{42}};"""
    fig, ax = new_canvas(11, 3.9)
    note(ax, 5.5, 3.65, "int* ptr{new int{42}};", ha="center", color=NAVY, size=20)
    region(ax, 0.3, 0.2, 4.0, 3.0, "the stack",
           "locals: freed automatically, small (MBs)")
    region(ax, 5.2, 0.2, 5.5, 3.0, "the heap",
           "new / delete: you free it, large (GBs)")

    ptr = box(ax, 2.3, 1.6, "0x5020...", "named", width=1.9, height=0.75, fontsize=17)
    step_label(ax, 2.3, 2.3, "ptr")
    obj = box(ax, 7.95, 1.6, "42", "named", width=1.4, height=0.75, fontsize=19)
    step_label(ax, 7.95, 2.3, "no name, only an address")
    arrow(ax, (2.3, 1.6), (7.95, 1.6), ptr, obj)
    return fig


def memory_leak_figure():
    """Before and after do_something() returns."""
    fig, ax = new_canvas(11, 3.8)

    note(ax, 2.75, 3.5, "inside do_something()", ha="center", color=NAVY)
    ptr = box(ax, 1.4, 1.7, "ptr", "named", width=1.3, height=0.7, fontsize=17)
    obj = box(ax, 4.1, 1.7, "42", "named", width=1.2, height=0.7, fontsize=19)
    arrow(ax, (1.4, 1.7), (4.1, 1.7), ptr, obj)
    step_label(ax, 1.4, 0.9, "stack")
    step_label(ax, 4.1, 0.9, "heap")

    ax.plot([5.5, 5.5], [0.3, 3.4], color=MUTED, linewidth=1.5, linestyle=":")

    note(ax, 8.25, 3.5, "after it returns", ha="center", color=NAVY)
    box(ax, 6.9, 1.7, "(gone)", "memory", width=1.3, height=0.7, fontsize=15)
    box(ax, 9.6, 1.7, "42", "named", width=1.2, height=0.7, fontsize=19)
    step_label(ax, 6.9, 0.9, "ptr destroyed")
    step_label(ax, 9.6, 0.9, "still allocated")
    note(ax, 8.25, 0.35, "leaked: nobody knows its address any more", ha="center",
         color=MUTED, size=14)
    return fig


def dynamic_array_figure():
    """int* numbers{new int[length]{}}; filled with squares."""
    fig, ax = new_canvas(11, 3.2)
    note(ax, 5.5, 2.95, "int* numbers{new int[length]{}};   (length = 6)", ha="center",
         color=NAVY, size=18)
    ptr = box(ax, 1.2, 1.4, "numbers", "named", width=1.8, height=0.7, fontsize=16)
    step_label(ax, 1.2, 0.75, "stack")

    left, size = 3.4, 1.15
    first = None
    for i, value in enumerate([0, 1, 4, 9, 16, 25]):
        x = left + i * size
        cell = box(ax, x, 1.4, str(value), "named", width=size - 0.05, height=0.7,
                   fontsize=18)
        step_label(ax, x, 0.75, f"[{i}]")
        first = first or cell
    arrow(ax, (1.2, 1.4), (left, 1.4), ptr, first)
    note(ax, left + 2.5 * size, 0.25, "heap: one block of 6 ints, side by side",
         ha="center", color=MUTED, size=14)
    return fig


FIGURES = {
    "stack_vs_heap.png": stack_vs_heap_figure,
    "memory_leak.png": memory_leak_figure,
    "dynamic_array.png": dynamic_array_figure,
}

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--outdir", type=Path, default=FIGURE_DIR,
                        help=f"where to write the PNG files (default: {FIGURE_DIR})")
    render(FIGURES, parser.parse_args().outdir)
