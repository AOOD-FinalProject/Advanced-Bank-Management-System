#include "User.h"
#include "Manager.h"
#include "fstream"


int main() {
    //initialize variables
    int ans;
    string userName;
    string passWord;
    User* user;
    Manager* manager;
    bool menu = true;
    fstream UsersTextFile;
    bool match = false;
    string u;

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
            user->getLogin();
            delete user;
            break;
        //create user login case
        case 2:
            user = new User();
            user->createUser();
            delete user;
            break;
        //manager login case
        case 3:
            manager = new Manager();
            manager->getMLogin();
            delete manager;
            break;
            //exit case
        case 4:
            cout << "Exiting the program." << endl;
            return 0;
        //default case
        default:
            cout << "Invalid choice. Please enter a number between 1 and 4.\n" << endl;
        }
        //prevent infinite loop when characters are entered instead of integer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (0 < ans < 5 && menu == true);

    return 0;
}
