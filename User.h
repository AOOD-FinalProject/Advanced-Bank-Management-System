#ifndef ADVANCED_BANK_MANAGEMENT_SYSTEM_PERSON_H
#define ADVANCED_BANK_MANAGEMENT_SYSTEM_PERSON_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "BankAccount.h"

class User {
private:
	string Name;
	int userID;
public:
	User() {}
	~User() {}
	virtual void login(string userName, string passWord);
	void create(string userName, string passWord);

};

#endif //ADVANCED_BANK_MANAGEMENT_SYSTEM_PERSON_H
