/*
-----------------------------------------------------------------------
		  Person
-----------------------------------------------------------------------
- identity: int
- birthday: Date
-----------------------------------------------------------------------
+Person(id: int, dob: Date): birthday(dob)
+PrintPerson(): void
-----------------------------------------------------------------------
*/

#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include "Date.h"
using namespace std;

class Person {
private:
	int identity;
	Date birthday;

public:
	//contructor
	Person(int id, Date dob) : birthday(dob){		//passing values into Person And aggregation
		identity = id;
	}

	//printing data
	void PrintPerson() {
		if (!(birthday.CheckDate())) {
			birthday.PrintDate();
			cout << "\t>Identity(SSN): " << identity << endl;
		}
		else {
			cout << "\t>Please try again!" << endl;
		}
	}
};
#endif

