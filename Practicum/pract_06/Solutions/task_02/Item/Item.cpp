#include "Item.h"

void Item::copyFrom(const Item& other) {
    int otherNameLen = strlen(other.getName());
    name = new char[otherNameLen + 1];
    strcpy(name, other.getName());

    quantity = other.getQuantity();
    price = other.getPrice();
}

void Item::free() {
    if (name) {
        delete[] name;
    }
    quantity = 0;
    price = 0.0;
}

Item::Item(const char* name, int quantity, double price) {
    setName(name);
    setQuantity(quantity);
    setPrice(price);
}

Item::Item(const Item& other) {
    copyFrom(other);
}

Item& Item::operator=(const Item& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

Item::~Item() {
    free();
}

const char* Item::getName() const {
    return name;
}

int Item::getQuantity() const {
    return quantity;
}

double Item::getPrice() const {
    return price;
}

void Item::setName(const char* name) {
    int nameLen = strlen(name);
    if (this->name) {
        delete[] this->name;
        this->name = new char[nameLen + 1];
    }
    strcpy(this->name, name);
}

void Item::setQuantity(int quantity) {
    this->quantity = quantity;
}

void Item::setPrice(double price) {
    this->price = price;
}

void Item::save(std::ofstream& ofs) const {
    if (!ofs.is_open()) {
        return;
    }
    
    ofs << name << " " << quantity << " " << price << std::endl;
}