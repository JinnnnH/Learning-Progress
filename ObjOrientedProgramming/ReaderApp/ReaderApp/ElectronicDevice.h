/*-----------------------------------------------------------
		ElectronicDevice
-------------------------------------------------------------
-type: string
-OS: string
-memory: int
-------------------------------------------------------------
+ElectronicDevice()
+ElectronicDevice(string, string, int)
+PrintElectronic() void
+setType(ty: string): void
+setOS(os: string): void
+setMemory(my: int): void
+getType(): string
+getOS(): string
+getMemory(): int
-----------------------------------------------------------*/

#ifndef ELECTRONICDEVICE_H
#define ELECTRONICDEVICE_H
#include <iostream>
#include <string>
using namespace std;

class ElectronicDevice {
private:
	string type;
	string OS;
	int memory;

public:
	ElectronicDevice() {
		type = "";
		OS = "";
		memory = 0;
	}
	ElectronicDevice(string tp, string os, int my) {
		type = tp;
		OS = os;
		memory = my;
	}
	void PrintElectronic() {
		cout << "\t> App type: " << type << endl;
		cout << "\t> Operarting system required: " << OS << endl;
		cout << "\t> Memory required: "<< memory << "G"<< endl << endl;
	}
	void setType(string ty) { type = ty; }
	void setOS(string os) { OS = os; }
	void setMemory(int my) { memory = my; }
	string getType() { return type; }
	string getOS() { return OS; }
	int getMemory() { return memory; }
};
#endif
