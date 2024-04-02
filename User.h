

#ifndef FINAL_PROJECT_USER_H
#define FINAL_PROJECT_USER_H
#include <string>

class User{
public:
    void create_User();
    void remove_User();
    void login_User(string userName, string passWord);
    int withdraw(int withdraw_amount);
    int deposit(int deposit_amount);

private:
    //int get_account_value();

};

#endif //FINAL_PROJECT_USER_H
