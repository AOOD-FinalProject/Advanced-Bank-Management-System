#include "Transaction.h"

void Transaction::deposit(const string& userName, double amount) {

    ifstream bankAccountsFile("BankAccounts.txt");
    ofstream tempFile("temp.txt");

    if (!bankAccountsFile || !tempFile) {
        cout << "Error: Unable to open file." << endl;
        return;
    }

    string line;
    bool userFound = false;

    while (getline(bankAccountsFile, line)) {
        string userID, Name, accNum, accountType, bal;
        istringstream iss(line);
        getline(iss, userID, ';');
        getline(iss, Name, ';');
        getline(iss, accNum, ';');
        getline(iss, accountType, ';');
        getline(iss, bal);

        if (userID == userName) {
            double currentBalance = stod(bal);
            currentBalance += amount;
            tempFile << userID << ";" << Name << ";" << accNum << ";" << accountType << ";" << fixed << setprecision(2) << currentBalance << endl;
            userFound = true;

            ofstream outFile("transactions.txt", ios::app);
            if (outFile.is_open()) {
                outFile << "Deposite by user " << userID << " (" << accNum << "): $" << amount << ". Current balance is: " << fixed << setprecision(2) << currentBalance << endl;
                outFile.close();
            }
            else {
                cout << "Error: Unable to open transaction file for logging." << endl;
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
        cout << "Error: User not found." << endl;
        remove("temp.txt");
    }
}

void Transaction::withdraw(const string& userName, double amount) {

    ifstream bankAccountsFile("BankAccounts.txt");
    ofstream tempFile("temp.txt");

    if (!bankAccountsFile || !tempFile) {
        cout << "Error: Unable to open file." << endl;
        return;
    }

    string line;
    bool userFound = false;

    while (getline(bankAccountsFile, line)) {
        string userID, Name, accNum, accountType, bal;
        istringstream iss(line);
        getline(iss, userID, ';');
        getline(iss, Name, ';');
        getline(iss, accNum, ';');
        getline(iss, accountType, ';');
        getline(iss, bal);

        if (userID == userName) {
            double currentBalance = stod(bal); //string to double
            currentBalance -= amount;
            tempFile << userID << ";" << Name << ";" << accNum << ";" << accountType << ";" << fixed << setprecision(2) << currentBalance << endl;
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
        cout << "Error: User not found." << endl;
        remove("temp.txt");
    }
}

void Transaction::displayHistory(const string& userName) {

    ifstream inFile("transactions.txt");

    if (inFile.is_open()) {
        string line;
        cout << "Transaction History for Account " << userName << ":" << endl;
        while (getline(inFile, line)) {
            /* cout << "Debug: Read line: " << line << endl;
             cout << "Debug: Searching for user: " << userName << endl;*/
            if (line.find(userName) != string::npos) {
                //    cout << "Debug: Found matching transaction for user " << userName << ": " << line << endl;
                cout << line << endl;
            }


        }
        inFile.close();
    }
    else {
        cout << "Error: Unable to open transaction file for reading." << endl;
    }
}