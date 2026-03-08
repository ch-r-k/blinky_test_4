#pragma once

#include "device_abstraction/user_indication/icb_user_indication.hpp"
#include "hardware_abstraction/gpio/i_gpio.hpp"
namespace DeviceLayer
{

using HardwareLayer::IGpioConcept;

template <IGpioConcept IGpio, typename IcbUserIndication> class UserIndication
{
  public:
    UserIndication(IGpio&             i_gpio_ref,                 //
                   IcbUserIndication& icb_user_indication_ref)    //
        : i_gpio{ i_gpio_ref },                                   //
          icb_user_indication{ icb_user_indication_ref }          //
    {
        i_gpio.open();
    }

    void set() { i_gpio.set(); }

    void reset() { i_gpio.reset(); }

    void done() { icb_user_indication.userIndicationCallback(); }

  private:
    IGpio&             i_gpio;
    IcbUserIndication& icb_user_indication;
};

}    // namespace DeviceLayer