//
// Created by Michael Helzer on 3/27/24.
//

#ifndef FINAL_PROJECT_USER_H
#define FINAL_PROJECT_USER_H


class User{
public:
    void create_User();
    void remove_User();
    void login_User();
    int withdraw(int withdraw_amount);
    int deposit(int deposit_amount);

private:
    int get_account_value();

};

#endif //FINAL_PROJECT_USER_H
