//main.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Video.h"
#include "Customer.h"
using namespace std;

int mainMenu();
void checkOutVideos(vector<Video>&, vector<Customer>);
void checkInVideos(vector<Video>&);
void runReports(vector<Video>&, vector<Customer>&);
void manageInventory(vector<Video>&);
void manageCustomers(vector<Customer>&, vector<Video>);
void runOverdue(vector<Video>&, vector<Customer>&);
void writeVideos(vector<Video>&);
void writeCustomers(vector<Customer>&);
void addVideo(vector<Video>&);
void deleteVideo(vector<Video>&);
void updateVideo(vector<Video>&);
char getYN();
void addCustomer(vector<Customer>&);
void deleteCustomer(vector<Customer>&);
void updateCustomer(vector<Customer>&, vector<Video>);

const string infile_v_name = "videos.txt";
const string infile_c_name = "customers.txt";
const int MIN_CUSTNR = 1000;
const int MAX_CUSTNR = 9999;

int main()
{
	//housekeeping
	ifstream infile_v(infile_v_name);
	ifstream infile_c(infile_c_name);
	string title;
	bool status, checkedOut;
	int number, cust, choice, count;
	vector<Video> inventory;
	string line, lName, fName;
	vector<Customer> customers;

	//process video inventory
	while (getline(infile_v, title))
	{
		getline(infile_v, line);
		stringstream ss(line);
		ss >> number;
		ss >> checkedOut;
		ss >> status;
		ss >> cust;
		inventory.push_back({ title, number, checkedOut, status, cust });
	}
	infile_v.close();

	//process customer database
	while (getline(infile_c, lName))
	{
		getline(infile_c, fName);
		getline(infile_c, line);
		stringstream ss(line);
		ss >> number;
		customers.push_back({ number, lName, fName });
	}
	infile_c.close();

	//main menu
	do
	{
		choice = mainMenu();
		switch (choice)
		{
		case 1: checkOutVideos(inventory, customers);
			break;
		case 2: checkInVideos(inventory);
			break;
		case 3: runReports(inventory, customers);
			break;
		case 4: manageInventory(inventory);
			break;
		case 5: manageCustomers(customers, inventory);
			break;
		case 6: cout << "Program ending.\n";
		}
	} while (choice != 6);


	return 0;
}

int mainMenu()
{
	int choice;
	cout << "\n***VIDEO STORE MAIN MENU***\n";
	cout << "[1] Check out videos\n";
	cout << "[2] Check in videos\n";
	cout << "[3] Run reports\n";
	cout << "[4] Manage inventory\n";
	cout << "[5] Manage customers\n";
	cout << "[6] Quit\n";
	cout << "Your choice: ";
	cin >> choice;
	while (choice < 1 or choice > 6)
	{
		cout << "\t> ERROR: choose 1-6 only: ";
		cin >> choice;
	}
	return choice;
}
void checkOutVideos(vector<Video>& v, vector<Customer> c)
{
	cout << "\n***VIDEO CHECK-OUT***\n";
	int selection;
	vector<int> available;
	cout << "Select video to check out:\n";
	for (unsigned int i = 0; i < v.size(); i++)
		if (!v[i].getCheckedOut())
			available.push_back(i);
	int nrAvailable = available.size(); // to clear Eclipse warning
	for (int i = 0; i < nrAvailable; i++)
		cout << "[" << i + 1 << "] " << v[available[i]].getInvNr() << " " << v[available[i]].getTitle() << endl;
	cout << "[" << nrAvailable + 1 << "] Cancel and return to main menu\n";
	cout << "Enter your choice: ";
	cin >> selection;
	while (selection < 1 or selection > nrAvailable + 1)
	{
		cout << "\t> ERROR: enter 1 - " << nrAvailable + 1 << " only: ";
		cin >> selection;
	}
	if (selection != nrAvailable + 1)
	{
		v[available[--selection]].setCheckedOut(true);

		int selection2;
		cout << "\nChoose the customer to rent this title:\n";
		for (unsigned int i = 0; i < c.size(); i++)
			cout << "[" << i + 1 << "] " << c[i].getLName() << ", "
			<< c[i].getFName() << " (" << c[i].getCustNr() << ")\n";
		cout << "Enter your choice: ";
		cin >> selection2;
		int c_size = c.size();  // to clear Eclipse warning
		while (selection2 < 1 or selection2 > c_size)
		{
			cout << "\t> ERROR: enter 1 - " << c.size() << " only: ";
			cin >> selection2;
		}
		v[available[selection]].setCustomer(c[--selection2].getCustNr());
	}
}

