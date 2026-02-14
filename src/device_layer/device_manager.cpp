#include "device_manager.hpp"
#include "hardware_layer/hardware_manager.hpp"

namespace Manager
{
DeviceManager::DeviceManager(HardwareManager& hardware_manager)
    : hardware_manager{hardware_manager},
      user_indication{hardware_manager.getGpio0()}
{
}

UserIndication<Gpio>& DeviceManager::getUserIndication()
{
    return user_indication;
}
}  // namespace Manager
