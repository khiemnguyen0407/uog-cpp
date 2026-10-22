"""Shared helpers for the sketchy (matplotlib xkcd-style) lecture figures.

Each chapter has its own script (chap01_figures.py, chap02_figures.py, ...)
that imports this module, draws its figures and calls render().

For the full hand-written look, install the "xkcd Script" font
(https://github.com/ipython/xkcd-font) and delete ~/.cache/matplotlib so
matplotlib finds it. Without it, matplotlib falls back to Humor Sans,
Comic Neue or Comic Sans MS; the lines still look hand-drawn.
"""

from __future__ import annotations

import logging
from pathlib import Path

import matplotlib

matplotlib.use("Agg")  # no window needed, just files

import matplotlib.pyplot as plt  # noqa: E402
from matplotlib.patches import Circle, FancyArrowPatch, FancyBboxPatch  # noqa: E402

# Matplotlib tries several hand-written fonts in turn and complains about each
# one that isn't installed. That's expected, so keep it quiet.
logging.getLogger("matplotlib.font_manager").setLevel(logging.ERROR)

REPO_ROOT = Path(__file__).resolve().parents[1]

DPI = 200  # 11-inch-wide figures -> 2200 px, sharp on any projector

# Colours from the slide theme (theme/eng3091-slides.scss)
INK = "#1b2a41"
NAVY = "#12355b"
MUTED = "#586579"
SOURCE_FILL = "#f3f5f8"
SOURCE_EDGE = "#8792a2"
HEADER_FILL = "#eef4fb"
HEADER_EDGE = "#5b8cc4"
TERMINAL = "#14233a"
TERMINAL_INK = "#e6edf5"
HIGHLIGHT = "#fff1c2"
WHITE = "#ffffff"

# How every kind of box looks: (fill, edge colour, line style, text colour)
BOX_STYLES = {
    "source": (SOURCE_FILL, SOURCE_EDGE, "-", NAVY),   # .cpp files
    "header": (HEADER_FILL, HEADER_EDGE, "--", NAVY),  # .h files
    "object": (WHITE, MUTED, "-", INK),                # .o files, plain boxes
    "library": (WHITE, MUTED, ":", MUTED),             # standard library
    "program": (NAVY, NAVY, "-", WHITE),               # a compiled program
    "terminal": (TERMINAL, TERMINAL, "-", TERMINAL_INK),  # what the user sees
    "memory": (WHITE, MUTED, "-", MUTED),              # an anonymous memory cell
    "named": (HIGHLIGHT, NAVY, "-", NAVY),             # a memory cell with a name
}

BOX_W, BOX_H = 1.7, 0.56  # default box size in inches
FONT_SIZE = 17


def new_canvas(width: float, height: float):
    """A blank figure whose data units are inches, with (0, 0) bottom left."""
    fig = plt.figure(figsize=(width, height))
    ax = fig.add_axes((0, 0, 1, 1))
    ax.set_xlim(0, width)
    ax.set_ylim(0, height)
    ax.set_aspect("equal")
    ax.axis("off")
    return fig, ax


def box(ax, x, y, text, kind="source", width=BOX_W, height=BOX_H, fontsize=FONT_SIZE):
    """Draw a labelled, rounded box centred on (x, y) and return its patch."""
    fill, edge, style, text_colour = BOX_STYLES[kind]
    patch = FancyBboxPatch(
        (x - width / 2, y - height / 2), width, height,
        boxstyle="round,pad=0.02,rounding_size=0.12",
        facecolor=fill, edgecolor=edge, linestyle=style, linewidth=2.2,
    )
    ax.add_patch(patch)
    label = ax.text(x, y, text, ha="center", va="center", fontsize=fontsize,
                    color=text_colour)
    if text_colour in (WHITE, TERMINAL_INK):
        # xkcd mode outlines everything in white; on light text that turns
        # the letters into blobs, so switch the outline off here.
        label.set_path_effects([])
    return patch


def circle_node(ax, x, y, text, radius=0.45):
    """Draw a labelled circle (e.g. 'link') and return its patch."""
    patch = Circle((x, y), radius, facecolor=WHITE, edgecolor=NAVY, linewidth=2.4)
    ax.add_patch(patch)
    ax.text(x, y, text, ha="center", va="center", fontsize=FONT_SIZE, color=NAVY)
    return patch


def arrow(ax, start, end, patch_a=None, patch_b=None, dashed=False, bend=0.0,
          color=NAVY):
    """Draw an arrow from start to end, clipped at the edges of the patches.

    bend > 0 curves the arrow to the right of its direction of travel.
    """
    ax.add_patch(FancyArrowPatch(
        start, end, patchA=patch_a, patchB=patch_b,
        shrinkA=4, shrinkB=4,
        arrowstyle="-|>", mutation_scale=22,
        connectionstyle=f"arc3,rad={bend}",
        color=color, linewidth=2.2, linestyle="--" if dashed else "-",
    ))


def step_label(ax, x, y, text):
    """A small label naming a step, e.g. 'compile'."""
    ax.text(x, y, text, ha="center", va="center", fontsize=FONT_SIZE - 3, color=MUTED)


def note(ax, x, y, text, ha="left", color=MUTED, size=FONT_SIZE - 2):
    """A hand-written remark."""
    ax.text(x, y, text, ha=ha, va="center", fontsize=size, color=color)


def render(figures: dict, outdir: Path):
    """Draw every figure in {file name: function} and save it as PNG."""
    outdir.mkdir(parents=True, exist_ok=True)
    with plt.xkcd(scale=1.2, length=90, randomness=2):
        for name, make in figures.items():
            fig = make()
            path = outdir / name
            fig.savefig(path, dpi=DPI, facecolor="white")
            plt.close(fig)
            shown = path.relative_to(REPO_ROOT) if path.is_relative_to(REPO_ROOT) else path
            print(f"wrote {shown}")
