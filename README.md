# uog-cpp

**Learn C++ at the University of Glasgow**

Course materials for **ENG3091 Advanced Programming & Software Engineering 3**: C++ programming, object-oriented programming and UML class diagrams, in 18 chapters (00–17). Every chapter has lecture notes as a web page and a PDF, a slide deck, and every C++ example shown in the lectures. Each of the four sections also has its own prose lecture notes, written to be read on their own. The assignments and a mock exam are here too.

The materials draw heavily on [learncpp.com](https://www.learncpp.com), an excellent free tutorial. They don't reproduce the website as a book: they select, reorder and adapt its topics for this course.

## Getting started

**Get the materials.** Clone the repository, or click **Code → Download ZIP** on GitHub:

```bash
git clone https://github.com/khiemnguyen0407/uog-cpp.git
```

If you cloned it, run `git pull` inside the `uog-cpp` folder to get new and updated chapters during the semester.

**Read the notes and slides.** Open any `.html` file in a web browser. Each one is self-contained (images, fonts and styles are built in), so it works offline. GitHub can't display these pages, and shows their source code instead, so download them first. PDFs do open directly on GitHub: every chapter below links to its PDF.

In the slides, use the arrow keys to move, `F` for full screen and `Esc` for an overview of all the slides.

**Set up a compiler.** Chapter 00 comes with an installation guide, `sec-01-cpp-basics/00-intro-to-eng3091/installation.html`, covering Visual Studio and Visual Studio Code. The course uses C++20. From a terminal, compile and run an example with:

```bash
g++ -std=c++20 -Wall -Wextra example.cpp -o example
./example
```

Some examples **fail to compile on purpose**, to show you a compiler error. The notes and slides label them "does not compile". See [Compiling the examples](#compiling-the-examples) for programs with several files.

## Course contents

The chapters are grouped into four sections, one folder each:

| Section | Folder | Chapters |
|:---|:---|:---|
| 01: C++ Basics | [`sec-01-cpp-basics`](sec-01-cpp-basics) | 00–04 |
| 02: C++ Intermediate | [`sec-02-cpp-intermediate`](sec-02-cpp-intermediate) | 05–09 |
| 03: Object-Oriented Programming | [`sec-03-oop`](sec-03-oop) | 10–15 |
| 04: UML Class Diagrams | [`sec-04-uml-class`](sec-04-uml-class) | 16–17 |

Chapters are numbered continuously across sections: Section 02 starts where Section 01 ends, and so on.

### Lecture notes for each section

Each section folder has a `lecture-notes/` folder with one document for the whole section, as a web page and a PDF. The slides are made for the lecture; these notes are made for reading afterwards. They cover the same topics in the same order, with the same examples, explained in full sentences, with the programs' output and the compiler's error messages, and with comparisons to Python. Most chapters end with a summary and further reading.

| Section | Lecture notes | Pages |
|:---|:---|---:|
| 01: C++ Basics | [`lecture_notes_01.pdf`](sec-01-cpp-basics/lecture-notes/lecture_notes_01.pdf) | 42 |
| 02: C++ Intermediate | [`lecture_notes_02.pdf`](sec-02-cpp-intermediate/lecture-notes/lecture_notes_02.pdf) | 39 |
| 03: Object-Oriented Programming | [`lecture_notes_03.pdf`](sec-03-oop/lecture-notes/lecture_notes_03.pdf) | 68 |
| 04: UML Class Diagrams | [`lecture_notes_04.pdf`](sec-04-uml-class/lecture-notes/lecture_notes_04.pdf) | 28 |

The `.html` file next to each PDF is the same document as a web page; download it first, as with the chapters. Chapter 17 has no slides, so Section 04's notes include its chapter notes as they are.

**Why separate "basics" and "intermediate"?** Both are foundational C++, and could be one section. They're split for two reasons. It makes the course easier to follow, and lets the Moodle page mirror this repository. And Section 02 is where C++ stops looking like the Python you learned in Year 2: it covers what Python hides from you, namely value categories (lvalues and rvalues), references, pointers, and the difference between passing by value, by reference and by address. (Python only has something that *feels* similar: passing an immutable object behaves a bit like pass by value, and passing a mutable object a bit like pass by reference.)

### Section 01: C++ Basics

- **Chapter 00: Introduction to ENG3091** ([`00-intro-to-eng3091`](sec-01-cpp-basics/00-intro-to-eng3091), [PDF](sec-01-cpp-basics/00-intro-to-eng3091/chap_00.pdf))
    - C and C++: a short history; compiled C++ versus interpreted Python
    - What the course covers, how it is assessed, and how to learn it
    - Installing an IDE and a compiler (a separate guide, `installation.html`)
- **Chapter 01: Program Structure and Variables** ([`01-structure-and-variables`](sec-01-cpp-basics/01-structure-and-variables), [PDF](sec-01-cpp-basics/01-structure-and-variables/chap_01.pdf))
    - The structure of a C++ program; compiling and running it from the terminal
    - Defining and initializing variables; fundamental types; narrowing conversions
    - Input and output with `<iostream>`
    - Undefined behaviour, starting with uninitialized variables
- **Chapter 02: Functions and Files** ([`02-functions-and-files`](sec-01-cpp-basics/02-functions-and-files), [PDF](sec-01-cpp-basics/02-functions-and-files/chap_02.pdf))
    - Why functions: Don't Repeat Yourself
    - Defining and calling functions; return values; parameters and arguments
    - Local scope and lifetime
    - Forward declarations; programs with multiple files; header files and header guards
    - Compiler errors versus linker errors
- **Chapter 03: Control Flow** ([`03-control-flow`](sec-01-cpp-basics/03-control-flow), [PDF](sec-01-cpp-basics/03-control-flow/chap_03.pdf))
    - `if`, `else if` and `else`; the `=` versus `==` trap; guard clauses
    - `switch` statements and fallthrough
    - `while`, `do-while` and `for` loops; `break` and `continue`
    - A Python-to-C++ phrasebook
- **Chapter 04: Constants and Strings** ([`04-constants-and-strings`](sec-01-cpp-basics/04-constants-and-strings), [PDF](sec-01-cpp-basics/04-constants-and-strings/chap_04.pdf))
    - `const` and `constexpr`; literals; avoiding magic numbers; `std::numbers::pi`
    - `std::string`: creating, combining and comparing strings
    - Reading text: `>>` versus `std::getline`, and `std::ws`

### Section 02: C++ Intermediate

- **Chapter 05: Function Overloading and Default Arguments** ([`05-function-overloading`](sec-02-cpp-intermediate/05-function-overloading), [PDF](sec-02-cpp-intermediate/05-function-overloading/chap_05.pdf))
    - Function overloading and overload resolution
    - Ambiguous matches; deleting functions with `= delete`
    - Default arguments
- **Chapter 06: Function Templates** ([`06-function-template`](sec-02-cpp-intermediate/06-function-template), [PDF](sec-02-cpp-intermediate/06-function-template/chap_06.pdf))
    - Function templates and template instantiation
    - Template argument deduction; templates with several template types
    - Non-template parameters; abbreviated function templates (C++20)
    - Templates in header files
- **Chapter 07: Compound Types and References** ([`07-compound-types-references`](sec-02-cpp-intermediate/07-compound-types-references), [PDF](sec-02-cpp-intermediate/07-compound-types-references/chap_07.pdf))
    - Compound types
    - Value categories: lvalues and rvalues
    - lvalue references and `const` references; dangling references
    - Pass by reference and pass by `const` reference; return by reference
- **Chapter 08: Pointers** ([`08-pointers`](sec-02-cpp-intermediate/08-pointers), [PDF](sec-02-cpp-intermediate/08-pointers/chap_08.pdf))
    - Addresses: the address-of operator `&` and the dereference operator `*`
    - Pointers; null pointers and `nullptr`; dangling pointers
    - Pass by address; pointers versus references
- **Chapter 09: Dynamic Memory Allocation** ([`09-dynamic-allocation`](sec-02-cpp-intermediate/09-dynamic-allocation), [PDF](sec-02-cpp-intermediate/09-dynamic-allocation/chap_09.pdf))
    - The stack and the heap
    - `new` and `delete`; memory leaks, and finding them with AddressSanitizer
    - Dynamic arrays with `new[]` and `delete[]`
    - Letting `std::vector` and `std::unique_ptr` do the deleting

### Section 03: Object-Oriented Programming

- **Chapter 10: Object-Oriented Programming** ([`10-intro-to-oop`](sec-03-oop/10-intro-to-oop), [PDF](sec-03-oop/10-intro-to-oop/chap_10.pdf))
    - Why OOP; the four pillars: encapsulation, abstraction, inheritance and polymorphism
    - Classes and objects; `struct` versus `class`
    - Member functions and the implicit object
    - `const` objects and `const` member functions
- **Chapter 11: Classes and Constructors** ([`11-classes`](sec-03-oop/11-classes), [PDF](sec-03-oop/11-classes/chap_11.pdf))
    - `public` and `private` members; access specifiers
    - Aggregates; member selection through pointers with `->`
    - Constructors, the `this` pointer, and member initializer lists
    - Default constructors; copy constructors and copy elision
- **Chapter 12: More on Classes** ([`12-classes-more`](sec-03-oop/12-classes-more), [PDF](sec-03-oop/12-classes-more/chap_12.pdf))
    - The hidden `this` pointer and method chaining
    - Destructors and RAII; the rule of three (and of zero)
    - Class templates and `std::pair`
    - Friend functions and friend classes
- **Chapter 13: Operator Overloading** ([`13-operator-overloading`](sec-03-oop/13-operator-overloading), [PDF](sec-03-oop/13-operator-overloading/chap_13.pdf))
    - Operators as functions
    - Overloading operators with friend, normal and member functions
    - Overloading the I/O operators `<<` and `>>`
    - `+=` as a member, `+` as a normal function
- **Chapter 14: Inheritance** ([`14-inheritance`](sec-03-oop/14-inheritance), [PDF](sec-03-oop/14-inheritance/chap_14.pdf))
    - "Is a" relationships; basic inheritance in C++
    - Splitting a class hierarchy into header and implementation files
    - Order of construction and destruction; initializing base classes
    - `protected` members and kinds of inheritance
    - Adding, redefining and extending inherited behaviour
    - Multiple inheritance
    - Also in the folder: `uni_diagram.html`, a class diagram of the chapter's university example
- **Chapter 15: Virtual Functions and Polymorphism** ([`15-virtual-functions`](sec-03-oop/15-virtual-functions), [PDF](sec-03-oop/15-virtual-functions/chap_15.pdf))
    - Base class pointers and references to derived objects
    - Virtual functions and polymorphism; `override` and `final`
    - Object slicing; virtual destructors
    - Pure virtual functions, abstract base classes and interface classes

### Section 04: UML Class Diagrams

- **Chapter 16: Object Relationships** ([`16-object-relationships`](sec-04-uml-class/16-object-relationships), [PDF](sec-04-uml-class/16-object-relationships/chap_16.pdf))
    - Composition and aggregation (object composition)
    - Association and dependency
    - Implementing each relationship in C++
- **Chapter 17: UML Class Diagrams** ([`17-uml-class-diagram`](sec-04-uml-class/17-uml-class-diagram), [PDF](sec-04-uml-class/17-uml-class-diagram/chap_17.pdf)), lecture notes only, no slides
    - Class notation and visibility
    - Drawing relationships: dependency, association, aggregation, composition, inheritance and realization
    - Multiplicity
    - Diagram conventions, and translating a diagram into C++

## What's in a chapter folder

| File or folder | Contents |
|:---|:---|
| `chap_XX.html` | the lecture notes, as a web page |
| `chap_XX.pdf` | the lecture notes, as a PDF |
| `chap_XX_slide.html` | the slides (every chapter except 17) |
| `chap_XX.qmd` | the Quarto source that all three are built from |
| `cpp/` | every C++ example in the chapter; a program made of several files has its own subfolder |
| `figures/` | the figures used in the chapter |
| `*.py` or `py/` | Python versions of some examples, for comparison (Chapters 02, 10, 13 and 14) |

Next to its chapter folders, each section folder has a `lecture-notes/` folder: `lecture_notes_0N.html` and `.pdf`, built from `lecture_notes_0N.qmd`, which pulls in one `_XX-*.qmd` file per chapter. The notes take their code listings and figures straight from the chapter folders.

## Assignments and exam preparation

Assignments 01 and 02 are assessed and count 25% each. The paper exam is the other 50%. Chapter 00 and Moodle have the details.

| Folder | Contents |
|:---|:---|
| [`assignments/assignment-01`](assignments/assignment-01) | **Assignment 01: C++ Basics.** Translate two of three Python programs (Newton–Raphson, a rogue-like room, tic-tac-toe) into C++, then build a linear regression model. The Python notebooks and their solutions are in `python/`. |
| [`assignments/assignment-02`](assignments/assignment-02) | **Assignment 02: machine learning in C++.** Implement linear and logistic regression as a header-only C++ library modelled on scikit-learn, working up to classifying handwritten digits. Read the five parts in order, from `01-description` to `05-header-only-library`. `data/` holds the datasets, `src/` the Python reference code, and `project/` an example header-only library. The MNIST files are too large for the repository: `src/generate_mnist_csv.py` creates them (it needs pandas and scikit-learn). |
| [`assignments/assignment-03`](assignments/assignment-03) | **Assignment 01 resit.** A `Polynomial` class modelled on NumPy's `poly1d`, built in three steps starting from a generative-AI baseline. |
| [`assignments/formative`](assignments/formative) | **Formative assignment**, not marked: practice classes for complex numbers, fractions, matrices and polynomials. |
| [`exam-preparation`](exam-preparation) | The mock exam with worked answers (`mock.html`), the C++ code for its questions and answers (`cpp/`), and answers to students' questions (`q_and_a.html`). The paper exam has three questions: C++ theory (30 marks), writing C++ code (40) and a UML class diagram (30). |

## Other folders

- [`theme`](theme): the shared look of all chapters: fonts, colours, slide layout and code style (see [`theme/README.md`](theme/README.md))
- [`scripts`](scripts): the Python scripts that draw the chapters' figures (see [Regenerating the figures](#regenerating-the-figures))

## Building the materials yourself

You need [Quarto](https://quarto.org), and a LaTeX distribution for the PDFs (for example, run `quarto install tinytex`).

Render a chapter from its own folder:

```bash
cd sec-02-cpp-intermediate/07-compound-types-references
quarto render chap_07.qmd                  # HTML notes, PDF and slides
quarto render chap_07.qmd --to revealjs    # the slides only
```

Render a section's lecture notes from its `lecture-notes/` folder:

```bash
cd sec-03-oop/lecture-notes
quarto render lecture_notes_03.qmd         # HTML and PDF
```

Chapter 17's diagrams are drawn with Mermaid, so its PDF, and the PDF of Section 04's lecture notes, also need a Chrome or Chromium browser (`quarto install chrome-headless-shell`).

Every chapter takes its settings from `theme/` through one line in its YAML header, `metadata-files: [../../theme/lecture.yml]`. The path is relative, so a chapter folder must sit two levels below the repository root, like the existing ones. [`theme/README.md`](theme/README.md) explains how to set up a new chapter, and the conventions for code panes, terminal output and callout boxes.

### Compiling the examples

The course uses C++20 and g++. A single-file example:

```bash
g++ -std=c++20 -Wall -Wextra example.cpp -o example
./example
```

For a program made of several files, list every `.cpp` file (the header files are found through `#include`):

```bash
cd sec-01-cpp-basics/02-functions-and-files/cpp/multiple_files
g++ -std=c++20 -Wall main.cpp add.cpp -o program
```

Chapter 09 finds memory leaks with AddressSanitizer:

```bash
g++ -std=c++20 -g -fsanitize=address memory_leak.cpp
```

The examples are formatted with clang-format, using the repository's [`.clang-format`](.clang-format) file (LLVM style with 4-space indents): run `clang-format -i example.cpp`.

### Regenerating the figures

The figures are drawn with Python and matplotlib in a hand-drawn (xkcd) style. Chapters 01–16 each have their own script, and `scripts/sketch.py` holds the colours and drawing helpers they share:

```bash
pip install matplotlib
python scripts/chap07_figures.py
```

The scripts can be run from any folder, and write straight into the chapter's `figures/` folder, so re-rendering the chapter picks up the new figures. For the full hand-written look, install the free [xkcd Script font](https://github.com/ipython/xkcd-font); without it, matplotlib falls back to a similar font. [`scripts/README.md`](scripts/README.md) has the details.

## Found a mistake?

If you spot a typo, a wrong explanation, or an example that doesn't behave as described, please [open an issue](https://github.com/khiemnguyen0407/uog-cpp/issues).

## Licence

The materials are released under the GNU General Public License v3.0: see [`LICENSE`](LICENSE). The Atkinson Hyperlegible fonts in `theme/fonts/` are under the SIL Open Font License ([`theme/fonts/OFL.txt`](theme/fonts/OFL.txt)).
