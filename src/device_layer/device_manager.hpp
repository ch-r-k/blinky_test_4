#pragma once

#include "device_layer/user_indication/user_indication.hpp"
#include "hardware_layer/hardware_manager.hpp"

namespace Manager
{

using DeviceLayer::UserIndication;
using HardwareLayer::GpioConcept;

class HardwareManager;

template <GpioConcept IGpio>
class DeviceManager
{
   public:
    DeviceManager(HardwareManager& hardware_manager, IGpio gpio_pin)
        : hardware_manager{hardware_manager},  //
          user_indication{gpio_pin}
    {
    }

    UserIndication<IGpio>& getUserIndication() { return user_indication; }

   private:
    const HardwareManager& hardware_manager;
    UserIndication<IGpio> user_indication;
};

}  // namespace Manager