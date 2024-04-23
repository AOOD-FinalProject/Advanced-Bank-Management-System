#include "Transaction.h"

/*void Transaction::accountCreated(const string& accountNumber) {
    ifstream userFile("user.txt");
    if (!userFile.is_open()) {
        cout << "Error: Unable to open user file." << endl;
        return;
    }

    string line;
    bool accountFound = false;
    while (getline(userFile, line)) {
        stringstream ss(line);
        string fileLogin, filePassword, fileName, fileAccountType, fileAccountNumber;
        double fileBalance;
        ss >> fileLogin >> filePassword >> fileName >> fileAccountType >> fileBalance >> fileAccountNumber;

        if (fileAccountNumber == accountNumber) {

            ofstream transactionFile("transactions.txt", ios::app);
            if (transactionFile.is_open()) {

                transactionFile << fileAccountType << " type of account is created for user " << fileName << " with starting amount of: " << fileBalance << endl;
                transactionFile.close();
            }
            else {
                cout << "Error: Unable to open transaction file for logging." << endl;
            }

            // Set flag indicating account was found
            accountFound = true;
            break;
        }
    }

    // Close user file
    userFile.close();

    // If account was not found, display error message
    if (!accountFound) {
        cout << "Error: Account number not found." << endl;
    }
}*/


void Transaction::deposit(User& user, double amount) {
    double newBalance = user.getBalance() + amount;
    user.setBalance(newBalance);

    ofstream outFile("transactions.txt", ios::app);
    if (outFile.is_open()) {
        outFile << "Deposit by user " << user.getName() << " (" << user.getAccountNumber() << "): $" << amount << endl;
        outFile.close();
    }
    else {
        cout << "Error: Unable to open transaction file for logging." << endl;
    }

    string line;
    ifstream inFile("user.txt");
    ofstream tempFile("temp.txt");
    if (inFile.is_open() && tempFile.is_open()) {
        while (getline(inFile, line)) {
            stringstream ss(line);
            string fileLogin, filePassword, fileName, fileAccountType, fileAccountNumber;
            double fileBalance;
            ss >> fileLogin >> filePassword >> fileName >> fileAccountType >> fileBalance >> fileAccountNumber;
            if (fileAccountNumber == user.getAccountNumber()) {
                tempFile << fileLogin << " " << filePassword << " " << fileName << " " << fileAccountType << " " << newBalance << " " << fileAccountNumber << endl;
            }
            else {
                tempFile << line << endl;
            }
        }
        inFile.close();
        tempFile.close();

        remove("user.txt");
        rename("temp.txt", "user.txt");
    }
    else {
        cout << "Error: Unable to open user file for updating balance." << endl;
    }
}

void Transaction::withdraw(User& user, double amount) {
    if (amount > user.getBalance()) {
        cout << "Error: Insufficient balance." << endl;
        return;
    }

    double newBalance = user.getBalance() - amount;
    user.setBalance(newBalance);


    ofstream outFile("transactions.txt", ios::app);
    if (outFile.is_open()) {
        outFile << "Withdrawal by user " << user.getName() << " (" << user.getAccountNumber() << "): $" << amount << endl;
        outFile.close();
    }
    else {
        cout << "Error: Unable to open transaction file for logging." << endl;
    }

    string line;
    ifstream inFile("user.txt");
    ofstream tempFile("temp.txt");
    if (inFile.is_open() && tempFile.is_open()) {
        while (getline(inFile, line)) {
            stringstream ss(line);
            string fileLogin, filePassword, fileName, fileAccountType, fileAccountNumber;
            double fileBalance;
            ss >> fileLogin >> filePassword >> fileName >> fileAccountType >> fileBalance >> fileAccountNumber;
            if (fileAccountNumber == user.getAccountNumber()) {

                tempFile << fileLogin << " " << filePassword << " " << fileName << " " << fileAccountType << " " << newBalance << " " << fileAccountNumber << endl;
            }
            else {

                tempFile << line << endl;
            }
        }
        inFile.close();
        tempFile.close();

        remove("user.txt");
        rename("temp.txt", "user.txt");
    }
    else {
        cout << "Error: Unable to open user file for updating balance." << endl;
    }
}

void Transaction::displayHistory(const string& accountNumber) {

    ifstream inFile("transactions.txt");

    if (inFile.is_open()) {
        string line;
        cout << "Transaction History for Account " << accountNumber << ":" << endl;
        while (getline(inFile, line)) {
            if (line.find(accountNumber) != string::npos) {
                cout << line << endl;
            }
        }
        inFile.close();
    }
    else {
        cout << "Error: Unable to open transaction file for reading." << endl;
    }
}

void Transaction::clearHistory() {
    ofstream outFile("transactions.txt", ios::trunc);
    if (!outFile.is_open()) {
        cout << "Error: Unable to open transaction file for clearing." << endl;
    }
    outFile.close();
}