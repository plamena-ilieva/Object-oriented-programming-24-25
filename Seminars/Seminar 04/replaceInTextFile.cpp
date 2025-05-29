#include <iostream>
#include <fstream>
using namespace std;

void replaceInFile(char ch, char ch2, fstream& file)
{
	while (!file.eof()) {
		char curr = file.get();
		if (curr == ch) {
			file.seekg(-1, std::ios::cur);
			file.put(ch2);
			file.flush();
		}
	}
}

int main()
{
	fstream file("test.txt", ios::in | ios::out);


	if (!file.is_open())
	{
		std::cout << "Error while opening the file!" << std::endl;
		return -1;
	}

	replaceInFile('a', 'X', file);
	return 0;
}