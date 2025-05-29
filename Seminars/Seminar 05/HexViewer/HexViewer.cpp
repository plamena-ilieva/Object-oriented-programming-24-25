#include <iostream>
#include <fstream>
#include <iomanip>

#include "HexViewer.h"

bool isValid(char ch) {
	return ch >= 'a' && ch <= 'z' ||
		ch >= 'A' && ch <= 'Z' ||
		ch >= '0' && ch <= '9';
}

size_t getFileSize(std::ifstream& inFile) {
	size_t currPos = inFile.tellg();
	inFile.seekg(0, std::ios::end);
	size_t size = inFile.tellg();
	inFile.seekg(currPos);

	return size;
}

HexViewer::HexViewer(const char* fileName)
{
	std::ifstream ifs(fileName, std::ios::in | std::ios::binary);

	if (!ifs.is_open())
	{
		return;
	}

	size = getFileSize(ifs);
	data = new unsigned char[size];
	ifs.read((char*)data, size);
}

void HexViewer::print() const
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)data[i] << " ";
	}

	std::cout << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		char ch = data[i];
		if (isValid(data[i])) {
			std::cout << data[i] << ' ';
		}
		else {
			std::cout << ".. ";
		}
	}
}

HexViewer::~HexViewer()
{
	delete[] data;
}
