#pragma once

#include "hardware_layer/gpio/gpio.hpp"

using HardwareLayer::Gpio;

namespace Manager
{
class HardwareManager
{
   public:
    HardwareManager();

    Gpio& getGpio0();

   private:
    Gpio gpio{1};
};
}  // namespace Manager