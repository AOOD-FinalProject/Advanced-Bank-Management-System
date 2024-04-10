#pragma once
#include "User.h"

class BankAccount{
private:
	float balance;
	static int accountNumber;
	static int activeAccounts;
public:
	fstream BankAccountsTextFile;
	fstream AccNumActAccTextFile;//ADD another text file for accountNumber and activeAccounts?
	ofstream temp;
	//string use to read file
	string userID, Name, accNum, accountType, bal, line;
	//use for bank account menu //private?
	bool bankAccountMenu;
	int currentUserAccounts;
	int ans;
	//use for adding and removing accounts
	bool accountExist;
	//vector use to store accounts //private?
	vector<string> myVector;

	BankAccount();
	//copy constructor?
	~BankAccount();
	void loadBankAccount(string userName);
	void removeBankAccount(string userName, string passWord);
	void addAccount(string userName);
	int getActiveAccounts();
	void setActiveAccounts(int accAct);
};

