#include "Player.h"

bool Player::levelUp() {
    Stars currStars = star;
    if (points >= TWO_STARS) {
        star = Stars::TWO;
    }
    if (points >= THREE_STARS) {
        star = Stars::THREE;
    }
    if (points >= FOUR_STARS) {
        star = Stars::FOUR;
    }
    if (points >= FIVE_STARS) {
        star = Stars::FIVE;
    }

    if (currStars == star) {
        return false;
    }
    points = 0;
    return true;
}

void Player::play() {
    points++;
}