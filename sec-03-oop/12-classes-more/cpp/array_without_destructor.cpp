#include <iostream>
#include <stdexcept>

// Both type parameter template and non-type parameter template
template <typename T, int N>    // This is a good opportunity to teach this
class Vector
{
    T* data;    // pointer to the data type T

public:
    Vector() {
        data = new T[N];
    }

    void fill_fourty_two() {
        for (int i {0}; i <= N; ++i) {
            data[i] = static_cast<T>(42);
        }
    }

    // fill the array with 42 for the first m positon: 0 --> m - 1
    void fill_fourty_two(int m) {
        if (m > N) {
            throw std::out_of_range("Requested size m exceeds the template capacity N!");
        }
        for (int i {0}; i <= m; ++i) {
            data[i] = 42.0;
        }
    }

    void print() const {
        for (int i {0}; i <= N; ++i) {
            if (i % 10 == 0) std::cout << '\n';
            std::cout << data[i] << '\t';
        }
    }

    void cleanup() {
        delete data;
        std::cout << "Array pointed by pointer " << data << " is cleaned and returned to OS\n";
    }
};

int main()
{
    Vector<double, 42> vector {};
    vector.fill_fourty_two(24);
    vector.print(); std::cout << '\n';
    vector.cleanup();

    return 0;
}