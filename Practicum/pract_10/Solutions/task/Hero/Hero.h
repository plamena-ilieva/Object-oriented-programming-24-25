#pragma once
#include <iostream>

class Hero {
public:

    Hero() = default;
    Hero(const char* name, unsigned hp, unsigned defense);
    Hero(const Hero& other);
    Hero(Hero&& other) noexcept;

    Hero& operator=(const Hero& other);
    Hero& operator=(Hero&& other) noexcept;

    ~Hero();

    void attack(Hero& target);
    void deffend();

    const char* getName() const;
    unsigned getHP() const;
    unsigned getDefense() const;

    void setName(const char* name);
    void setHP(unsigned hp);
    void setDefense(unsigned defense);

protected:
    char* name = nullptr;
    unsigned hp = 0;
    unsigned defense = 0;

private:
    void copyFrom(const Hero& other);
    void moveFrom(Hero&& other);
    void free(); 
};