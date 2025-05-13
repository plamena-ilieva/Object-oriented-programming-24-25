#pragma once
#include <iostream>

const int TWO_STARS = 256;
const int THREE_STARS = 512;
const int FOUR_STARS = 1024;
const int FIVE_STARS = 2048;

enum class Stars {
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE
};

class Player {
public:
    virtual bool levelUp();
    virtual void play();

protected:
    int id = 0;
    int points = 1;
    Stars star = Stars::ONE;
};