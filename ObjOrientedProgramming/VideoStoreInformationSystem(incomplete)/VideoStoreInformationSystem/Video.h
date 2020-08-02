/*
----------------------------------------
Video
----------------------------------------
- title: string
- inventoryNumber : int
- checkedOut : bool
- overdue : bool
- customer : int //represents which customer is currently renting the video
----------------------------------------
+ Video(string, int, bool, bool, int)
+ getTitle() : string
+ getInvNr() : int
+ getCheckedOut() : bool
+ getOverdue() : bool
+ getCustomer() : int
+ setCheckedOut(bool) : void
+ setTitle(string) : void
+ setInvNr(int) : void
+ setCustomer(int) : void
----------------------------------------
*/
#ifndef VIDEO_H
#define VIDEO_H
#include <iostream>
#include <string>
using namespace std;

class Video {
private:
	string title;
	int inventory;
	bool checkedOut;
	int overdue;
	int customer;

public:
	//constructors
	Video(string tit, int inv, bool check, bool over, int cus) {
		title = tit;
		inventory = inv;
		checkedOut = check;
		overdue = over;
		customer = cus;
	}

	//accessor
	string getTitle() 
		{return title;}
	int getInvNr() 
		{return inventory;}
	bool getCheckedOut()
		{return checkedOut;}
	bool getOverdue()
		{return overdue;}
	int getCustomer() 
		{return customer;}

	//mutators
	void setCheckedOut(bool check) 
		{checkedOut = check;}
	void setTitle(string tit)
		{title = tit;}
	void setInvNr(int inv)
		{inventory = inv;}
	void setCustomer(int cus)
		{customer = cus;}

};

#endif