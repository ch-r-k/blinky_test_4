#pragma once

#include "device_abstraction/user_indication/i_user_indication.hpp"

namespace ApplicationLayer
{

template <DeviceLayer::UserIndicationConcept IUserIndication>
class Blinky
{
   private:
    IUserIndication& i_user_indication;

   public:
    Blinky(IUserIndication& interface) : i_user_indication{interface} {};
    ~Blinky() = default;

    void run()
    {
        i_user_indication.set();
        i_user_indication.reset();
    }
};

}  // namespace ApplicationLayer