#ifndef ADVANCED_BANK_MANAGEMENT_SYSTEM_PERSON_H
#define ADVANCED_BANK_MANAGEMENT_SYSTEM_PERSON_H
#include <iostream>
#include <fstream>//I/O files
#include <string>
#include <iomanip>//setprecision()
#include <vector>//vectors better than arrays

using namespace std;

//keep here or move?
bool isAlphaNumeric(string input);
bool isTwoDecimalPlaces(double input);

class User {
private:
	//any private?
public:
	fstream TextFile;
	fstream UsersTextFile;
	ofstream temp;
	//string use to read file
	string username, user, pass, line;
	bool matches;

	User();
	//copy constructor?
	~User();
	virtual int login(string userName, string passWord);
	string createUser();
	int userExist(string userName);
	void removeUser(string userName);
};

#endif //ADVANCED_BANK_MANAGEMENT_SYSTEM_PERSON_H
