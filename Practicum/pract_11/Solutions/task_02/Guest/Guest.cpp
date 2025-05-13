#include "Guest.h"

bool Guest::levelUp() {
    return false;
}

void Guest::play() {
    if (timeLeft <= 0) {
        canPlay = false;
    }
    timeLeft--;
    points++;
}

int Guest::getTimeLeft() const {
    return timeLeft;
}

bool Guest::getCanPlay() const {
    return canPlay;
}