void checkInVideos(vector<Video>& v)
{
	cout << "\n***VIDEO CHECK-IN***\n";
	int selection;
	vector<int> available;
	cout << "Select video to check in:\n";
	for (unsigned int i = 0; i < v.size(); i++)
		if (v[i].getCheckedOut())
			available.push_back(i);
	int nrAvailable = available.size();
	for (int i = 0; i < nrAvailable; i++)
		cout << "[" << i + 1 << "] " << v[available[i]].getInvNr() << " " << v[available[i]].getTitle() << endl;
	cout << "[" << nrAvailable + 1 << "] Cancel and return to main menu\n";
	cout << "Enter your choice: ";
	cin >> selection;
	while (selection < 1 or selection > nrAvailable + 1)
	{
		cout << "\t> ERROR: enter 1 - " << nrAvailable + 1 << " only: ";
		cin >> selection;
	}
	if (selection != nrAvailable + 1)
		v[available[--selection]].setCheckedOut(false);
}

void runReports(vector<Video>& v, vector<Customer>& c)
{
	int choice;
	cout << "\n***RUN REPORTS***\n";
	cout << "[1] Overdue video report\n";
	cout << "[2] Write new video database\n";
	cout << "[3] Write new customer database\n";
	cout << "[4] Main menu\n";
	cout << "Your choice: ";
	cin >> choice;
	while (choice < 1 or choice > 4)
	{
		cout << "\t> ERROR: choose 1-4 only: ";
		cin >> choice;
	}
	switch (choice)
	{
	case 1: runOverdue(v, c);
		break;
	case 2: writeVideos(v);
		break;
	case 3: writeCustomers(c);
		break;
	}
}

void writeVideos(vector<Video>& v)
{
	string line;
	cout << "\n***WRITE NEW VIDEO DATABASE***\n";
	cout << "Enter new filename for video database (cannot be ";
	cout << infile_v_name << ": ";
	cin >> line;
	if (line == infile_v_name)
	{
		cout << "\t> ERROR: need a different filename: ";
		cin >> line;
	}
	ofstream outfile(line);
	for (unsigned int i = 0; i < v.size(); i++)
	{
		outfile << v[i].getTitle() << endl;
		outfile << v[i].getInvNr() << " " << v[i].getCheckedOut() << " ";
		outfile << v[i].getOverdue() << " " << v[i].getCustomer() << endl;
	}
	outfile.close();
}

void writeCustomers(vector<Customer>& c)
{
	string line;
	cout << "\n***WRITE NEW CUSTOMER DATABASE***\n";
	cout << "Enter new filename for customer database (cannot be ";
	cout << infile_c_name << ": ";
	cin >> line;
	if (line == infile_c_name)
	{
		cout << "\t> ERROR: need a different filename: ";
		cin >> line;
	}
	ofstream outfile(line);
	for (unsigned int i = 0; i < c.size(); i++)
	{
		outfile << c[i].getLName() << endl;
		outfile << c[i].getFName() << endl;
		outfile << c[i].getCustNr() << endl;
	}
	outfile.close();
}

