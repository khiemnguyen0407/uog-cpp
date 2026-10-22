#include <iostream>
#include <memory> // for std::unique_ptr and std::make_unique

int main() {
    std::unique_ptr<int> ptr{std::make_unique<int>(42)};
    std::cout << *ptr << '\n'; // use it just like a pointer
    return 0;
} // no delete: the int is freed automatically here
