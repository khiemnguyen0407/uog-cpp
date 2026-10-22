int main() {
    int& invalid_ref; // error: a reference must be initialized

    int x{5};
    int& ref{x}; // fine: ref is bound to x
    return 0;
}
