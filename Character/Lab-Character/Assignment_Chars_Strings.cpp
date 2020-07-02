/***************************************************************
Problem#: COMSC 165 Assignment_Chars_Strings
Question: Write a program that asks the user for his/her name. The program will
ask the user to enter 3 character values: a letter, a number, and a
symbol (such as: B, 6, and #). 
Name: Jin Han Ho
ID: 1790201
Date: 2/15/2020
Status: complete
****************************************************************/






#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <bitset>
using namespace std;

void showOriginal( string user, string con, int num, char let, char sym) {

    cout << user << " - Character Formatting" << endl << endl;

    cout << setw(20) << "letter = " << let;
    cout << setw(20) << "number = " << num;
    cout << setw(20) << "symbol = " << sym;

    cout << endl;

    cout << setfill('-') << setw(61 + con.length());
    cout << "-" << endl;

}


void showDec(int num, char let, char sym){

    cout << setfill(' ') << setw(10) << left << "Decimal";
    cout << setw(11) << right << dec << static_cast<int>(let);
    cout << setw(20) << dec << num;
    cout << setw(21) << dec << static_cast<int>(sym);
    cout << endl;

}


void showHex(int num, char let, char sym) {

    cout << setw(10) << left << "Hex";
    cout << setw(11) << right << showbase << hex;
    cout << uppercase << static_cast<int>(let);
    cout << setw(20) << showbase << hex;
    cout << uppercase << num;
    cout << setw(21) << showbase << hex;
    cout << uppercase << static_cast<int>(sym);
    cout << endl;

}

void showOct(int num, char let, char sym) {

    cout << setw(10) << left << "Octal";
    cout << setw(11) << right << showbase << oct << static_cast<int>(let);
    cout << setw(20) << showbase << oct << num;
    cout << setw(21) << showbase << oct << static_cast<int>(sym);
    cout << endl;

}

void showBin(int num, char let, char sym) {

    cout << setw(10) << left << "Binary";
    cout << setw(11) << right << bitset<8>(static_cast<int>(let));
    cout << setw(20) << bitset<8>(num);
    cout << setw(21) << bitset<8>(static_cast<int>(sym));
    cout << endl;

}


int main()
{
    string username, convert;
    char letter, symbol;
    int number;



    cout << "What is your name? :";
    getline(cin, username); 

    cout << endl << endl;

    cout << "OK " << username << ", Please input a letter, ";
    cout << "number, and a symbol" << endl;
    cout << "seperated by a space: ";
    getline(cin, convert);
    stringstream (convert) >> letter >> number >> symbol;

    cout << endl << endl;
    cout << "Output succeeded.";
    cout << endl << endl << endl;
    

    showOriginal(username, convert, number, letter, symbol);

    showDec(number, letter, symbol);

    showHex(number, letter, symbol);

    showOct(number, letter, symbol);

    showBin(number, letter, symbol);

    return 0;
}
