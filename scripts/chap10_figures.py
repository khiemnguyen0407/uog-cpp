"""Sketchy (hand-drawn style) figures for Chapter 10: Object-Oriented Programming.

Usage, from anywhere in the repo:

    python scripts/chap10_figures.py

This writes four PNG files into the chapter's figures folder:

    figures/four_pillars.png     the four pillars of OOP
    figures/encapsulation.png    private data behind a public interface
    figures/abstraction.png      what the user sees versus what is hidden
    figures/implicit_object.png  today.print(): the members of today are used

Re-render the chapter afterwards (quarto render chap_10.qmd).
Drawing helpers and fonts: see sketch.py.
"""

import argparse
from pathlib import Path

from matplotlib.patches import FancyBboxPatch

from sketch import (HEADER_EDGE, HEADER_FILL, MUTED, NAVY, REPO_ROOT, WHITE, arrow, box,
                    new_canvas, note, render, step_label)

FIGURE_DIR = REPO_ROOT / "sec-03-oop" / "10-intro-to-oop" / "figures"


def frame(ax, x0, y0, width, height, title, dashed=True):
    """A big rounded frame with a title in its top-left corner."""
    ax.add_patch(FancyBboxPatch(
        (x0, y0), width, height, boxstyle="round,pad=0.02,rounding_size=0.2",
        facecolor=HEADER_FILL, edgecolor=HEADER_EDGE, linestyle="--" if dashed else "-",
        linewidth=2))
    note(ax, x0 + 0.25, y0 + height - 0.3, title, color=NAVY, size=17)


def four_pillars_figure():
    """Encapsulation, abstraction, inheritance, polymorphism."""
    fig, ax = new_canvas(11, 3.6)
    pillars = [
        ("Encapsulation", "bundle data with its functions;", "protect it from misuse"),
        ("Abstraction", "show what it does,", "hide how it does it"),
        ("Inheritance", "build new classes from", "existing ones"),
        ("Polymorphism", "one interface,", "many behaviours"),
    ]
    roof = FancyBboxPatch((0.4, 2.85), 10.2, 0.5, boxstyle="round,pad=0.02,rounding_size=0.1",
                          facecolor=NAVY, edgecolor=NAVY, linewidth=2)
    ax.add_patch(roof)
    label = ax.text(5.5, 3.1, "Object-Oriented Programming", ha="center", va="center",
                    fontsize=18, color=WHITE)
    label.set_path_effects([])
    for i, (name, line1, line2) in enumerate(pillars):
        x = 1.6 + i * 2.6
        box(ax, x, 1.75, name, "named", width=2.3, height=1.7, fontsize=16)
        step_label(ax, x, 0.35, line1)
        step_label(ax, x, 0.05, line2)
    ax.set_ylim(-0.2, 3.6)
    return fig


def encapsulation_figure():
    """A BankAccount: private balance, public deposit() and withdraw()."""
    fig, ax = new_canvas(11, 3.9)
    frame(ax, 3.6, 0.3, 7.0, 3.2, "a BankAccount object")
    private = box(ax, 8.7, 1.8, "private:\nbalance", "memory", width=2.2, height=1.1,
                  fontsize=16)
    deposit = box(ax, 5.3, 2.4, "deposit()", "named", width=2.2, height=0.6, fontsize=15)
    withdraw = box(ax, 5.3, 1.2, "withdraw()", "named", width=2.2, height=0.6, fontsize=15)
    arrow(ax, (5.3, 2.4), (8.7, 1.8), deposit, private)
    arrow(ax, (5.3, 1.2), (8.7, 1.8), withdraw, private)
    step_label(ax, 5.3, 0.7, "public: checks every request")

    you = box(ax, 1.3, 1.8, "your code", "object", width=1.9, height=0.7, fontsize=16)
    arrow(ax, (1.3, 1.8), (5.3, 2.4), you, deposit)
    arrow(ax, (1.3, 1.8), (5.3, 1.2), you, withdraw)
    note(ax, 1.3, 0.5, "balance = -1000000;", ha="center", color=MUTED, size=14)
    note(ax, 1.3, 0.15, "won't compile: it's private", ha="center", color=MUTED, size=14)
    return fig


def abstraction_figure():
    """A coffee machine: buttons outside, machinery inside."""
    fig, ax = new_canvas(11, 3.8)
    frame(ax, 0.4, 0.3, 4.4, 3.1, "what you see: the interface", dashed=False)
    for i, label in enumerate(["espresso", "latte", "hot water"]):
        box(ax, 2.6, 2.45 - i * 0.75, label, "named", width=2.4, height=0.55,
            fontsize=15)

    frame(ax, 5.8, 0.3, 4.8, 3.1, "what's hidden: the implementation")
    for i, label in enumerate(["grind 18 g of beans", "heat water to 93 C",
                               "pump at 9 bar for 25 s"]):
        box(ax, 8.2, 2.45 - i * 0.75, label, "memory", width=3.8, height=0.55,
            fontsize=14)
    note(ax, 5.3, 0.1, "change the machinery, and the buttons stay the same",
         ha="center", color=MUTED, size=14)
    ax.set_ylim(-0.1, 3.8)
    return fig


def implicit_object_figure():
    """today.print(): inside print(), year means today.year."""
    fig, ax = new_canvas(11, 3.4)
    note(ax, 5.5, 3.15, "today.print();", ha="center", color=NAVY, size=20)
    frame(ax, 0.4, 0.3, 4.3, 2.4, "the object today", dashed=False)
    for i, (name, value) in enumerate([("year", "2026"), ("month", "2"), ("day", "26")]):
        box(ax, 2.55, 1.85 - i * 0.6, f"{name}: {value}", "named", width=2.6, height=0.5,
            fontsize=15)

    func = box(ax, 8.6, 1.4, "void print() {\n  ... year ... month ... day ...\n}",
               "source", width=4.0, height=1.3, fontsize=14)
    arrow(ax, (8.6, 1.4), (4.75, 1.4), func, None)
    step_label(ax, 5.65, 2.0, "year means")
    step_label(ax, 5.65, 1.7, "today.year")
    note(ax, 8.6, 0.3, "the implicit object: the one print() was called on", ha="center",
         color=MUTED, size=14)
    return fig


FIGURES = {
    "four_pillars.png": four_pillars_figure,
    "encapsulation.png": encapsulation_figure,
    "abstraction.png": abstraction_figure,
    "implicit_object.png": implicit_object_figure,
}

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--outdir", type=Path, default=FIGURE_DIR,
                        help=f"where to write the PNG files (default: {FIGURE_DIR})")
    render(FIGURES, parser.parse_args().outdir)
