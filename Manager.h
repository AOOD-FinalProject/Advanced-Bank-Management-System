#ifndef ADVANCED_BANK_MANAGEMENT_SYSTEM_MANAGER_H
#define ADVANCED_BANK_MANAGEMENT_SYSTEM_MANAGER_H
#include "User.h"

class Manager : public User {
private:
	string Name;
	int managerID;
public:
	Manager() {}
	~Manager() = default;
	void login(string userName, string passWord) override;
	void remove(string userName, string passWord);
	void load(string userName, int accountNumber);
};


#endif //ADVANCED_BANK_MANAGEMENT_SYSTEM_MANAGER_H
