"""Sketchy (hand-drawn style) figures for Chapter 16: Object Relationships.

Usage, from anywhere in the repo:

    python scripts/chap16_figures.py

This writes four PNG files into the chapter's figures folder:

    figures/relationships_overview.png  the four relationships, strongest first
    figures/composition_lifetime.png    a part lives and dies with its whole
    figures/aggregation_shared.png      a part can be shared, and outlives the whole
    figures/association_many.png        doctors and patients: many-to-many

Re-render the chapter afterwards (quarto render chap_16.qmd).
Drawing helpers and fonts: see sketch.py.
"""

import argparse
from pathlib import Path

from matplotlib.patches import Polygon

from sketch import MUTED, NAVY, REPO_ROOT, WHITE, arrow, box, new_canvas, note, render

FIGURE_DIR = REPO_ROOT / "sec-04-uml-class" / "16-object-relationships" / "figures"


def diamond(ax, x, y, filled, size=0.17):
    """A UML diamond centred on (x, y): filled for composition, hollow for aggregation."""
    ax.add_patch(Polygon([(x - size * 1.6, y), (x, y + size), (x + size * 1.6, y),
                          (x, y - size)], closed=True, facecolor=NAVY if filled else WHITE,
                         edgecolor=NAVY, linewidth=2.2, zorder=5))


def line(ax, x1, x2, y, dashed=False):
    ax.plot([x1, x2], [y, y], color=NAVY, linewidth=2.2, linestyle="--" if dashed else "-")


def relationships_overview_figure():
    """Composition, aggregation, association, dependency: strongest to weakest."""
    fig, ax = new_canvas(11, 4.6)
    rows = [
        ("composition", "Body", "Heart", "part-of: the whole owns its parts", "filled"),
        ("aggregation", "Person", "Address", "has-a: shared, not owned", "hollow"),
        ("association", "Doctor", "Patient", "uses-a: otherwise unrelated", "plain"),
        ("dependency", "Point", "std::ostream", "depends-on: used for a moment", "dashed"),
    ]
    for i, (kind, left, right, words, style) in enumerate(rows):
        y = 3.95 - i * 1.05
        note(ax, 0.2, y, kind, color=NAVY, size=16)
        box(ax, 3.1, y, left, "named", width=1.6, height=0.6, fontsize=15)
        box(ax, 6.0, y, right, "source", width=1.9, height=0.6, fontsize=15)
        if style == "dashed":
            line(ax, 3.9, 4.95, y, dashed=True)
            arrow(ax, (4.85, y), (5.0, y))
        else:
            line(ax, 3.9, 5.05, y)
            if style in ("filled", "hollow"):
                diamond(ax, 4.17, y, filled=(style == "filled"))
        note(ax, 7.2, y, words, color=MUTED, size=14)
    ax.annotate("", xy=(10.75, 0.55), xytext=(10.75, 4.2),
                arrowprops=dict(arrowstyle="-|>", color=MUTED, lw=2))
    note(ax, 10.6, 4.4, "stronger", ha="right", color=MUTED, size=13)
    note(ax, 10.6, 0.35, "weaker", ha="right", color=MUTED, size=13)
    return fig


def lifeline(ax, y, start, end, label, kind="named"):
    ax.plot([start, end], [y, y], color=NAVY if kind == "named" else MUTED, linewidth=7,
            solid_capstyle="round")
    note(ax, start - 0.2, y, label, ha="right", color=NAVY, size=15)


def composition_lifetime_figure():
    """A Body and its Heart are created and destroyed together."""
    fig, ax = new_canvas(11, 2.8)
    note(ax, 0.3, 2.5, "time ->", color=MUTED, size=15)
    lifeline(ax, 1.75, 2.4, 9.6, "Body")
    lifeline(ax, 0.95, 2.4, 9.6, "Heart")
    note(ax, 2.4, 0.35, "created together", ha="center", color=MUTED, size=14)
    note(ax, 9.6, 0.35, "destroyed together", ha="center", color=MUTED, size=14)
    note(ax, 6.0, 2.35, "composition: the part's lifetime is managed by the whole",
         ha="center", color=NAVY, size=15)
    return fig


def aggregation_shared_figure():
    """Two people share one address, which outlives them both."""
    fig, ax = new_canvas(11, 3.4)
    a = box(ax, 1.6, 2.5, "Person: Ann", "named", width=2.4, height=0.6, fontsize=15)
    b = box(ax, 1.6, 1.0, "Person: Bob", "named", width=2.4, height=0.6, fontsize=15)
    address = box(ax, 6.2, 1.75, "Address:\n10 Kelvin Way", "source", width=2.8, height=0.95,
                  fontsize=15)
    for patch, y in ((a, 2.5), (b, 1.0)):
        arrow(ax, (1.6, y), (6.2, 1.75), patch, address)
        diamond(ax, 3.12, y, filled=False)
    note(ax, 8.0, 2.4, "shared by both,", color=MUTED, size=14)
    note(ax, 8.0, 2.05, "owned by neither:", color=MUTED, size=14)
    note(ax, 8.0, 1.45, "it existed before they", color=MUTED, size=14)
    note(ax, 8.0, 1.1, "moved in, and stays after", color=MUTED, size=14)
    note(ax, 8.0, 0.75, "they move out", color=MUTED, size=14)
    return fig


def association_many_figure():
    """Doctors and patients: many-to-many, neither owns the other."""
    fig, ax = new_canvas(11, 3.4)
    james = box(ax, 2.0, 2.4, "Doctor James", "named", width=2.6, height=0.6, fontsize=15)
    sarah = box(ax, 2.0, 1.0, "Doctor Sarah", "named", width=2.6, height=0.6, fontsize=15)
    dave = box(ax, 7.0, 2.4, "Patient Dave", "source", width=2.6, height=0.6, fontsize=15)
    betsy = box(ax, 7.0, 1.0, "Patient Betsy", "source", width=2.6, height=0.6, fontsize=15)
    for (p1, xy1), (p2, xy2) in [((james, (2.0, 2.4)), (dave, (7.0, 2.4))),
                                 ((sarah, (2.0, 1.0)), (dave, (7.0, 2.4))),
                                 ((sarah, (2.0, 1.0)), (betsy, (7.0, 1.0)))]:
        ax.plot([xy1[0] + 1.3, xy2[0] - 1.3],
                [xy1[1] + (xy2[1] - xy1[1]) * 0.0, xy2[1]], color=NAVY, linewidth=2.2)
    note(ax, 5.5, 3.15, "each knows about the other (bidirectional)", ha="center",
         color=NAVY, size=15)
    note(ax, 5.5, 0.25, "many-to-many; neither owns the other; both exist on their own",
         ha="center", color=MUTED, size=14)
    return fig


FIGURES = {
    "relationships_overview.png": relationships_overview_figure,
    "composition_lifetime.png": composition_lifetime_figure,
    "aggregation_shared.png": aggregation_shared_figure,
    "association_many.png": association_many_figure,
}

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--outdir", type=Path, default=FIGURE_DIR,
                        help=f"where to write the PNG files (default: {FIGURE_DIR})")
    render(FIGURES, parser.parse_args().outdir)
