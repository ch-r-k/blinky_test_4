#include "application_manager.hpp"
#include <cstddef>
#include "application_layer/blinky/blinky.hpp"
#include "device_layer/user_indication/user_indication.hpp"
#include "hardware_layer/gpio/gpio.hpp"

namespace Manager
{
ApplicationManager::ApplicationManager(DeviceManager& device_manager)
    : device_manager{device_manager},  //
      blinky{device_manager.getUserIndication()}

{
}

void ApplicationManager::run()
{
    for (std::size_t it = 0; it < 10; it++)
    {
        blinky.run();
    }
}
}  // namespace Manager