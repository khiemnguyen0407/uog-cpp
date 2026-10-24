#include <iostream>

template <typename T, typename U>
struct Pair {
    T first{};
    U second{};
};

template <typename T, typename U>
void print(const Pair<T, U>& p) {
    std::cout << '[' << p.first << ", " << p.second << "]\n";
}

int main() {
    Pair<int, double> p1{1, 2.3}; // an int and a double
    Pair<double, int> p2{4.5, 6}; // a double and an int
    Pair<int, int> p3{7, 8};      // two ints
    print(p1);
    print(p2);
    print(p3);
    return 0;
}
