// Lab 7-1
// Chair.h
#ifndef CHAIR_H
#define CHAIR_H
#include "Furniture.h"

class Chair : public Furniture //FIRST NOTE BELOW
{
private:
	int legs;
	string color;
public:
	//constructors
	Chair() : Furniture() //SECOND NOTE BELOW
	{
		legs = 0;
		color = "";
	}
	Chair(string b, int y, int l, string c) : Furniture(b, y) //THIRD NOTE BELOW
	{
		legs = l;
		color = c;
	}
	//other methods
	void printChair() {
		Furniture::print();
		cout << "Legs: " << legs << endl;
		cout << "Color: " << color << endl;
	}
};
#endif
