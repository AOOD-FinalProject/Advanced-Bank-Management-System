#include "User.h"

//keep here or move?
//function to take only letters and numbers as input
bool isAlphaNumeric(string input) {
    for (char c : input) {
        if (!isalnum(c)) {
            cout << "Enter only letters and numbers. Try again.\n" << endl;
            return false;
        }
    }
    return true;
}

//initialize static integers
int User::accountNumber;
int User::activeAccounts;

//constructor and deconstructor
User::User() { 
    int ans = 0; 
    float balance = 0; 
}
User::~User() {}

//function for user login
void User::login(string userName, string passWord) {
    match = false;
    //open text file
    UsersTextFile.open("Users.txt");

    //fail to open file
    if (!UsersTextFile) {
        cout << "No such file found.\n" << endl;
        return;
    }

    //open file successfully
    //validate Username and Password with Username and Password in text file
    else {
        while (getline(UsersTextFile, user, ';'), getline(UsersTextFile, pass, ';'), getline(UsersTextFile, accNum, ';'), getline(UsersTextFile, Name, ';'), getline(UsersTextFile, accountType, ';'), getline(UsersTextFile, bal)) {
            if (user == userName && pass == passWord) {//continue if Username and Password matches with Username and Password in text file
                cout << "User successfully login.\n" << endl;
                match = true;
                //close the file
                UsersTextFile.close();
                break;
            }
        }
        if (match == false) {//return to menu if Username and Password does not matches with Username and Password in text file
            cout << "User login fail.\n" << endl;
            //close the file
            UsersTextFile.close();
            return;
        }
    }

    //if Username and Password matches with Username and Password in text file
    //prompt user login welcome page
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
        cout << "4. Exit\n" << endl;
        cin >> ans;

        //case base on input
        switch (ans) {
            //withdraw case
        case 1:             
            break;
            //deposit case
        case 2:
            break;
            //account summary case
        case 3:
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

//function to create user login
void User::create() {
    //enter in Username
    do { 
        //check to see if user enter only letters and numbers
        do { 
            cout << "Enter Username: " << endl;
            cin >> user;
        } while (!isAlphaNumeric(user)); 

        //check to see if Username is already in text file
        match = false;
        UsersTextFile.open("Users.txt");
        while (getline(UsersTextFile, line, ';'),getline(UsersTextFile, pass)) {
            if (user == line) {
                cout << "Username already in use. Try again.\n" << endl;
                match = true;
            }
        }
        UsersTextFile.close();
    } while (match == true);

    //enter in Password
    do {
        cout << "Enter Password: " << endl;
        cin >> pass;
    } while (!isAlphaNumeric(pass));

    //enter in name
    do {
        cout << "Enter Name:" << endl;
        cin >> Name;
    } while (!isAlphaNumeric(Name));

    //enter in account type
    do {
        cout << "Enter Account Type:" << endl;
        cin >> accountType;
        if (accountType != "Checking" && accountType != "Saving") {
            cout << "Enter only Checking or Saving. Try again.\n" << endl;
        }
    } while (accountType != "Checking" && accountType != "Saving");

    //enter in balance
    do {
        cout << "Enter Balance:" << endl;
        cin >> balance;
        //clear error input due to input type doesn't match and ignore input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (0 >= balance) {
            cout << "Enter a number greater than 0. Try again.\n" << endl;
        }
    } while (0 >= balance);

    //give a bank account number and increase active account
    accountNumber++;
    activeAccounts++;
    cout << "Account Number: " << accountNumber << endl;

    //append all info to file
    //open text file
    UsersTextFile.open("Users.txt", ios::app);
    //fail to open file
    if (!UsersTextFile) {
    cout << "No such file found.\n" << endl;
    }
    //open file successfully
    else {
        //write to the file
        UsersTextFile << user << ";" << pass << ";" << accountNumber << ";" << Name << ";" << accountType << ";" << balance << endl;
        cout << "User successfully created.\n" << endl;
    }
    //close the file
    UsersTextFile.close();
}