#include "StudentsCollection.h"

void StudentsCollection::copyFrom(const StudentsCollection& other)
{
	size = other.size;
	capacity = other.capacity;
	count = other.count;
	firstFreeIndex = other.firstFreeIndex;

	students = new Student * [capacity] {nullptr};

	for (size_t i = 0; i < size; i++)
	{
		if (other.students[i]) {
			students[i] = new Student(*other.students[i]);
		}
		else {
			students[i] = nullptr;
		}
	}
}

void StudentsCollection::moveFrom(StudentsCollection&& other)
{
	students = other.students;

	size = other.size;
	capacity = other.capacity;
	count = other.count;
	firstFreeIndex = other.firstFreeIndex;

	other.students = nullptr;
	other.size = other.capacity = other.count = other.firstFreeIndex = 0;
}

void StudentsCollection::free()
{
	for (size_t i = 0; i < size; i++)
	{
		delete students[i];
	}
	delete[] students;
}

void StudentsCollection::resize(size_t newCap)
{
	capacity = newCap;
	Student** temp = new Student * [capacity];

	for (size_t i = 0; i < size; i++)
	{
		temp[i] = students[i];
	}

	delete[] students;
	students = temp;
}

void StudentsCollection::goToNextFreeIndex()
{
	for (size_t i = firstFreeIndex + 1; i < capacity; i++)
	{
		if (students[i] == nullptr) {
			firstFreeIndex = i;
			return;
		}
	}

	firstFreeIndex = capacity;
}

void StudentsCollection::goToPrevNotFreeIndex()
{
	for (size_t i = size - 1; i >= 0; i--)
	{
		if (students[i] != nullptr) {
			size = i + 1;
			return;
		}
	}

	size = 0;
}

StudentsCollection::StudentsCollection()
{
	capacity = 8;
	size = count = firstFreeIndex = 0;
	students = new Student * [capacity] {nullptr};
}

StudentsCollection::StudentsCollection(const StudentsCollection& other)
{
	copyFrom(other);
}

StudentsCollection& StudentsCollection::operator=(const StudentsCollection& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

StudentsCollection::~StudentsCollection()
{
	free();
}

StudentsCollection::StudentsCollection(StudentsCollection&& other) noexcept
{
	moveFrom(std::move(other));
}

StudentsCollection& StudentsCollection::operator=(StudentsCollection&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

void StudentsCollection::addAtFirstFreeIndex(const Student& st)
{
	if (firstFreeIndex == capacity) {
		resize(capacity * 2);
	}

	students[firstFreeIndex] = new Student(st);
	count++;

	if (firstFreeIndex == size) {
		size++;
	}

	goToNextFreeIndex();
}

void StudentsCollection::addAtFirstFreeIndex(Student&& st)
{
	if (firstFreeIndex == capacity) {
		resize(capacity * 2);
	}

	students[firstFreeIndex] = new Student(std::move(st));
	count++;

	if (firstFreeIndex == size) {
		size++;
	}
	goToNextFreeIndex();
}

void StudentsCollection::setAtIndex(const Student& st, unsigned idx)
{
	if (idx >= capacity) {
		resize(idx);
	}

	if (students[idx] == nullptr) {
		students[idx] = new Student(st);

		if (firstFreeIndex == idx) {
			goToNextFreeIndex();
		}
		if (size < idx) {
			size = idx + 1;
		}
		count++;
	}
	else {
		*students[idx] = st;
	}
}

void StudentsCollection::setAtIndex(Student&& st, unsigned idx)
{
	if (idx >= capacity) {
		resize(idx);
	}

	if (students[idx] == nullptr) {
		students[idx] = new Student(std::move(st));

		if (firstFreeIndex == idx) {
			goToNextFreeIndex();
		}
		if (size < idx) {
			size = idx + 1;
		}
		count++;
	}
	else {
		*students[idx] = std::move(st);
	}
}

void StudentsCollection::removeAtIndex(unsigned idx)
{
	if (idx >= capacity) {
		throw std::out_of_range("index out of range");
	}

	if (students[idx] == nullptr) {
		return;
	}

	delete students[idx];
	students[idx] = nullptr;

	count--;
	if (firstFreeIndex > idx) {
		firstFreeIndex = idx;
	}

	if (idx == size) {
		goToPrevNotFreeIndex();
	}
}

const Student* StudentsCollection::getAtIndex(unsigned idx) const
{
	if (idx >= capacity) {
		throw std::out_of_range("index out of range");
	}
	return students[idx];
}
