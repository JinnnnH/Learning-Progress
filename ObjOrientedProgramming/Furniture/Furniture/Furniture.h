// Lab 7-1
// Furniture.h
#ifndef FURNITURE_H_
#define FURNITURE_H_
#include <iostream>
#include <iomanip>
using namespace std;

class Furniture
{
private:
	string brand;
	int yearMade;

public:
	//constructors
	Furniture()
	{
		brand = "";
		yearMade = 0;
	}
	Furniture(string b, int y)
	{
		brand = b;
		yearMade = y;
	}
	//mutator methods
	void setYear(int y) { yearMade = y; }
	void setBrand(string b) { brand = b; }
	//other methods
	void print()
	{
		cout << "Brand: " << brand << endl;
		cout << "Year made: " << yearMade << endl;
	}
};
#endif