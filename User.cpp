#include "User.h"

int User::accountNumber;
int User::activeAccount;

User::User(){}
User::~User(){}

//function for user login
void User::login(string userName, string passWord) {
    //open text file
    UsersTextFile.open("Users.txt");

    //fail to open file
    if (!UsersTextFile) {
        cout << "No such file found.\n" << endl;
    }

    //open file successfully
    //validate Username and Password with Username and Password in text file
    else {
        while (getline(UsersTextFile, user, ';'), getline(UsersTextFile, pass, ';'), getline(UsersTextFile, line))
        {
            if (user == userName && pass == passWord)
            {
                cout << "User successfully login.\n" << endl;
                match = true;
            }
        }
        if (match == false)
        {
            cout << "User login fail.\n" << endl;
            return;
        }
    }

    //close the file
    UsersTextFile.close();

    //user login welcome page
    do {
        cout << "Welcome User: " << userName << endl;
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
            cout << "Invalid choice. Please enter a number between 1 and 3.\n" << endl;
        }
        //prevent infinite loop when characters are entered instead of integer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (0 < ans < 4 && menu == true);
}

//function to create user login
void User::create() {
    //enter in Username and Password
    do {    //check to see if Username is already in text file
        match = false;
        cout << "Enter Username: " << endl;
        cin >> userName;
        UsersTextFile.open("Users.txt");
        while (getline(UsersTextFile, user, ';'),getline(UsersTextFile, pass))
        {
            if (user == userName)
            {
                cout << "Username already in use. Try again.\n" << endl;
                match = true;
            }
        }
        UsersTextFile.close();
    } while (match == true);
    cout << "Enter Password: " << endl;
    cin >> passWord;

    //enter in bank info
    cout << "Enter Name:" << endl;
    cin >> Name;
    cout << "Enter Account Type:" << endl;
    cin >> accountType;
    cout << "Enter Balance:" << endl;
    cin >> balance;
    //given a bank account number 
    accountNumber += 1;
    activeAccount += 1;
    cout << "Account Number: " << accountNumber << endl;

    //append all info to file
    //open text file
    UsersTextFile.open("Users.txt", ios::app);
    if (!UsersTextFile) {
    //fail to open file
    cout << "No such file found.\n" << endl;
    }
    //open file successfully
    else {
        //write to the file
        UsersTextFile << userName << ";" << passWord << ";" << accountNumber << ";" << Name << ";" << accountType << ";" << balance << endl;
        cout << "User successfully created.\n" << endl;
    }
    //close the file
    UsersTextFile.close();
}