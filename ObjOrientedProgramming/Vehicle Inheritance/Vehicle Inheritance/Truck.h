/*----------------------------
Truck::Vehicle
----------------------------
- TowingCapacity : int
- NoOfAxles : int
----------------------------
+ Truck()
+ Truck(tow, axles)
+ printVehicle() : void
----------------------------*/

#ifndef TRUCK_H
#define TRUCK_H
#include "Vehicle.h"
#include "Sedan.h"
#include <iostream>
#include <iomanip>
#include<vector>
#include <string>
using namespace std;

class Truck : public Vehicle {
private:
	int TowingCapacity;
	int NoOfAxles;

public:
	Truck() {
		TowingCapacity = 0;
		NoOfAxles = 0;
	}
	Truck(int y, int m, int tow, int axles, string n) : Vehicle(y, m, n) {
		TowingCapacity = tow;
		NoOfAxles = axles;
	}
	int setTowingCapacity(int tow) {
		TowingCapacity = tow;
	}
	int setNoOfAxles(int axles) {
		NoOfAxles = axles;
	}
	void printTruck() {
		Vehicle::print();
		cout << "Towing capacity: " << TowingCapacity << " tons" << endl;
		cout << "Number of axles: " << NoOfAxles << endl << endl;
	}
};

#endif