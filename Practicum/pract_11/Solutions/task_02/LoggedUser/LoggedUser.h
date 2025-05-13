#pragma once
#include "Player/Player.h"

const int PASS_LEN = 8;

class LoggedUser : public Player{
public:
    LoggedUser(int id, const char* password);

    bool log(int id, const char* password) const;

    void setPassword(const char* password);

private:
    char password[PASS_LEN + 1] = ""; // for the '\0'
};