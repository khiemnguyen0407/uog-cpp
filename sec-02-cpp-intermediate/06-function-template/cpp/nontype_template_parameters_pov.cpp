#include <iostream>

template <int Factor, typename T>
T scale_sensor_reading(T raw_value); // declaration only

template <>
int scale_sensor_reading<5>(int raw_value) { // Factor = 5
    return raw_value * 5;
}

template <>
int scale_sensor_reading<2>(int raw_value) { // Factor = 2
    return raw_value * 2;
}

int main() {
    int raw_input{10};
    std::cout << scale_sensor_reading<5>(raw_input) << '\n';
    std::cout << scale_sensor_reading<2>(raw_input) << '\n';
    return 0;
}
