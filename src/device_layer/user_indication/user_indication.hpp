#pragma once

#include "hardware_abstraction/gpio/i_gpio.hpp"
namespace DeviceLayer
{

using HardwareLayer::IGpioConcept;

template <IGpioConcept IGpio, typename IcbUserIndication> class UserIndication
{
  public:
    UserIndication(IGpio&             i_gpio_ref,    //
                   IcbUserIndication& icb_user_indication_ref);

    void set();
    void reset();
    void done();

  private:
    IGpio&             i_gpio;
    IcbUserIndication& icb_user_indication;
};

template <IGpioConcept IGpio,    //
          typename IcbUserIndication>
UserIndication<IGpio, IcbUserIndication>::UserIndication(
    IGpio&             i_gpio_ref,                      //
    IcbUserIndication& icb_user_indication_ref)         //
    : i_gpio{ i_gpio_ref },                             //
      icb_user_indication{ icb_user_indication_ref }    //
{
    i_gpio.open();
}

template <IGpioConcept IGpio,    //
          typename IcbUserIndication>
void UserIndication<IGpio, IcbUserIndication>::set()
{
    i_gpio.set();
}

template <IGpioConcept IGpio,    //
          typename IcbUserIndication>
void UserIndication<IGpio, IcbUserIndication>::reset()
{
    i_gpio.reset();
}

template <IGpioConcept IGpio,    //
          typename IcbUserIndication>
void UserIndication<IGpio, IcbUserIndication>::done()
{
    icb_user_indication.userIndicationCallback();
}

}    // namespace DeviceLayer