#pragma once

#include <concepts>

namespace HardwareLayer
{

template <typename T>
concept IcbGpioConcept = requires(T gpio) {
    { gpio.done() } -> std::same_as<void>;
};

}    // namespace HardwareLayer