void do_something() {
    int* ptr{new int{42}}; // allocated...
} // ptr is destroyed: the int leaks

int main() {
    do_something();
    return 0;
}
