#include <iostream>
#include <fstream>

size_t getFileSize(std::ifstream& ifs) {
    if (!ifs.is_open()) {
        return 0;
    }
    size_t currentPos = ifs.tellg();
    ifs.seekg(0, std::ios::end);
    size_t fileSize = ifs.tellg();
    ifs.seekg(currentPos, std::ios::beg);
    return fileSize;
}