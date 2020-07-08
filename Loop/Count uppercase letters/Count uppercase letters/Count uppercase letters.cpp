/*************************************************************************
Problem#: #3 Count uppercase letters
Question: Write a program that prompts the user to enter a string and
          displays the number of the uppercase letters in the string. 
Name: Jin Han Ho
ID: 1790201
Date: 28/2/2020
Status: complete
**************************************************************************/


#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

int main()
{
    string str;
    int num = 0;

    cout << " Enter a string: ";
    getline(cin, str);
     

    for (int i = 0; i < str.length(); i++) {

        num += (str.at(i) == toupper(str.at(i)));

    }

    cout << "The number of uppercase letters is " << num;


    return 0;
}

