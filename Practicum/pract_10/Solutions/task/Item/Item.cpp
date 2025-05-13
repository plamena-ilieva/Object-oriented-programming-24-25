#include "Item.h"

Item::Item(const char* name, unsigned stat, ItemType type)
        : stat(stat), type(type) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
}

Item::Item(const Item& other) {
    copyFrom(other);
}

Item::Item(Item&& other) {
    moveFrom(std::move(other));
}

Item& Item::operator=(const Item& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

Item& Item::operator=(Item&& other) {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

Item::~Item() {
    free();
}

void Item::copyFrom(const Item& other) {
    stat = other.stat;
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
}

void Item::moveFrom(Item&& other) {
    stat = other.stat;
    other.stat = 0;

    name = other.name;
    other.name = nullptr;
}

void Item::free() {
    stat = 0;
    delete[] name;
    name = nullptr;
}

unsigned Item::getAttack() const {
    return type == ItemType::ATTACK ? stat : 0;
}

unsigned Item::getDeffese() const {
    return type == ItemType::DEFENSE ? stat : 0;
}