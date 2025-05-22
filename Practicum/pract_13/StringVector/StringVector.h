#include <exception>
#include "MyString/MyString.h"

class StringVector {

public:
    StringVector() = default;
    StringVector(size_t capacity);
    StringVector(const StringVector& other);
    StringVector& operator=(const StringVector& other);
    ~StringVector();

    void push_back(const MyString& toAdd);
    void pop_back();
    void insert(const MyString& toAdd, size_t index);
    void erase(size_t index);
    void clear();

    const MyString& operator[](size_t index) const;
    MyString& operator[](size_t index);

    bool empty() const;
    size_t getSize() const;

private:
    MyString* vector = nullptr;
    size_t size = 0;
    size_t capacity = 0;

    void copyFrom(const StringVector& other);
    void free();

    void resize();
};