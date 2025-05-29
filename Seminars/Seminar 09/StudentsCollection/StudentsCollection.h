#pragma once
#include "Student.h"

class StudentsCollection {
	Student** students;
	size_t count = 0;
	size_t capacity;

	size_t size = 0;
	size_t firstFreeIndex = 0;

	void copyFrom(const StudentsCollection& other);
	void moveFrom(StudentsCollection&& other);
	void free();
	void resize(size_t newCap);

	void goToNextFreeIndex();
	void goToPrevNotFreeIndex();
public:
	StudentsCollection();

	StudentsCollection(const StudentsCollection& other);
	StudentsCollection& operator=(const StudentsCollection& other);

	~StudentsCollection();

	StudentsCollection(StudentsCollection&& other) noexcept;
	StudentsCollection& operator=(StudentsCollection&& other) noexcept;

	void addAtFirstFreeIndex(const Student& st);
	void addAtFirstFreeIndex(Student&& st);

	void setAtIndex(const Student& st, unsigned idx);
	void setAtIndex(Student&& st, unsigned idx);

	void removeAtIndex(unsigned idx);
	const Student* getAtIndex(unsigned idx) const;
};
