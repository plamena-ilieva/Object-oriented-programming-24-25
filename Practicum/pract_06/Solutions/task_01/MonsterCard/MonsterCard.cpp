#include "MonsterCard.h"

void MonsterCard::copyFrom(const MonsterCard& other) {
    int otherNameLen = strlen(other.getName());
    name = new char[otherNameLen + 1]; // because of '\0'
    strcpy(name, other.getName());

    atkPoints = other.getAtkPoints();
    defPoints = other.getDefPoints();
}

void MonsterCard::free() {
    if (name) {
        delete[] name;
    }

    atkPoints = 0;
    defPoints = 0;
}

MonsterCard::MonsterCard(const char* name, unsigned atkPoints, unsigned defPoints) {
    setName(name);
    setAtkPoints(atkPoints);
    setDefPoints(defPoints);
}

MonsterCard::MonsterCard(const MonsterCard& other) {
    copyFrom(other);
}

MonsterCard& MonsterCard::operator=(const MonsterCard& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

MonsterCard::~MonsterCard() {
    free();
}

void MonsterCard::setName(const char* name) {
    int nameLen = strlen(name);
    if (this->name) {
        delete[] this->name;
        this->name = new char[nameLen];
    }
    strcpy(this->name, name);
}

void MonsterCard::setAtkPoints(unsigned atkPoints) {
    this->atkPoints = atkPoints;
}

void MonsterCard::setDefPoints(unsigned defPoints) {
    this->defPoints = defPoints;
}

const char* MonsterCard::getName() const {
    return name;
}

unsigned MonsterCard::getAtkPoints() const {
    return atkPoints;
}

unsigned MonsterCard::getDefPoints() const {
    return defPoints;
}