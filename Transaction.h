#ifndef TRANSACTION_H
#define TRANSACTION_H

//#include "User.h"
//#include <fstream>
//#include <string>
#include "ValidInput.h"
#include <sstream>

class Transaction {
public:
    double amount;
    static void deposit(const string& userName, double amount, const string& accountType);//why static void instead of void?
    static void withdraw(const string& userName, double amount, const string& accountType);//why use reference?
    static void displayHistory(const string& userName);// why constant?

};

#endif // TRANSACTION_H
