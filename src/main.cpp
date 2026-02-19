#include "application_layer/application_manager.hpp"
#include "device_layer/device_manager.hpp"
#include "device_layer/user_indication/user_indication.hpp"
#include "hardware_layer/gpio/gpio.hpp"
#include "hardware_layer/hardware_manager.hpp"

int main([[maybe_unused]] int argc, [[maybe_unused]] const char* argv[])
{
    using DeviceLayer::UserIndication;
    using Manager::ApplicationManager;
    using Manager::DeviceManager;
    using Manager::HardwareManager;

    static HardwareManager hardware_manager;

    static DeviceManager<Gpio> device_manager{hardware_manager,  //
                                              hardware_manager.getGpio0()};

    static ApplicationManager<UserIndication<Gpio>> application_manager{
        device_manager,  //
        device_manager.getUserIndication()};

    application_manager.run();

    return 0;
}
