#include "LoggedUser.h"

LoggedUser::LoggedUser(int id, const char* password) {
    this->id = id;
    setPassword(password);
}

bool LoggedUser::log(int id, const char* password) const {
    if (this->id != id || strcmp(this->password, password) != 0) {
        return false;
    }
    return true;
}

void LoggedUser::setPassword(const char* password) {
    if (!password) {
        return;
    }

    if (strlen(password) > PASS_LEN) {
        return;
    }

    strcpy(this->password, password);
}