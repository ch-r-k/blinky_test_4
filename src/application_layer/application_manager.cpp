#include "application_manager.hpp"
#include <cstddef>

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