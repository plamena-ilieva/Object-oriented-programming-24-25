#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cassert>

#pragma warning(disable : 4996) 

namespace GlobalConstants {
    constexpr int FIELD_MAX_SIZE = 30;
    constexpr int MAX_FIELDS_ROW = 10;
    constexpr int ROWS_MAX_SIZE = 300;
    constexpr int BUFFER_SIZE = 1024;
    constexpr char SEP = ',';
}

struct Field {
    char data[GlobalConstants::FIELD_MAX_SIZE];
};

struct Row {
    Field fields[GlobalConstants::MAX_FIELDS_ROW];
    size_t colsCount = 0;

    void parseRow(const char* rowStr, char separator = GlobalConstants::SEP) {
        std::stringstream ss(rowStr);

        while (!ss.eof()) {
            ss.getline(fields[colsCount].data, GlobalConstants::FIELD_MAX_SIZE, GlobalConstants::SEP);
            colsCount++;
        }
    }
};

class CsvTable {
private:
    Row rows[GlobalConstants::ROWS_MAX_SIZE];
    size_t rowsCount;

public:
    CsvTable() : rowsCount(0) {}

    size_t getRowsCount() const { return rowsCount; }

    bool loadFromFile(std::istream& ifs) {
        char line[GlobalConstants::BUFFER_SIZE];
        while (!ifs.eof()) {
            ifs.getline(line, GlobalConstants::BUFFER_SIZE);
            rows[rowsCount].parseRow(line);
            rowsCount++;
        }
        return true;
    }

    bool loadFromFile(const char* fileName) {
        std::ifstream ifs(fileName);
        if (!ifs.is_open()) {
            return false;
        }
        return loadFromFile(ifs);
    }

    void printTable() const {
        for (size_t i = 0; i < rowsCount; i++) {
            for (size_t j = 0; j < rows[i].colsCount; j++) {
                std::cout << rows[i].fields[j].data << "  ";
            }
            std::cout << std::endl;
        }
    }

    bool saveToFile(std::ostream& ofs) const {
        for (size_t i = 0; i < rowsCount; i++) {
            for (size_t j = 0; j < rows[i].colsCount; j++) {
                ofs << rows[i].fields[j].data;
                if (j != rows[i].colsCount - 1) {
                    ofs << GlobalConstants::SEP;
                }
            }
            ofs << std::endl;
        }
        return true;
    }

    bool saveToFile(const char* fileName) const {
        std::ofstream ofs(fileName);
        if (!ofs.is_open()) {
            return false;
        }
        return saveToFile(ofs);
    }
};

int main() {
    CsvTable myTable;
    if (!myTable.loadFromFile("students.csv")) {
        std::cerr << "Failed to load file!" << std::endl;
        return 1;
    }

    std::cout << "Original Table:" << std::endl;
    myTable.printTable();

    myTable.saveToFile("students_new.csv");

    return 0;
}
