/*****************************************************************************
Problem#: #4 Checking Palindromes
Question: A string is a palindrome if it reads the same forward and backward. 
          The words “mom,” “dad,” and “noon,” for example, are palindromes.

Name: Jin Han Ho
ID: 1790201
Date: 28/2/2020
Status: complete
******************************************************************************/

#include <iostream>
#include <sstream>
#include<string>
#include <iomanip>
using namespace std;

int main()
{
    string str;
    bool valid = false;
    int num = 0;


    cout << "Enter a string: ";
    getline(cin, str);


    for (int i = 0; i <= (str.length() / 2); i++) {
        
        valid = (str.at(i) == str.at(str.length() - 1 - i));

    }

    if (valid) {

        cout << str << " is a palindrome.";

    }
    else {

        cout << str << " is not a palindrome.";

    }


    return 0;
}
