#include "PC.h"

PC::PC() {
    addPerifDevice(PerifDev::MOUSE_PAD);
    addPerifDevice(PerifDev::KEYBOARD);
    addPerifDevice(PerifDev::MIC);
    addPerifDevice(PerifDev::HEADPHONES);
}

void PC::printComputerType() const {
    std::cout << "PC" << std::endl;
}