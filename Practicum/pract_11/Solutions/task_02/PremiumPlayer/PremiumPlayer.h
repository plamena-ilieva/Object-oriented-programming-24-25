#pragma once
#include "Player/Player.h"

class PremiumPlayer : public Player {

public:
    PremiumPlayer() = default;
    PremiumPlayer(const PremiumPlayer& other);
    PremiumPlayer(PremiumPlayer&& other) noexcept;

    PremiumPlayer& operator=(const PremiumPlayer& other);
    PremiumPlayer& operator=(PremiumPlayer&& other) noexcept;

    ~PremiumPlayer();

    bool levelUp() override;

private:
    char* name = nullptr;

    void copyFrom(const PremiumPlayer& other);
    void moveFrom(PremiumPlayer&& other);
    void free();
};