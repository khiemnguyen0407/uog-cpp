#include <iostream>
#include <utility> // for std::pair

auto max(const auto& pair) { // abbreviated function template (Ch. 06)
    return (pair.first < pair.second) ? pair.second : pair.first;
}

int main() {
    std::pair<int, double> p1{1, 2.3};
    std::pair<double, int> p2{4.5, 6};
    std::cout << "max(p1) = " << max(p1) << '\n';
    std::cout << "max(p2) = " << max(p2) << '\n';
    std::cout << p1.first << ' ' << p1.second << '\n';
    return 0;
}
