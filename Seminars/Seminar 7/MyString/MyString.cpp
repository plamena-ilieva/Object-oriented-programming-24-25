#include "MyString.h"
#include <cstring>
#include <cmath>
#pragma warning (disable : 4996)

void MyString::copyFrom(const MyString& other)
{
	size = other.size;
	cap = other.cap;
	data = new char[cap + 1];
	strcpy(data, other.data);
}

void MyString::free()
{
	delete[] data;
	data = nullptr;
	size = cap = 0;
}

MyString::MyString() : MyString("")
{
}

MyString::MyString(const char* str)
{
	if (str == nullptr) {
		size = 0;
		cap = 15;
		data = new char[cap + 1];
		strcpy(data, "");
		return;
	}
	size = strlen(str);
	cap = std::max((int)nextPowerOfTwo(size), 16) - 1;
	data = new char[cap + 1];
	strcpy(data, str);
}

MyString::MyString(const MyString& other)
{
	copyFrom(other);
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

MyString::~MyString()
{
	free();
}

unsigned MyString::lenght() const
{
	return size;
}

const char* MyString::c_str() const
{
	return data;
}

MyString& MyString::operator+=(const MyString& other)
{
	if (size + other.size <= cap) {
		size += other.size;
		strcat(data, other.data);
		return *this;
	}

	size += other.size;
	cap = nextPowerOfTwo(size) - 1;
	char* buff = new char[cap + 1];
	strcpy(buff, data);
	strcat(buff, other.data);

	delete[] data;
	data = buff;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const MyString& str)
{
	return os << str.c_str();
}

unsigned nextPowerOfTwo(unsigned n)
{
	unsigned step = 1;

	while ((n >> step) > 0) {
		n |= n >> step;
		step <<= 1;
	}

	return n + 1;
}