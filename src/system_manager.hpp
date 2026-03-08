#pragma once

#include "application_layer/blinky/blinky.hpp"
#include "device_layer/user_indication/user_indication.hpp"
#include "hardware_layer/gpio/gpio.hpp"

namespace Manager
{

using ApplicationLayer::Blinky;
using DeviceLayer::UserIndication;
using HardwareLayer::Gpio;

class SystemManager
{
    using GpioType           = Gpio<SystemManager>;
    using UserIndicationType = UserIndication<GpioType, SystemManager>;
    using BlinkyType         = Blinky<UserIndicationType>;

  public:
    GpioType           gpio{ *this, 1 };
    UserIndicationType user_indication{ gpio, *this };
    BlinkyType         blinky{ user_indication };

    //
    void run()
    {
        for (int i = 0; i < 10; i++)
        {
            blinky.run();
        }
    }

    // callbacks
    void gpioCallback() { user_indication.done(); };
    void userIndicationCallback() { blinky.done(); };
};

}    // namespace Manager
