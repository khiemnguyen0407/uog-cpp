#include <iostream>
#include <vector>

int main() {
    std::vector<double> original{1.1, 2.2, 3.3, 4.4};

    std::vector<double> copy1{original};  // brace initialization
    std::vector<double> copy2(original);  // direct initialization
    std::vector<double> copy3 = original; // copy initialization

    copy1[0] = 99.9; // proof that copy1 is independent:
    std::cout << "original[0]: " << original[0] << '\n';
    std::cout << "copy1[0]:    " << copy1[0] << '\n';
    return 0;
}
