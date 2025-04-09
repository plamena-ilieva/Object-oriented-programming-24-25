
#include "Nvector.h"

void Nvector::copyFrom(const Nvector& other) {
	vector = new int[other.size];
	size = other.size;

	for (size_t i = 0; i < size; i++) {
		vector[i] = other.vector[i];
	}
}
void Nvector::free() {
	delete[] vector;
	vector = nullptr;

	size = 0;
}

Nvector::Nvector(size_t size) {
	vector = new int[size] {0};
	this->size = size;
}
Nvector::Nvector(const Nvector& other) {
	copyFrom(other);
}
Nvector& Nvector::operator=(const Nvector& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
Nvector::~Nvector() {
	free();
}

Nvector operator+(const Nvector& lhs, const Nvector& rhs) {
	Nvector result(lhs);
	result += rhs;

	return result;
}
Nvector operator-(const Nvector& lhs, const Nvector& rhs) {
	Nvector result(lhs);
	result -= rhs;

	return result;
}

Nvector& Nvector::operator+=(const Nvector& other) {
	if (size == other.size) {
		for (size_t i = 0; i < size; i++) {
			vector[i] += other.vector[i];
		}
	}
	return *this;
}
Nvector& Nvector::operator-=(const Nvector& other) {
	if (size == other.size) {
		for (size_t i = 0; i < size; i++) {
			vector[i] -= other.vector[i];
		}
	}
	return *this;
}

Nvector operator*(const Nvector& vector, size_t scalar) {
	Nvector result(vector);
	result *= scalar;

	return result;
}
Nvector operator*(size_t scalar, const Nvector& vector) {
	return vector * scalar;
}
Nvector& Nvector::operator*=(size_t scalar) {
	for (size_t i = 0; i < size; i++) {
		vector[i] *= scalar;
	}
	return *this;
}

size_t Nvector::getSize() const {
    return size;
}

std::ostream& operator<<(std::ostream& os, const Nvector& vect) {
	for (size_t i = 0; i < vect.size; i++) {
		os << vect[i] << " ";
	}
	return os;
}
std::istream& operator>>(std::istream& is, Nvector& vect) {
	for (size_t i = 0; i < vect.size; i++) {
		is >> vect[i];
	}
	return is;
}

int& Nvector::operator[](size_t index) {
	return vector[index];
}
int Nvector::operator[](size_t index) const {
	return vector[index];
}