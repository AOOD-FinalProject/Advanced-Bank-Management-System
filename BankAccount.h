#pragma once
#include "User.h"

class BankAccount
{
private:
	int accountNumber;
	string accountType;
	int balance;
	string Name;
	int activeAccount = 0;
public:
	BankAccount();
	~BankAccount();
	BankAccount(string userName, string passWord);
	int withdraw(int withdraw_amount);
	int deposit(int deposit_amount);
	void printAccountSummary();
};

