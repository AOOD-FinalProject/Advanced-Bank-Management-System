#include "BankAccount.h"

//initialize static integers
int BankAccount::accountNumber = 0;
int BankAccount::activeAccounts = 0;

//constructor and deconstructor
BankAccount::BankAccount() { 
    AccNumActAccTextFile.open("AccNumActAcc.txt");
    //fail to open file
    if (!AccNumActAccTextFile) {
        cout << "No such file found.\n" << endl;
    }
    //open file successfully
    else {
        AccNumActAccTextFile >> accountNumber;
        AccNumActAccTextFile >> activeAccounts;
    }
    //close the file
    AccNumActAccTextFile.close();
    bankAccountMenu = true;
}

BankAccount::~BankAccount() {}

//function for load bank info
void BankAccount::loadBankAccount(string userName) {
    do {
        myVector.clear();
        currentUserAccounts = 0;
        //open text file
        BankAccountsTextFile.open("BankAccounts.txt");

        //fail to open file
        if (!BankAccountsTextFile) {
            cout << "No such file found.\n" << endl;
            return;
        }

        //open file successfully
        //validate Username with Username in text file and load accounts accordingly
        else {
            while (getline(BankAccountsTextFile, userID, ';'), getline(BankAccountsTextFile, Name, ';'), getline(BankAccountsTextFile, accNum, ';'), getline(BankAccountsTextFile, accountType, ';'), getline(BankAccountsTextFile, bal)) {
                if (userID == userName) {
                    currentUserAccounts++;
                    myVector.push_back(userID);
                    myVector.push_back(Name);
                    myVector.push_back(accNum);
                    myVector.push_back(accountType);
                    myVector.push_back(bal);
                }
            }
        }

        //close file
        BankAccountsTextFile.close();

        //display bank account info according to the numbers of bank accounts the user have
        cout << userName << "'s Bank Account" << endl;
        cout << "---------------------------" << endl;
        if (currentUserAccounts == 0) {
            cout << "No accounts exist for this user." << endl;
        }
        else if (currentUserAccounts == 1) {
            cout << "Name: " << myVector[1] << endl;
            cout << "Account Number: " << myVector[2] << endl;
            cout << "Account Type: " << myVector[3] << endl;
            cout << "Balance: $" << myVector[4] << endl;
        }
        else {
            cout << "Name: " << myVector[1] << endl;
            cout << "Account Number: " << myVector[2] << endl;
            cout << "Account Type: " << myVector[3] << endl;
            cout << "Balance: $" << myVector[4] << endl;
            cout << "Account Number: " << myVector[7] << endl;
            cout << "Account Type: " << myVector[8] << endl;
            cout << "Balance: $" << myVector[9] << endl;
        }
        cout << "---------------------------" << endl;
        cout << "1. Add Account" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. Account Summary" << endl;
        cout << "5. Exit\n" << endl;
        cin >> ans;
        
        //case base on input
        switch (ans) {
            //add account case
        case 1:
            if (currentUserAccounts == 2) {
                cout << "User already have both a checking and saving accounts.\n" << endl;
            }
            else { addAccount(userName); }
            break;
            //withdraw case
        case 2:
            break;
            //deposit case
        case 3:
            break;
            //account summary case
        case 4:
            break;
            //exit case
        case 5:
            //optional?
            /*if (managerMenu = true) {
                cout << "Returning to manager menu.\n" << endl;
                bankAccountMenu = false;
                return;
            }*/
            cout << "Returning to menu.\n" << endl;
            return;
            //default case
        default:
            //clear error input due to input type doesn't match and ignore input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please enter a number between 1 and 4.\n" << endl;
        }
    } while (bankAccountMenu == true);
}

