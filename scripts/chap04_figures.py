"""Sketchy (hand-drawn style) figures for Chapter 04: Constants and Strings.

Usage, from anywhere in the repo:

    python scripts/chap04_figures.py

This writes two PNG files into the chapter's figures folder:

    figures/string_chars.png     a std::string is a row of characters
    figures/cin_vs_getline.png   >> stops at a space; std::getline reads the line

Re-render the chapter afterwards (quarto render chap_04.qmd).
Drawing helpers and fonts: see sketch.py.
"""

import argparse
from pathlib import Path

from sketch import MUTED, NAVY, REPO_ROOT, arrow, box, new_canvas, note, render, step_label

FIGURE_DIR = REPO_ROOT / "sec-01-cpp-basics" / "04-constants-and-strings" / "figures"


def string_chars_figure():
    """std::string name{"Khiem"}: five characters, numbered from 0."""
    fig, ax = new_canvas(11, 2.9)
    y, size, left = 1.45, 1.0, 3.0

    note(ax, 0.3, y, "name", color=NAVY, size=19)
    for i, ch in enumerate("Khiem"):
        x = left + i * (size + 0.12)
        box(ax, x, y, ch, "named", width=size, height=size, fontsize=22)
        step_label(ax, x, y - 0.8, f"name[{i}]")

    last = left + 4 * (size + 0.12)
    note(ax, 1.25, y, "=", color=NAVY, size=22)
    note(ax, last + 0.9, y + 0.25, "name.length() is 5", color=MUTED)
    note(ax, last + 0.9, y - 0.25, "the first index is 0", color=MUTED)
    note(ax, 5.5, 2.65, 'std::string name{"Khiem"};', ha="center", color=NAVY, size=17)
    return fig


def cin_vs_getline_figure():
    """The same typed line, read two different ways."""
    fig, ax = new_canvas(11, 4.4)
    chunks = [("Khiem", 1.4), ("space", 1.2), ("Nguyen", 1.6), ("Enter", 1.2)]

    def buffer_row(y, taken, title, result):
        note(ax, 0.2, y + 0.75, title, color=NAVY)
        x = 0.5
        patches = []
        for (text, width), take in zip(chunks, taken):
            patches.append(box(ax, x + width / 2, y, text, "named" if take else "memory",
                               width=width, height=0.6, fontsize=15))
            x += width + 0.1
        out = box(ax, 9.3, y, result, "object", width=2.9, height=0.6, fontsize=15)
        arrow(ax, (x - 0.1, y), (9.3, y), None, out)
        return patches

    buffer_row(3.0, [True, False, False, False], "std::cin >> name;",
               'name is "Khiem"')
    note(ax, 3.4, 2.25, "stops at the space; the rest waits in the buffer", color=MUTED)

    buffer_row(1.0, [True, True, True, False], "std::getline(std::cin, name);",
               'name is "Khiem Nguyen"')
    note(ax, 3.4, 0.25, "reads up to the Enter (and throws the Enter away)", color=MUTED)
    return fig


FIGURES = {
    "string_chars.png": string_chars_figure,
    "cin_vs_getline.png": cin_vs_getline_figure,
}

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--outdir", type=Path, default=FIGURE_DIR,
                        help=f"where to write the PNG files (default: {FIGURE_DIR})")
    render(FIGURES, parser.parse_args().outdir)
