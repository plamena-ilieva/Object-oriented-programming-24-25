#pragma once
#include <iostream>

enum class ItemType {
    ATTACK,
    DEFENSE,
    UNDEF
};

class Item {

public:
    Item() = default;
    Item(const char* name, unsigned stat, ItemType type);
    Item(const Item& other);
    Item(Item&& other) noexcept;

    Item& operator=(const Item& other);
    Item& operator=(Item&& other) noexcept;

    ~Item();

    unsigned getDeffese() const;
    unsigned getAttack() const;

private:
    unsigned stat = 0;
    char* name = nullptr;
    ItemType type = ItemType::UNDEF;

    void copyFrom(const Item& other);
    void moveFrom(Item&& other);
    void free();
};