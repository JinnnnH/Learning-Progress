/*------------------------------------------------------------
		Ferry
--------------------------------------------------------------
- Shiptype: string
- ShipDesignation: string
- NoOfCrewMembers: int
- NuclearPowered: bool
- MaxSpeed: int
--------------------------------------------------------------
+ NavyShip()
+ NavyShip(st: string, sd: string, num: int, n: bool, ms: int)
+ ValidationNavy(): bool
+ PrintNavyShip(): void
+ getShiptype(): string
+ getShipDesignation(): string
+ getNoOfCrewMembers(): int
+ getNuclearPowered(): bool
+ getMaxSpeed(): int
+ setPassengerCapacity(Shiptype: string): void
+ setShipDesignation(sd: string): void
+ setNoOfCrewMembers(num: int): void
+ setNuclearPowered(n: bool): void
+ void setMaxSpeed(ms: double): void
-------------------------------------------------------------*/


#ifndef NAVYSHIP_H
#define NAVYSHIP_H
#include "Ship.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class NavyShip : public Ship {
private:
	string ShipType;
	string ShipDesignation;
	int NoOfCrewMembers;
	bool NuclearPowered;
	int MaxSpeed;

public:
	NavyShip() : Ship() {
		ShipType = "";
		ShipDesignation = "";
		NoOfCrewMembers = 0;
		NuclearPowered = false;
		MaxSpeed = 0;
	}
	NavyShip(string reg, string home, string n, int len, int dis, 
		string stype, string sdes, int num, bool nuc, int max) : Ship(reg, home, n, len, dis) {

		ShipType = stype;
		ShipDesignation = sdes;
		NoOfCrewMembers = num;
		NuclearPowered = nuc;
		MaxSpeed = max;
	}
	bool ValidationNavy() {
		int counter = 0;

		if (ShipType.empty()) {
			cout << "Ship type cannot be empty!" << endl;
		}
		for (int i = 0; i < ShipType.size(); i++) {
			if (isalpha(ShipType.at(i)) || isspace(ShipType.at(i))) {
				continue;
			}
			else {
				cout << "The ship type should be formed with alphabets only!" << endl;
				counter++;
				break;
			}
		}
		if (ShipDesignation.empty()) {
			cout << "Ship designation cannot be empty!" << endl;
			counter++;
		}
		if (NoOfCrewMembers == 0) {
			cout << "The number of crewmember cannot be 0!" << endl;
			counter++;
		}
		if (NoOfCrewMembers < 100 || NoOfCrewMembers > 5000) {
			cout << "The number of crew member should be between 100 and 5000 people" << endl;
			counter++;
		}
		if (MaxSpeed == 0) {
			cout << "The maximum speed of ship cannot be 0!" << endl;
			counter++;
		}
		if (MaxSpeed < 15 || MaxSpeed > 100) {
			cout << "The maximum speed should be between 15 and 100 meters/second" << endl;
			counter++;
		}
		if (counter > 0) {
			return true;
		}
		else {
			return false;
		}


	}
	void PrintNavyShip(){
		if (ValidationNavy() || PrintShip()) {
			cout << "Please enter again with correct data!" << endl;
		}
		else {
			cout << "\t> Type: " << getShipType() << endl
				 << "\t> Designation: " << getShipDesignation() << endl
				 << "\t> Crew: " << getNoOfCrewMembers() << endl
				 << "\t> Nuclear: " << getNuclearPowered() << endl
				 << "\t> Max Speed: " << getMaxSpeed() << endl << endl;
		}
	}
	string getShipType() { return ShipType; }
	string getShipDesignation() { return ShipDesignation; }
	int getNoOfCrewMembers() { return NoOfCrewMembers; }
	bool getNuclearPowered() { return NuclearPowered; }
	int getMaxSpeed() { return MaxSpeed; }
	void setPassengerCapacity(string stype) { ShipType = stype; }
	void setShipDesignation(string sdes) { ShipDesignation = sdes; }
	void setNoOfCrewMembers(int num) { NoOfCrewMembers = num; }
	void setNuclearPowered(bool nuc) { NuclearPowered = nuc; }
	void setMaxSpeed(double max) { MaxSpeed = max; }
};

#endif
