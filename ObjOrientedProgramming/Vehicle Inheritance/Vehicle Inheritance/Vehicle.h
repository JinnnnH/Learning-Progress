/*----------------------------
Vehicle
----------------------------
- year : int
- mileage : int
- name : string
----------------------------
+ Vehicle()
+ Vehicle(int, int)
+ print() : void
+ setYear(int) : void
+ setMileage(int) : void
----------------------------*/

#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <iomanip>
#include<vector>
#include <string>
using namespace std;

class Vehicle {
private:
	int year;
	int mileage;
	string name;

public:
	Vehicle() { year = 0; mileage = 0; name = ""; };
	Vehicle(int y, int m, string n) {
		year = y;
		mileage = m;
		name = n;
	}
	void print() {
		cout << "Information about Vehicle \"" << """" << GetName() << "\": " << endl;
		cout << "Year: " << year << endl;
		cout << "Mileage: " << mileage << endl;
	}
	string GetName() { return name; }
	void setYear(int y) { year = y; }
	void setMileage(int m) { mileage = m; }

};
#endif