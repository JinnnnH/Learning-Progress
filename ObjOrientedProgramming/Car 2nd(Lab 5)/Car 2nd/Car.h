//Car.h
/*
-----------------------
          Car
-----------------------
- make: string
- year : int
-----------------------
+ Car(name: string, num: int)
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
    Car(string, int);
    void setMake(string);
    string getMake();
    void setYear(int);
    int getYear();

};
#endif