#include <iostream>

class MonsterCard {
public:
    MonsterCard(const char* name, unsigned atkPoints, unsigned defPoints);

    MonsterCard() = default;
    MonsterCard(const MonsterCard& other);
    MonsterCard& operator=(const MonsterCard& other);
    ~MonsterCard();

    void setName(const char* name);
    void setAtkPoints(unsigned atkPoints);
    void setDefPoints(unsigned defPoints);

    const char* getName() const;
    unsigned getAtkPoints() const;
    unsigned getDefPoints() const;

private:
    char* name = nullptr;
    unsigned atkPoints = 0;
    unsigned defPoints = 0;

    void copyFrom(const MonsterCard& other);
    void free();

};