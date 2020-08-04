//Video.h
/*
-----------------------
Video
-----------------------
- title: string
- inventoryNumber: int
- checkedOut: bool
- overdue: bool
- customer: int //represents which customer has rented the video
-----------------------
+ Video (string, int, bool, bool, int)
+ getTitle() : string
+ getInvNr() : int
+ getCheckedOut() : bool
+ getOverdue() : bool
+ getCustomer() : int
+ setCheckedOut(bool) : void
+ setTitle(string) : void
+ setInvNr(int) : void
+ setCustomer(int) : void
----------------------
*/

#ifndef VIDEO_H
#define VIDEO_H
#include <iostream>
using namespace std;

class Video
{
private:
	string title;
	int inventoryNumber;
	bool checkedOut;
	bool overdue;
	int customer;

public:
	// constructor
	Video(string t, int i, bool c, bool o, int cu)
	{
		title = t;
		inventoryNumber = i;
		checkedOut = c;
		overdue = o;
		customer = cu;
	}

	// accessors
	string getTitle()
	{
		return title;
	}
	int getInvNr()
	{
		return inventoryNumber;
	}
	bool getCheckedOut()
	{
		return checkedOut;
	}
	bool getOverdue()
	{
		return overdue;
	}
	int getCustomer()
	{
		return customer;
	}

	// mutators
	void setCheckedOut(bool c)
	{
		checkedOut = c;
	}
	void setTitle(string t)
	{
		title = t;
	}
	void setInvNr(int i)
	{
		inventoryNumber = i;
	}
	void setCustomer(int c)
	{
		customer = c;
	}
};

#endif
