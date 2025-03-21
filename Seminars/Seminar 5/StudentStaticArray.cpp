#include <iostream>
#include <fstream>
#include <cstring>

struct Student
{
	char name[10];
	int age;
	int fn;
};

size_t getFileSize(std::ifstream& inFile)
{
	size_t currPos = inFile.tellg();
	inFile.seekg(0, std::ios::end);
	size_t size = inFile.tellg();
	inFile.seekg(currPos);

	return size;
}

int main()
{	
	std::ofstream outFile("test.dat", std::ios::binary);

	if (!outFile.is_open())
	{
		std::cout << "Error while opening the file!" << std::endl;
		return -1;
	}

	constexpr size_t size = 3;
	Student st[3] = { {"Pesho", 20, 1234 }, {"Gosho", 20, 1235 } , {"Vankata", 20, 1236 } };
	outFile.write((const char*)st, sizeof(Student)*size);
	outFile.close();

	std::ifstream inFile("test.dat", std::ios::binary);

	if (!inFile.is_open())
	{
		std::cout << "Error while opening the file!" << std::endl;
		return -1;
	}

	size_t sizeOfFile = getFileSize(inFile);
	size_t count = sizeOfFile / sizeof(Student);
	Student* st2 = new Student[count];
	inFile.read((char*)st2, sizeOfFile);

	for (int i = 0; i < count; i++)
		std::cout << "Name: " << st2[i].name << ", age: " << st2[i].age << ", fn: " << st2[i].fn << std::endl;

	delete[] st2;

	return 0;
}