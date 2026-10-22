int main() {
    int x{};
    x = 5; // fine: x is a variable we can assign to
    5 = x; // error: you can't assign to 5
    return 0;
}
