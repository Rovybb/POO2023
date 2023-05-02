#include <iostream>

float operator""_Kelvin(unsigned long long value) {
    return (float)value - 273.15;
}

float operator""_Fahrenheit(unsigned long long value) {
    return ((float)value - 32) / 1.8;
}

int main()
{
    std::cout << "300 K => " << 300_Kelvin << " C\n";
    std::cout << "120 F => " << 120_Fahrenheit << " C";
}