#pragma once

constexpr size_t QUOTE_SIZE = 32;
class Student
{
	char* name = nullptr;
	int* grades = nullptr;
	size_t gradesCount = 0;
	size_t gradesCapacity = 0;
	char quote[QUOTE_SIZE] = "";

	void copyFrom(const Student& other);
	void free();
	void resize();

	void setGradesToDefault();

public:
	Student();
	Student(const char* name, const char* quote);

	Student(const Student& other);
	Student& operator=(const Student& other);
	~Student();

	void addGrade(int grade);

	void setName(const char* newName);
	void setQuote(const char* quote);

	const char* getName() const;
	const int* getGrades() const;
	unsigned getGradesCount() const;
	const char* getQuote() const;
};