#pragma once
#include <iostream>
class MyString
{
	char* data;
	unsigned size;
	unsigned cap;

	void copyFrom(const MyString& other);
	void moveFrom(MyString&& other);
	void free();
	void resize(unsigned newCap);

	explicit MyString(unsigned cap);

public:
	MyString();
	MyString(const char* str);
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);

	MyString(MyString&& other) noexcept;
	MyString& operator=(MyString&& other) noexcept;

	~MyString();

	unsigned length() const;
	const char* c_str() const;

	MyString& operator+=(const MyString& other);

	friend MyString operator+(const MyString& lhs, const MyString& rhs);

	char& operator[](unsigned ind);
	char operator[](unsigned ind) const;

	friend std::istream& operator>>(std::istream& is, MyString& lhs);
};

std::ostream& operator<<(std::ostream&, const MyString& lhs);

bool operator==(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);
bool operator<(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
bool operator>=(const MyString& lhs, const MyString& rhs);

unsigned nextPowerOfTwo(unsigned n);
unsigned calcCapacity(unsigned size);
