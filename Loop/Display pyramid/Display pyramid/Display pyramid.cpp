/*************************************************************************
Problem#: #1 Display pyramid
Question: Write a program that prompts the user to enter an integer
          from 1 to 9 and displays a pyramid, as shown in the following
Name: Jin Han Ho
ID: 1790201
Date: 3/9/2020
Status: complete
**************************************************************************/

#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {

    string convert, str = "1 ";
    int num1;


    cout << "Pyramid Builders International." << endl
        << "Enter the number of lines [1-9]: ";
    getline(cin, convert);
    stringstream(convert) >> num1;


    for (int i = 2; i <= num1+1; i++) {

        cout << string((2*num1)-((i-2)*2),' ') << str << endl;

        stringstream ss;

        ss << i << ' ';

        str = ss.str() + str + ss.str();

    }

    return 0;
}