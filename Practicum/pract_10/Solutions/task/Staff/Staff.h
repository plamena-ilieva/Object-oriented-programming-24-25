#pragma once
#include "Hero/Hero.h"

enum class SpellType {
    HEAL,
    DAMAGE,
    UNDEF
};

class Staff {

public:
    Staff(unsigned manaCost, int power, SpellType type);

    unsigned getManaCost() const;

    int applyEffect(const Hero& target) const;

private:
    unsigned manaCost = 0;
    int power = 0;
    SpellType type = SpellType::UNDEF;
};