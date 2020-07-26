/*
------------------------------------------------
		  Date
------------------------------------------------
- day: int
- month: int
- year : int
------------------------------------------------
+Date()
+Date(int, int, int)
+setDay(dd: int): void
+setMonth(mm: int): void
+setYear(yy: int): void
+CheckDate(): bool
+PrintDate(): void
------------------------------------------------
*/

#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

class Date {
private:
	int day;
	int month;
	int year;

public:
	//contructor
	Date() {
		day = 0;
		month = 0;
		year = 0;
	}

	//contructors
	Date(int dd, int mm, int yy) { 
		setDay(dd);
		setMonth(mm);
		setYear(yy);
	}

	//Mutator
	void setDay(int dd) {		
		day = dd;
	}
	void setMonth(int mm) {
		month = mm;
	}
	void setYear(int yy) {
		year = yy;
	}

	//data validation
	bool CheckDate() {
		if (day < 1 || day > 31) {
			cout << "\t>The day should be between 1 and 31." << endl;
			return true;
		}

		if (year < 1900 || year > 2020) {
			cout << "\t>The year should be between 1900 and 2020." << endl;
			return true;
		}

		if (month < 1 || month > 12) {
			cout << "\t>The month should be between 1 and 12." << endl;
			return true;
		}

		if (month == 4 || (month == 6) || (month == 9) || (month == 11)) {
			day > 30 ? cout << "\t>The day should be between 1 and 30 "
							<< "for the month of " << month << endl
						: cout << "" << endl;
			return(day > 30);
		}

		if (month == 2 && year % 4 == 0) {
			day > 29 ? cout << "\t>The day should be between 1 and 29"
				<< " for the Feburary and the year of "
				<< year << endl
				: cout << "";
			return (day > 29);
		}
		else if (month == 2 && year % 4 != 0) {
			day > 28 ? cout << "\t>The day should be between 1 and 28"
				<< " for the Feburary and the year of "
				<< year << endl
				: cout << "";
			return (day > 28);
		}

		return false;
	}

	//printing data  
	void PrintDate() {
			cout << "\t>Date: " << month << "/" << day << "/" << year << endl;
	}
};
#endif