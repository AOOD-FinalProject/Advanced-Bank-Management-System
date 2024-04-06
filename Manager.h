#ifndef ADVANCED_BANK_MANAGEMENT_SYSTEM_MANAGER_H
#define ADVANCED_BANK_MANAGEMENT_SYSTEM_MANAGER_H
#include "User.h"

class Manager : public User {
private:
	string Name;
public:
	fstream ManagerTextFile;
	Manager();
	~Manager();
	void login(string userName, string passWord);
	void removeAccount(string userName, int accountNumber);
	void loadAccount(string userName, int accountNumber);

};


#endif //ADVANCED_BANK_MANAGEMENT_SYSTEM_MANAGER_H
