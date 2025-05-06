#include "Student.h"

Student::Student(const char* name, int age, size_t fn) : Person(name, age)
{
	setFn(fn);
}

size_t Student::getFn() const
{
	return fn;
}

void Student::setFn(size_t fn)
{

	if (fn < 100)
		fn = 100;
	this->fn = fn;
}
