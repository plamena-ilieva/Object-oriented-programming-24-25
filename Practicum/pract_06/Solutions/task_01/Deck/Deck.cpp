#include "Deck.h"

bool Deck::isValidIndex(int index, int max) const {
    return index > 0 && index < max;
}

unsigned Deck::getCurrCountMonsterCards() const {
    return currCountMonsterCards;
}

unsigned Deck::getCurrCountMagicCards() const {
    return currCountMagicCards;
}

void Deck::addMonsterCard(const MonsterCard& toAdd) {
    if (currCountMonsterCards >= DeckConstants::MAX_CARDS) {
        return;
    }
    monsterCards[currCountMonsterCards++] = toAdd;
}

void Deck::addMagicCard(const MagicCard& toAdd) {
    if (currCountMagicCards > DeckConstants::MAX_CARDS) {
        return;
    }
    magicCards[currCountMagicCards++] = toAdd;
}

void Deck::changeMonsterCard(int index, const MonsterCard& card) {
    if (isValidIndex(index, currCountMonsterCards)) {
        monsterCards[index] = card; 
    } 
}

void Deck::changeMonsterCard(int index, const char* name, unsigned atkPoints, unsigned defPoints) {
    MonsterCard cardToChange(name, atkPoints, defPoints);
    changeMonsterCard(index, cardToChange);
}

void Deck::changeMagicCard(int index, const MagicCard& card) {
    if (isValidIndex(index, currCountMagicCards)) {
        magicCards[index] = card;
    }
}

void Deck::changeMagicCard(int index, const char* name, const char* effect, Type type) {
    MagicCard cardToChange(name, effect, type);
    changeMagicCard(index, cardToChange);
}

void Deck::removeMonsterCard(int index) {
    if (currCountMonsterCards <= 0 || !isValidIndex(index, currCountMonsterCards)) {
        return;
    }
    std::swap(monsterCards[index], monsterCards[currCountMonsterCards - 1]);
    currCountMonsterCards--;
}

void Deck::removeMagicCard(int index) {
    if (currCountMagicCards <= 0 || !isValidIndex(index, currCountMagicCards)) {
        return;
    }
    std::swap(magicCards[index], magicCards[currCountMagicCards - 1]);
    currCountMagicCards--;
}

void Deck::sortMonsterCards(bool (*predicate)(const MonsterCard&, const MonsterCard&)) {
    for (unsigned i = 0; i < currCountMonsterCards - 1; i++) {
        unsigned minIndex = i;
        for (unsigned j = i + 1; j < currCountMonsterCards; j++) {
            if (predicate(monsterCards[j], monsterCards[minIndex])) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(monsterCards[i], monsterCards[minIndex]);
        }
    }
}