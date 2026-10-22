#include <iostream>

int main() {
    int outer{1};
    while (outer <= 5) {
        int inner{1}; // created afresh for every row
        while (inner <= outer) {
            std::cout << inner << ' ';
            ++inner;
        }
        std::cout << '\n';
        ++outer;
    } // inner is destroyed at the end of each row
    return 0;
}
