#include <iostream>
#include <fstream>

#include "User/User.h"

const constexpr int MAX_USERS = 100;

struct System {
public:
    void writeSystemToFile(std::ofstream& ofs) const;
    
    void readSystemFromFile(std::ifstream& ifs);
    
private:
    int size;
    User users[MAX_USERS];
};
