#include "Laptop.h"

Laptop::Laptop() {
    addPerifDevice(PerifDev::MOUSE_PAD);
    addPerifDevice(PerifDev::KEYBOARD);
    addPerifDevice(PerifDev::MONITOR);
}

void Laptop::printComputerType() const {
    std::cout << "Laptop" << std::endl;
}