#ifndef ADVANCED_BANK_MANAGEMENT_SYSTEM_MANAGER_H
#define ADVANCED_BANK_MANAGEMENT_SYSTEM_MANAGER_H
#include "User.h"
#include "BankAccount.h"

//can manager be subclass of 2 class?
class Manager : public User, public BankAccount {
private:
	//any private?
	int aN;
	int aA;
public:
	bool managerMenu;//private?

	Manager();
	//copy constructor?
	~Manager();
	int login(string userName, string passWord);
};

#endif //ADVANCED_BANK_MANAGEMENT_SYSTEM_MANAGER_H
