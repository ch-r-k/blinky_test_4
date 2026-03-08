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
  public:
    Gpio<SystemManager>                                gpio{ *this, 1 };
    UserIndication<Gpio<SystemManager>, SystemManager> user_indication{ gpio,
                                                                        *this };
    Blinky<UserIndication<Gpio<SystemManager>, SystemManager>> blinky{
        user_indication
    };

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
