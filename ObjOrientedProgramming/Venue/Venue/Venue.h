/*
------------------------------------------------
		  Venue
------------------------------------------------
-TypeVenue: string
-Capacity: int
-BasePrice: int
------------------------------------------------
+Venue()
+Venue(string, int, int)
+setTypeVenue(address: string): void
+setCapacity(cap: int): void
+setBasePrice(price: float): void
+getTypeVenue(): string
+getCapacity(): int
+getBasePrice(): float
+PotentialRevenue(avg: float): float
+ValidationVenue(): bool
+PrintVenue(): void
------------------------------------------------
*/
#ifndef VENUE_H
#define VENUE_H
#include <iostream>
#include <string>
using namespace std;

class Venue {
protected:
	string TypeVenue;
	int Capacity;
	float BasePrice;

public:
	//constructors
	Venue() {
		TypeVenue = "";
		Capacity = 0;
		BasePrice = 0.0;
	}

	Venue(string type, int cap, int price) {
		setTypeVenue(type);
		setCapacity(cap);
		setBasePrice(price);
	}

	//accessors
	void setTypeVenue(string address)
		{TypeVenue = address;}

	void setCapacity(int cap)
		{Capacity = cap;}

	void setBasePrice(float price)
		{BasePrice = price;}

	//mutators
	string getTypeVenue()
		{return TypeVenue;}

	int getCapacity()
		{return Capacity;}

	float getBasePrice()
		{return BasePrice;}

	float PotentialRevenue(float avg)
		{return (avg + Capacity * BasePrice);}

	//data validation
	bool ValidationVenue() {
		if (TypeVenue.empty()) {
			cout << "\t>Type of venue cannot be empty!";
			return false;
		}
		if (Capacity < 50 || Capacity > 1000) {
			cout << "\t>Capacity should be between 50 and 1000." << endl;
			return false;
		}
		if (BasePrice < 10 || BasePrice > 200) {
			cout << "\t>Base price should be between 10 and 200." << endl;
			return false;
		}
		return true;
	}

	//print data
	void PrintVenue() {
			cout << "\t>Type of venue: " << getTypeVenue() << endl;
			cout << "\t>Capacity: " << getCapacity() << " people" << endl;
			cout << "\t>Base Price: $" << getBasePrice() << endl;
	}
};

#endif
