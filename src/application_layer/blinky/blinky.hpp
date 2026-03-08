#pragma once

#include <iostream>
#include "device_abstraction/user_indication/i_user_indication.hpp"

namespace ApplicationLayer
{

using DeviceLayer::IUserIndicationConcept;

template <IUserIndicationConcept IUserIndication> class Blinky
{
  public:
    Blinky(IUserIndication& i_user_indication_ref)
        : i_user_indication(i_user_indication_ref)
    {
    }

    void run()
    {
        i_user_indication.set();
        i_user_indication.reset();
    }

    void done() { std::cout << "Callback Done \n"; }

  private:
    IUserIndication& i_user_indication;
};

}    // namespace ApplicationLayer