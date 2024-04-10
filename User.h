#ifndef ADVANCED_BANK_MANAGEMENT_SYSTEM_PERSON_H
#define ADVANCED_BANK_MANAGEMENT_SYSTEM_PERSON_H
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

class User {
private:
	float balance = 0;
	static int accountNumber;
public:
	fstream UsersTextFile;
	ofstream temp;//ADD another text file for accountNumber and activeAccounts?
	string user;
	string pass;
	string accNum;
	string Name;
	string accountType;	
	string bal;
	string line;
	bool match = false;
	bool menu = true;
	int ans = 0;
	static int activeAccounts;//private?
	User();
	//copy constructor?
	~User();
	virtual void login(string userName, string passWord);
	void create();
	//getter and setter?
};

#endif //ADVANCED_BANK_MANAGEMENT_SYSTEM_PERSON_H
