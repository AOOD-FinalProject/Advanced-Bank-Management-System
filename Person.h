

#ifndef ADVANCED_BANK_MANAGEMENT_SYSTEM_PERSON_H
#define ADVANCED_BANK_MANAGEMENT_SYSTEM_PERSON_H
#include "User.h"
#include "Manager.h"
#include <string>

class Person {
public:
    void user_login_user(string userName, string passWord);
    void user_create_user();
    void manager_login_manager();

};

#endif //ADVANCED_BANK_MANAGEMENT_SYSTEM_PERSON_H
