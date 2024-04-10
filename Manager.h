#ifndef ADVANCED_BANK_MANAGEMENT_SYSTEM_MANAGER_H
#define ADVANCED_BANK_MANAGEMENT_SYSTEM_MANAGER_H
#include "User.h"

class Manager : public User {
private:
	string Name;
	int managerID;
public:
	Manager() {}
	~Manager() {}
	void login(string& userName, string& passWord);
	void remove(string userName, string passWord);
	void load(string userName, int accountNumber);

    void getMLogin();
};


#endif //ADVANCED_BANK_MANAGEMENT_SYSTEM_MANAGER_H
