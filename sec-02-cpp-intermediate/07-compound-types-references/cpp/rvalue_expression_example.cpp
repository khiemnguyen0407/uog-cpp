int return5() { return 5; }

int main() {
    int x{5};            // 5 is an rvalue
    const double d{1.2}; // 1.2 is an rvalue

    int y{x};                   // x is a modifiable lvalue
    const double e{d};          // d is a non-modifiable lvalue
    int z{return5()};           // return5() is an rvalue (returned by value)
    int w{x + 1};               // x + 1 is an rvalue
    int q{static_cast<int>(d)}; // the converted value is an rvalue
    return y + z + w + q + static_cast<int>(e);
}
