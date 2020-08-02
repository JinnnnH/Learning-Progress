/*
---------------------- -
Customer
---------------------- -
-custNr: int
- lName : string // last name
- fName : string // first name
---------------------- -
+getCustNr() : int
+ getLName() : string
+ getFName() : string
+ setFName(string) : void
+ setLName(string) : void
+ setCustNr(int) : void
----------------------
*/
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
using namespace std;

class Customer {
private:
	int custNr;
	string lName;
	string fName;

public:
	//constructor
	Customer(int cust, string ln, string fn) {
		custNr = cust;
		lName = ln;
		fName = fn;
	}

	//accessors
	int getCustNr() 
		{return custNr;}
	string getLName() 
		{return lName;}
	string getFName() 
		{return fName;}

	//mutators
	void setFName(string fn)
		{fName = fn;}
	void setLName(string ln) 
		{lName = ln;}
	void setCustNr(int cust) 
		{custNr = cust;}

};

#endif