#include "gpio.hpp"
#include <cstdint>
#include <iostream>

namespace HardwareLayer
{

Gpio::Gpio(std::uint8_t pin) : pin{pin} {}

void Gpio::open() { std::cout << "Open Pin" << pin << "\n"; }

void Gpio::close() { std::cout << "Close Pin" << pin << "\n"; }

void Gpio::set() { std::cout << "Set Pin" << pin << "\n"; }

void Gpio::reset() { std::cout << "Rest Pin" << pin << "\n"; }

}  // namespace HardwareLayer