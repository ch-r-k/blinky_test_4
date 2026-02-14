#pragma once

#include "hardware_layer/gpio/gpio.hpp"
#include "device_layer/user_indication/user_indication.hpp"

namespace Manager
{

using DeviceLayer::UserIndication;
using HardwareLayer::Gpio;

class HardwareManager;

class DeviceManager
{
   public:
    DeviceManager(HardwareManager& hardware_manager);
    UserIndication<Gpio>& getUserIndication();

   private:
    const HardwareManager& hardware_manager;
    UserIndication<Gpio> user_indication;
};
}  // namespace Manager