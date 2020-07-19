#include "Car.h"
#include <iostream>
#include<vector>
#include <iomanip>
#include <string>
using namespace std;

Car::Car(string m, int y) {
	setMake(m);
	setYear(y);
	setSpeed(0);
}

void Car::accelerate() {
	speed += 5;
	cout << setw(43) << "> Done. Car accelerated. New speed " << getSpeed() << " mph." << endl << endl;
}
void Car::brake() {
	if (speed > 0) {
		speed -= 5;
		cout << setw(38) << "> Done. Car braked. New speed " << getSpeed() << " mph." << endl << endl;
	}
	else {
		cout << setw(57) << "> Error: can't brake a car that's standing still." << endl << endl;
	}
}