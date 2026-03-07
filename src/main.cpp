#include "system_manager.hpp"

int main([[maybe_unused]] int argc, [[maybe_unused]] const char* argv[])
{
    Manager::SystemManager system;

    system.run();

    return 0;
}