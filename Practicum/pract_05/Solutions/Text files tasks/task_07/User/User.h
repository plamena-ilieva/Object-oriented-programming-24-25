#include <iostream>
#include <fstream>

const constexpr int MAX_USER_FIELD_LENGTH = 129;

struct User {
private:
    char name[MAX_USER_FIELD_LENGTH];
    char username[MAX_USER_FIELD_LENGTH];
    char password[MAX_USER_FIELD_LENGTH];

public:
    void writeUserToFile(std::ofstream& ofs) const;

    void readUserFromFile(std::ifstream& ifs);
};