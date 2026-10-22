int main() {
    int x{5};
    int& ref{x}; // fine: x is a modifiable lvalue

    const int y{5};
    int& invalid_ref{y}; // error: y is const

    int& invalid_ref2{0}; // error: 0 is an rvalue
    return 0;
}
