//*****************************************************************************************************
//Program Name: Car
//Author: Jin Han Ho
//IDE Used: Visual Studio 2019
//Program description: This program gives a menu with few operations you can do to your car collection
//*****************************************************************************************************

#include "Car.h"
#include <iostream>
#include<vector>
#include <iomanip>
#include <string>
using namespace std;

int PrintMenu(int &choice) {
	cout << "MAIN MENU ** Enter:" << endl;
	cout << setw(43) << "> 1 | Print complete car collection" << endl;
	cout << setw(41) << "> 2 | Add a car to the collection" << endl;
	cout << setw(46) << "> 3 | Remove a car from the collection" << endl;
	cout << setw(30) << "> 4 | Accelerate a car" << endl;
	cout << setw(25) << "> 5 | Brake a car" << endl;
	cout << setw(18) << "> 6 | Quit" << endl;

	cout << setw(18) << "> Choice: ";
	cin >> choice;

	return choice;
}

void PrintCollection(vector<Car>Collection) {
	for (int i = 0; i < Collection.size(); i++) {
		cout << setw(10) << "> " << Collection.at(i).getMake() << " | "
			<< Collection.at(i).getYear() << " | "
			<< Collection.at(i).getSpeed() << " mph" << endl;
	}
	cout << endl;
}

void PrintSelection(vector<Car>Collection) {
	for (int i = 0; i < Collection.size(); i++) {
		cout << setw(10) << "> " << (i+1) << " | 	" << "> " 
			<< Collection.at(i).getMake() << " | "
			<< Collection.at(i).getYear() << " | "
			<< Collection.at(i).getSpeed() << " mph" << endl;
	}
}

int main() {

	vector<Car>Collection;
	string name;
	int year, choice = 0, choice2 = 0;

	cout << "*** Car Collection Demo ***" << endl << endl;

	while (PrintMenu(choice) != 6) {

		if (choice == 1) {

			if (!(Collection.empty())) {
				cout << "Car inventory: " << endl;
				PrintCollection(Collection);
			}
			else {
				cout << setw(53) << "> Error: There are no cars in the collection." << endl << endl;
			}

		}
		else if (choice == 2) {
			cout << "Adding a car to the collection..." << endl;
			cout << setw(23) << "> Enter make : ";
			cin >> name;
			cout << setw(23) << "> Enter year : ";
			cin >> year;

			Car Car1(name, year);
			Collection.push_back(Car1);

			cout << setw(26) << "> Done. Car added." << endl << endl;

		}
		else if (choice == 3) {

				if (!(Collection.empty())) {


					cout << "Removing a car from the collection..." << endl;
					cout << setw(48) << "> Enter the number of the car to remove:" << endl;

					PrintSelection(Collection);

					cout << setw(18) << "> Choice: ";
					cin >> choice2;

					Collection.erase(Collection.begin() + (choice2)-1);
					cout << setw(28) << "> Done. Car removed." << endl;

				}
				else {
					cout << setw(16) << "> Error!" << endl << endl;
				}

		}
		else if (choice == 4) {
			if (!(Collection.empty())) {

				cout << "Accelerating a car..." << endl;
				cout << setw(52) << "> Enter the number of the car to accelerate:" << endl;

				PrintSelection(Collection);

				cout << setw(18) << "> Choice: ";
				cin >> choice2;
				Collection.at((choice2 - 1)).accelerate();

			}
			else {
				cout << setw(16) << "> Error!" << endl << endl;
			}
		}
		else if (choice == 5) {

			if (!(Collection.empty())) {

				cout << "Braking a car..." << endl;
				cout << setw(47) << "> Enter the number of the car to brake:" << endl;

				PrintSelection(Collection);

				cout << setw(18) << "> Choice: ";
				cin >> choice2;

				Collection.at((choice2 - 1)).brake();
			}
			else {
				cout << setw(16) << "> Error!" << endl;
			}
		}
		else if( choice < 1 || choice > 6){
			cout << "Error!" << endl << endl;
		}
		else {
			cout << "Program ending." << endl;
			break;
		}
	}

	cout << endl << "I attest that this code is my original programming work, and that I received" << endl
		<< "no help creating it.I attest that I did not copy this code or any portion of this" << endl
		<< "code from any source." << endl << endl;

	return 0;
}