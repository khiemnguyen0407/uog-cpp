#include <iostream>
#include <vector>

int main() {
    // Original vector
    std::vector<double> original = {1.1, 2.2, 3.3, 4.4};

    // Method 1: 
    std::vector<double> copy1{original};
    std::vector<double> copy2(original); // Direct initialization (Calling the copy constructor)

    // Method 2: Using the assignment syntax (Also calls copy constructor here)
    std::vector<double> copy3 = original;

    // Proof they are independent:
    copy1[0] = 99.9;

    std::cout << "Original[0]: " << original[0] << "\n"; // Still 1.1
    std::cout << "Copy1[0]:    " << copy1[0] << "\n";    // Now 99.9

    return 0;
}