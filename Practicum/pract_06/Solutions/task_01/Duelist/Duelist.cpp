#include "Duelist.h"

void Duelist::copyFrom(const Duelist& other) {
    int otherNameLen = strlen(other.name);
    name = new char[otherNameLen + 1];
    strcpy(name, other.name);
    
    deck = other.deck;
}

void Duelist::free() {
    if (name) {
        delete[] name;
    }
}

Duelist::Duelist(const char* name) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

Duelist::Duelist(const Duelist& other) {
    copyFrom(other);
}

Duelist& Duelist::operator=(const Duelist& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

Duelist::~Duelist() {
    free();
}

const Deck& Duelist::getDeck() const {
    return deck;
}

void Duelist::addMonsterCard(const MonsterCard& toAdd) {
    deck.addMonsterCard(toAdd);
}

void Duelist::addMagicCard(const MagicCard& toAdd) {
    deck.addMagicCard(toAdd);
}

void Duelist::changeMonsterCard(int index, const MonsterCard& card) {
    deck.changeMonsterCard(index, card);
}

void Duelist::changeMonsterCard(int index, const char* name, unsigned atkPoints, unsigned defPoints) {
    deck.changeMonsterCard(index, name, atkPoints, defPoints);
}

void Duelist::changeMagicCard(int index, const MagicCard& card) {
    deck.changeMagicCard(index, card);
}

void Duelist::changeMagicCard(int index, const char* name, const char* effect, Type type) {
    deck.changeMagicCard(index, name, effect, type);
}

void Duelist::removeMonsterCard(int index) {
    deck.removeMonsterCard(index);
}

void Duelist::removeMagicCard(int index) {
    deck.removeMagicCard(index);
}

void Duelist::sortMonsterCards(bool (*predicate)(const MonsterCard&, const MonsterCard&)) {
    deck.sortMonsterCards(predicate);
}
