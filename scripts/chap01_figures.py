"""Sketchy (hand-drawn style) figures for Chapter 01: Program Structure and Variables.

Usage, from anywhere in the repo:

    python scripts/chap01_figures.py

This writes four PNG files into the chapter's figures folder:

    figures/build_and_run.png      source code -> program -> output
    figures/variables_memory.png   a variable is a named box in memory
    figures/io_direction.png       << and >> point the way the data moves
    figures/cin_buffer.png         std::cin reads from a buffer

Re-render the chapter afterwards (quarto render chap_01.qmd).
Drawing helpers and fonts: see sketch.py.
"""

import argparse
from pathlib import Path

from sketch import (MUTED, NAVY, REPO_ROOT, arrow, box, new_canvas, note, render,
                    step_label)

FIGURE_DIR = REPO_ROOT / "sec-01-cpp-basics" / "01-structure-and-varaibles" / "figures"


def build_and_run_figure():
    """From the code you write to the text you see."""
    fig, ax = new_canvas(11, 2.6)
    y = 1.15

    source = box(ax, 1.3, y, "hello.cpp", width=1.9)
    program = box(ax, 5.5, y, "hello", "program", width=1.6)
    output = box(ax, 9.45, y, "Hello world!", "terminal", width=2.6)

    arrow(ax, (1.3, y), (5.5, y), source, program)
    step_label(ax, 3.4, y + 0.35, "compile + link")
    step_label(ax, 3.4, y - 0.35, "g++")
    arrow(ax, (5.5, y), (9.45, y), program, output)
    step_label(ax, 7.3, y + 0.35, "run")
    step_label(ax, 7.3, y - 0.35, "./hello")

    note(ax, 1.3, 2.2, "you write this", ha="center")
    note(ax, 5.5, 2.2, "the compiler makes this", ha="center")
    note(ax, 9.45, 2.2, "you see this", ha="center")
    return fig


def variables_memory_figure():
    """Memory is a long row of boxes; a variable is a box with a name."""
    fig, ax = new_canvas(11, 3.9)
    y = 1.4
    cells = [("?", None), ("5", "x"), ("?", None), ("?", None), ("7", "width"), ("?", None)]
    left, step = 1.35, 1.5

    for i, (value, name) in enumerate(cells):
        x = left + i * step
        box(ax, x, y, value, "named" if name else "memory", width=1.25, height=0.75)
        step_label(ax, x, y - 0.65, f"0x...{0xa0 + 4 * i:02x}")
        if name:
            tag = box(ax, x, y + 1.2, name, "object", width=1.15, height=0.48)
            arrow(ax, (x, y + 1.2), (x, y + 0.4), tag)

    note(ax, 0.25, y, "...", size=22)
    note(ax, 10.75, y, "...", ha="right", size=22)
    note(ax, 5.5, 3.6, "a variable = a named object (a box that holds a value)", ha="center")
    note(ax, 5.5, 0.25, "every box has an address: a number that says where it is", ha="center")
    return fig


def io_direction_figure():
    """The arrows in << and >> point the way the data moves."""
    fig, ax = new_canvas(11, 3.6)
    top, bottom = 2.6, 0.95

    # std::cout << "Hello";   the data moves right-to-left, into std::cout
    screen = box(ax, 1.0, top, "screen", "terminal", width=1.7)
    cout = box(ax, 3.9, top, "std::cout", "object", width=2.0)
    hello = box(ax, 6.8, top, '"Hello"', "source", width=1.7)
    arrow(ax, (6.8, top), (3.9, top), hello, cout)
    step_label(ax, 5.35, top + 0.38, "<<")
    arrow(ax, (3.9, top), (1.0, top), cout, screen)

    # std::cin >> x;   the data moves left-to-right, out of std::cin
    keyboard = box(ax, 1.0, bottom, "keyboard", "terminal", width=1.7)
    cin = box(ax, 3.9, bottom, "std::cin", "object", width=2.0)
    x = box(ax, 6.8, bottom, "x", "named", width=1.0)
    arrow(ax, (1.0, bottom), (3.9, bottom), keyboard, cin)
    arrow(ax, (3.9, bottom), (6.8, bottom), cin, x)
    step_label(ax, 5.35, bottom + 0.38, ">>")

    note(ax, 10.75, top, 'std::cout << "Hello";', ha="right", color=NAVY)
    note(ax, 10.75, bottom, "std::cin >> x;", ha="right", color=NAVY)
    note(ax, 3.9, (top + bottom) / 2, "follow the arrows: they show where the data goes",
         ha="center")
    return fig


def cin_buffer_figure():
    """What you type waits in a buffer until std::cin takes it."""
    fig, ax = new_canvas(11, 3.6)
    buffer_y = 2.3

    note(ax, 0.3, 3.25, "You type   4 5   and press Enter. It all goes into the input buffer:")
    chars = ["4", "space", "5", "Enter"]
    widths = [0.8, 1.3, 0.8, 1.3]
    x = 2.2
    centres = []
    for ch, w in zip(chars, widths):
        x_centre = x + w / 2
        box(ax, x_centre, buffer_y, ch, "named" if ch in "45" else "memory",
            width=w, height=0.62, fontsize=16)
        centres.append(x_centre)
        x += w + 0.12
    note(ax, 0.3, buffer_y, "buffer:", color=NAVY)

    first = box(ax, centres[0], 0.75, "std::cin >> x;   x = 4", "object", width=3.4)
    second = box(ax, 7.6, 0.75, "std::cin >> y;   y = 5", "object", width=3.4)
    arrow(ax, (centres[0], buffer_y - 0.31), (centres[0], 0.75), None, first)
    arrow(ax, (centres[2], buffer_y - 0.31), (7.6, 0.75), None, second, bend=-0.15)

    note(ax, 8.15, 2.05, "the 5 is already waiting,", color=MUTED)
    note(ax, 8.15, 1.7, "so std::cin doesn't wait for you", color=MUTED)
    return fig


FIGURES = {
    "build_and_run.png": build_and_run_figure,
    "variables_memory.png": variables_memory_figure,
    "io_direction.png": io_direction_figure,
    "cin_buffer.png": cin_buffer_figure,
}

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--outdir", type=Path, default=FIGURE_DIR,
                        help=f"where to write the PNG files (default: {FIGURE_DIR})")
    render(FIGURES, parser.parse_args().outdir)
