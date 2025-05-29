#include <iostream>
#include <fstream>
#include <cstring>

#pragma warning( disable : 4996)
struct Student
{
	char* name = nullptr;
	int age = 0;
	int fn = 0;

	Student() = default;

	Student(const char* name, int age, int fn) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);

		this->age = age;
		this->fn = fn;
	}

	~Student() {
		delete[] name;
		name = nullptr;
		age = fn = 0;
	}
};

void saveToFile(std::ofstream& outFile, const Student& st)
{
	int nameLen = strlen(st.name);
	outFile.write((const char*)&nameLen, sizeof(int));
	outFile.write(st.name, nameLen + 1);

	outFile.write((const char*)&st.age, sizeof(st.age));
	outFile.write((const char*)&st.fn, sizeof(st.fn));
}

void readFromFile(std::ifstream& inFile, Student& st)
{
	int nameLen;
	inFile.read((char*)&nameLen, sizeof(nameLen));

	delete[] st.name;
	st.name = new char[nameLen + 1];

	inFile.read(st.name, nameLen + 1);

	inFile.read((char*)&st.age, sizeof(st.age));
	inFile.read((char*)&st.fn, sizeof(st.fn));
}

void printStudent(const Student& st)
{
	std::cout << st.name << " " << st.age << " " << st.fn << std::endl;
}

void saveStudentsToFile(std::ofstream& outFile, const Student* st, size_t size)
{
	outFile.write((const char*)&size, sizeof(size));

	for (size_t i = 0; i < size; i++)
		saveToFile(outFile, st[i]);
}

void readStudentsFromFile(std::ifstream& inFile, Student*& st, size_t& size)
{
	inFile.read((char*)&size, sizeof(size));

	st = new Student[size];

	for (size_t i = 0; i < size; i++)
		readFromFile(inFile, st[i]);
}

int main()
{
	std::ofstream outFile("test.dat", std::ios::out | std::ios::binary);
	if (!outFile.is_open())
		return -1;

	Student st[3] = { {"Pesho", 20, 1234 }, {"Gosho", 20, 1235 } , {"Vankata", 20, 1236 } };

	saveStudentsToFile(outFile, st, 3);
	outFile.close();

	std::ifstream inFile("test.dat", std::ios::in | std::ios::binary);
	if (!inFile.is_open())
		return -1;
	Student* st2;
	size_t size;

	readStudentsFromFile(inFile, st2, size);

	for (size_t i = 0; i < size; i++)
		printStudent(st2[i]);

	delete[] st2;
}

