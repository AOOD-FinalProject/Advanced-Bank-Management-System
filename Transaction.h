#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "User.h"
#include <fstream>
#include <string>
#include <sstream>

class Transaction {
public:
    static void deposit(const string& userName, double amount);
    static void withdraw(const string& userName, double amount);
    static void displayHistory(const string& userName);

};

#endif // TRANSACTION_H

