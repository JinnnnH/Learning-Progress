//*****************************************************************************************
//Program Name: AppDemo
//Author: Jin Han Ho
//IDE Used: Visual Studio 2019
//Program description: This program prints out the records of all checks from input file
//*****************************************************************************************
#include "Check.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    string name, date, memo, amtTemp, checkTemp; 
    int checknum;
    double amt;
    vector<Check> CheckRecords;

    if (fin.is_open()) {                                                            //check if file is open
        while (getline(fin, name)) {                                                //getting inputs from file
            getline(fin, date);
            getline(fin, amtTemp);
            stringstream(amtTemp) >> amt;
            getline(fin, memo);
            getline(fin, checkTemp);
            stringstream(checkTemp) >> checknum;
            CheckRecords.push_back({ name, date, amt, memo, checknum });
        }

        for (int i = 0; i < CheckRecords.size(); i++) {
            CheckRecords.at(i).PrintCheck();                                        //printing checks
        }

    }
    else {
        cout << "Error opening file." << endl;
    }

    cout << endl << endl << "I attest that this code is my original programming work, and that I received " << endl
        << "no help creating it.I attest that I did not copy this code or any portion of this" << endl
        << "code from any source." << endl;

    return 0;
}