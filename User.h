#ifndef ADVANCED_BANK_MANAGEMENT_SYSTEM_PERSON_H
#define ADVANCED_BANK_MANAGEMENT_SYSTEM_PERSON_H
#include "ValidInput.h"

class User : public ValidInput {
private:
    //any private?
public:
    fstream TextFile;
    fstream UsersTextFile;
    ofstream temp;
    //string use to read file
    string userName, passWord, user;
    bool matches;

    User();
    //copy constructor?
    ~User();
    virtual int login(string userName, string passWord);
    string createUser();
    int userExist(string userName);
    void removeUser(string userName);
};

#endif //ADVANCED_BANK_MANAGEMENT_SYSTEM_PERSON_H