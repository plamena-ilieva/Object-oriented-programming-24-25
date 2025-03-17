#include <iostream>
#include <fstream>

constexpr int BUFF_SIZE = 1024;

bool copyFile(const char* source, const char* dest) {
    std::ifstream inFile(source);
    if (!inFile.is_open()) {
        return false;
    }
    std::ofstream outFile(dest);
    if (!outFile.is_open()) {
        return false;
    }

    while (!inFile.eof()) {
        char buff[BUFF_SIZE];
        inFile.getline(buff, BUFF_SIZE);

        outFile << buff << std::endl;
    }

    inFile.close();
    outFile.close();
    return true;
}

int main()
{
    std::cout << copyFile("file.txt", "newfile.txt");
}