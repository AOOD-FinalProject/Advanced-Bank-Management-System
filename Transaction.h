#pragma once
#include "ValidInput.h"

class Transaction
{
private:
public:
	fstream TransactionsTextFile;

	Transaction();
	//copy constructor?
	~Transaction();
	int withdraw(int withdraw_amount);
	int deposit(int deposit_amount);
	void printAccountSummary();
};

