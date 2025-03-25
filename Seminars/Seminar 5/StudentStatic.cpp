#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

struct Student
{
	char name[10];
	int age;
	int fn;
};


int main()
{

    std::ofstream outFile("test.dat", std::ios::binary);
    
    if(!outFile.is_open())
        return -1;

    Student st{ "Pesho", 20, 1234 };

    outFile.write((const char*)&st, sizeof(st));
    outFile.close();

    Student st1;
    
    std::ifstream inFile("test.dat", std::ios::binary);
    
    if(!inFile.is_open())
        return -1;

    inFile.read( (char*)&st1, sizeof(st1));

    std::cout << st1.name << " " << st1.age << " " << st1.fn;

}