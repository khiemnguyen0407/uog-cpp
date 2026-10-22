int main() {
    int x{5};
    int* ptr{&x};     // fine: &x is an int*
    double* dptr{&x}; // error: an int* is not a double*
    return 0;
}