//function to add bank account
void BankAccount::addAccount(string userName) {
    //enter in account type
    do {
        //valid input check
        do {
            cout << "Enter Account Type:" << endl;
            cin >> accountType;
            if (accountType != "Checking" && accountType != "Saving") {
                cout << "Enter only Checking or Saving. Try again.\n" << endl;
            }
        } while (accountType != "Checking" && accountType != "Saving");

        //check to see if accountType already exist
        accountExist = false;
        BankAccountsTextFile.open("BankAccounts.txt");
        if (!BankAccountsTextFile) {
            cout << "No such file found.\n" << endl;
            return;
        }
        else {
            while (getline(BankAccountsTextFile, userID, ';'), getline(BankAccountsTextFile, Name, ';'), getline(BankAccountsTextFile, accNum, ';'), getline(BankAccountsTextFile, line, ';'), getline(BankAccountsTextFile, bal)) {
                if (userID == userName && line == accountType) {
                    cout << "Account type already exist. Try again.\n" << endl;
                    BankAccountsTextFile.close();
                    accountExist = true;
                    break;
                }
            }
        }
        BankAccountsTextFile.close();
    } while (accountExist == true);

    //enter in name
    if (currentUserAccounts == 0) {
        do {
            cout << "Enter Name:" << endl;
            cin >> Name;
        } while (!isAlphaNumeric(Name));
    }
    else {
        Name = myVector[1];
    }

    //enter in balance
    do {
        cout << "Enter Balance:" << endl;
        cin >> balance;
    } while (!isTwoDecimalPlaces(balance));

    //give a bank account number and increase active account
    accountNumber++;
    activeAccounts++;
    cout << "Account Number: " << accountNumber << endl;

    //append all info to file
    //open text file
    BankAccountsTextFile.open("BankAccounts.txt", ios::app);
    AccNumActAccTextFile.open("AccNumActAcc.txt", ios::out);
    //fail to open file
    if (!BankAccountsTextFile && !AccNumActAccTextFile) {
        cout << "No such file found.\n" << endl;
    }
    //open file successfully
    else {
        //write to the file
        BankAccountsTextFile << userName << ";" << Name << ";" << accountNumber << ";" << accountType << ";" << fixed << setprecision(2) << balance << endl;
        AccNumActAccTextFile << accountNumber << endl << activeAccounts << endl;
        cout << "Bank account successfully created.\n" << endl;
    }
    //close the file
    BankAccountsTextFile.close();
    AccNumActAccTextFile.close();
}

//getter function for activeAccounts
int BankAccount::getActiveAccounts() {
    return activeAccounts;
}

//setter function for activeAccounts
void BankAccount::setActiveAccounts(int accAct) {
    activeAccounts = accAct;
}

//getter function for accountNumber
int BankAccount::getAccountNumber() {
    return accountNumber;
}

//setter function for accountNumber
void BankAccount::setAccountNumber(int number) {
    accountNumber = number;
}

//function for manager to remove bank account
void BankAccount::removeBankAccount(string userName, string accountNumber) {
    accountExist = false;
    //open text file
    BankAccountsTextFile.open("BankAccounts.txt");
    AccNumActAccTextFile.open("AccNumActAcc.txt");
    temp.open("temp.txt");

    //fail to open file
    if (!BankAccountsTextFile && !temp && !AccNumActAccTextFile) {
        cout << "No such file found.\n" << endl;
        return;
    }

    //open file successfully
    //validate Username and accountNumber with Username and accountNumber in text file and remove account accordingly
   
    else {
        AccNumActAccTextFile >> actAcc;
        AccNumActAccTextFile >> activeAccounts;
        AccNumActAccTextFile.close();
        AccNumActAccTextFile.open("AccNumActAcc.txt", ios::out);
        while (getline(BankAccountsTextFile, userID, ';'), getline(BankAccountsTextFile, Name, ';'), getline(BankAccountsTextFile, accNum, ';'), getline(BankAccountsTextFile, line)) {
            if (userID == userName && accNum == accountNumber) {//if account match, don't write to temp text file and decrease activeAccounts
                activeAccounts--;
                cout << "Remove account successfully.\n" << "Numbers of Active Accounts: " << activeAccounts << "\n" << endl;
                AccNumActAccTextFile << actAcc << endl;
                AccNumActAccTextFile << activeAccounts << endl;
                accountExist = true;
            }
            else {//write any accounts that doesn't match to temp text file
                temp << userID << ';' << Name << ';' << accNum << ';' << line << endl;
            }
        }
        if (accountExist == false) {//no account remove
            cout << "Remove account fail.\n" << endl;
        }
    }

    //close text file
    BankAccountsTextFile.close();
    AccNumActAccTextFile.close();
    temp.close();

    //remove old Users.txt file and rename temp to new Users.txt file
    remove("BankAccounts.txt");
    if (rename("temp.txt", "BankAccounts.txt") == -1) {
        cout << "Rename file failed." << endl;
    }
    return;
}