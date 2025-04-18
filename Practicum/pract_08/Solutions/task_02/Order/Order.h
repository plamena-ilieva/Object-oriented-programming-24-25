#pragma once
#include "MyString/MyString.h"

class Order {
	
public:
	Order();
	Order(const Order& other);
	Order& operator=(const Order& other);
	~Order();

	void addProduct(const MyString& prod);
	void addProduct(MyString&& prod);

	size_t orderTime() const;

	const MyString* getProducts() const;
	const MyString& getName() const;
	unsigned getCount() const;

private:
	MyString name;
	unsigned productsCount;
	unsigned productsCapacity;
	MyString* products;

	void free();
	void copyFrom(const Order& other);

	void resize();
};

