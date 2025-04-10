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

void MyString::resize(unsigned newCap)
{
	char* newData = new char[newCap];
	cap = newCap - 1;
	std::strcpy(newData, data);
	delete[] data;
	data = newData;
}

MyString::MyString(unsigned cap) {
	this->cap = cap;
	data = new char[cap + 1];
	size = 0;
	data[0] = '\0';
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
	cap = calcCapacity(size);
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

unsigned MyString::length() const
{
	return size;
}

const char* MyString::c_str() const
{
	return data;
}

MyString& MyString::operator+=(const MyString& other)
{
	unsigned newSize = size + other.size;
	if (newSize > cap) {
		resize(calcCapacity(newSize));
	}

	size += other.size;
	strcat(data, other.data);
	return *this;
}

char& MyString::operator[](unsigned ind)
{
	return data[ind];
}

char MyString::operator[](unsigned ind) const
{
	return data[ind];
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	size_t cap = calcCapacity(lhs.size + rhs.size);
	MyString res(cap);
	res += lhs;
	res += rhs;
	return res;
}

std::istream& operator>>(std::istream& is, MyString& str)
{
	char buff[1024];
	is.getline(buff, 1024);
	size_t size = strlen(buff);

	if (size > str.size) {
		size_t cap = calcCapacity(size);
		delete[] str.data;
		str.data = new char[cap + 1];
		str.cap = cap;
	}

	strcpy(str.data, buff);
	str.size = size;

	return is;
}

std::ostream& operator<<(std::ostream& os, const MyString& str)
{
	return os << str.c_str();
}

bool operator==(const MyString& lhs, const MyString& rhs)
{
	return std::strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator!=(const MyString& lhs, const MyString& rhs)
{
	return std::strcmp(lhs.c_str(), rhs.c_str()) != 0;
}

bool operator<(const MyString& lhs, const MyString& rhs)
{
	return std::strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator<=(const MyString& lhs, const MyString& rhs)
{
	return std::strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}

bool operator>(const MyString& lhs, const MyString& rhs)
{
	return std::strcmp(lhs.c_str(), rhs.c_str()) > 0;
}

bool operator>=(const MyString& lhs, const MyString& rhs)
{
	return std::strcmp(lhs.c_str(), rhs.c_str()) >= 0;
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

unsigned calcCapacity(unsigned size)
{
	return std::max((int)nextPowerOfTwo(size), 16) - 1;
}