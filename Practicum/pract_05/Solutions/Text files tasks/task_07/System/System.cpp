#include "System/System.h"

void System::writeSystemToFile(std::ofstream& ofs) const {
    if (!ofs.is_open()) {
        return;
    }

    ofs << size << std::endl;
    for (int i = 0; i < size; ++i) {
        users[i].writeUserToFile(ofs);
    }
}

void System::readSystemFromFile(std::ifstream& ifs) {
    if (!ifs.is_open()) {
        return;
    }

    ifs >> size;
    for (int i = 0; i < size; ++i) {
        users[i].readUserFromFile(ifs);
    }
}