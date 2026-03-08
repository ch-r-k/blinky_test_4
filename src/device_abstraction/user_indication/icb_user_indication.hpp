#pragma once

#include <concepts>

namespace DeviceLayer
{

template <typename T>
concept IcbUserIndicationConcept = requires(T system) {
    { system.userIndicationCallback() } -> std::same_as<void>;
};

}    // namespace DeviceLayer