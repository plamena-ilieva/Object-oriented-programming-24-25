#pragma once
#include "Hero/Hero.h"
#include "Item/Item.h"
#include "Staff/Staff.h"

class Mage : public Hero {

public:
    Mage(const char* name, unsigned hp, unsigned defense, unsigned mana, const Staff& staff);

    void castSpell(Hero& target);
    void deffend();

private:
    unsigned mana = 0;
    Staff staff;
};