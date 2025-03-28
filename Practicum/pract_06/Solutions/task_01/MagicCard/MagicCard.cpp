#include "MagicCard.h"

MagicCard::MagicCard(const char* name, const char* effect, Type type) {
    setName(name);
    setEffect(effect);
    setType(type);
}

void MagicCard::setName(const char* name) {
    if (!name || strlen(name) > MagicCardConstants::NAME_LEN) {
        return;
    }
    strcpy(this->name, name);
}

void MagicCard::setEffect(const char* effect) {
    if (!effect || strlen(effect) > MagicCardConstants::EFFECT_LEN) {
        return;
    }
    strcpy(this->effect, effect);
}

void MagicCard::setType(Type type) {
    this->type = type;
}

const char* MagicCard::getName() const {
    return name;
}

const char* MagicCard::getEffect() const {
    return effect;
}

Type MagicCard::getType() const {
    return type;
}
