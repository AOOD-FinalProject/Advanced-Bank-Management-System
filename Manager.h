#ifndef ADVANCED_BANK_MANAGEMENT_SYSTEM_MANAGER_H
#define ADVANCED_BANK_MANAGEMENT_SYSTEM_MANAGER_H
#include "User.h"

class Manager : public User {
private:
public:
    fstream ManagerTextFile;
    Manager();
    ~Manager();
    void login(string userName, string passWord);
    void removeAccount(string userName, string accountNumber);
    void loadAccount(string userName, string accountNumber);

};


#endif //ADVANCED_BANK_MANAGEMENT_SYSTEM_MANAGER_H