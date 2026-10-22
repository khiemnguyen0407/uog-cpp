#include <iostream>

// Factor is a value, not a type
template <int Factor, typename T>
T scale_sensor_reading(T raw_value) {
    return raw_value * Factor;
}

int main() {
    int raw_input{10};

    int high{scale_sensor_reading<5>(raw_input)}; // Factor = 5
    int low{scale_sensor_reading<2>(raw_input)};  // Factor = 2

    std::cout << "Raw: " << raw_input << '\n';
    std::cout << "High (x5): " << high << '\n';
    std::cout << "Low  (x2): " << low << '\n';
    return 0;
}
