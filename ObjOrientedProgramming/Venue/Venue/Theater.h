/*
--------------------------------------------------------------------------------------
		  Theater
--------------------------------------------------------------------------------------
-VenueName: string
-VenueAddress: string
-VenueCity: string
-AverageConcessionsSales: float
--------------------------------------------------------------------------------------
+Theater() : Venue()
+Theater(string, string, string, float, string, int, int) : Venue(string, int, float)
+setVenueName(name: string): void
+setVenueAddress(address: string): void
+setVenueCity(city: string): void
+setAverageConcessionsSales(avg: float): void
+getVenueName(): string
+getVenueAddress(): string
+getVenueCity(): string
+getAverageConcessionsSales(): float
+PotentialRevenue(avg: float): void
+ValidationTheater(): bool
+PrintTheater(): void
---------------------------------------------------------------------------------------
*/
#ifndef THEATER_H
#define THEATER_H
#include "Venue.h"
#include <iostream>
#include <string>
using namespace std;

class Theater : public Venue {
protected:
	string VenueName;
	string VenueAddress;
	string VenueCity;
	float AverageConcessionsSales;

public:
	//constructors
	Theater() : Venue(){
		VenueName = "";
		VenueAddress = "";
		VenueCity = "";
		AverageConcessionsSales = 0.0;
	}

	Theater(string name, string address, string city, float avg, string type, int cap, int price) : Venue(type, cap, price){
		setVenueName(name);
		setVenueAddress(address);
		setVenueCity(city);
		setAverageConcessionsSales(avg);
	}

	//accessors
	void setVenueName(string name) 
		{ VenueName = name; }

	void setVenueAddress(string address) 
		{ VenueAddress = address; }

	void setVenueCity(string city) 
		{ VenueCity = city; }

	void setAverageConcessionsSales(float avg) 
		{ AverageConcessionsSales = avg; }

	//mutators
	string getVenueName()
		{return VenueName;}

	string getVenueAddress()
		{return VenueAddress;}

	string getVenueCity()
		{return VenueCity;}

	float getAverageConcessionsSales()
		{return AverageConcessionsSales;}
	
	void PotentialRevenue(float avg) {
		AverageConcessionsSales = avg;
		Venue :: PotentialRevenue(AverageConcessionsSales);			//redefining base function
	}

	//data validation
	bool ValidationTheater() {
		if (VenueName.empty()) {
			cout << "\t>Venue name cannot be empty!";
			return false;
		}
		if (VenueAddress.empty()) {
			cout << "\t>Venue address cannot be empty!";
			return false;
		}
		if (VenueCity.empty()) {
			cout << "\t>Venue city cannot be empty!";
			return false;
		}
		if (AverageConcessionsSales < 0 || AverageConcessionsSales > 20000) {
			cout << "\t>Average concessions sales should be between 0 and 20000." << endl;
			return false;
		}
		return true;
	}

	//print data
	void PrintTheater() {
		if (ValidationTheater() && Venue::ValidationVenue()) {
			PotentialRevenue(AverageConcessionsSales);
			cout << "\t>Name of Venue: " << getVenueName() << endl;
			cout << "\t>Venue address: " << getVenueAddress() << endl;
			cout << "\t>City of Venue: " << getVenueCity() << endl;
			Venue::PrintVenue();
			cout << "\t>Average Concessions Sales: $" << getAverageConcessionsSales() << endl;
			cout << "\t>Potential Revenue: $" << Venue::PotentialRevenue(AverageConcessionsSales) << endl << endl;
		}
		else {
			cout << endl << "\t>Please correct the data." << endl;
		}
	}
};
#endif
