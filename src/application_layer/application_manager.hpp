#pragma once

#include <cstddef>
#include "blinky/blinky.hpp"
#include "device_layer/device_manager.hpp"
#include "device_abstraction/user_indication/i_user_indication.hpp"

namespace DeviceLayer
{
template <HardwareLayer::GpioConcept IGpio>
class UserIndication;
}
namespace HardwareLayer
{
class Gpio;
}
namespace Manager
{

using ApplicationLayer::Blinky;
using DeviceLayer::UserIndication;
using DeviceLayer::UserIndicationConcept;
using HardwareLayer::Gpio;
using HardwareLayer::GpioConcept;

template <GpioConcept IGpio>
class DeviceManager;

template <UserIndicationConcept IUserIndication>
class ApplicationManager
{
   public:
    ApplicationManager(DeviceManager<Gpio>& device_manager,
                       IUserIndication user_indication)
        : device_manager{device_manager},  //
          blinky{user_indication}

    {
    }

    void run()
    {
        for (std::size_t it = 0; it < 10; it++)
        {
            blinky.run();
        }
    }

   private:
    const DeviceManager<Gpio>& device_manager;
    Blinky<IUserIndication> blinky;
};

}  // namespace Manager