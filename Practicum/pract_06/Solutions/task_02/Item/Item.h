#include <iostream>
#include <fstream>

class Item {
private:
    char* name = nullptr;
    int quantity = 0;
    double price = 0.0;

    void copyFrom(const Item& other);
    void free();

public:
    Item() = default;
    Item(const char* name, int quantity, double price);
    Item(const Item& other);
    ~Item();

    const char* getName() const;
    int getQuantity() const;
    double getPrice() const;

    void setName(const char* name);
    void setQuantity(int quantity);
    void setPrice(double price);

    void save(std::ofstream& ofs) const;
};