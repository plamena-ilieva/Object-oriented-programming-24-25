#include "Sword.h"

Sword::Sword(const char* name, unsigned stat)
        : Item(name, stat, ItemType::ATTACK) {}