#pragma once

#include <iostream>
#include "device_abstraction/user_indication/i_user_indication.hpp"
#include "hardware_abstraction/gpio/icb_gpio.hpp"
namespace DeviceLayer
{

using HardwareLayer::IcbGpioConcept;

template <typename System> class UserIndication
{
  public:
    UserIndication(System& sys) : system(sys)
    {
        using UserIndication
            = decltype(std::declval<System&>().user_indication);
        static_assert(IcbGpioConcept<UserIndication>,
                      "must satisfy IcbGpioConcept");

        static_assert(IUserIndicationConcept<UserIndication>,
                      "must satisfy IUserIndication");

        system.gpio.open();
    }

    void set() { system.gpio.set(); }

    void reset() { system.gpio.reset(); }

    void done() { system.blinky.done(); }

  private:
    System& system;
};

}    // namespace DeviceLayer