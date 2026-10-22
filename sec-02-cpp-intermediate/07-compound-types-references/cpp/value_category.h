#ifndef VALUE_CATEGORY_H
#define VALUE_CATEGORY_H

#include <iostream>

// A little tool that prints whether an expression is an lvalue or an
// rvalue. You don't need to understand how it works (yet!).
template <typename T>
constexpr bool is_lvalue(T&) {
    return true;
}

template <typename T>
constexpr bool is_lvalue(T&&) {
    return false;
}

#define PRINT_VALUE_CATEGORY(expr)                                             \
    std::cout << #expr << " is an " << (is_lvalue(expr) ? "lvalue" : "rvalue") \
              << '\n'

#endif
