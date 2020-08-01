/*--------------------------------------------------------------------------------------------
		ReaderApp
----------------------------------------------------------------------------------------------
-AppName: string
-AppCost: float
----------------------------------------------------------------------------------------------
+ReaderApp() : PublishedWork(), ElectronicDevice()
+ReaderApp(string, float) : PublishedWork(string, string, int), ElectronicDevice(string, int)
+PrintReader(): void
+setAppName(aname: string): void
+setAppCost(app: float): void
+getAppName(): string
+getAppCost(): float
----------------------------------------------------------------------------------------------*/

#ifndef READERAPP_H
#define READERAPP_H
#include "PublishedWork.h"
#include "ElectronicDevice.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class ReaderApp : public PublishedWork, public ElectronicDevice {
private:
	string AppName;
	float AppCost;

public:
	ReaderApp() : PublishedWork(), ElectronicDevice() {
		AppName = "";
		AppCost = 0.0;
	}
	ReaderApp(string aname, float app, string tp, string os, int my, string au, int yy)
		:PublishedWork(au, yy), ElectronicDevice(tp, os, my) {
		AppName = aname;
		AppCost = app;
	}
	void PrintReader() {
		cout << "\t> App Name: "<< AppName << endl;
		AppCost ? cout << fixed << setprecision(2)<< "\t> App price: $" << AppCost << endl
				: cout << "\t> App price: free" << endl;
		PublishedWork :: PrintPublished();
		ElectronicDevice :: PrintElectronic();
	}
	void setAppName(string aname) { AppName = aname; }
	void setAppCost(float app) { AppCost = app; }
	string getAppName() { return AppName; }
	float getAppCost() { return AppCost; }
};
#endif

