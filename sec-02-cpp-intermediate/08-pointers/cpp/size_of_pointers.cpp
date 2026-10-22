#include <iostream>

int main() {
    char* char_ptr{};      // a char is 1 byte
    int* int_ptr{};        // an int is usually 4 bytes
    long double* ld_ptr{}; // a long double is often 16 bytes

    // But every pointer is the same size: it just holds an address
    std::cout << sizeof(char_ptr) << '\n';
    std::cout << sizeof(int_ptr) << '\n';
    std::cout << sizeof(ld_ptr) << '\n';
    return 0;
}
