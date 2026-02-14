#pragma once

#include "hardware_layer/gpio/gpio.hpp"

namespace Manager
{
class HardwareManager
{
   public:
    HardwareManager();

    HardwareLayer::Gpio& getGpio0();

   private:
    HardwareLayer::Gpio gpio{1};
};
}  // namespace Manager