//***********************************************************************************************************
//Program Name: TheaterDemo
//Author: Jin Han Ho
//IDE Used: Visual Studio 2019
//Program description: this program will redefine the function of base class and output the data of theaters
//***********************************************************************************************************
#include "Venue.h"
#include "Theater.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    Theater th1("Pleasant Hill Theater",        //Theater's name
                "2063 Norse Drive",             //Theater's address
                "Pleasant Hill, CA 94523",      //Theater's City 
                16983.765,                      //Theater's Average Concessions Sales
                "Theater",                      //Venue's Type
                150,                            //Theater's Capacity
                160.12),                        //Theater's Base Price

            th2("Berkeley Theater",             //Theater's name
                "Berkeley Hills",               //Theater's address
                "Berkeley, CA 94523",           //Theater's City 
                5700.245,                       //Theater's Average Concessions Sales
                "Theater",                      //Venue's Type
                200,                            //Theater's Capacity
                135.12);                        //Theater's Base Price

    cout << th1.getTypeVenue() << "'s information: " << endl;
    th1.PrintTheater();                         //access print function
    cout << th2.getTypeVenue() << "'s information: " << endl;
    th2.PrintTheater();                         //access print function

    cout << endl << "I attest that this code is my original programming work, and that I received " << endl
        << "no help creating it.I attest that I did not copy this code or any portion of this" << endl
        << "code from any source." << endl << endl;

    return 0;
}
