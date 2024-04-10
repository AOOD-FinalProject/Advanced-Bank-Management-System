#include "User.h"

//constructor and deconstructor
User::User() { matches = false; }
User::~User() {}

//function for user login
int User::login(string userName, string passWord) {
    //open text file
    TextFile.open("Users.txt");

    //fail to open file
    if (!TextFile) {
        cout << "No such file found.\n" << endl;
        TextFile.close();
        return 0;
    }

    //open file successfully
    //validate Username and Password with Username and Password in text file
    else {
        while (getline(TextFile, user, ';'), getline(TextFile, pass)) {
            if (user == userName && pass == passWord) {
                cout << "User successfully login.\n" << endl;
                //close the file
                TextFile.close();
                return 1;
            }
        } 
    }
    cout << "User login fail.\n" << endl;
    //close the file
    TextFile.close();
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
        TextFile.open("Users.txt");
        while (getline(TextFile, user, ';'),getline(TextFile, pass)) {
            if (user == username) {
                cout << "Username already in use. Try again.\n" << endl;
                matches = true;
            }
        }
        TextFile.close();
    } while (matches == true);

    //enter in Password
    do {
        cout << "Enter Password: " << endl;
        cin >> pass;
    } while (!isAlphaNumeric(pass));

    //append all info to file
    //open text file
    TextFile.open("Users.txt", ios::app);
    //fail to open file
    if (!TextFile) {
        cout << "No such file found.\n" << endl;
    }
    //open file successfully
    else {
        //write to the file
        TextFile << username << ";" << pass << endl;
        cout << "User successfully created.\n" << endl;
    }
    //close the file
    TextFile.close();
    return username;
}

//function to check if a user account exist
int User::userExist(string userName) {
    //open text file
    TextFile.open("Users.txt");

    //fail to open file
    if (!TextFile) {
        cout << "No such file found.\n" << endl;
        TextFile.close();
        return 0;
    }

    //open file successfully
    //validate Username with Username in text file
    else {
        while (getline(TextFile, user, ';'), getline(TextFile, pass)) {
            if (user == userName) {
                cout << "Access user account succesfully.\n" << endl;
                //close the file
                TextFile.close();
                return 1;
            }
        }
    }
    cout << "User doesn't exist.\n" << endl;
    //close the file
    TextFile.close();
    return 0;
}

//function to remove user account?
void User::removeUser(string userName) {
    //matches = false;
    //open text file
    TextFile.open("Users.txt");
    temp.open("temp.txt");

    //fail to open file
    if (!TextFile && !temp) {
        cout << "No such file found.\n" << endl;
        return;
    }

    //open file successfully
    //validate Username with Username in text file
    else {
        while (getline(TextFile, user, ';'), getline(TextFile, pass)) {
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
    temp.close();

    //remove old Users.txt file and rename temp to new Users.txt file
    remove("Users.txt");
    if (rename("temp.txt", "Users.txt") == -1) {
        cout << "Rename file failed." << endl;
    }
    return;
}
