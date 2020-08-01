//**************************************************************************************************************************
//Program Name: AppDemo
//Author: Jin Han Ho
//IDE Used: Visual Studio 2019
//Program description: This program prints out the information of several App which has a type derived from two base class
//**************************************************************************************************************************

#include "PublishedWork.h"
#include "ElectronicDevice.h"
#include "ReaderApp.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    ReaderApp App1("MyMap", 10.0, "transportation",
                  "IOS", 4, "James", 2000),

              App2("MyBrowser", 0.0, "Internet", 
                  "Android", 1, "Ryan", 1995),

              App3("Track Package", 14.67, "logistics",
                  "Windows", 10, "Bryan", 2020);
    cout << "App 1: " << endl;
    App1.PrintReader();
    cout << "App 2: " << endl;
    App2.PrintReader();
    cout << "App 3: " << endl;
    App3.PrintReader();

    cout << "I attest that this code is my original programming work, and that I received" << endl
         << "no help creating it.I attest that I did not copy this code or any portion of this" << endl
         << "code from any source." << endl << endl;

    return 0;
}
