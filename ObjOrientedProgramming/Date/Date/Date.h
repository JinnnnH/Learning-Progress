/*
------------------------------------------------
          Date
------------------------------------------------
- day: int
-month: int
- year : int
------------------------------------------------
+Date(dd: int, mm: int, yy: int);
+CheckDate(day: int, month: int, year: int)
+ShowRegularDate(Month: vector<string>): void;
+ShowMilitaryDate(Month: vector<string>): void;
------------------------------------------------
*/
#ifndef DATE_H
#define DATE_H
#include "Date.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Date {

private:
    int day;
    int month;
    int year;

public:
    Date(int, int, int);
    bool CheckDate();
    void ShowRegularDate(vector<string>);
    void ShowMilitaryDate(vector<string>);

};
#endif