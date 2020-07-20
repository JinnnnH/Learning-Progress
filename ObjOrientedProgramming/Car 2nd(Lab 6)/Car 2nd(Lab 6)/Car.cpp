#include "Car.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

Car::Car(string m, int y) {
	setMake(m);
	setYear(y);
	setSpeed(0);
}

void Car::accelerate() {
	cout << "Accelerating..." << endl;
	speed += 5;
	cout << getMake() << " | " << getYear() << " | " << getSpeed() << " mph" << endl << endl;
}
void Car::brake() {
	if (speed > 0) {
		cout << "Braking..." << endl;
		speed -= 5;
		cout << getMake() << " | " << getYear() << " | " << getSpeed() << " mph" << endl << endl;
	}
	else {
		cout << "Braking... Error: can't brake a car that's standing still." << endl;
		cout << getMake() << " | " << getYear() << " | " << getSpeed() << " mph" << endl << endl;
	}
}