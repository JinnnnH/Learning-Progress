/*
-----------------------
          Car
-----------------------
- make: string
- year : int
- speed: int
-----------------------
+ Car(string, int)
+ setMake(m: string) : void
+ getMake() : string
+ setYear(y: int) : void
+ getYear() : int
+ setSpeed(s: int) : void
+ getSpeed() : int
+ accelerate() : void
+ brake() : void
----------------------
*/
#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Car {
    private:
        string make;
        int year;
        int speed;

    public:
        Car(string, int);
        void setMake(string m) { make = m;};
        string getMake() { return make;};
        void setYear(int y) { year = y; };
        int getYear() { return year; };
        void setSpeed(int s) {speed = s;};
        int getSpeed() { return speed; };
        void accelerate();
        void brake();

};
#endif