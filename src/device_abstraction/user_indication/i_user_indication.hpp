#pragma once

#include <concepts>
#include <cstdint>

namespace DeviceLayer
{

template <typename T>
concept UserIndicationConcept = requires(T user_indication)
{
    {
        user_indication.set()
        } -> std::same_as<void>;
    {
        user_indication.reset()
        } -> std::same_as<void>;
};

}  // namespace DeviceLayer