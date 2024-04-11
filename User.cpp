#include "User.h"

//constructor and deconstructor
User::User() { matches = false; }
User::~User() {}

//function for user login
int User::login(string userName, string passWord) {
    //open text file
    UsersTextFile.open("Users.txt");

    //fail to open file
    if (!UsersTextFile) {
        cout << "No such file found.\n" << endl;
        return 0;
    }

    //open file successfully
    //validate Username and Password with Username and Password in text file
    else {
        while (getline(UsersTextFile, user, ';'), getline(UsersTextFile, pass)) {
            if (user == userName && pass == passWord) {
                cout << "User successfully login.\n" << endl;
                //close the file
                UsersTextFile.close();
                return 1;
            }
        } 
    }
    cout << "User login fail.\n" << endl;
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
            cin >> username;
        } while (!isAlphaNumeric(username)); 

        //check to see if Username is already in text file
        UsersTextFile.open("Users.txt");
        if (!UsersTextFile) {
            cout << "No such file found.\n" << endl;
        }
        else {
            while (getline(UsersTextFile, user, ';'), getline(UsersTextFile, pass)) {
                if (user == username) {
                    cout << "Username already in use. Try again.\n" << endl;
                    matches = true;
                }
            }
        }
        UsersTextFile.close();
    } while (matches == true);

    //enter in Password
    do {
        cout << "Enter Password: " << endl;
        cin >> pass;
    } while (!isAlphaNumeric(pass));

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
        UsersTextFile << username << ";" << pass << endl;
        cout << "User successfully created.\n" << endl;
    }
    //close the file
    UsersTextFile.close();
    return username;
}

//function to check if a user account exist
int User::userExist(string userName) {
    //open text file
    UsersTextFile.open("Users.txt");

    //fail to open file
    if (!UsersTextFile) {
        cout << "No such file found.\n" << endl;
        return 0;
    }

    //open file successfully
    //validate Username with Username in text file
    else {
        while (getline(UsersTextFile, user, ';'), getline(UsersTextFile, pass)) {
            if (user == userName) {
                cout << "Access user account succesfully.\n" << endl;
                //close the file
                UsersTextFile.close();
                return 1;
            }
        }
    }
    cout << "User doesn't exist.\n" << endl;
    //close the file
    UsersTextFile.close();
    return 0;
}

//function to remove user account?
void User::removeUser(string userName) {
    matches = false;
    //open text file
    UsersTextFile.open("Users.txt");
    TextFile.open("BankAccounts.txt");
    temp.open("temp.txt");

    //fail to open file
    if (!TextFile && !temp && !UsersTextFile) {
        cout << "No such file found.\n" << endl;
        return;
    }

    //open file successfully
    //validate Username with Username in text file
    else {
        while (getline(TextFile, username, ';'), getline(TextFile, line)) {
            if (username == userName) {
                cout << "There is still an open bank account for this user. Close bank accounts first and try again. \n" << endl;
                UsersTextFile.close();
                TextFile.close();
                temp.close();
                return;
            }
        }
        while (getline(UsersTextFile, user, ';'), getline(UsersTextFile, pass)) {
            if (user == userName) {//if user matches, don't write to temp text file
                cout << "Remove user successfully.\n" << endl;
                matches = true;
            }
            else {//write any user that doesn't match to temp text file
                temp << user << ';' << pass << endl;
            }
        }
        if (matches == false) {//no user remove
            cout << "Remove user fail.\n" << endl;
        }
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
    return;
}
