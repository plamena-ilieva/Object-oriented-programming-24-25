#include "Shield.h"

Shield::Shield(const char* name, unsigned stat)
        : Item(name, stat, ItemType::DEFENSE) {}