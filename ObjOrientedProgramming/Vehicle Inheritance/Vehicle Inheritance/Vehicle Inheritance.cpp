//*******************************************************************************************************************
//Program Name: Vehicle Inheritance
//Author: Jin Han Ho
//IDE Used: Visual Studio 2019
//Program description: This program will out put the information of few vehicles which is derived from the same class
//*******************************************************************************************************************

#include "Vehicle.h"
#include "Sedan.h"
#include "Truck.h"
#include <iostream>
#include <iomanip>
#include<vector>
#include <string>
using namespace std;

int main()
{
	Vehicle MotorVehicle(1992, 4000, "MotorVehicle");
	Sedan Yaris(1994, 50500, 4, true, "Yaris");
	Truck Pickup(2015, 20000, 3000, 2, "Pickup");
	
	MotorVehicle.print();
	cout << endl;

	Yaris.printVehicle();

	Pickup.printTruck();

	return 0;
}

