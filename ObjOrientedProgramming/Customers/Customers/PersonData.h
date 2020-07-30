#ifndef PERSONDATA_H
#define PERSONDATA_H
#include <iostream>
#include <string>
using namespace std;

class PersonData {
private:
	string lastName;
	string firstName;
	string address;
	string city;
	string state;
	int zip;
	int phone;

public:
	PersonData() {
		lastName = "";
		firstName = "";
		address = "";
		city = "";
		state = "";
		zip = 0;
		phone = 0;
	}
	PersonData(string lname, string fname, string add  , string city, string state, int zip, int pnum) {
		lastName = lname;
		firstName = fname;
		address = add;
		city = "";
		state = "";
		zip = 0;
		phone = 0;
	}


};

#endif
