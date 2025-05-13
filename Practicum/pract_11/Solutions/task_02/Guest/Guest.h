#pragma once
#include "Player/Player.h"

const int TIME = 65000; //seconds

class Guest : public Player {

public:
    bool levelUp() override;
    void play() override;

    int getTimeLeft() const;
    bool getCanPlay() const;

private:
    int timeLeft = TIME;
    bool canPlay = true;
};