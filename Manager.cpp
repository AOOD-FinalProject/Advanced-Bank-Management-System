#include "Manager.h"

//constructor and deconstructor
Manager::Manager() {}
Manager::~Manager() {}

//function for manager login
void Manager::login(string userName, string passWord) {
    match = false;
    //open text file
    ManagerTextFile.open("Managers.txt");

    //fail to open file
    if (!ManagerTextFile) {
        cout << "No such file found.\n" << endl;
    }

    //open file successfully
    //validate Username and Password with Username and Password in text file
    else {
        while (getline(ManagerTextFile, user, ';'), getline(ManagerTextFile, pass)) {
            if (user == userName && pass == passWord) {//continue if Username and Password matches with Username and Password in text file
                cout << "Manager successfully login.\n" << endl;
                match = true;
                //close text file
                ManagerTextFile.close();
            }
        }
        if (match == false){//return to menu if Username and Password does not matches with Username and Password in text file
            cout << "Manager login fail.\n" << endl;
            //close text file
            ManagerTextFile.close();
            return;
        }
    }

    //if Username and Password matches with Username and Password in text file
    //prompt manager login welcome page
    do {
        cout << "Welcome Manager: " << userName << endl;
        cout << "1. Remove User" << endl;
        cout << "2. Load Account" << endl;
        cout << "3. Show Number of Active Accounts" << endl;
        cout << "4. Exit\n" << endl;
        cin >> ans;

        //case base on input
        switch (ans) {
            //remove account case
        case 1:
            cout << "Enter Account Username: " << endl;
            cin >> user;
            cout << "Enter Account Number: " << endl;
            cin >> accNum;
            removeAccount(user, accNum);
            break;
            //load user account case
        case 2:
            cout << "Enter Account Username: " << endl;
            cin >> user;
            cout << "Enter Account Number: " << endl;
            cin >> accNum;
            loadAccount(user, accNum);
            break;
            //show number of active accounts case
        case 3:
            cout << "Number of Active Accounts: " << activeAccounts << "\n" << endl;
            break;
            //exit case
        case 4:
            cout << "Returning to menu.\n" << endl;
            return;
            //default case
        default:
            //clear error input due to input type doesn't match and ignore input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please enter a number between 1 and 4.\n" << endl;
        }
    } while (menu == true);
}

//function for manager to remove user
void Manager::removeAccount(string userName, string accountNumber) {
    match = false;
    //open text file
    UsersTextFile.open("Users.txt");
    temp.open("temp.txt");

    //fail to open file
    if (!UsersTextFile || !temp) {
        cout << "No such file found.\n" << endl;
    }

    //open file successfully
    //validate Username and accountNumber with Username and accountNumber in text file and remove account accordingly
    else {
        while (getline(UsersTextFile, user, ';'), getline(UsersTextFile, pass, ';'), getline(UsersTextFile,accNum, ';'), getline(UsersTextFile, line)) {
            if (user == userName && accNum == accountNumber) {//if account matches, don't write to temp text file and decrease activeAccounts
                activeAccounts--;
                cout << "Remove account successfully.\n" << "Numbers of Active Accounts: " << activeAccounts << "\n" << endl;
                match = true;
            } 
            else {//write any accounts that doesn't match to temp text file
                temp << user << ';' << pass << ';' << accNum << ';' << line << endl;
            }
        }
        if (match == false) {//no account matches
            cout << "Remove account fail.\n" << endl;
        }
    }

    //close text file
    UsersTextFile.close();
    temp.close();

    //remove old Users.txt file and rename temp to new Users.txt file
    remove("Users.txt");
    if (rename("temp.txt", "Users.txt") == -1) {
        cout << "Rename file failed." << endl;
    }
}

//function to load user's bank account
void Manager::loadAccount(string userName, string accountNumber) {
    match = false;
    //open text file
    UsersTextFile.open("Users.txt");

    //fail to open file
    if (!UsersTextFile) {
        cout << "No such file found.\n" << endl;
    }

    //open file successfully
    //validate Username and accountNumber with Username and accountNumber in text file and load account accordingly
    else {
        while (getline(UsersTextFile, user, ';'), getline(UsersTextFile, pass, ';'), getline(UsersTextFile, accNum, ';'), getline(UsersTextFile, Name, ';'), getline(UsersTextFile, accountType, ';'), getline(UsersTextFile, bal)) {
            if (user == userName && accNum == accountNumber) {//continue if account found
                cout << "Bank account successfully access.\n" << endl;
                match = true;
                //close text file
                UsersTextFile.close();
                break;
            }
        }
        if (match == false) {//return to manager menu if account was not found
            cout << "Fail to access bank account.\n" << endl;
            //close text file
            UsersTextFile.close();
            return;
        }
    }

    //do while loop to load user's bank information and ask what to do with user's bank account
    do {
        cout << userName << "'s Bank Account" << endl;
        cout << "---------------------------" << endl;
        cout << "Name: " << Name << endl;
        cout << "Account Number: " << accNum << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: " << bal << endl;
        cout << "---------------------------" << endl;
        cout << "1. Withdraw" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Account Summary" << endl;
        cout << "4. Exit" << endl;
        cin >> ans;

        //case base on input
        switch (ans) {
            //withdraw case
        case 1:
            cout << endl;
            break;
            //deposit case
        case 2:
            cout << endl;
            break;
            //account summary case
        case 3: 
            cout << endl;
            break;
            //exit case
        case 4:
            cout << "Returning to manager menu.\n" << endl;
            return;
            //default case
        default:
            //clear error input due to input type doesn't match and ignore input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please enter a number between 1 and 4.\n" << endl;
        }
    } while (menu == true);
}
