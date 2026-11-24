"""Sketchy (hand-drawn style) figures for Chapter 14: Inheritance.

Usage, from anywhere in the repo:

    python scripts/chap14_figures.py

This writes five PNG files into the chapter's figures folder:

    figures/uni_hierarchy.png        the university's people, as a hierarchy
    figures/uniperson_classes.png    UniPerson, Lecturer and Student
    figures/derived_object_parts.png a Derived object = a Base part + a Derived part
    figures/construction_chain.png   construction and destruction order in a chain
    figures/smartphone.png           multiple inheritance

They replace the Mermaid diagrams, which need a browser to render in PDFs.
Re-render the chapter afterwards (quarto render chap_14.qmd).
Drawing helpers and fonts: see sketch.py.
"""

import argparse
from pathlib import Path

from matplotlib.patches import FancyBboxPatch

from sketch import (HEADER_EDGE, HEADER_FILL, MUTED, NAVY, REPO_ROOT, arrow, box,
                    new_canvas, note, render, step_label)

FIGURE_DIR = REPO_ROOT / "sec-03-oop" / "14-inheritance" / "figures"


def up(ax, child, parent, child_xy, parent_xy):
    """An inheritance arrow, pointing from the derived class to its base."""
    arrow(ax, child_xy, parent_xy, child, parent)


def uni_hierarchy_figure():
    fig, ax = new_canvas(11, 4.4)
    person = box(ax, 5.5, 3.85, "UniPerson", "program", width=2.4, height=0.6, fontsize=17)
    staff = box(ax, 2.9, 2.45, "StaffMember", "named", width=2.4, height=0.6, fontsize=16)
    student = box(ax, 8.3, 2.45, "Student", "named", width=2.0, height=0.6, fontsize=16)
    up(ax, staff, person, (2.9, 2.45), (5.5, 3.85))
    up(ax, student, person, (8.3, 2.45), (5.5, 3.85))
    for x, name in zip([0.75, 2.2, 3.65, 5.1], ["Lecturer", "TOMember", "Demonstrator",
                                                 "SecurityGuard"]):
        b = box(ax, x, 0.9, name, "source", width=1.35, height=0.55, fontsize=12)
        up(ax, b, staff, (x, 0.9), (2.9, 2.45))
    for x, name in zip([6.9, 8.3, 9.7], ["UGStudent", "PGTStudent", "PGRStudent"]):
        b = box(ax, x, 0.9, name, "source", width=1.3, height=0.55, fontsize=12)
        up(ax, b, student, (x, 0.9), (8.3, 2.45))
    note(ax, 0.2, 3.85, "arrows point to the base class:", color=MUTED, size=13)
    note(ax, 0.2, 3.5, '"is a"', color=MUTED, size=13)
    return fig


def uniperson_classes_figure():
    fig, ax = new_canvas(11, 4.0)
    person = box(ax, 5.5, 3.0, "UniPerson\nname, id, age\nget_name(), get_age(), get_id()",
                 "program", width=4.6, height=1.3, fontsize=15)
    lecturer = box(ax, 2.5, 0.85, "Lecturer\nsalary\nget_salary()", "named", width=2.8,
                   height=1.2, fontsize=15)
    student = box(ax, 8.5, 0.85, "Student\ntuition\nget_tuition()", "named", width=2.8,
                  height=1.2, fontsize=15)
    up(ax, lecturer, person, (2.5, 0.85), (5.5, 3.0))
    up(ax, student, person, (8.5, 0.85), (5.5, 3.0))
    note(ax, 5.5, 0.85, "each derived class adds\nonly what's new", ha="center",
         color=MUTED, size=14)
    return fig


def derived_object_parts_figure():
    fig, ax = new_canvas(11, 3.6)
    note(ax, 3.0, 3.35, "Derived derived{4.2, 42};", ha="center", color=NAVY, size=18)
    ax.add_patch(FancyBboxPatch((0.6, 0.4), 4.8, 2.5,
                                boxstyle="round,pad=0.02,rounding_size=0.2",
                                facecolor=HEADER_FILL, edgecolor=HEADER_EDGE,
                                linestyle="--", linewidth=2))
    note(ax, 0.85, 2.6, "a Derived object", color=NAVY, size=15)
    base = box(ax, 3.0, 1.8, "Base part: id", "named", width=3.8, height=0.6, fontsize=16)
    derived = box(ax, 3.0, 1.0, "Derived part: value", "source", width=3.8, height=0.6,
                  fontsize=16)
    note(ax, 6.2, 2.4, "construction: Base part first,", color=MUTED, size=15)
    note(ax, 6.2, 2.05, "then the Derived part", color=MUTED, size=15)
    note(ax, 6.2, 1.35, "destruction: the reverse,", color=MUTED, size=15)
    note(ax, 6.2, 1.0, "Derived part first", color=MUTED, size=15)
    arrow(ax, (5.95, 2.2), (5.95, 1.2), None, None)
    return fig


def construction_chain_figure():
    fig, ax = new_canvas(11, 3.2)
    xs = [1.4, 4.1, 6.8, 9.5]
    patches = []
    for x, name in zip(xs, "ABCD"):
        patches.append(box(ax, x, 1.6, name, "named", width=1.3, height=0.7, fontsize=20))
    for i in range(3):
        up(ax, patches[i + 1], patches[i], (xs[i + 1], 1.6), (xs[i], 1.6))
    note(ax, 5.45, 2.85, "D d{};   constructs A, then B, then C, then D", ha="center",
         color=NAVY, size=16)
    note(ax, 5.45, 0.4, "at the end of its block: destroys D, then C, then B, then A",
         ha="center", color=MUTED, size=15)
    step_label(ax, 2.75, 1.95, "derives from")
    return fig


def smartphone_figure():
    fig, ax = new_canvas(11, 3.2)
    camera = box(ax, 3.0, 2.4, "Camera\ntake_photo()", "program", width=2.8, height=0.95,
                 fontsize=15)
    phone = box(ax, 8.0, 2.4, "Phone\nmake_call()", "program", width=2.8, height=0.95,
                fontsize=15)
    smart = box(ax, 5.5, 0.7, "SmartPhone\nuse_app()", "named", width=2.8, height=0.95,
                fontsize=15)
    up(ax, smart, camera, (5.5, 0.7), (3.0, 2.4))
    up(ax, smart, phone, (5.5, 0.7), (8.0, 2.4))
    note(ax, 8.1, 0.7, "inherits from both", color=MUTED, size=14)
    return fig


FIGURES = {
    "uni_hierarchy.png": uni_hierarchy_figure,
    "uniperson_classes.png": uniperson_classes_figure,
    "derived_object_parts.png": derived_object_parts_figure,
    "construction_chain.png": construction_chain_figure,
    "smartphone.png": smartphone_figure,
}

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--outdir", type=Path, default=FIGURE_DIR,
                        help=f"where to write the PNG files (default: {FIGURE_DIR})")
    render(FIGURES, parser.parse_args().outdir)
