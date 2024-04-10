#include "Manager.h"

//constructor and deconstructor
Manager::Manager() { managerMenu = true; }
Manager::~Manager() {}

//function for manager login
int Manager::login(string userName, string passWord) {
    //open text file
    TextFile.open("Managers.txt");

    //fail to open file
    if (!TextFile) {
        cout << "No such file found.\n" << endl;
        return 0;
    }

    //open file successfully
    //validate Username and Password with Username and Password in text file
    else {
        while (getline(TextFile, user, ';'), getline(TextFile, pass)) {
            if (user == userName && pass == passWord) {//continue if Username and Password matches with Username and Password in text file
                cout << "Manager successfully login.\n" << endl;
                matches = true;
                //close text file
                TextFile.close();
            }
        }
        if (matches == false) {
            cout << "Manager login fail.\n" << endl;
            //close text file
            TextFile.close();
            return 0;
        }
    }

    //shoud we create a function to prompt this?
    //if Username and Password matches with Username and Password in text file
    //prompt manager login welcome page
    do {
        cout << "Welcome Manager: " << userName << endl;
        cout << "1. Remove Account" << endl;
        cout << "2. Load Account" << endl;
        cout << "3. Show Number of Active Accounts" << endl;
        //cout << "4. Remove User" << endl;//???
        cout << "4. Exit\n" << endl;
        cin >> ans;

        //case base on input
        switch (ans) {
            //remove account case
        case 1:
            cout << "Enter Account Username: " << endl;
            cin >> user;
            cout << "Enter Account Number: " << endl;
            cin >> accNum;
            removeBankAccount(user, accNum);
            break;
            //load user account case
        case 2:
            cout << "Enter Account Username: " << endl;
            cin >> user;
            /*cout << "Enter Account Number: " << endl;
            cin >> accNum;*/
            if (userExist(user) == 1) {
                loadBankAccount(user);
            }
            break;
            //show number of active accounts case
        case 3:
            cout << "Number of Active Accounts: " << getActiveAccounts() << "\n" << endl;
            break;
            //exit case
        case 4:
            cout << "Returning to menu.\n" << endl;
            return 1;
            //default case
        default:
            //clear error input due to input type doesn't match and ignore input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please enter a number between 1 and 4.\n" << endl;
        }
    } while (managerMenu == true);
    return 1;
}