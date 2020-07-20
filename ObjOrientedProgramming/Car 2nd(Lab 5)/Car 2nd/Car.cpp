//Car.cpp
#include "Car.h"
#include <iostream>
#include <cstdlib>
using namespace std;


Car::Car(string name, int num) {
	make = name;
	year = num;
}
void Car::setMake(string m) {
	make = m;
}

string Car::getMake() {
	return make;
}

void Car::setYear(int y) {
	year = y;
}

int Car::getYear() {
	return year;
}
