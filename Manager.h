#ifndef ADVANCED_BANK_MANAGEMENT_SYSTEM_MANAGER_H
#define ADVANCED_BANK_MANAGEMENT_SYSTEM_MANAGER_H
#include "User.h"
#include "BankAccount.h"

class Manager : public User, public BankAccount {
private:
    //any private?
public:
    bool managerMenu;//private?

    Manager();
    //copy constructor?
    ~Manager();
    int login(string userName, string passWord);
};

#endif //ADVANCED_BANK_MANAGEMENT_SYSTEM_MANAGER_H