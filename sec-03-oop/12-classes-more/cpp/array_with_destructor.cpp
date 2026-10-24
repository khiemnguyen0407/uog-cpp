#include <iostream>

template <typename T, int N> // a type AND a value (Chapter 06)
class FixedArray {
    T* data{}; // private by default

  public:
    FixedArray(const T& value) : data{new T[N]} { // acquire...
        for (int i{0}; i < N; ++i) {              // i < N, not i <= N!
            data[i] = value;
        }
    }
    ~FixedArray() {    // ...and release
        delete[] data; // new[] needs delete[] (Chapter 09)
        std::cout << "Memory returned\n";
    }
    T get(int i) const { return data[i]; }
};

int main() {
    FixedArray<double, 5> numbers{4.2};
    std::cout << numbers.get(0) << ' ' << numbers.get(4) << '\n';
    return 0;
} // no cleanup() call needed
