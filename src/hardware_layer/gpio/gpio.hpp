#pragma once
#include <cstdint>
#include <iostream>
#include "hardware_abstraction/gpio/i_gpio.hpp"

namespace HardwareLayer
{

template <typename System> class Gpio
{
  public:
    Gpio(System&      sys,    //
         std::uint8_t pin)
        : system(sys),    //
          pin(pin)
    {
        using GpioType = decltype(std::declval<System&>().gpio);
        static_assert(IGpioConcept<GpioType>,
                      "System.gpio must satisfy IGpioConcept");
    }

    void open() { std::cout << "Open Pin " << pin << "\n"; }
    void close() { std::cout << "Close Pin " << pin << "\n"; }

    void set()
    {
        std::cout << "Set Pin " << pin << "\n";
        system.gpioCallback();
    }

    void reset()
    {
        std::cout << "Reset Pin " << pin << "\n";
        system.gpioCallback();
    }

  private:
    System&      system;
    std::uint8_t pin;
};

}    // namespace HardwareLayer