#include "Staff.h"

Staff::Staff(unsigned manaCost, int power, SpellType type)
    : manaCost(manaCost), power(power), type(type) {}

unsigned Staff::getManaCost() const {
    return manaCost;
}

int Staff::applyEffect(const Hero& target) const {
    if (type == SpellType::HEAL)
        return power;
    else
        return -power;
}