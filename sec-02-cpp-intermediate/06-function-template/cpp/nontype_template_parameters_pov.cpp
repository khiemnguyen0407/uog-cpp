#include <iostream>

/**
 * Scales a value by a factor known at compile-time.
 * T: The data type (e.g., int, float)
 * Factor: The non-type parameter (the scaling multiplier)
 */
template <int Factor, typename T>
T scale_sensor_reading(T raw_value);

template<>
int scale_sensor_reading<5>(int raw_value) {
    return raw_value * 5;
}

template<>
int scale_sensor_reading<2>(int raw_value) {
    return raw_value * 2;
}

int main() {
    int raw_input = 10;

    // The factor '5' is baked into this specific version of the function.
    int high_sensitivity = scale_sensor_reading<5>(raw_input);

    // The factor '2' is baked into this one.
    int low_sensitivity = scale_sensor_reading<2>(raw_input);

    std::cout << "Raw: " << raw_input << "\n";
    std::cout << "High (x5): " << high_sensitivity << "\n";
    std::cout << "Low  (x2): " << low_sensitivity << "\n";

    return 0;
}