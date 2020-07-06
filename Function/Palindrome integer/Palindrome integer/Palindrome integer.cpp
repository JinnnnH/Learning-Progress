/*************************************************************************
Problem#: #1 Palindrome integer
Question: Use the flip function to implement isPalindrome. A number is a
          palindrome if its reversal is the same as itself. For example,
          flip(3456) displays 6543..
Name: Jin Han Ho
ID: 1790201
Date: 3/6/2020
Status: complete
**************************************************************************/



#include <iostream>
#include <sstream>
#include <iomanip>
#include<cmath>
#include<string>
using namespace std;


int flip(int num) {

    string str;
    char x;

    str = to_string(num);


    for (int i = 0; i < (str.length()/2); i++) {
        
        x = str.at(i);
        str.at(i) = str.at(str.length()-1 - i);
        str.at(str.length()-1 - i) = x;

    }

    stringstream(str) >> num;

    return num;

}

bool isPalindrome(int number) {

    return (number == flip(number));
}


int main() {

    string str;
    int num = 0;

    cout << "Please enter a number: ";
    getline(cin, str);
    stringstream(str) >> num;



    if (isPalindrome(num)) {

        cout << "The number is palindrome." << endl;
        cout << flip(num);

    }
    else {

        cout << "The number is not palindrome.";

    }

    

    return 0;
}