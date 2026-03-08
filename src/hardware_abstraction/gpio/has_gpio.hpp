#pragma once

#include "i_gpio.hpp"

namespace HardwareLayer
{
template <typename T>
concept HasGpio = IGpioConcept<decltype(T::gpio)>;

}