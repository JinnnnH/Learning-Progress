/*----------------------------
Sedan::Vehicle
----------------------------
- doors : int
- hatchback : bool
----------------------------
+ Sedan()
+ Sedan(int, int, int, bool)
+ printVehicle() : void
----------------------------*/

#ifndef SEDAN_H
#define SEDAN_H
#include "Vehicle.h"
#include <iostream>
#include <iomanip>
#include<vector>
#include <string>
using namespace std;

class Sedan : public Vehicle {
private:
	int doors;
	bool hatchback;

public:
	Sedan() {
		doors = 0; hatchback = false;
	}
	Sedan(int y, int m, int d, bool h, string n) : Vehicle(y, m, n) {
		doors = d;
		hatchback = h;
	}
	void printVehicle() {
		Vehicle::print();
		cout << "Doors: " << doors << endl;
		cout << "Hatchback: " << (hatchback ? "yes" : "no") << endl << endl;
	}
};

#endif