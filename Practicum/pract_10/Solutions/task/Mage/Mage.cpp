#include "Mage.h"

Mage::Mage(const char* name, unsigned hp, unsigned defense, unsigned mana, const Staff& staff)
    : Hero(name, hp, defense), mana(mana), staff(staff) {}

void Mage::castSpell(Hero& target) {
    unsigned cost = staff.getManaCost();
    if (mana < cost) {
        std::cout << "Not enough mana to cast the spell!\n";
        return;
    }

    int effect = staff.applyEffect(target);
    target.setHP(target.getHP() + effect);

    if (target.getHP() < 0)
        target.setHP(0);

    mana -= cost;
}

void Mage::deffend() {
    mana += hp;
}
