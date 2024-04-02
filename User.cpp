//
// Created by Michael Helzer on 3/27/24.
//

#include "User.h"
#include <iostream>
#include <fstream>
using namespace std;

void User::login_User(string userName, string passWord) {

}

void User::create_User() {

}

void User::remove_User() {

}

int User::deposit(int deposit_amount) {
    int value = get_account_value();
    value += deposit_amount;
    return value;
}

int User::withdraw(int withdraw_amount) {
    int value = get_account_value();
    value -= withdraw_amount;
    if (value < 0) {
        cout << "Not enough money to withdraw" << endl;
        value += withdraw_amount;
    }
    return 0;
}