#include "User.h"

//constructor and deconstructor
User::User() { matches = false; }
User::~User() {}

//function for user login
int User::login(string userName, string passWord) {
    ifstream UsersTextFile("Users.txt");

    //fail to open file
    if (!UsersTextFile.is_open()) {
        cout << "debug: No such file found.\n" << endl;
        return 0;
    }

    string user;
    string password;
    while (getline(UsersTextFile, user, ';') && getline(UsersTextFile, password)) {
        if (user == userName && password == passWord) {
            cout << "User successfully logged in.\n" << endl;
            //close the file
            UsersTextFile.close();
            return 1;
        }
    }

    cout << "User login failed.\n" << endl;
    //close the file
    UsersTextFile.close();
    return 0;
}

//function to create user login
string User::createUser() {
    //enter in Username
    do {
        matches = false;
        //check to see if user enter only letters and numbers
        do {
            cout << "Enter Username: " << endl;
            cin >> userName;
        } while (!isAlphaNumeric(userName));

        //check to see if Username is already in text file
        if (userExist(userName) == 1) {
            cout << "Username already in use. Try again.\n" << endl;
            matches = true;
        }
    } while (matches);

    //enter in Password
    do {
        cout << "Enter Password: " << endl;
        cin >> passWord;
    } while (!isAlphaNumeric(passWord));

    //append username and password to file
    ofstream UsersTextFile("Users.txt", ios::app);

    //fail to open file
    if (!UsersTextFile.is_open()) {
        cout << "Debug: No such file found.\n" << endl;
        return "";
    }

    //write to the file
    UsersTextFile << userName << ";" << passWord << endl;
    cout << "User successfully created.\n" << endl;
    //close the file
    UsersTextFile.close();
    return userName;
}

//function to check if a user account exists
int User::userExist(string userName) {
    ifstream UsersTextFile("Users.txt");

    //fail to open file
    if (!UsersTextFile.is_open()) {
        cout << "Debug: 1"
                "1"
                "Debug: No such file found.\n" << endl;
        return 0;
    }

    string user;
    string password;
    while (getline(UsersTextFile, user, ';') && getline(UsersTextFile, password)) {
        if (user == userName) {
            //close the file
            UsersTextFile.close();
            return 1;
        }
    }
    //close the file
    UsersTextFile.close();
    return 0;
}

//function to remove user account
void User::removeUser(string userName) {
    matches = false;
    ifstream UsersTextFile("Users.txt");
    ifstream TextFile("BankAccounts.txt");
    ofstream temp("temp.txt");

    //fail to open file
    if (!TextFile.is_open() || !temp.is_open() || !UsersTextFile.is_open()) {
        cout << "Debug: 1"
                "No such file found.\n" << endl;
        return;
    }

    string user;
    string password;
    //prevent deletion of user account if user still has open bank accounts
    while (getline(TextFile, user, ';') && getline(TextFile, password)) {
        if (user == userName) {
            cout << "There is still an open bank account for this user. Close bank accounts first and try again. \n" << endl;
            UsersTextFile.close();
            TextFile.close();
            temp.close();
            return;
        }
    }

    //else delete user
    while (getline(UsersTextFile, user, ';') && getline(UsersTextFile, password)) {
        if (user == userName) {
            cout << "Remove user successfully.\n" << endl;
            matches = true;
        } else {
            temp << user << ';' << password << endl;
        }
    }

    if (!matches) {
        cout << "Remove user fail.\n" << endl;
    }

    //close text file
    TextFile.close();
    UsersTextFile.close();
    temp.close();

    //remove old Users.txt file and rename temp to new Users.txt file
    remove("Users.txt");
    if (rename("temp.txt", "Users.txt") == -1 ) {
        cout << "Rename file failed." << endl;
    }
}
