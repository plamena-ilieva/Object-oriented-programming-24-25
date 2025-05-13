#pragma once
#include "Hero/Hero.h"
#include "Item/Item.h"

class Warrior : public Hero {

public:

    Warrior(const char* name, int hp, int deffense, unsigned attack, const Item& item);

    void attack(Hero& traget);
    void deffend();

private:
    unsigned attackPower = 0;
    Item item;
    bool isDefending = false;
};