#pragma once

#include <iostream>
#include "device_abstraction/user_indication/has_user_indication.hpp"
#include "device_abstraction/user_indication/icb_user_indication.hpp"

namespace ApplicationLayer
{

using DeviceLayer::HasUserIndicationConcept;
using DeviceLayer::IcbUserIndicationConcept;

template <typename System> class Blinky
{
  public:
    Blinky(System& sys) : system(sys)
    {
        static_assert(HasUserIndicationConcept<System>,
                      "System must have UserIndication");

        using Blinky = decltype(std::declval<System&>().blinky);
        static_assert(DeviceLayer::IcbUserIndicationConcept<Blinky>,
                      "this must implement callback");
    }

    void run()
    {
        system.user_indication.set();
        system.user_indication.reset();
    }

    void done() { std::cout << "Callback Done \n"; }

  private:
    System& system;
};

}    // namespace ApplicationLayer