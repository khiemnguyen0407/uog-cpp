#include <iostream>

class Humidity;     // forward declaration: used before it's defined
class Temperature { // members are private by default
    int temp{};

  public:
    Temperature(int temp) : temp{temp} {}
    friend void print_weather(const Temperature& t, const Humidity& h);
};

class Humidity {
    int humidity{};

  public:
    Humidity(int humidity) : humidity{humidity} {}
    friend void print_weather(const Temperature& t, const Humidity& h);
};

void print_weather(const Temperature& t, const Humidity& h) {
    std::cout << t.temp << " degrees, " << h.humidity << "% humidity\n";
}

int main() {
    print_weather(Temperature{12}, Humidity{10});
    return 0;
}
