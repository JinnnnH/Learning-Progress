#include "Date.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

Date::Date(int dd, int mm, int yy) {
	day = dd;
	month = mm;
	year = yy;
}

bool Date::CheckDate() {
	if (day < 1 || day > 31) {
		return true;
	}

	if (year < 1000 || year > 3000) {
		return true;
	}

	if (month < 1 || month > 12) {
		return true;
	}

	if (month == 4 || (month == 6) || (month == 9) || (month == 11)) {
		return(day > 30);
	}

	if (month == 2 && year % 4 == 0) {
		return (day > 29);
	}
	else if (month == 2 && year % 4 != 0) {
		return (day > 28);
	}

	return false;
}

void Date::ShowRegularDate(vector<string>Month) {
	if (CheckDate()) {
		cout << "Error!Please input correct date again" << endl;
	}
	else {
		string mm;
		Month.at(month - 1).at(1) = toupper(Month.at(month - 1).at(1));
		Month.at(month - 1).at(2) = toupper(Month.at(month - 1).at(2));
		Month.at(month - 1).at(3) = toupper(Month.at(month - 1).at(3));
		mm = Month.at(month - 1).substr(0, 3);

		cout << setfill('0') << setw(2) << day << mm << year << endl;
	}
}

void Date::ShowMilitaryDate(vector<string>Month) {
	if (!(CheckDate())) {
		cout << Month.at(month - 1) << " " << day << ", " << year << endl;
	}
} 
