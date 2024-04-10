#include "Manager.h"
fstream ManagerTextFile;

//function for manager login
void Manager::login(string& userName, string& passWord) {
    bool match = false;
    string u;
    string p;

    // Open text file
    ManagerTextFile.open("Managers.txt");
    // Fail to open file
    if (!ManagerTextFile) {
        cout << "No such file found.\n" << endl;
    }
    // Open file successfully
    // Validate Username and Password with Username and Password in text file
    else {
        while (ManagerTextFile)
        {
            getline(ManagerTextFile, u, ';');
            getline(ManagerTextFile, p);
            if (u == userName && p == passWord)
            {
                cout << "Manager successfully login.\n" << endl;
                match = true;
                break;
            }
        }
        if (match == false)
        {
            cout << "Manager login fail.\n" << endl;
        }
    }
    // Close text file
    ManagerTextFile.close();
}

void Manager::getMLogin() {
    string userName, passWord;
    cout << "Enter Username: " << endl;
    cin >> userName;
    cout << "Enter Password: " << endl;
    cin >> passWord;
    login(userName, passWord);
}