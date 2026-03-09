#pragma once
#include <cstdint>
#include <iostream>
#include "hardware_abstraction/gpio/icb_gpio.hpp"
namespace HardwareLayer
{

template <typename IcbGpio> class Gpio
{
  public:
    Gpio(IcbGpio&     icb_gpio_ref,    //
         std::uint8_t pin)
        : icb_gpio(icb_gpio_ref),    //
          pin(pin)
    {
    }

    void open();
    void close();
    void set();
    void reset();

  private:
    IcbGpio&     icb_gpio;
    std::uint8_t pin;
};

template <typename IcbGpio> void Gpio<IcbGpio>::open()
{
    std::cout << "Open Pin " << pin << "\n";
}

template <typename IcbGpio> void Gpio<IcbGpio>::close()
{
    std::cout << "Close Pin " << pin << "\n";
}

template <typename IcbGpio> void Gpio<IcbGpio>::set()
{
    std::cout << "Set Pin " << pin << "\n";
    icb_gpio.gpioCallback();
}

template <typename IcbGpio> void Gpio<IcbGpio>::reset()
{
    std::cout << "Reset Pin " << pin << "\n";
    icb_gpio.gpioCallback();
}

}    // namespace HardwareLayer