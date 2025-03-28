#include "Item/Item.h"

class ShoppingCart {
private:
    Item* items = nullptr;
    int currentCount = 0;
    int capacity = 0;

    void copyFrom(const ShoppingCart& other);
    void free();

    void resize();
    int find(const char* name) const;

public:
    ShoppingCart() = default;
    ShoppingCart(int capacity);
    ShoppingCart(const ShoppingCart& other);
    ShoppingCart& operator=(const ShoppingCart& other);
    ~ShoppingCart();

    bool addItem(const Item& toAdd);
    bool removeItem(const char* name);
    int getCurrentCount() const;
    bool exists(const char* itemName) const;
    bool isEmpty() const;
    double getPriceOf(const char* itemName) const;
    double totalPrice() const;
    void sortByName();
    void save(std::ofstream& ofs) const;
};