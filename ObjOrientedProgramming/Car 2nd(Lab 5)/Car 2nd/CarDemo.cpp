//CarDemo.cpp
#include "Car.h"
#include <iostream>
using namespace std;

int main() {

	Car myCar1("Toyota", 1999);
	Car myCar2("Ford", 2019);
	Car myCar3("Acura", 2016);
	Car myCar4("Honda", 2005);

	cout << myCar1.getMake() << " " << myCar1.getYear() << endl;
	cout << myCar2.getMake() << " " << myCar2.getYear() << endl;
	cout << myCar3.getMake() << " " << myCar3.getYear() << endl;
	cout << myCar4.getMake() << " " << myCar4.getYear() << endl;

	return 0;
}