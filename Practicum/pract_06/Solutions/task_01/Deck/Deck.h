#include "MonsterCard/MonsterCard.h"
#include "MagicCard/MagicCard.h"

namespace DeckConstants {
    const int MAX_CARDS = 20;
}

class Deck {
private:
    MonsterCard monsterCards[DeckConstants::MAX_CARDS];
    MagicCard magicCards[DeckConstants::MAX_CARDS];

    unsigned currCountMonsterCards = 0;
    unsigned currCountMagicCards = 0;

    bool isValidIndex(int index, int max) const;

public:
    unsigned getCurrCountMonsterCards() const;
    unsigned getCurrCountMagicCards() const;

    void addMonsterCard(const MonsterCard& toAdd);
    void addMagicCard(const MagicCard& toAdd);

    void changeMonsterCard(int index, const MonsterCard& card);
    void changeMonsterCard(int index, const char* name, unsigned atkPoints, unsigned defPoints);

    void changeMagicCard(int index, const MagicCard& card);
    void changeMagicCard(int index, const char* name, const char* effect, Type type);

    void removeMonsterCard(int index);
    void removeMagicCard(int index);

    void sortMonsterCards(bool (*predicate)(const MonsterCard&, const MonsterCard&));
};