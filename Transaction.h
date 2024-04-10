#pragma once
#include "User.h"

class Transaction
{
private:
public:
	Transaction();
	//copy constructor?
	~Transaction();

	int withdraw(int withdraw_amount);
	int deposit(int deposit_amount);
	void printAccountSummary();
};

