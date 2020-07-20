#include "Car.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {

	string name;
	int year, choice = 0;

	cout << "Enter your car's make: ";
	cin >> name;
	cout << endl;
	cout << "Enter your car's year: ";
	cin >> year;
	cout << endl;

	Car Car1(name, year);

	while (choice != 3) {

		cout << "Enter: " << endl;
		cout << "1 | Accelerate Car" << endl;
		cout << "2 | Brake Car" << endl;
		cout << "3 | Quit" << endl;
		cout << "Choice: ";
		cin >> choice;

		switch (choice) {
			case 1:
				Car1.accelerate();
				break;
			
			case 2:
				Car1.brake();
				break;

			default:
				break;
		}

	}
	return 0;
}