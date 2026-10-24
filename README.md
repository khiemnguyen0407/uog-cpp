# uog-cpp

**Learn C++ at the University of Glasgow**

Course materials for **ENG3091**: C++ programming and object-oriented programming. Every chapter comes as HTML lecture notes, a PDF and a slide deck, together with all the C++ examples shown in the lectures.

The materials draw heavily on [learncpp.com](https://www.learncpp.com), an excellent free tutorial. They don't try to reproduce the website as a book: they select, reorder and adapt its topics for this course.

# Contents

The repository is divided into four sections, one folder each:

| Section | Folder | Chapters |
|:---|:---|:---|
| 01: C++ Basics | `sec-01-cpp-basics` | 00–04 |
| 02: C++ Intermediate | `sec-02-cpp-intermediate` | 05–09 |
| 03: Object-Oriented Programming | `sec-03-oop` | 10–15 |
| 04: UML Class Diagrams | `sec-04-uml-class` | 16–17 |

Chapters are numbered continuously across sections: Section 02 starts where Section 01 ends, and so on.

**Why separate "basics" and "intermediate"?** Both sections are foundational C++, and one could argue they belong together. They're separate for two reasons:

- It makes the course easier to follow, and lets the Moodle page mirror this repository.
- Section 02 covers ideas that Python, taught in Year 2, hides from you: value categories (lvalues and rvalues), references, pointers, and the difference between passing by value, by reference and by address. (Python has something that only *feels* similar: passing an immutable object behaves a bit like pass by value, and passing a mutable object a bit like pass by reference.)

## Section 01: C++ Basics

- **Chapter 00: Introduction to ENG3091**, folder `00-intro-to-eng3091`
    - Welcome to ENG3091: course materials, assessment, and how the course is run
    - Installing a C++ compiler and editor
- **Chapter 01: Program Structure and Variables**, folder `01-structure-and-variables`
    - The structure of a C++ program; compiling and running it from the terminal
    - Defining and initializing variables; fundamental types; narrowing conversions
    - Input and output with `<iostream>`
    - Undefined behaviour, starting with uninitialized variables
- **Chapter 02: Functions and Files**, folder `02-functions-and-files`
    - Why functions: Don't Repeat Yourself
    - Defining and calling functions; return values; parameters and arguments
    - Local scope and lifetime
    - Forward declarations; programs with multiple files; header files and header guards
    - Compiler errors versus linker errors
- **Chapter 03: Control Flow**, folder `03-control-flow`
    - `if`, `else if` and `else`; the `=` versus `==` trap; guard clauses
    - `switch` statements and fallthrough
    - `while`, `do-while` and `for` loops; `break` and `continue`
    - A Python-to-C++ phrasebook
- **Chapter 04: Constants and Strings**, folder `04-constants-and-strings`
    - `const` and `constexpr`; literals; avoiding magic numbers; `std::numbers::pi`
    - `std::string`: creating, combining and comparing strings
    - Reading text: `>>` versus `std::getline`, and `std::ws`

## Section 02: C++ Intermediate

- **Chapter 05: Function Overloading and Default Arguments**, folder `05-function-overloading`
    - Function overloading and overload resolution
    - Ambiguous matches; deleting functions with `= delete`
    - Default arguments
- **Chapter 06: Function Templates**, folder `06-function-template`
    - Function templates and template instantiation
    - Template argument deduction; templates with several template types
    - Non-template parameters; abbreviated function templates (C++20)
    - Templates in header files
- **Chapter 07: Compound Types and References**, folder `07-compound-types-references`
    - Compound types
    - Value categories: lvalues and rvalues
    - lvalue references and `const` references; dangling references
    - Pass by reference and pass by `const` reference; return by reference
- **Chapter 08: Pointers**, folder `08-pointers`
    - Addresses: the address-of operator `&` and the dereference operator `*`
    - Pointers; null pointers and `nullptr`; dangling pointers
    - Pass by address; pointers versus references
- **Chapter 09: Dynamic Memory Allocation**, folder `09-dynamic-allocation`
    - The stack and the heap
    - `new` and `delete`; memory leaks, and finding them with AddressSanitizer
    - Dynamic arrays with `new[]` and `delete[]`
    - Letting `std::vector` and `std::unique_ptr` do the deleting

## Section 03: Object-Oriented Programming

- **Chapter 10: Object-Oriented Programming**, folder `10-intro-to-oop`
    - Why OOP; the four pillars: encapsulation, abstraction, inheritance and polymorphism
    - Classes and objects; `struct` versus `class`
    - Member functions and the implicit object
    - `const` objects and `const` member functions
- **Chapter 11: Classes and Constructors**, folder `11-classes`
    - `public` and `private` members; access specifiers
    - Aggregates; member selection through pointers with `->`
    - Constructors, the `this` pointer, and member initializer lists
    - Default constructors; copy constructors and copy elision
- **Chapter 12: More on Classes**, folder `12-classes-more`
    - The hidden `this` pointer and method chaining
    - Destructors and RAII; the rule of three (and of zero)
    - Class templates and `std::pair`
    - Friend functions and friend classes
- **Chapter 13: Operator Overloading**, folder `13-operator-overloading`
    - Operators as functions
    - Overloading operators with friend, normal and member functions
    - Overloading the I/O operators `<<` and `>>`
    - `+=` as a member, `+` as a normal function
- **Chapter 14: Inheritance**, folder `14-inheritance`
    - "Is a" relationships; basic inheritance in C++
    - Splitting a class hierarchy into header and implementation files
    - Order of construction and destruction; initializing base classes
    - `protected` members and kinds of inheritance
    - Adding, redefining and extending inherited behaviour
    - Multiple inheritance
- **Chapter 15: Virtual Functions and Polymorphism**, folder `15-virtual-functions`
    - Base class pointers and references to derived objects
    - Virtual functions and polymorphism; `override` and `final`
    - Object slicing; virtual destructors
    - Pure virtual functions, abstract base classes and interface classes

## Section 04: UML Class Diagrams

- **Chapter 16: Object Relationships**, folder `16-object-relationships`
    - Composition and aggregation (object composition)
    - Association and dependency
    - Implementing each relationship in C++
- **Chapter 17: UML Class Diagrams**, folder `17-uml-class-diagram` (HTML and PDF notes only, no slides)
    - Class notation and visibility
    - Drawing relationships: dependency, association, aggregation, composition, inheritance and realization
    - Multiplicity
    - Diagram conventions, and translating a diagram into C++

## Other folders

- `assignments`: the coursework assignments (01 to 03) and a formative assignment
- `exam-preparation`: a mock exam, and questions and answers
- `references`: further reading
- `theme`: the shared look of all chapters: fonts, colours, slide layout and code style (see `theme/README.md`)
- `scripts`: Python scripts that draw the figures in the chapters

# What's in a chapter folder

| File or folder | Contents |
|:---|:---|
| `chap_XX.qmd` | the Quarto source of the chapter |
| `chap_XX.html` | the lecture notes, as a web page |
| `chap_XX.pdf` | the lecture notes, as a PDF |
| `chap_XX_slide.html` | the slides |
| `cpp/` | every C++ example shown in the chapter |
| `figures/` | the figures used in the chapter |

# Building the materials yourself

You need [Quarto](https://quarto.org), and a LaTeX distribution for the PDFs (for example, run `quarto install tinytex`).

Render a chapter from its own folder:

```bash
cd sec-02-cpp-intermediate/07-compound-types-references
quarto render chap_07.qmd                  # HTML notes, PDF and slides
quarto render chap_07.qmd --to revealjs    # the slides only
```

Chapter 17's diagrams are drawn with Mermaid, so its PDF also needs a Chrome or Chromium browser (`quarto install chrome-headless-shell`).

## Compiling the examples

The course uses C++20 and g++:

```bash
g++ -std=c++20 -Wall -Wextra example.cpp -o example
./example
```

Some examples **fail to compile on purpose**, to show a compiler error. The slides mark them as "does not compile". The code is formatted with the repository's `.clang-format` file.

## Regenerating the figures

The figures are drawn with Python and matplotlib in a hand-drawn (xkcd) style. Each chapter has its own script:

```bash
pip install matplotlib
python scripts/chap07_figures.py
```

The scripts can be run from any folder, and write straight into the chapter's `figures/` folder. For the full hand-written look, install the free [xkcd Script font](https://github.com/ipython/xkcd-font); without it, matplotlib falls back to a similar font.