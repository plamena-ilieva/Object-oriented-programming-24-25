#include "PremiumPlayer.h"

PremiumPlayer::PremiumPlayer(const PremiumPlayer& other) {
    copyFrom(other);
}

PremiumPlayer::PremiumPlayer(PremiumPlayer&& other) {
    moveFrom(std::move(other));
}

PremiumPlayer& PremiumPlayer::operator=(const PremiumPlayer& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

PremiumPlayer& PremiumPlayer::operator=(PremiumPlayer&& other) {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

PremiumPlayer::~PremiumPlayer() {
    free();
}

void PremiumPlayer::copyFrom(const PremiumPlayer& other) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
}

void PremiumPlayer::moveFrom(PremiumPlayer&& other) {
    name = other.name;
    other.name = nullptr;
}

void PremiumPlayer::free() {
    delete[] name;
    name = nullptr;
}

bool PremiumPlayer::levelUp() {
    if (points >= TWO_STARS) {
        points = 0;
        return true;
    }
    return false;
}