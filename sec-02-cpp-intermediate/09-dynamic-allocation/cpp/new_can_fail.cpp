#include <iostream>
#include <new> // for std::nothrow

int main() {
    long long huge{1'000'000'000'000}; // a trillion ints: 4 TB!

    int* safe{new (std::nothrow) int[huge]}; // null if it fails
    if (!safe) {
        std::cout << "Could not allocate memory\n";
    }

    int* unsafe{new int[huge]}; // throws if it fails
    std::cout << "We never get here\n";

    delete[] safe;
    delete[] unsafe;
    return 0;
}
