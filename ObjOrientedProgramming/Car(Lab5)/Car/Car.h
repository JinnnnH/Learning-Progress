//Car.h
/*
-----------------------
          Car
-----------------------
- make: string
- year : int
-----------------------
+ Car()
+ setMake(m: string) : void
+ getMake() : string
+ setYear(y: int) : void
+ getYear() : int
----------------------
*/
#ifndef CAR_H
#define CAR_H
#include <iostream>
using namespace std;

class Car {

private:
    string make;
    int year;

public:
    void setMake(string m) {make = m;};
    string getMake() {return make;}
    void setYear(int y) {year = y;}
    int getYear() {return year;}

};
#endif