void runOverdue(vector<Video>& v, vector<Customer>& c)
{
	bool atLeastOne = false;
	cout << "\n***OVERDUE VIDEOS***\n";
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i].getOverdue())
		{
			atLeastOne = true;
			cout << "Inventory #: " << v[i].getInvNr() << " Title: " << v[i].getTitle() << endl;
			cout << "\tCustomer #: " << v[i].getCustomer();
			//search thru customer vector to retrieve name
			for (unsigned int j = 0; j < c.size(); j++)
				if (v[i].getCustomer() == c[j].getCustNr())
					cout << " (" << c[j].getLName() << ", " << c[j].getFName() << ")\n";
		}
	}
	if (!atLeastOne) cout << "No videos overdue.\n";
}

void manageInventory(vector<Video>& v)
{
	int choice;
	cout << "\n***MANAGE INVENTORY***\n";
	cout << "[1] Add video to inventory\n";
	cout << "[2] Remove video from inventory\n";
	cout << "[3] Update video data\n";
	cout << "[4] Return to main menu\n";
	cout << "Your choice: ";
	cin >> choice;
	while (choice < 1 or choice > 4)
	{
		cout << "\t> ERROR: choose 1-4 only: ";
		cin >> choice;
	}
	switch (choice)
	{
	case 1: addVideo(v);
		break;
	case 2: deleteVideo(v);
		break;
	case 3: updateVideo(v);
	}
}

void addVideo(vector<Video>& v)
{
	string name;
	int number;
	cout << "Enter video name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Enter inventory number: ";
	cin >> number;
	Video temp({ name, number, false, false, 0 });
	v.push_back(temp);
}

void deleteVideo(vector<Video>& v)
{
	cout << "Enter video number to delete:\n";
	for (unsigned int i = 0; i < v.size(); i++)
		cout << "[" << i + 1 << "] " << v[i].getTitle() << endl;
	int choice;
	cin >> choice;
	int size = v.size(); // to eliminate an Eclipse warning
	while (choice < 1 or choice > size)
	{
		cout << "\t> ERROR: choose 1-" << v.size() << " only: ";
		cin >> choice;
	}
	choice--; //correct off-by-one error
	v.erase(v.begin() + choice);
	cout << "Video deleted.\n";
}

void updateVideo(vector<Video>& v)
{
	cout << "Enter video number to update:\n";
	for (unsigned int i = 0; i < v.size(); i++)
		cout << "[" << i + 1 << "] " << v[i].getTitle() << endl;
	int choice;
	cin >> choice;
	int size = v.size();  // to eliminate an Eclipse warning
	while (choice < 1 or choice > size)
	{
		cout << "\t> ERROR: choose 1-" << v.size() << " only: ";
		cin >> choice;
	}
	choice--; //correct off-by-one error
	cout << "Title currently is: ";
	cout << v[choice].getTitle();
	cout << ". Update title? ";
	char YN = getYN();
	if (YN == 'Y')
	{
		cout << "Enter new title: ";
		string line;
		getline(cin, line);
		v[choice].setTitle(line);
	}
	cout << "Inventory # currently is: ";
	cout << v[choice].getInvNr();
	cout << ". Update inventory number? ";
	YN = getYN();
	if (YN == 'Y')
	{
		cout << "Enter new inventory number: ";
		int number;
		cin >> number;
		v[choice].setInvNr(number);
	}
}

char getYN()
{
	cout << "Y/N: ";
	char entry;
	cin >> entry;
	entry = toupper(entry);
	while (entry != 'Y' and entry != 'N')
	{
		cout << "\t> ERROR: Y/N only: ";
		cin >> entry;
	}
	cin.ignore();
	return entry;
}

