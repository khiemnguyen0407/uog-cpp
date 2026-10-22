int main() {
    const double gravity; // error: no initializer
    gravity = 9.81;       // error: can't assign to a const
    return 0;
}
