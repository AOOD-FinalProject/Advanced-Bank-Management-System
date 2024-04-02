//
// Created by Michael Helzer on 3/27/24.
//
#include "User.h"
#include <iostream>
using namespace std;

int main() {

// prompt initial login
cout << "\nWelcome To Your Banking System" << endl;
cout << "\t1. User Login" << endl;
cout << "\t2. Create Account" << endl;
cout << "\t3. Manager Login" << endl;
cout << "\t4. Exit\n" << endl;

int ans;
cin >> ans;

if (ans == 1) {
    cout << "Enter Username: " << endl;
    string userName;
    cin >> userName;
    cout << "Enter Password: " << endl;
    string passWord;
    cin >> passWord;
    void User::login_User(userName, passWord);
}

// show list of options












}