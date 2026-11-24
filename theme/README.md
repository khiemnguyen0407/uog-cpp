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

A chapter that is lecture notes only (HTML and PDF, no slides), like Chapter 17,
uses `metadata-files: [../../theme/notes.yml]` instead and lists only the
`html` and `pdf` formats.

## Section lecture notes

Each section's prose notes, such as
`sec-03-oop/lecture-notes/lecture_notes_03.qmd`, layer `section-notes.yml` on
top of `notes.yml`:

```yaml
metadata-files: [../../theme/notes.yml, ../../theme/section-notes.yml]
format:
  html:
    output-file: lecture_notes_03.html
    number-offset: [9]   # number the chapters 10-15, like the slides
  pdf:
    output-file: lecture_notes_03.pdf
```

`section-notes.yml` adapts the notes for long reading: a narrower text column
in the HTML; A4 pages, with each `# Heading` starting a new chapter, in the PDF;
and cross-references printed as "§12.3", because "Section" already means one of
the course's four sections.

The master file holds only the title block and one
`{{< include _XX-name.qmd >}}` per chapter. Each chapter file starts with
`# Title {#sec-chXX}` and includes its listings and figures from the chapter
folder (`../12-classes-more/cpp/...`). The PDF numbers its chapters with a raw
LaTeX block at the top of the master file, `\setcounter{chapter}{9}` for
Section 03, matching the HTML's `number-offset`. Sections 03 and 04 also put
`\sloppy` there, so that long inline code can't run into the margin.

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

Add `{.dense-code}` to a slide title (`## Title {.dense-code}`) to shrink its code a
little, for long listings.

Use `::: {.fragment}` rather than `. . .` for pauses: `. . .` shows up as
literal dots in the HTML and PDF notes.

`# Heading` starts a section: it gets its own navy slide with a big section
number. `## Heading` starts an ordinary slide.

## Files

- `lecture.yml`: shared Quarto options for all three formats.
- `notes.yml`: the same, for notes-only chapters (HTML and PDF).
- `section-notes.yml`: extra settings for the section lecture notes, layered
  on top of `notes.yml`.
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
