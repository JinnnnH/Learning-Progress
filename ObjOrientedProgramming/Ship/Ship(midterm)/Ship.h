/*-----------------------------------------------------------
		Ship
-------------------------------------------------------------
- registry : string
- homeport : string
- name : string
- length : int
- displacement : int
-------------------------------------------------------------
+ Ship()
+ Ship(r: string, h: string, n: string, l: int, d: double)
+ Validation(): bool
+ PrintShip(): void
+ getRegistry(): string
+ getHomePort(): string
+ getName(): string
+ getLength(): int
+ getDisplacement(): int
+ setRegistry(r: string): viod
+ setHomePort(h: string): void
+ setName(n: string): void
+ setLength(l: int): void
+ setDisplacement(d: int): void
-----------------------------------------------------------*/

#ifndef SHIP_H
#define SHIP_H
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Ship {
private:
	string Registry;
	string HomePort;
	string name;
	int length;
	int Displacement;

public:
	Ship() {
		Registry = "";
		HomePort = "";
		name ="";
		length = 0;
		Displacement = 0;
	}
	Ship(string reg, string home, string n, int len, int dis) {
		Registry = reg;
		HomePort = home;
		name = n;
		length = len;
		Displacement = dis;
	}
	bool Validation() {
			int counter = 0;

			if (Registry.empty()) {
				cout << "Registry cannot be empty!" << endl;
			}
			for (int i = 0; i < Registry.size(); i++){
				if (isalpha(Registry.at(i))) {
					continue;
				}
				else {
					cout << "The registry should be formed with alphabets only!" << endl;
					counter++;
					break;
				}
			}
			if (HomePort.empty()) {
				cout << "Homeport cannot be empty!" << endl;
				counter++;
			}
			for (int i = 0; i < HomePort.size(); i++) {
				if (isalpha(HomePort.at(i))) {
					continue;
				}
				else {
					cout << "The homeport should be formed with alphabets only!" << endl;
					counter++;
					break;
				}
			}
			if (name.empty()) {
				cout << "The name cannot be empty!" << endl;
				counter++;
			}
			if (length == 0) {
				cout << "The length of ship cannot be 0!" << endl;
				counter++;
			}
			if (length <= 200 || length > 2000) {
				cout << "The length of ship should be between 200 and 2000 feet" << endl;
				counter++;
			}
			if (Displacement == 0) {
				cout << "The displacement of ship cannot be 0!" << endl;
				counter++;
			}
			if (Displacement <= 4000 || Displacement > 200000) {
				cout << "The displacement of ship should be between 4000 and 200000 tons" << endl;
				counter++;
			}
			if (counter > 0) {
				return true;
			}
			else {
				return false;
			}
	}
	bool PrintShip() {
		if (Validation()) {
			return true;
		}
		else {
			cout << "\t> Registry: " << getRegistry() << endl
				 << "\t> Homeport: " << getHomePort() << endl
				 << "\t> Length: " << getLength() << endl
				 << "\t> Displacement: " << getDisplacement() << endl;
		}
		return false;
	}
	string getRegistry(){return Registry;}
	string getHomePort() {return HomePort;}
	string getName() {return name;}
	int getLength() {return length;}
	int getDisplacement() {return Displacement;}
	void setRegistry(string reg) {Registry = reg;}
	void setHomePort(string home) {HomePort = home;}
	void setName(string n) {name = n;}
	void setLength(int len) {length = len;}
	void setDisplacement(int dis) {Displacement = dis;}
};
#endif
