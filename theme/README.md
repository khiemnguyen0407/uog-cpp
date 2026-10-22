# ENG3091 lecture theme

Shared look and settings for every lecture chapter: reveal.js slides, HTML
notes and PDF notes.

## Using it in a chapter

Put this in the chapter's YAML header (the chapter folder must sit two levels
below the repo root, like `sec-01-cpp-basics/02-functions-and-files/`):

```yaml
---
title: "Chapter 02: Functions and Files"
subtitle: "ENG3091"
author:
  - name: Khiem Nguyen
    email: khiem.nguyen@glasgow.ac.uk
    affiliations: University of Glasgow
metadata-files: [../../theme/lecture.yml]
format:
  html:
    output-file: chap_02.html
  pdf:
    output-file: chap_02.pdf
  revealjs:
    output-file: chap_02_slide.html
---
```

The chapter no longer needs its own `doc.css` or `slide.css`.

## Conventions

| You write | You get |
|---|---|
| ```` ```{.cpp filename="add.cpp"} ```` | Source code in a light editor pane with a filename tab |
| ```` ```{.cpp filename="bad.cpp" .no-compile} ```` | Red tab saying "does not compile" (also works without `filename`) |
| ```` ```{.text .terminal} ```` | Dark terminal pane for commands and their output (`$ g++ ...`) |
| ```` ```{.text .output} ```` | Dark pane labelled "Output" for program output |
| ```` ```{.text .output .compiler} ```` | Dark pane labelled "Compiler says" for error messages |
| `::: {.callout-note title="Coming from Python"}` | Blue box |
| `::: {.callout-important title="Key idea"}` | Navy box |
| `::: {.callout-tip title="Best practice"}` | Green box |
| `::: {.callout-warning title="Watch out"}` | Amber box |
| `::: {.fragment}` ... `:::` | Appears on the next click (ignored in HTML/PDF notes) |

Use `::: {.fragment}` rather than `. . .` for pauses: `. . .` shows up as
literal dots in the HTML and PDF notes.

`# Heading` starts a section: it gets its own navy slide with a big section
number. `## Heading` starts an ordinary slide.

## Files

- `lecture.yml`: shared Quarto options for all three formats.
- `eng3091-slides.scss`: the slide theme (palette, type, code panes, callouts).
- `slides.html`: paints the title slide and section slides navy.
- `notes.css`: small additions for the HTML notes.
- `eng3091.theme`: syntax colours, tuned for projectors; used by all formats.
- `eng3091.lua`: keeps line numbers off output and terminal panes.
- `fonts.css`, `fonts/`: Atkinson Hyperlegible Next and Mono, stored locally
  so slides work offline (SIL Open Font License, see `fonts/OFL.txt`).

## Layout tips

At this slide size, a full-width code pane fits about 90 characters per line.
Next to an output pane (`::: {.columns}`), keep lines under about 55
characters, or the code will wrap.
