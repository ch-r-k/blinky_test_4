#include "hardware_manager.hpp"

namespace Manager
{
using HardwareLayer::Gpio;

HardwareManager::HardwareManager() = default;

Gpio& HardwareManager::getGpio0() { return gpio; }
}  // namespace Manager
