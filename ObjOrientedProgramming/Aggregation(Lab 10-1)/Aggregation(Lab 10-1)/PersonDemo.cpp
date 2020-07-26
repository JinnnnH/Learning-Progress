//***************************************************************************
//Program Name: PersonDemo
//Author: Jin Han Ho
//IDE Used: Visual Studio 2019
//Program description: this program will output the information of a person
//***************************************************************************

#include <iostream>
#include "Person.h"
using namespace std;

int main()
{	
	Date dob(29, 2, 2000);				//creating date object
	Person ppl(1314520789, dob);		//creating person object

	cout << "Person's information: " << endl;
	ppl.PrintPerson();							//output data

	cout << endl << endl << "I attest that this code is my original programming work, and that I received" << endl
		<< "no help creating it.I attest that I did not copy this code or any portion of this" << endl
		<< "code from any source." << endl;

	return 0;
}
