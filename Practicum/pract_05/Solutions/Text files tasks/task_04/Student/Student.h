#include <iostream>
#include <fstream>


namespace StudentConstants {
    const int STR_SIZE = 17;
    const int FN_INIT_VAL = 0;
    const double GRADE_INIT_VAL = 0.0;
    const int FN_LENGTH = 5;
    const char FILE_NAME[] = "file.txt";

    namespace HairColorConstants {
        const char BLONDE[] = "blonde";
        const char BROWN[] = "brown";
        const char DARK[] = "dark";
        const char RED[] = "red";
        const char UNDEFINED[] = "undefined";
    }
}

namespace StudentUtil {
    int getNumLen(int num) {
        int len = 0;
        while (num) {
            len++;
            num /= 10;
        }
        return len;
    }
}

enum class HairColor {
    Blonde, Brown, Dark, Red, Undefined
};

class Student {
    char firstName[StudentConstants::STR_SIZE] = "";
    char lastName[StudentConstants::STR_SIZE] = "";
    int fn = StudentConstants::FN_INIT_VAL;
    double averageGrade = StudentConstants::GRADE_INIT_VAL;
    HairColor hairColor = HairColor::Undefined;

    bool isValidName(const char* name) const;
    bool isValidFn(int fn) const;

public:
    Student() = default;
    Student(const char* firstName, const char* lastName, int fn, double averageGrade, HairColor HairColor);
    Student(const char* firstName, const char* lastName, int fn, double averageGrade, const char* hairColor);

    const char* getFirstName() const;
    const char* getLastName() const;
    int getFn() const;
    double getAverageGrade() const;
    const char* getHairColor() const;

    void setFirstName(const char* firstName);
    void setLastName(const char* lastName);
    void setFn(int fn);
    void setAverageGrade(double averageGrade);
    void setHairColor(const char* hairColor);
    void setHairColor(HairColor hairColor);

    void save();
    void save(const char* fileName);
    void save(std::ofstream& ofs);

    void load();
    void load(const char* fileName);
    void load(std::ifstream& ifs); 

    void print() const;
};