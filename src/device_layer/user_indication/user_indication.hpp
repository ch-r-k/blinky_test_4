#pragma once

#include <iostream>
#include "device_abstraction/user_indication/i_user_indication.hpp"
#include "device_abstraction/user_indication/icb_user_indication.hpp"
#include "hardware_abstraction/gpio/has_gpio.hpp"
#include "hardware_abstraction/gpio/i_gpio.hpp"
#include "hardware_abstraction/gpio/icb_gpio.hpp"
namespace DeviceLayer
{

using HardwareLayer::HasGpio;
using HardwareLayer::IcbGpioConcept;
using HardwareLayer::IGpioConcept;

template <IGpioConcept IGpio> class UserIndication
{
  public:
    UserIndication(IGpio& i_gpio_ref) : i_gpio{ i_gpio_ref } { i_gpio.open(); }

    void set() { i_gpio.set(); }

    void reset() { i_gpio.reset(); }

    // void done() { icb_user_indication.userIndicationCallback(); }

  private:
    IGpio& i_gpio;
    // IcbUserIndicationConcept& icb_user_indication;
};

}    // namespace DeviceLayer