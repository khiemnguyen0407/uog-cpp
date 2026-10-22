#include <iostream>

int main() {
    int score{85};

    std::cout << "if, if:\n";
    if (score >= 80) {
        std::cout << "  A\n";
    }
    if (score >= 60) { // checked as well, and also true
        std::cout << "  B\n";
    }

    std::cout << "if, else if:\n";
    if (score >= 80) {
        std::cout << "  A\n";
    } else if (score >= 60) { // skipped: a branch already ran
        std::cout << "  B\n";
    }
    return 0;
}
