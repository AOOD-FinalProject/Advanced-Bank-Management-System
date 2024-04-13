#include "Manager.h"
#include <cstdlib> // for exit()?

int main() {
    //initialize variables
    int ans;
    bool mainMenu = true;
    string userName;
    string passWord;
    BankAccount* bankAccount;
    User* user;

    //do while loop to validate input
    do {
        //print welcome page
        cout << "Welcome To Your Banking System" << endl;
        cout << "1. User Login" << endl;
        cout << "2. Create Account" << endl;
        cout << "3. Manager Login" << endl;
        cout << "4. Exit\n" << endl;
        cin >> ans;

        //case base on input
        switch (ans) {
        //user login case
        case 1:
            user = new User();
            cout << "Enter Username: " << endl;
            cin >> userName;
            cout << "Enter Password: " << endl;
            cin >> passWord;
            if (user->login(userName, passWord) == 1) {
                bankAccount = new BankAccount();
                bankAccount->loadBankAccount(userName);
                delete bankAccount;
            }
            delete user;
            break;
        //create user login case
        case 2:
            user = new User();
            bankAccount = new BankAccount();
            bankAccount->addAccount(user->createUser());
            delete bankAccount;
            delete user;
            break;
        //manager login case
        case 3:
            user = new Manager();
            cout << "Enter Username: " << endl;
            cin >> userName;
            cout << "Enter Password: " << endl;
            cin >> passWord;
            user->login(userName, passWord);
            delete user;
            break;
            //exit case
        case 4:
            cout << "Exiting the program." << endl;
            return 0;
        //default case
        default:
            //clear error input due to input type doesn't match and ignore input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please enter a number between 1 and 4.\n" << endl;
        }
    } while (mainMenu == true);
    return 0;
}