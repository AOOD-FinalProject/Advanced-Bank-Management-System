
#include "Person.h"
#include <iostream>
#include <string>
#include <cstdlib> // for exit()
using namespace std;

int main() {


    cout << "\nWelcome To Your Banking System" << endl;
    cout << "\t1. User Login" << endl;
    cout << "\t2. Create Account" << endl;
    cout << "\t3. Manager Login" << endl;
    cout << "\t4. Exit\n" << endl;

    int ans;
    cin >> ans;

    // Call the appropriate function based on user input
    Person p;
    switch (ans) {
        case 1:
            cout << "Enter Username: " << endl;
            string userName;
            cin >> userName;
            cout << "Enter Password: " << endl;
            string passWord;
            cin >> passWord;
            p.user_login_user(userName, passWord);
            break;
        case 2:
            p.user_create_user();
            break;
        case 3:
            p.manager_login_manager();
            break;
        case 4:
            cout << "Exiting the program." << endl;
            return 0;
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 4." << std::endl;
            break;
    }

    return 0;
}
