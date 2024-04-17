#pragma once
#include <iostream>
#include <fstream>//I/O files
#include <string>
#include <iomanip>//setprecision()
//#include <vector>//vectors better than arrays

using namespace std;

class ValidInput {
private:
    //any private?
public:
    ValidInput();
    //copy constructor?
    ~ValidInput();
    bool isAlphaNumeric(string input);
    bool isTwoDecimalPlaces(double input);
};