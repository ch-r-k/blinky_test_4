#pragma once

#include <iostream>
#include "device_abstraction/user_indication/i_user_indication.hpp"
#include "hardware_abstraction/gpio/has_gpio.hpp"
#include "hardware_abstraction/gpio/icb_gpio.hpp"
namespace DeviceLayer
{

using HardwareLayer::HasGpio;
using HardwareLayer::IcbGpioConcept;

template <typename System> class UserIndication
{
  public:
    UserIndication(System& sys) : system(sys)
    {
        static_assert(HasGpio<System>, "System must have Gpio");

        using UserIndication
            = decltype(std::declval<System&>().user_indication);

        static_assert(IUserIndicationConcept<UserIndication>,
                      "this must implement Interface");

        static_assert(IcbGpioConcept<UserIndication>,
                      "this must implement Callback");

        system.gpio.open();
    }

    void set() { system.gpio.set(); }

    void reset() { system.gpio.reset(); }

    void done() { system.blinky.done(); }

  private:
    System& system;
};

}    // namespace DeviceLayer