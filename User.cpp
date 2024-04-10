#include "User.h"

void User::login(string& userName, string& passWord) {
    bool match = false;
    string u;
    string p;

    // Open text file
    fstream UsersTextFile("Users.txt", ios::in);
    // Fail to open file
    if (!UsersTextFile) {
        cout << "No such file found.\n" << endl;
        return;
    }

    // Validate Username and Password with Username and Password in text file
    while (getline(UsersTextFile, u, ';') && getline(UsersTextFile, p)) {
        if (u == userName && p == passWord) {
            cout << "User successfully login.\n" << endl;
            match = true;
            break;
        }
    }

    if (!match) {
        cout << "User login fail.\n" << endl;
    }

    // Close the file
    UsersTextFile.close();
}

void User::create(string& userName, string& passWord) {
    // Open text file
    fstream UsersTextFile("Users.txt", ios::out | ios::app);
    if (!UsersTextFile) {
        // Fail to open file
        cout << "No such file found.\n" << endl;
        return;
    }

    // Write to the file
    UsersTextFile << userName << ";" << passWord << endl;
    cout << "User successfully created.\n" << endl;

    // Close the file
    UsersTextFile.close();
}

void User::getLogin() {
    string userName, passWord;
    cout << "Enter Username: " << endl;
    cin >> userName;
    cout << "Enter Password: " << endl;
    cin >> passWord;
    login(userName, passWord);
}

void User::createUser() {
    bool match;
    string userName, passWord;
    fstream UsersTextFile;
    string u;
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
    } while (match == true);
    cout << "Enter Password: " << endl;
    cin >> passWord;
    create(userName, passWord);

}
