#pragma once

#include "i_user_indication.hpp"

namespace DeviceLayer
{
template <typename T>
concept HasUserIndicationConcept
    = IUserIndicationConcept<decltype(T::user_indication)>;

}