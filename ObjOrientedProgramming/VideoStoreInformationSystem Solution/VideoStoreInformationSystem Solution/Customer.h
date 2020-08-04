//Customer.h
/*
-----------------------
Customer
-----------------------
- custNr: int
- lName: string // last name
- fName: string // first name
-----------------------
+ getCustNr() : int
+ getLName() : string
+ getFName() : string
+ setFName(string) : void
+ setLName(string) : void
+ setCustNr(int) : void
----------------------
*/
#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <iostream>
using namespace std;

class Customer
{
private:
	int custNr;
	string lName;
	string fName;

public:
	Customer(int c, string l, string f)
	{
		custNr = c;
		lName = l;
		fName = f;
	}

	int getCustNr()
	{
		return custNr;
	}
	string getLName()
	{
		return lName;
	}
	string getFName()
	{
		return fName;
	}
	void setFName(string f)
	{
		fName = f;
	}
	void setLName(string l)
	{
		lName = l;
	}
	void setCustNr(int c)
	{
		custNr = c;
	}
};




#endif