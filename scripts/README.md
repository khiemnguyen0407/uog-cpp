# Figure scripts

Each lecture chapter that has figures gets one script here, named after the
chapter. It draws the figures with matplotlib's hand-drawn xkcd style and
writes the PNG files straight into the chapter's `figures/` folder.

```bash
python scripts/chap01_figures.py
python scripts/chap02_figures.py
```

Then re-render the chapter with Quarto. The `.qmd` files refer to the PNGs by
name, so regenerating a figure never requires editing a chapter.

`sketch.py` holds what the scripts share: the slide theme's colours, the box,
arrow and label helpers, and `render()`, which saves every figure.

For the full hand-written lettering, install the free "xkcd Script" font
(https://github.com/ipython/xkcd-font) and delete `~/.cache/matplotlib`.
Without it, matplotlib uses another hand-drawn font if one is installed; the
lines look hand-drawn either way.
