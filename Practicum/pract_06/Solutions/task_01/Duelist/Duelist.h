#include "Deck/Deck.h"

class Duelist {

public:
    Duelist() = default;
    Duelist(const char* name);
    Duelist(const Duelist& other);
    Duelist& operator=(const Duelist& other);
    ~Duelist();

    const Deck& getDeck() const;

    void addMonsterCard(const MonsterCard& toAdd);
    void addMagicCard(const MagicCard& toAdd);

    void changeMonsterCard(int index, const MonsterCard& card);
    void changeMonsterCard(int index, const char* name, unsigned atkPoints, unsigned defPoints);

    void changeMagicCard(int index, const MagicCard& card);
    void changeMagicCard(int index, const char* name, const char* effect, Type type);

    void removeMonsterCard(int index);
    void removeMagicCard(int index);

    void sortMonsterCards(bool (*predicate)(const MonsterCard&, const MonsterCard&));

private:
    char* name = nullptr;
    Deck deck;

    void copyFrom(const Duelist& other);
    void free();

};