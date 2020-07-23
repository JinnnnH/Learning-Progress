//***************************************************************************************************
//Program Name: Collection of Ships
//Author: Jin Han Ho
//IDE Used: Visual Studio 2019
//Program description: This program will output the information of ships which stored in two arrays.
//***************************************************************************************************

#include "Ship.h"
#include "Ferry.h"
#include "NavyShip.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    const int SIZE = 2;
    Ferry ferry[SIZE] = { 
        Ferry("US",
             "Seatle",
             "Walla Walla",
             440,
             4860,
             2000,
             188,
             "Edmonds",
             "Kingston",
             35.95), 

        Ferry("US",           
            "Seattle",  
            "Samish",
            362,
            4320,
            1500,
            144,
            "Anacortes",
            "Friday Harbor",
            45.95)
    };

    NavyShip navy[SIZE] = {
       NavyShip("US",
                "Yokosuka",
                "USS John McCain",
                505,
                8900,
                "Destroyer",
                "DDG-56",
                281,
                false,
                35),
               
       NavyShip("US",
                "Yokosuka",
                "USS Ronald Reagan",
                1092,
                101400,
                "Aircraft Carrier",
                "CVN-76",
                3532,
                true,
                40)
    };

    for (int i = 0; i < SIZE; i++) {
        cout << "Information for the Ferry " << ferry[i].getName() << ":" << endl;
        ferry[i].PrintFerry();
        cout << endl;
    }

    for (int i = 0; i < SIZE; i++) {
        cout << "Information for the Ferry " << navy[i].getName() << ":" << endl;
        navy[i].PrintNavyShip();
        cout << endl;
    }

    cout << "I attest that this code is my original programming work, and that I received" << endl
         << "no help creating it.I attest that I did not copy this code or any portion of this" << endl
         << "code from any source." << endl;

    return 0;
}
