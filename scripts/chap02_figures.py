"""Sketchy (hand-drawn style) figures for Chapter 02: Functions and Files.

Usage, from anywhere in the repo:

    python scripts/chap02_figures.py

This writes two PNG files into the chapter's figures folder, replacing the
ones the slides use, so chap_02.qmd needs no changes:

    figures/compile_link.png
    figures/include_compile_link.png

Re-render the chapter afterwards (quarto render chap_02.qmd).
Drawing helpers and fonts: see sketch.py.
"""

import argparse
from pathlib import Path

from sketch import REPO_ROOT, arrow, box, circle_node, new_canvas, note, render, step_label

FIGURE_DIR = REPO_ROOT / "sec-01-cpp-basics" / "02-functions-and-files" / "figures"


def compile_link_figure():
    """Each .cpp file is compiled on its own, then the pieces are linked."""
    fig, ax = new_canvas(11, 3.4)

    top, bottom, middle = 2.45, 1.05, 1.75

    main_cpp = box(ax, 1.15, top, "main.cpp")
    add_cpp = box(ax, 1.15, bottom, "add.cpp")
    main_o = box(ax, 4.55, top, "main.o", "object", width=1.5)
    add_o = box(ax, 4.55, bottom, "add.o", "object", width=1.5)

    for src, obj, y in ((main_cpp, main_o, top), (add_cpp, add_o, bottom)):
        arrow(ax, (1.15, y), (4.55, y), src, obj)
        step_label(ax, 2.85, y + 0.32, "compile")

    link = circle_node(ax, 7.0, middle, "link")
    arrow(ax, (4.55, top), (7.0, middle), main_o, link)
    arrow(ax, (4.55, bottom), (7.0, middle), add_o, link)

    library = box(ax, 7.0, 0.38, "std library", "library", width=2.1, height=0.5)
    arrow(ax, (7.0, 0.38), (7.0, middle), library, link)

    program = box(ax, 9.75, middle, "program", "program")
    arrow(ax, (7.0, middle), (9.75, middle), link, program)

    note(ax, 0.3, 3.15, "Each .cpp file is compiled on its own ...")
    note(ax, 10.6, 3.15, "... then the linker joins the pieces.", ha="right")
    return fig


def include_compile_link_figure():
    """Headers are pasted in, each .cpp is compiled, then everything is linked."""
    fig, ax = new_canvas(11, 4.5)

    header_y, source_y, object_y = 3.95, 2.55, 1.2

    iostream = box(ax, 1.15, header_y, "<iostream>", "header", width=1.9)
    add_h = box(ax, 3.4, header_y, "add.h", "header", width=1.4)
    note(ax, 4.5, header_y, "#include pastes the header text into each .cpp")

    main_cpp = box(ax, 1.15, source_y, "main.cpp")
    add_cpp = box(ax, 4.3, source_y, "add.cpp")

    arrow(ax, (1.15, header_y), (1.15, source_y), iostream, main_cpp, dashed=True)
    arrow(ax, (3.4, header_y), (1.15, source_y), add_h, main_cpp, dashed=True)
    arrow(ax, (3.4, header_y), (4.3, source_y), add_h, add_cpp, dashed=True)

    main_o = box(ax, 1.15, object_y, "main.o", "object", width=1.5)
    add_o = box(ax, 4.3, object_y, "add.o", "object", width=1.5)
    for x, src, obj in ((1.15, main_cpp, main_o), (4.3, add_cpp, add_o)):
        arrow(ax, (x, source_y), (x, object_y), src, obj)
        step_label(ax, x + 0.55, (source_y + object_y) / 2, "compile")

    link = circle_node(ax, 7.2, object_y, "link")
    arrow(ax, (1.15, object_y), (7.2, object_y), main_o, link, bend=0.2)
    arrow(ax, (4.3, object_y), (7.2, object_y), add_o, link)

    library = box(ax, 7.2, source_y, "std library", "library", width=2.1, height=0.5)
    arrow(ax, (7.2, source_y), (7.2, object_y), library, link)

    program = box(ax, 9.75, object_y, "program", "program")
    arrow(ax, (7.2, object_y), (9.75, object_y), link, program)
    return fig


FIGURES = {
    "compile_link.png": compile_link_figure,
    "include_compile_link.png": include_compile_link_figure,
}

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--outdir", type=Path, default=FIGURE_DIR,
                        help=f"where to write the PNG files (default: {FIGURE_DIR})")
    render(FIGURES, parser.parse_args().outdir)
