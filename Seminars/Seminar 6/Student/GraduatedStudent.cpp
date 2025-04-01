#include "GraduatedStudent.h"
#include <cstring>
#pragma warning (disable : 4996)

void Student::copyFrom(const Student& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	gradesCount = other.gradesCount;
	gradesCapacity = other.gradesCapacity;
	grades = new int[gradesCapacity];
	for (int i = 0; i < other.gradesCount; i++)
		grades[i] = other.grades[i];

	strcpy(quote, other.quote);
}
void Student::free()
{
	delete[] name;
	delete[] grades;

	name = nullptr;
	grades = nullptr;
	gradesCount = 0;
	strcpy(quote, "");
}

void Student::resize()
{
	gradesCapacity *= 2;
	int* temp = new int[gradesCapacity];

	for (size_t i = 0; i < gradesCount; i++)
	{
		temp[i] = grades[i];
	}

	delete[] grades;
	grades = temp;
}

void Student::setGradesToDefault()
{
	gradesCount = 0;
	gradesCapacity = 4;
	grades = new int[gradesCapacity];
}

Student::Student()
{
	setName("");
	setGradesToDefault();
	setQuote("");
}

Student::Student(const char* name, const char* quote)
{
	setName(name);
	setGradesToDefault();
	setQuote(quote);
}
Student::Student(const Student& other)
{
	copyFrom(other);
}

Student& Student::operator=(const Student& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}


Student::~Student()
{
	free();
}

void Student::addGrade(int grade)
{
	if (gradesCount == gradesCapacity) {
		resize();
	}
	grades[gradesCount] = grade;
	gradesCount++;
}


void Student::setName(const char* newName)
{
	if (!newName || newName == name) 
		return;
	delete[] name;
	name = new char[strlen(newName) + 1];
	strcpy(name, newName);
}

void Student::setQuote(const char* newQuote)
{
	if (!newQuote || strlen(newQuote) > QUOTE_SIZE - 1)
		return;
	strcpy(quote, newQuote);
}

const char* Student::getName() const
{
	return name;
}
const int* Student::getGrades() const
{
	return grades;
}

unsigned Student::getGradesCount() const
{
	return gradesCount;
}

const char* Student::getQuote() const
{
	return quote;
}