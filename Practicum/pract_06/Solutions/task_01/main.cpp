#include "Duelist/Duelist.h"

bool compareByAtkPoints(const MonsterCard& first, const MonsterCard& second) {
    return first.getAtkPoints() > second.getAtkPoints();
}

int main() {
    Duelist yugioh("Yugioh");

    yugioh.addMonsterCard(MonsterCard("Dark Magician", 2500, 2100));
    yugioh.addMonsterCard(MonsterCard("Summoned Skull", 2500, 1200));
    yugioh.addMonsterCard(MonsterCard("Celtic Guardian", 1400, 1200));

    yugioh.sortMonsterCards(compareByAtkPoints);
}