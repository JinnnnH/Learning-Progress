/*****************************************************************************
Problem#: #3 Swap case
Question: Write a test program that prompts the user to enter a phone number 
          as a string. The input number may contain letters. The program 
          translates a letter (uppercase or lowercase) to a digit and leaves 
          all other characters intact. 

Name: Jin Han Ho
ID: 1790201
Date: 3/8/2020
Status: complete
******************************************************************************/


#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <math.h>

using namespace std;

int getNumber(char uppercaseLetter) {

    return 2 + ((uppercaseLetter - 'A') - (uppercaseLetter >= 'S') - (uppercaseLetter >= 'Z'))/3;

}

int main()
{

    string str;


    cout << "Enter a string: ";
    getline(cin, str);
    cout << endl;



    for (int i = 0; i < str.length(); i++) {


        if(!(isalpha(str.at(i)))) {

            cout << str.at(i);

        }
        else {

            str.at(i) = toupper(str.at(i));
            cout << getNumber(str.at(i));

        }


    }


    return 0;
}
