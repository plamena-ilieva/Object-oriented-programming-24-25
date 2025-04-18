#include "StringVector.h"

StringVector::StringVector(size_t capacity) : capacity(capacity) {
    vector = new MyString[capacity];
    size = 0;
}

StringVector::StringVector(const StringVector& other) {
    copyFrom(other);
}

StringVector& StringVector::operator=(const StringVector& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

StringVector::~StringVector() {
    free();
}

void StringVector::copyFrom(const StringVector& other) {
    size = other.size;
    capacity = other.capacity;
    vector = new MyString[capacity];

    for (size_t i = 0; i < size; i++) {
        vector[i] = other.vector[i];
    }
}

void StringVector::free() {
    delete[] vector;
    vector = nullptr;
    size = 0;
    capacity = 0;
}

void StringVector::resize() {
    MyString* temp = new MyString[capacity *= 2];
    for (size_t i = 0; i < size; i++) {
        temp[i] = vector[i];
    }
    delete[] vector;
    vector = temp;
}

void StringVector::push_back(const MyString& toAdd) {
    if (size >= capacity) {
        resize();
    }
    vector[size++] = toAdd;
}

void StringVector::pop_back() {
    if (size == 0) {
        throw std::out_of_range("Cannot pop from empty vector.");
    }
    --size;
}

void StringVector::insert(const MyString& toAdd, size_t index) {
    if (index > size) {
        throw std::invalid_argument("Invalid index!");
    }

    if (size >= capacity) {
        resize();
    }

    for (size_t i = size; i > index; --i) {
        vector[i] = vector[i - 1];
    }

    vector[index] = toAdd;
    ++size;
}

void StringVector::erase(size_t index) {
    if (index >= size) {
        throw std::invalid_argument("Invalid index!");
    }

    for (size_t i = index; i < size - 1; ++i) {
        vector[i] = vector[i + 1];
    }

    --size;
}

void StringVector::clear() {
    for (size_t i = 0; i < size; ++i) {
        vector[i] = MyString();
    }
    size = 0;
}

const MyString& StringVector::operator[](size_t index) const {
    if (index >= size) {
        throw std::invalid_argument("Invalid index!");
    }
    return vector[index];
}

MyString& StringVector::operator[](size_t index) {
    if (index >= size) {
        throw std::invalid_argument("Invalid index!");
    }
    return vector[index];
}

bool StringVector::empty() const {
    return size == 0;
}

size_t StringVector::getSize() const {
    return size;
}