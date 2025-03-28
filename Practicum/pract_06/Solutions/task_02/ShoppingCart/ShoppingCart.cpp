#include "ShoppingCart.h"
#pragma warning (disable : 4996)

void ShoppingCart::copyFrom(const ShoppingCart& other) {
    currentCount = other.currentCount;
    capacity = other.capacity;

    items = new Item[capacity];

    for (int i = 0; i < currentCount; i++) {
        items[i] = other.items[i];
    }
}

void ShoppingCart::free() {
    if (items) {
        delete[] items;
        items = nullptr;
    }
    currentCount = 0;
    capacity = 0;
}

void ShoppingCart::resize() {
    Item* temp = new Item[capacity *= 2];
    for (int i = 0; i < currentCount; i++) {
        temp[i] = items[i];
    }
    delete[] items;
    items = temp;
}

int ShoppingCart::find(const char* name) const {
    for (int i = 0; i < currentCount; i++) {
        if (strcmp(items[i].getName(), name) == 0) {
            return i;
        }
    }
    return -1;
}

ShoppingCart::ShoppingCart(int capacity) {
    this->capacity = capacity;
    this->currentCount = 0;

    this->items = new Item[capacity];
}

ShoppingCart::ShoppingCart(const ShoppingCart& other) {
    copyFrom(other);
}

ShoppingCart& ShoppingCart::operator=(const ShoppingCart& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

ShoppingCart::~ShoppingCart() {
    free();
}

bool ShoppingCart::addItem(const Item& toAdd) {
    if (find(toAdd.getName()) == -1) {
        return false;
    }
    if (currentCount == capacity) {
        resize();
    }
    items[currentCount++] = toAdd;
    return true;
}

bool ShoppingCart::removeItem(const char* name) {
    int elemIndex = find(name);
    if (currentCount == 0 || elemIndex == -1) {
        return false;
    }
    std::swap(items[elemIndex], items[currentCount - 1]);
    currentCount--;
}

int ShoppingCart::getCurrentCount() const {
    return currentCount;
}

bool ShoppingCart::exists(const char* itemName) const {
    if (find(itemName) != -1) {
        return true;
    }
    return false;
}

bool ShoppingCart::isEmpty() const {
    return currentCount == 0;
}

double ShoppingCart::getPriceOf(const char* itemName) const {
    int elemIndex = find(itemName);
    if (elemIndex != -1) {
        return items[elemIndex].getPrice();
    }
    return 0.0;
}

double ShoppingCart::totalPrice() const {
    double total = 0.0;
    for (int i = 0; i < currentCount; i++) {
        total += items[i].getPrice();
    }
    return total;
}

void ShoppingCart::sortByName() {
    if (currentCount < 2) {
        return;
    }

    for (int i = 0; i < currentCount - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < currentCount; j++) {
            if (strcmp(items[j].getName(), items[minIndex].getName()) < 0) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(items[i], items[minIndex]);
        }
    }
}

void ShoppingCart::save(std::ofstream& ofs) const {
    if (!ofs.is_open()) {
        return;
    }
    ofs << currentCount << std::endl;

    for (int i = 0; i < currentCount; i++) {
        items[i].save(ofs);
    }
}
