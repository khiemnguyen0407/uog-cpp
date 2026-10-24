# uog-cpp


**Learn C++ at University of Glasgow**


This repo is developed by heavily using [www.learncpp.com](www.learncpp.com). However, the repo does not try to compile the website into a single book.

Unfortunately, this repo is not really about Software Engineering. Please refer to [Software Engineering at Google](https://raw.githubusercontent.com/abseil/abseil.github.io/cd13b21daa6ec74155548241241693198c1b1264/resources/swe_at_google.2.pdf) for a proper learning in Software Engineering.

# Contents
The repo is divided into the following sections: 

1. **Section 01**: C++ Basics
2. **Section 02**: C++ Intermediate
3. **Section 03**: Object-oriented Programming in C++
4. **Section 04**: UML Class Diagrams. 

Each section corresponds to one folder and contains multiple chapters that cover various topics in C++ programming. Each chapter in one sepcfic section is numbered sequentially. Note that chapter numbers in Section 02 continue from the last chapter number in Section 01, and so on for Section 03 and Section 04.

**REMARK**  
It can be debatable when the contents in two sections "C++ basics" and "C++ intermediate" should not be considered separate as they are all actually foundational in C++. However, for educational purpose, I want to separate the contents in these two sections for two reasons:

- It is easier for the students to follow, and to structure the course Moodle to reflect the GitHub materials.
- The content in Section "C++ Intermediate" is only available and not relevant in Python programming that is taught in Year 2. They involve sophisticated topics such as pointers, reference, pass by value, pass by reference, pass by address, lvalue, rvalue. In fact, Python has something like "pass an immutable object" that feels like _pass by value_ and "pass a mutable object" that feels like _pass by reference_.

## Section 01: C++ Basics

- **Chapter 00** &mdash; Folder `00-intro-to-eng3091`
    - Welcome to ENG3091, course materials, marking system and how the course is run.
- **Chapter 01** &mdash; Folder `01-structure-and-variables`
    - How a basic C++ program source code looks like. 
    - Declare and initialize variables in C++. 
    -  Input and output values in C++ using `iostream`
- **Chapter 02** &mdash; Folder `02-functions-and-files`
    - User-defined functions: basic syntax and use
    - Function parameters & arguments
    - Forward declaration
    - Working with multiple files
    - Header files
- **Chapter 03** &mdash; Folder `03-control-flow`
    - `if`, `if-else` statement
    - `switch` statement
    - `for` loop
    - `while` loop
    - `do-while` loop
    - `break` and `continue` statements
- **Chapter 04** &mdash; Folder `04-constants-and-strings`
    - Define constant parameters in functions
    - Data type `std::string`

## Section 02: C++ Intermediates
- **Chapter 05** &mdash; Folder `05-function-overloading`
  - Quick intro to function overloading
  - Function overload resolution & ambigous matches
  - Default arguments
- **Chapter 06** &mdash; Folder `06-function-template`
  - Function templates
  - Function template instantiation
  - Function templates with multiple template types
- **Chapter 07** &mdash; Folder `07-compound-types-references-pointers`
  - Quick intro to compound data types
  - Value categories: **lvalues** and **rvalues**
  - lvalue references, lvalue references to const
  - pass by lvalue reference (pass by reference)
  - pass by const lvalue reference
  - Intro to pointers
  - `null` pointers
  - Pass by address
- **Chapter 08** &mdash; Folder `08-compound-types-enums-structs`
  - Unscoped enumerations
  - Unscoped enumerator integral conversions
  - Intro to structs, members, and member selection
  - Struct aggregate initialization
  - Default member initialization
  - Member selection with pointers and references
  - Quick intro to class templates
- **Chapter 09** &mdash; Folder `09-dynamic-allocation`
  - Dynamic memory allocation with `new` and `delete`
  - Dynamically allocating arrays
  
## Section 03: Object oriented programming
- **Chapter 10** &mdash; Folder `10-intro-to-classes`
  - Intro to classes
  - Member functions
  - Const class objects and const member functions
  - Public and private members & access specifiers
  - Access functions
  - Member functions returning references to data members
  - Encapsulation: Benefits of data hiding
  - Intro to **constructors**
  - Constructor member initializer lists
- **Chapter 11** &mdash; Folder `11-more-on-classes`
  - The hidden `this` pointer and member function chaining
  - Classes and header files
  - Nested types
  - Intro to **destructors**
  - Static member variables
  - Static member functions
  - Friend non-member functions
  - Friend classes and friend member functions
- **Chapter 12** &mdash; Folder `12-inheritance`
  - Intro to **inheritance**
  - Basic inheritance in C++
  - Order of construction of derived classes
  - Inheritance and access specifiers
  - Adding new functionality to a derived class
  - Calling inherited functions and overriding behavior
  - Hiding inherited functionality
  - Multiple inheritance
- **Chapter 13** &mdash; Folder `13-operator-overlading`
- **Chapter 14** &mdash; Folder `14-virtual-functions`
  - Pointers and references to base class of derived objects
  - Virtual functions and polymorphism

## Section 04: UML Class Diagram
