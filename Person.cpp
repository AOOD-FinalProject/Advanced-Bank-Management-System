

#include "Person.h"
#include "User.h"
#include "Manager.h"

void Person::user_login_user(string userName, string passWord) {
    User u;
    u.login_User(userName, passWord);
}

void Person::user_create_user() {
    User u;
    u.create_User();
}

void Person::manager_login_manager(){
    Manager m;
    m.login_manager();
}