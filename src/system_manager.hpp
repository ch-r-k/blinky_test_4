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
    Gpio<SystemManager>           gpio{ *this, 1 };
    UserIndication<SystemManager> user_indication{ *this };
    Blinky<SystemManager>         blinky{ *this };

    void                          run()
    {
        for (int i = 0; i < 10; i++)
        {
            blinky.run();
        }
    }
};

}    // namespace Manager
