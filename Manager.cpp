#include "Manager.h"

Manager::Manager() {}
Manager::~Manager() {}

//function for manager login
void Manager::login(string userName, string passWord) {
    //open text file
    ManagerTextFile.open("Managers.txt");

    //fail to open file
    if (!ManagerTextFile) {
        cout << "No such file found.\n" << endl;
    }

    //open file successfully
    //validate Username and Password with Username and Password in text file
    else {
        while (getline(ManagerTextFile, user, ';'), getline(ManagerTextFile, pass))
        {
            if (user == userName && pass == passWord)
            {
                cout << "Manager successfully login.\n" << endl;
                match = true;
            }
        }
        if (match == false)
        {
            cout << "Manager login fail.\n" << endl;
            ManagerTextFile.close();
            return;
        }
    }

    //close text file
    ManagerTextFile.close();

    //manager login welcome page
    do {
        cout << "Welcome Manager: " << userName << endl;
        cout << "1. Remove User" << endl;
        cout << "2. Load Account" << endl;
        cout << "3. Exit\n" << endl;
        cin >> ans;

        //case base on input
        switch (ans) {
            //remove account case
        case 1:
            cout << "Enter Account Username: " << endl;
            cin >> user;
            cout << "Enter Account Number: " << endl;
            cin >> ans;
            removeAccount(user, ans);
            break;
            //load user account case
        case 2:
            cout << "Enter Account Username: " << endl;
            cin >> user;
            cout << "Enter Account Number: " << endl;
            cin >> ans;
            loadAccount(user, ans);
            break;
            //exit case
        case 3:
            cout << "Returning to menu.\n" << endl;
            return;
            //default case
        default:
            cout << "Invalid choice. Please enter a number between 1 and 3.\n" << endl;
        }
        //prevent infinite loop when characters are entered instead of integer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (0 < ans < 4 && menu == true);
}

//function for manager to remove user
void Manager::removeAccount(string userName, int accountNumber) {
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
        while (getline(UsersTextFile, user, ';'), getline(UsersTextFile, pass, ';'), getline(UsersTextFile,accNum, ';'), getline(UsersTextFile, line))
        {
            if (user == userName && accNum == to_string(accountNumber))
            {
                activeAccount -= 1;
                cout << "Remove account successfully.\n" << "Numbers of Active Accounts: " << activeAccount << "\n" << endl;
                match = true;
            } 
            else 
            {
                temp << user << ';' << pass << ';' << accNum << ';' << line << endl;
            }
        }
        if (match == false)
        {
            cout << "Remove account fail.\n" << endl;
        }
    }

    //close text file
    UsersTextFile.close();
    temp.close();

    //remove old Users.txt file and rename temp to new Users.txt file
    remove("Users.txt");
    rename("temp.txt", "Users.txt");
}

//function to load user's bank account
void Manager::loadAccount(string userName, int accountNumber) {
    match = false;
    //open text file
    UsersTextFile.open("Users.txt");

    //fail to open file
    if (!UsersTextFile) {
        cout << "No such file found.\n" << endl;
    }

    //open file successfully
    //validate Username and accountNumber with Username and accountNumber in text file and remove account accordingly
    else {
        while (getline(UsersTextFile, user, ';'), getline(UsersTextFile, pass, ';'), getline(UsersTextFile, accNum, ';'), getline(UsersTextFile, Name, ';'), getline(UsersTextFile, accountType, ';'), getline(UsersTextFile, bal))
        {
            if (user == userName && accNum == to_string(accountNumber))
            {
                cout << "Bank account successfully access.\n" << endl;
                match = true;
                break;
            }
        }
        if (match == false)
        {
            cout << "Fail to access bank account.\n" << endl;
            UsersTextFile.close();
            return;
        }
    }

    //close text file
    UsersTextFile.close();

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
        cout << "3. Exit" << endl;
        cin >> ans;

        //case base on input
        switch (ans) {
            //remove account case
        case 1:
            cout << endl;
            break;
        case 2:
            cout << endl;
            break;
        case 3:
            cout << "Returning to manager menu.\n" << endl;
            return;
            //default case
        default:
            cout << "Invalid choice. Please enter a number between 1 and 3.\n" << endl;
        }
        //prevent infinite loop when characters are entered instead of integer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (0 < ans < 5 && menu == true);
}
