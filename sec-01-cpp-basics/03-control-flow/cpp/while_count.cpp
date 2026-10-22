#include <iostream>

int main() {
    int count{1};
    while (count <= 10) {
        std::cout << count << ' ';
        ++count; // add 1 to count
    }
    std::cout << "done!\n";
    return 0;
}
