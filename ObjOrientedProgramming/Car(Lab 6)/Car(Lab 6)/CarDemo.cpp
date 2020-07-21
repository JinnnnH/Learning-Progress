#include "Car.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {

	Car Car1("Toyota", 1998);

	for (int i = 0; i < 3; i++) {
		Car1.accelerate();
	}
	for (int i = 0; i < 4; i++) {
		Car1.brake();
	}
	return 0;
}