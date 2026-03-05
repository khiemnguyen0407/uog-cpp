#include <iostream>

class Humidity; // forward declaration of Humidity. Otherwise, it give compile error.

class Temperature
{
private:
    int temp { 0 };
public:
    explicit Temperature(int temp) : temp { temp } { }

    friend void print_weather(const Temperature& temperature, const Humidity& humidity); // forward declaration needed for this line
};

class Humidity
{
private:
    int humidity { 0 };
public:
    explicit Humidity(int humidity) : humidity { humidity } {  }

    friend void print_weather(const Temperature& temperature, const Humidity& humidity);
};

void print_weather(const Temperature& temperature, const Humidity& humidity)
{
    std::cout << "The temperature is " << temperature.temp <<
       " and the humidity is " << humidity.humidity << '\n';
}

int main()
{
    Humidity hum { 10 };
    Temperature temp { 12 };

    print_weather(temp, hum);

    return 0;
}