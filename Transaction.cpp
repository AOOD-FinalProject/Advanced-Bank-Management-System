#include "Transaction.h"
#include <iostream> // Added for cout
#include <fstream> // Added for file operations
#include <sstream> // Added for stringstream
#include <iomanip> // Added for setprecision

using namespace std; // Added for convenience

void Transaction::deposit(const string& userName, double amount) {
    ifstream bankAccountsFile("BankAccounts.txt");
    ofstream tempFile("temp.txt");

    if (!bankAccountsFile || !tempFile) {
        cout << "Error: Unable to open file." << endl;
        return;
    }

    string line;
    bool userFound = false;
    int chsvans;

    cout << "1 for Checking, 2 for Saving" << endl;
    cin >> chsvans;

    // Checking option
    switch (chsvans) {
        case 1:
            while (getline(bankAccountsFile, line)) {
                string userID, Name, accNum, accountType, bal;
                istringstream iss(line);
                getline(iss, userID, ';');
                getline(iss, Name, ';');
                getline(iss, accNum, ';');
                getline(iss, accountType, ';');
                getline(iss, bal);

                if (accountType == "Checking") {
                    double currentBalance = stod(bal);
                    currentBalance += amount;
                    tempFile << userID << ";" << Name << ";" << accNum << ";" << accountType << ";" << fixed
                             << setprecision(2) << currentBalance << endl;
                    userFound = true;

                    ofstream outFile("transactions.txt", ios::app);
                    if (outFile.is_open()) {
                        outFile << "Deposit by user " << userID << " (Account Number: " << accNum << " ): $" << amount
                                << ". Current balance is: " << fixed << setprecision(2) << currentBalance << endl;
                        outFile.close();
                    } else {
                        cout << "Error: Unable to open transaction file for logging." << endl;
                    }
                } else {
                    tempFile << line << endl;
                }
            }

            bankAccountsFile.close();
            tempFile.close();

            if (userFound) {
                if (remove("BankAccounts.txt") != 0) {
                    cout << "Error: Unable to remove file." << endl;
                    return;
                }
                if (rename("temp.txt", "BankAccounts.txt") != 0) {
                    cout << "Error: Unable to rename file." << endl;
                    return;
                }
            } else {
                cout << "Error: User not found." << endl;
                remove("temp.txt");
            }
            break;

            // Savings option
        case 2:
            while (getline(bankAccountsFile, line)) {
                string userID, Name, accNum, accountType, bal;
                istringstream iss(line);
                getline(iss, userID, ';');
                getline(iss, Name, ';');
                getline(iss, accNum, ';');
                getline(iss, accountType, ';');
                getline(iss, bal);

                if (accountType == "Saving") {
                    double currentBalance = stod(bal);
                    currentBalance += amount;
                    tempFile << userID << ";" << Name << ";" << accNum << ";" << accountType << ";" << fixed
                             << setprecision(2) << currentBalance << endl;
                    userFound = true;

                    ofstream outFile("transactions.txt", ios::app);
                    if (outFile.is_open()) {
                        outFile << "Deposit by user " << userID << " (Account Number: " << accNum << " ): $" << amount
                                << ". Current balance is: " << fixed << setprecision(2) << currentBalance << endl;
                        outFile.close();
                    } else {
                        cout << "Error: Unable to open transaction file for logging." << endl;
                    }
                } else {
                    tempFile << line << endl;
                }
            }
            bankAccountsFile.close();
            tempFile.close();

            if (userFound) {
                if (remove("BankAccounts.txt") != 0) {
                    cout << "Error: Unable to remove file." << endl;
                    return;
                }
                if (rename("temp.txt", "BankAccounts.txt") != 0) {
                    cout << "Error: Unable to rename file." << endl;
                    return;
                }
            } else {
                cout << "Error: User not found." << endl;
                remove("temp.txt");
            }
    }
}

void Transaction::withdraw(const string& userName, double amount, const string& accountType) {
    ifstream bankAccountsFile("BankAccounts.txt");
    ofstream tempFile("temp.txt");

    if (!bankAccountsFile || !tempFile) {
        cout << "Error: Unable to open file." << endl;
        return;
    }

    string line;
    bool userFound = false;

    while (getline(bankAccountsFile, line)) {
        string userID, Name, accNum, accType, bal;
        istringstream iss(line);
        getline(iss, userID, ';');
        getline(iss, Name, ';');
        getline(iss, accNum, ';');
        getline(iss, accType, ';');
        getline(iss, bal);

        double currentBalanceCheck = stod(bal); // string to double
        bool overdrawCheck = false;
        if (userID == userName && accType == accountType) {
            if (amount > currentBalanceCheck) {
                cout << "Error: Withdraw amount is greater than the current account balance." << endl;
                overdrawCheck = true;
            }

            if (!overdrawCheck) {
                double currentBalance = stod(bal); // string to double
                currentBalance -= amount;
                tempFile << userID << ";" << Name << ";" << accNum << ";" << accType << ";" << fixed << setprecision(2) << currentBalance << endl;
                userFound = true;

                ofstream outFile("transactions.txt", ios::app);
                if (outFile.is_open()) {
                    outFile << "Withdrawal by user " << userID << " (" << accNum << "): $" << amount <<". Current balance is: " << fixed << setprecision(2) << currentBalance << endl;
                    outFile.close();
                }
                else {
                    cout << "Error: Unable to open transaction file for logging." << endl;
                }
            }
        }
        else {
            tempFile << line << endl;
        }
    }

    bankAccountsFile.close();
    tempFile.close();

    if (userFound) {
        if (remove("BankAccounts.txt") != 0) {
            cout << "Error: Unable to remove file." << endl;
            return;
        }
        if (rename("temp.txt", "BankAccounts.txt") != 0) {
            cout << "Error: Unable to rename file." << endl;
            return;
        }
    }
    else {
        cout << "Error: User or account type not found." << endl;
        remove("temp.txt");
    }
}


void Transaction::displayHistory(const string& userName) {
    ifstream inFile("transactions.txt");

    if (inFile.is_open()) {
        string line;
        cout << "Transaction History for Account " << userName << ":" << endl;
        while (getline(inFile, line)) {
            if (line.find(userName) != string::npos) {
                cout << line << endl;
            }
        }
        inFile.close();
    }
    else {
        cout << "Error: Unable to open transaction file for reading." << endl;
    }
}
