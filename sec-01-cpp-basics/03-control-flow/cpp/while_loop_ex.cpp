#include <iostream>

int main() {
    int count{15};
    while (count <= 10) { // false from the start
        std::cout << count << ' ';
        ++count;
    }
    std::cout << "done!\n";
    return 0;
}
