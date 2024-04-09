<<<<<<< HEAD
#ifndef ADVANCED_BANK_MANAGEMENT_SYSTEM_TRANSACTION_H
#define ADVANCED_BANK_MANAGEMENT_SYSTEM_TRANSACTION_H


class Transaction {

};


#endif //ADVANCED_BANK_MANAGEMENT_SYSTEM_TRANSACTION_H
=======
#pragma once
#include "User.h"

class Transaction
{
private:
public:
	Transaction();
	~Transaction();
	int withdraw(int withdraw_amount);
	int deposit(int deposit_amount);
	void printAccountSummary();
};

>>>>>>> main
