#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "User.h"
#include <fstream>
#include <string>

class Transaction {
public:
    static void deposit(User& user, double amount);
    static void withdraw(User& user, double amount);
    static void displayHistory(const string& accountNumber);
    // static void accountCreated(const string& accountNumber);
    static void clearHistory();
};

#endif // TRANSACTION_H
