#include "Hero.h"

Hero::Hero(const char* name, unsigned hp, unsigned defense) {
    setName(name);
    setHP(hp);
    setDefense(defense);
}

Hero::Hero(const Hero& other) {
    copyFrom(other);
}

Hero::Hero(Hero&& other) {
    moveFrom(std::move(other));
}

Hero& Hero::operator=(const Hero& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

Hero& Hero::operator=(Hero&& other) {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

Hero::~Hero() {
    free();
}

void Hero::copyFrom(const Hero& other) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);

    hp = other.hp;
    defense = other.defense;
}

void Hero::moveFrom(Hero&& other) {
    name = other.name;
    other.name = nullptr;

    hp = other.hp;
    other.hp = 0;

    defense = other.defense;
    other.defense = 0;
}

void Hero::free() {
    delete[] name;
    name = nullptr;

    hp = 0;
    defense = 0;
}

void Hero::attack(Hero& target) {
    const int baseDamage = 5;
    if (target.defense <= 0) {
        target.hp -= baseDamage * 100;
        return;
    }

    int realDamage = (baseDamage * 100) / target.defense;
    target.hp -= realDamage;
}

void Hero::deffend() {
    defense += 15;
}

const char* Hero::getName() const {
    return name;
}

unsigned Hero::getHP() const {
    return hp;
}

unsigned Hero::getDefense() const {
    return defense;
}

void Hero::setName(const char* name) {
    if (this->name) {
        delete[] this->name;
    }
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Hero::setHP(unsigned hp) {
    this->hp = hp;
}

void Hero::setDefense(unsigned defense) {
    this->defense = defense;
}