#pragma once

#include <concepts>
#include <cstdint>

namespace HardwareLayer
{

template <typename T>
concept IcbGpioConcept = requires(T gpio) {
    { gpio.done() } -> std::same_as<void>;
};

}    // namespace HardwareLayer