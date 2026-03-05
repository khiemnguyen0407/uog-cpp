#include <iostream>
#include <utility>

auto max(const auto& pair) {
    // the members of std::pair have predefined names `first` and `second`
    return (pair.first < pair.second) ? pair.second : pair.first;
}

void print(const auto& pair) {
    // the members of std::pair have predefined names `first` and `second`
    std::cout << '[' << pair.first << ", " << pair.second << ']';
}

int main()
{
    std::pair<int, double> p1{ 1, 2.3 }; // a pair holding an int and a double
    std::pair<double, int> p2{ 4.5, 6 }; // a pair holding a double and an int
    std::pair<int, int> p3{ 7, 8 };      // a pair holding two ints

    std::cout << "max(p1) = " << max(p1) << '\n';
    std::cout << "max(p2) = " << max(p2) << '\n';
    print(p3);

    return 0;
}