#ifndef ADVANCED_BANK_MANAGEMENT_SYSTEM_PERSON_H
#define ADVANCED_BANK_MANAGEMENT_SYSTEM_PERSON_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class User {
private:
	int balance;
	static int accountNumber;
public:
	fstream UsersTextFile;
	ofstream temp;
	string user;
	string pass;
	string accNum;
	string bal;
	string userName;
	string passWord;
	string line;
	string Name;
	string accountType;
	bool match = false;
	bool menu = true;
	int ans;
	static int activeAccount;
	User();
	~User();
	virtual void login(string userName, string passWord);
	void create();
	//int getBalance();
	//string getName();
	//string getAccountType();
};

#endif //ADVANCED_BANK_MANAGEMENT_SYSTEM_PERSON_H
