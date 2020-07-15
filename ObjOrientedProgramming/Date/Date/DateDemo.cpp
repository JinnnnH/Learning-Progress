#include "Date.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <sstream>
using namespace std;

int main() {
	int day, month, year;
	string str;
	vector<string>Month = { "January", "February", "March", "April",
							"May", "June", "July", "August", "September",
							"October", "November", "December" };

		cout << "Please input a date, starting with day followed by month then year (seperate by space)";
		getline(cin, str);
		stringstream(str) >> day >> month >> year;
		cout << endl;
		Date input(day, month, year);

		input.ShowRegularDate(Month);
		input.ShowMilitaryDate(Month);

	cout << endl;
	cout << "I attest that this code is my original programming work, and that I received" << endl
		<< "no help creating it.I attest that I did not copy this code or any portion of this" << endl
		<< "code from any source." << endl;

	return 0;
}