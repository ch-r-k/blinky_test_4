#include <iostream>
#include "application_layer/application_manager.hpp"
#include "device_layer/device_manager.hpp"
#include "hardware_layer/hardware_manager.hpp"

int main([[maybe_unused]] int argc, [[maybe_unused]] const char* argv[])
{
    static Manager::HardwareManager hardware_manager;
    static Manager::DeviceManager device_manager{hardware_manager};
    static Manager::ApplicationManager application_manager{device_manager};

    application_manager.run();

    return 0;
}
