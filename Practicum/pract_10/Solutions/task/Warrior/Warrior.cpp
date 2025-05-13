#include "Warrior.h"
#include <iostream>

Warrior::Warrior(const char* name, int hp, int deffense, unsigned attack, const Item& item)
    : Hero(name, hp, deffense), attackPower(attack), item(item) {}

void Warrior::attack(Hero& target) {
    int totalAttack = attackPower + item.getAttack();

    int realDamage = (totalAttack * 100) / target.getDefense();

    target.setDefense(target.getHP() - realDamage);

    if (isDefending) {
        defense /= 2;
        isDefending = false;
    }
}

void Warrior::deffend() {
    if (!isDefending) {
        defense *= 2;
        isDefending = true;
    }
}
