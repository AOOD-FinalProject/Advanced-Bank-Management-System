#include "User.h"
fstream UsersTextFile;

void User::login(string userName, string passWord) {
    bool match = false;
    string u;
    string p;

    // Open text file
    UsersTextFile.open("Users.txt");
    // Fail to open file
    if (!UsersTextFile) {
        cout << "No such file found.\n" << endl;
    }
    // Open file successfully
    // Validate Username and Password with Username and Password in text file
    else {
        while (UsersTextFile)
        {
            getline(UsersTextFile, u, ';');
            getline(UsersTextFile, p);
            if (u == userName && p == passWord)
            {
                cout << "User successfully login.\n" << endl;
                match = true;
                break;
            }
        }
        if (match == false)
        {
            cout << "User login fail.\n" << endl;
        }
    }
    // Close the file
    UsersTextFile.close();
}

void User::create(string userName, string passWord) {
    // Open text file
    UsersTextFile.open("Users.txt", ios::app);
    if (!UsersTextFile) {
    // Fail to open file
    cout << "No such file found.\n" << endl;
    }
    // Open file successfully
    else {
        // Write to the file
        UsersTextFile << userName << ";" << passWord << endl;
        cout << "User successfully created.\n" << endl;
    }
    // Close the file
    UsersTextFile.close();
}