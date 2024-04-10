#ifndef ADVANCED_BANK_MANAGEMENT_SYSTEM_PERSON_H
#define ADVANCED_BANK_MANAGEMENT_SYSTEM_PERSON_H
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

class User {
private:
    float balance;
    static int accountNumber;
public:
    fstream UsersTextFile;
    ofstream temp;
    string user;
    string pass;
    string accNum;
    string Name;
    string accountType;
    string bal;
    string line;
    bool match = false;
    bool menu = true;
    int ans;
    static int activeAccounts;
    User();
    ~User();
    virtual void login(string userName, string passWord);
    void create();
};

#endif //ADVANCED_BANK_MANAGEMENT_SYSTEM_PERSON_H