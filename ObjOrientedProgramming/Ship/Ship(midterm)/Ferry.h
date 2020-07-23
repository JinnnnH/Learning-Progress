/*-----------------------------------------------------------
		Ferry
-------------------------------------------------------------
- registry : string
- homeport : string
- name : string
- length : int
- displacement : double
-------------------------------------------------------------
+ Ferry()
+ Ferry(p: int, c: int, o: string, des: string, tp: double)
++ ValidationFerry(): bool
+ PrintFerry(): void
+ getPassengerCapacity(): int
+ getCarCapcaity(): int
+ getOrigin(): string
+ getDestination(): string
+ getTicketPrice(): int
+ setPassengerCapacity(p: int): void
+ setCarCapcaity(c: int): int
+ setOrigin(o: string): void
+ setDestination(des: string): void
+ setTicketPrice(tp: double): void
------------------------------------------------------------*/

#ifndef FERRY_H
#define FERRY_H
#include "Ship.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Ferry : public Ship {
private:
	int PassengerCap;
	int CarCap;
	string Origin;
	string Destination;
	double TicketPrice;

public:
	Ferry() : Ship() {
		PassengerCap = 0;
		CarCap = 0;
		Origin = "";
		Destination = "";
		TicketPrice = 0.0;
	};
	Ferry(string reg, string home, string n, int len, int dis, 
		int pas, int car, string ori, string des, double tp) : Ship(reg, home, n, len, dis) {

		PassengerCap = pas;
		CarCap = car;
		Origin = ori;
		Destination = des;
		TicketPrice = tp;
	}
	bool ValidationFerry() {
		int counter = 0;

		if (PassengerCap == 0) {
			cout << "Passenger Capacity cannot be 0!" << endl;
		}
		if (CarCap == 0) {
			cout << "Car Capacity cannot be 0!" << endl;
			counter++;
		}
		if (Origin.empty()) {
			cout << "The Origin cannot be empty!" << endl;
			counter++;
		}
		for (int i = 0; i < Origin.size(); i++) {
			if (isalpha(Origin.at(i))) {
				continue;
			}
			else {
				cout << "Origin should be formed with alphabets only!" << endl;
				counter++;
				break;
			}
		}
		if (Destination.empty()) {
			cout << "The Origin cannot be empty!" << endl;
			counter++;
		}
		for (int i = 0; i < Destination.size(); i++) {
			if (isalpha(Destination.at(i)) || isspace(Destination.at(i))) {
				continue;
			}
			else {
				cout << "The destination should be formed with alphabets only!" << endl;
				counter++;
				break;
			}
		}
		if (TicketPrice == 0) {
			cout << "The ticket price cannot be 0!" << endl;
			counter++;
		}
		if (TicketPrice < 0 || TicketPrice > 100) {
			cout << "The ticket price should be between 1 and 100 dollar" << endl;
			counter++;
		}
		if (counter > 0) {
			return true;
		}
		else {
			return false;
		}
	}
	void PrintFerry() {

		if (ValidationFerry() || PrintShip()) {
			cout << "Please enter again with correct data!" << endl;
		}
		else {
			cout << "\t> Passenger Capacity: " << getPassengerCapacity() << endl
				 << "\t> Car Capacity: " << getCarCapcaity() << endl
				 << "\t> Origin: " << getOrigin() << endl
				 << "\t> Destination: " << getDestination() << endl
				 << "\t> Ticket Price: " << getTicketPrice() << endl << endl;
		}
	}
	int getPassengerCapacity() { return PassengerCap; }
	int getCarCapcaity() { return CarCap; }
	string getOrigin() { return Origin; }
	string getDestination() { return Destination; }
	double getTicketPrice() { return TicketPrice; }
	void setPassengerCapacity(int pas) { PassengerCap = pas; }
	void setCarCapcaity(int car) { CarCap = car; }
	void setOrigin(string ori) { Origin = ori; }
	void setDestination(string des) { Destination = des; }
	void setTicketPrice(double tp) { TicketPrice = tp; }

};
#endif
