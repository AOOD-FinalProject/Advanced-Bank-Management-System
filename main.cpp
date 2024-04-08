#include "User.h"
#include "Manager.h"


int main() {
    //initialize variables
    int ans;
    string userName;
    string passWord;
    User* user;
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
            cout << "Enter Username: " << endl;
            cin >> userName;
            cout << "Enter Password: " << endl;
            cin >> passWord;
            user->login(userName, passWord);
            delete user;
            break;
        //create user login case
        case 2:
            user = new User();

            // Check to see if Username is already in text file
            do {
                match = false;
                cout << "Enter Username: " << endl;
                cin >> userName;
                UsersTextFile.open("Users.txt");
                while (UsersTextFile)
                {
                    getline(UsersTextFile, u, ';');
                    if (u == userName)
                    {
                        cout << "Username already in use.\n" << endl;
                        match = true;
                        break;
                    }
                }
                UsersTextFile.close();
            } while (match);

            cout << "Enter Password: " << endl;
            cin >> passWord;
            user->create(userName, passWord);
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
            cout << "Invalid choice. Please enter a number between 1 and 4.\n" << endl;
        }
        //prevent infinite loop when characters are entered instead of integer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (0 < ans < 5 && menu == true);

    // This is out of reach and doesn't need to be here to function
    // return 0;
}
