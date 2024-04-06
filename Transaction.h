#pragma once
#include "User.h"

class Transaction
{
private:
	int accountNumber;
	string accountType;
	int balance;
	string Name;
public:
	Transaction();
	~Transaction();
	int withdraw(int withdraw_amount);
	int deposit(int deposit_amount);
	void printAccountSummary();
};