void manageCustomers(vector<Customer>& c, vector<Video> v)
{
	cout << "\n***MANAGE CUSTOMERS***\n";
	cout << "[1] List customers\n";
	cout << "[2] Add customer\n";
	cout << "[3] Delete customer\n";
	cout << "[4] Update customer\n";
	cout << "[5] Return to main menu\n";
	cout << "Your choice: ";
	int choice;
	cin >> choice;
	while (choice < 1 or choice > 5)
	{
		cout << "\t> ERROR: choose 1-5 only: ";
		cin >> choice;
	}
	switch (choice)
	{
	case 1:	cout << "\nCustomer list:\n";
		for (unsigned int i = 0; i < c.size(); i++)
			cout << "[" << i + 1 << "] " << c[i].getLName() << ", "
			<< c[i].getFName() << " (" << c[i].getCustNr() << ")\n";
		manageCustomers(c, v);
		break;
	case 2: addCustomer(c);
		break;
	case 3: deleteCustomer(c);
		break;
	case 4: updateCustomer(c, v);
	}
}

void addCustomer(vector<Customer>& c)
{
	string lname, fname;
	int custNr;
	cin.ignore();
	cout << "Enter new customer's last name: ";
	getline(cin, lname);
	cout << "Enter new customer's first name: ";
	getline(cin, fname);
	cout << "Enter new customer's number: ";
	cin >> custNr;
	cin.ignore();
	Customer temp({ custNr, lname, fname });
	c.push_back(temp);
}

void deleteCustomer(vector<Customer>& c)
{
	cout << "Enter customer number to delete:\n";
	for (unsigned int i = 0; i < c.size(); i++)
		cout << "[" << i + 1 << "] " << c[i].getLName() << ", "
		<< c[i].getFName() << endl;
	int choice;
	cin >> choice;
	int size = c.size(); // to eliminate an Eclipse warning
	while (choice < 1 or choice > size)
	{
		cout << "\t> ERROR: choose 1-" << c.size() << " only: ";
		cin >> choice;
	}
	choice--; //correct off-by-one error
	c.erase(c.begin() + choice);
	cout << "Customer deleted.\n";
}

void updateCustomer(vector<Customer>& c, vector<Video> v)
{
	cout << "Enter customer number to update:\n";
	for (unsigned int i = 0; i < c.size(); i++)
		cout << "[" << i + 1 << "] " << c[i].getLName() << ", "
		<< c[i].getFName() << endl;
	int choice;
	cin >> choice;
	int size = c.size(); // to eliminate an Eclipse warning
	while (choice < 1 or choice > size)
	{
		cout << "\t> ERROR: choose 1-" << c.size() << " only: ";
		cin >> choice;
	}
	choice--; //correct off-by-one error
	cout << "Last name currently is: ";
	cout << c[choice].getLName();
	cout << ". Update last name? ";
	char YN = getYN();
	if (YN == 'Y')
	{
		cout << "Enter new last name: ";
		string line;
		getline(cin, line);
		c[choice].setLName(line);
	}
	cout << "First name currently is: ";
	cout << c[choice].getFName();
	cout << ". Update first name? ";
	YN = getYN();
	if (YN == 'Y')
	{
		cout << "Enter new first name: ";
		string line;
		getline(cin, line);
		c[choice].setFName(line);
	}
	cout << "Customer number currently is: ";
	cout << c[choice].getCustNr();
	int savedCustNr = c[choice].getCustNr();
	cout << ". Update customer number? ";
	YN = getYN();
	if (YN == 'Y')
	{
		cout << "Enter new customer number: ";
		int number;
		cin >> number;
		bool goodnumber = false;
		while (!goodnumber)
		{
			bool found = false;
			for (int i = 0; i < c.size(); i++)
				if (number == c[i].getCustNr())
					found = true;
			while (number < MIN_CUSTNR or number > MAX_CUSTNR or found)
			{
				cout << "\t> ERROR: choose a number 1000-9999 that's not an existing customer number: ";
				cin >> number;
				found = false;
				for (int i = 0; i < c.size(); i++)
					if (number == c[i].getCustNr())
						found = true;
			}
			goodnumber = true;
		}
		c[choice].setCustNr(number);
		//now go through any current rentals and change that customer number to the new one (number)
		for (int i = 0; i < v.size(); i++)
			if (v[i].getCustomer() == savedCustNr)
				v[i].setCustomer(number);
	}
}
