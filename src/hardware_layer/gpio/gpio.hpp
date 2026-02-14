#pragma once

#include <cstdint>

namespace HardwareLayer
{

class Gpio
{
   public:
    Gpio(std::uint8_t pin);
    ~Gpio() = default;

    void open();
    void close();
    void set();
    void reset();

   private:
    std::uint8_t pin{0};
};
}  // namespace HardwareLayer
