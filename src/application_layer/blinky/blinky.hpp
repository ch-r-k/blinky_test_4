#pragma once

#include <iostream>

namespace ApplicationLayer
{

template <typename System> class Blinky
{
  public:
    Blinky(System& sys) : system(sys) {}

    void run()
    {
        system.user_indication.set();
        system.user_indication.reset();
    }

    void done() { std::cout << "Callback Done \n"; }

  private:
    System& system;
};

}    // namespace ApplicationLayer