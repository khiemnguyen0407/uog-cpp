#include <iostream>

int main() {
    int count{0};
    while (count < 10) {
        if (count == 5) {
            continue;
        }
        std::cout << count << '\n';
        ++count;
    }
    return 0;
}
