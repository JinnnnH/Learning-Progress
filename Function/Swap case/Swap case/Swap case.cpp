/*************************************************************************
Problem#: #3 Swap case
Question: Write the following function that returns a new string in which 
          the uppercase letters are changed to lowercase and lowercase to 
          uppercase. Write a test program that prompts the user to enter a 
          string and invokes this function, and displays the return value 
          from this function. 

Name: Jin Han Ho
ID: 1790201
Date: 3/6/2020
Status: complete
**************************************************************************/


#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

string swapCase(const string& s) {

    string str = s;

    for (int i = 0; i < str.length(); i++) {

        str.at(i) = (str.at(i) == toupper(str.at(i))) ? tolower(str.at(i)) : toupper(str.at(i));

    }

    return str;
}



int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    cout << "The new string is: " << swapCase(str);


    return 0;
}
