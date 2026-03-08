#pragma once

#include <concepts>

namespace DeviceLayer
{

template <typename T>
concept IcbUserIndicationConcept = requires(T user_indication) {
    { user_indication.done() } -> std::same_as<void>;
};

}    // namespace DeviceLayer