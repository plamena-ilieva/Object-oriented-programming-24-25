#include "Computer.h"

Computer::Computer() {
    devices = new PerifDev[devCapacity];
}

Computer::Computer(const Computer& other) {
    copyFrom(other);
}
Computer::Computer(Computer&& other) {
    moveFrom(std::move(other));
}

Computer& Computer::operator=(const Computer& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}
Computer& Computer::operator=(Computer&& other) {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

Computer::~Computer() {
    free();
}

void Computer::copyFrom(const Computer& other) {
    procPower = other.procPower;

    cardModel = new char[strlen(other.cardModel) + 1];
    strcpy(cardModel, other.cardModel);

    supplyPower = other.supplyPower;

    ram = other.ram;

    devCount = other.devCount;
    devCapacity = other.devCapacity;
    devices = new PerifDev[devCapacity];

    for (size_t i = 0; i < devCount; i++) {
        devices[i] = other.devices[i];
    }
}

void Computer::moveFrom(Computer&& other) {
    procPower = other.procPower;
    other.procPower = 0.0;

    cardModel = other.cardModel;
    other.cardModel = nullptr;

    supplyPower = other.supplyPower;
    other.supplyPower = 0;

    ram = other.ram;
    other.ram = 0;

    devices = other.devices;
    other.devices = nullptr;

    devCount = other.devCount;
    other.devCount = 0;

    devCapacity = other.devCapacity;
    other.devCapacity = INIT_CAPACITY;
}

void Computer::free() {
    procPower = 0.0;
    delete[] cardModel;
    cardModel = nullptr;
    supplyPower = 0;
    ram = 0;
    delete[] devices;
    devices = nullptr;
    devCount = 0;
    devCapacity = INIT_CAPACITY;
}

void Computer::setProcPower(double procPower) {
    this->procPower = procPower;
}

void Computer::setCardModel(const char* cardModel) {
    if (this->cardModel) {
        delete[] this->cardModel;
    }

    this->cardModel = new char[strlen(cardModel) + 1];
    strcpy(this->cardModel, cardModel);
}

void Computer::setSupplyPower(int supplyPower) {
    this->supplyPower = supplyPower;
}

void Computer::setRam(int ram) {
    this->ram = ram;
}

void Computer::addPerifDevice(PerifDev dev) {
    if (devCount >= devCapacity) {
        resizeDevices();
    }
    devices[devCount++] = dev;
}

void Computer::resizeDevices() {
    PerifDev* temp = new PerifDev[devCapacity *= 2];
    for (size_t i = 0; i < devCount; i++) {
        temp[i] = devices[i];
    }
    delete[] devices;
    devices = temp;
}

const PerifDev* Computer::getDevices() const {
    return devices;
}
