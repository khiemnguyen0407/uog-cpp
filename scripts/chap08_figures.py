"""Sketchy (hand-drawn style) figures for Chapter 08: Pointers.

Usage, from anywhere in the repo:

    python scripts/chap08_figures.py

This writes three PNG files into the chapter's figures folder:

    figures/memory_address.png        a variable lives at an address
    figures/pointer_concept.png       a pointer is an object holding an address
    figures/pointer_vs_reference.png  a reference is a name; a pointer is an object

Re-render the chapter afterwards (quarto render chap_08.qmd).
Drawing helpers and fonts: see sketch.py.
"""

import argparse
from pathlib import Path

from sketch import MUTED, NAVY, REPO_ROOT, arrow, box, new_canvas, note, render, step_label

FIGURE_DIR = REPO_ROOT / "sec-02-cpp-intermediate" / "08-pointers" / "figures"


def cell(ax, x, y, value, name=None, address=None, kind="named", width=1.6):
    """A memory cell, with an optional name tag above and address below."""
    patch = box(ax, x, y, value, kind, width=width, height=0.8, fontsize=19)
    if address:
        step_label(ax, x, y - 0.65, f"address {address}")
    if name:
        tag = box(ax, x, y + 1.2, name, "object", width=1.4, height=0.5, fontsize=16)
        arrow(ax, (x, y + 1.2), (x, y + 0.42), tag)
    return patch


def memory_address_figure():
    """int x{425}; lives somewhere in memory, at some address."""
    fig, ax = new_canvas(11, 3.3)
    note(ax, 5.5, 3.05, "int x{425};", ha="center", color=NAVY, size=20)
    addresses = ["0x1230", "0x1234", "0x1238", "0x123c"]
    for i, address in enumerate(addresses):
        x = 2.0 + i * 2.1
        if address == "0x1234":
            cell(ax, x, 1.2, "425", name="x", address=address)
        else:
            cell(ax, x, 1.2, "?", address=address, kind="memory")
    note(ax, 0.3, 1.2, "...", size=22)
    note(ax, 10.7, 1.2, "...", ha="right", size=22)
    return fig


def pointer_concept_figure():
    """int* ptr{&x}; ptr is an object whose value is the address of x."""
    fig, ax = new_canvas(11, 3.4)
    note(ax, 5.5, 3.15, "int x{425};     int* ptr{&x};", ha="center", color=NAVY, size=19)
    ptr = cell(ax, 2.6, 1.2, "0x1234", name="ptr", address="0x1550", width=2.0)
    x = cell(ax, 8.4, 1.2, "425", name="x", address="0x1234", width=2.0)
    arrow(ax, (2.6, 1.2), (8.4, 1.2), ptr, x)
    step_label(ax, 5.5, 1.55, "ptr points at x")
    step_label(ax, 5.5, 1.2 - 0.35, "*ptr is 425")
    return fig


def pointer_vs_reference_figure():
    """ref is just another name for x; ptr is a separate object pointing at x."""
    fig, ax = new_canvas(11, 3.6)
    note(ax, 5.5, 3.35, "int x{5};    int& ref{x};    int* ptr{&x};", ha="center",
         color=NAVY, size=18)
    x = box(ax, 5.5, 1.2, "5 -> 6 -> 7", "named", width=2.4, height=0.8, fontsize=18)
    step_label(ax, 5.5, 0.55, "the one and only object")

    x_tag = box(ax, 4.2, 2.45, "x", "object", width=1.0, height=0.5, fontsize=16)
    ref_tag = box(ax, 6.8, 2.45, "ref", "object", width=1.0, height=0.5, fontsize=16)
    arrow(ax, (4.2, 2.45), (5.5, 1.2), x_tag, x)
    arrow(ax, (6.8, 2.45), (5.5, 1.2), ref_tag, x)
    note(ax, 0.3, 2.45, "ref: just another name", color=MUTED)
    note(ax, 0.3, 2.1, "ref = 6; changes x", color=MUTED)

    ptr = box(ax, 9.6, 1.2, "&x", "named", width=1.4, height=0.8, fontsize=18)
    ptr_tag = box(ax, 9.6, 2.45, "ptr", "object", width=1.0, height=0.5, fontsize=16)
    arrow(ax, (9.6, 2.45), (9.6, 1.2), ptr_tag, ptr)
    arrow(ax, (9.6, 1.2), (5.5, 1.2), ptr, x)
    note(ax, 10.8, 0.55, "ptr: an object of its own", ha="right", color=MUTED)
    note(ax, 10.8, 0.2, "*ptr = 7; changes x", ha="right", color=MUTED)
    return fig


FIGURES = {
    "memory_address.png": memory_address_figure,
    "pointer_concept.png": pointer_concept_figure,
    "pointer_vs_reference.png": pointer_vs_reference_figure,
}

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--outdir", type=Path, default=FIGURE_DIR,
                        help=f"where to write the PNG files (default: {FIGURE_DIR})")
    render(FIGURES, parser.parse_args().outdir)
