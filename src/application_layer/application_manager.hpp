#pragma once

#include "blinky/blinky.hpp"
#include "device_layer/device_manager.hpp"

namespace Manager
{

using ApplicationLayer::Blinky;
using DeviceLayer::UserIndication;
using HardwareLayer::Gpio;

class ApplicationManager
{
   public:
    ApplicationManager(DeviceManager& device_manager);
    void run();

   private:
    const DeviceManager& device_manager;
    Blinky<UserIndication<Gpio>> blinky;
};

}  // namespace Manager