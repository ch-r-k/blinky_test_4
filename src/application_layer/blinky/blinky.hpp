#pragma once

#include <iostream>
#include "device_abstraction/user_indication/i_user_indication.hpp"

namespace ApplicationLayer
{

using DeviceLayer::IUserIndicationConcept;

template <IUserIndicationConcept IUserIndication> class Blinky
{
  public:
    Blinky(IUserIndication& i_user_indication_ref);

    void run();
    void done();

  private:
    IUserIndication& i_user_indication;
};

template <IUserIndicationConcept IUserIndication>
Blinky<IUserIndication>::Blinky(IUserIndication& i_user_indication_ref)
    : i_user_indication(i_user_indication_ref)
{
}

template <IUserIndicationConcept IUserIndication>
void Blinky<IUserIndication>::run()
{
    i_user_indication.set();
    i_user_indication.reset();
}

template <IUserIndicationConcept IUserIndication>
void Blinky<IUserIndication>::done()
{
    std::cout << "Callback Done \n";
}

}    // namespace ApplicationLayer