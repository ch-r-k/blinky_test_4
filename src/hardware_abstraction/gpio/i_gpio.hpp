#pragma once

#include <concepts>
#include <cstdint>

namespace HardwareLayer
{

template <typename T>
concept GpioConcept = requires(T gpio)
{
    {
        gpio.open()
        } -> std::same_as<void>;
    {
        gpio.close()
        } -> std::same_as<void>;
    {
        gpio.set()
        } -> std::same_as<void>;
    {
        gpio.reset()
        } -> std::same_as<void>;
};

}  // namespace HardwareLayer