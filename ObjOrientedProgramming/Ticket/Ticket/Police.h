/*
---------------------- -
Police
---------------------- -
-lastName: string
- badgeNumber : int
---------------------- -
+Police()
+ Police(string, int)
+ getName() : string
+ getBadge() : int
+ printOfficer() : void
----------------------
*/

#ifndef POLICE_H
#define POLICE_H
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Police {

private:
    string lastName;
    int badgeNumber;

public:
    Police() {
        lastName = " ";
        badgeNumber = 0;
    };
    Police(string n, int b) {
        lastName = n;
        badgeNumber = b;
    };
    string getName() 
        { return lastName; }
    int getBadge() 
        { return badgeNumber; }
    void printOfficer() {
        cout << getName() << ", " 
             << getBadge();
    }
};
#endif