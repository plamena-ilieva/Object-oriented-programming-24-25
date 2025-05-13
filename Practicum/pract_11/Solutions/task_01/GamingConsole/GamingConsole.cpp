#include "GamingConsole.h"

GamingConsole::GamingConsole() {
    addPerifDevice(PerifDev::JOYSTICK);
    addPerifDevice(PerifDev::MONITOR);
}

void GamingConsole::printComputerType() const {
    std::cout << "Gaming Console" << std::endl;
}