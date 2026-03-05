#include <iostream>

/**
 * Scales a value by a factor known at compile-time.
 * T: The data type (e.g., int, float)
 * Factor: The non-type parameter (the scaling multiplier)
 */
template <int Factor, typename T>
T scale_sensor_reading(T raw_value) {
    // Because Factor is a template parameter, the compiler 
    // treats 'raw_value * Factor' as a highly optimized operation.
    return raw_value * Factor;
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