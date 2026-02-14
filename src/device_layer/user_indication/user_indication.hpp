#pragma once

#include "hardware_abstraction/gpio/i_gpio.hpp"

namespace DeviceLayer
{

template <HardwareLayer::GpioConcept IGpio>
class UserIndication
{
   private:
    IGpio& i_gpio;

   public:
    UserIndication(IGpio& i_gpio) : i_gpio(i_gpio) { i_gpio.open(); }

    ~UserIndication() { i_gpio.close(); }

    void set() { i_gpio.set(); }

    void reset() { i_gpio.reset(); }
};

}  // namespace DeviceLayer