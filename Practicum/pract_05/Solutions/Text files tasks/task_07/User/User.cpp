#include "User.h"

void User::writeUserToFile(std::ofstream& ofs) const {
    if (!ofs.is_open()) {
        return;
    }

    ofs << name << ' ' << username << ' ' << password << std::endl;
}

void User::readUserFromFile(std::ifstream& ifs) {
    if (!ifs.is_open()) {
        return;
    }

    ifs >> name >> username >> password;
}