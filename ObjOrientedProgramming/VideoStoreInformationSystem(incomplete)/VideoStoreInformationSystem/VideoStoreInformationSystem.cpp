#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "Video.h"
#include "Customer.h"
using namespace std;

int PrintMain(int &choice) {
	cout << "***VIDEO STORE MAIN MENU***" << endl;
	cout << "[1] Check out videos " << endl;
	cout << "[2] Check in videos " << endl;
	cout << "[3] Run reports " << endl;
	cout << "[4] Manage inventory " << endl;
	cout << "[5] Manage customers " << endl;
	cout << "[6] Quit " << endl;

	cout << "Your choice: ";
	cin >> choice;
	cout << endl;
	return choice;
}

void PrintAllVideos(vector<Video>& VideoCollection) {
	for (int i = 0; i < VideoCollection.size(); i++) {
		cout << "[" << i << "]" << VideoCollection.at(i).getInvNr()
			<< " " << VideoCollection.at(i).getTitle() << endl;
	}
}

void PrintCheckOutVideos(vector<Video>& VideoCollection, vector<int>& Check) {
	cout << "***VIDEO CHECK - OUT ***" << endl;
	cout << "Select video to check out: " << endl << endl;

	//stuffing Check vector
	for (int i = 0; i < VideoCollection.size(); i++) {
		if (!(VideoCollection.at(i).getCheckedOut())) {
			Check.push_back(i);
		}
	}

	//Outputting Check vector data
	for(int i = 0; i < Check.size(); i++) {
		cout << "[" << i+1 << "]" 
			<< VideoCollection.at(Check.at(i)).getInvNr()
			<< " " << VideoCollection.at(Check.at(i)).getTitle() << endl;
	}

	cout << endl << "Enter your choice: ";
}

void PrintCheckInVideos(vector<Video>& VideoCollection, vector<int>& Check) {
	int counter = 1;
	cout << "***VIDEO CHECK - IN ***" << endl;
	cout << "Select video to check in: " << endl << endl;
	for (int i = 0; i < VideoCollection.size(); i++) {
		if (VideoCollection.at(i).getCheckedOut()) {
			cout << "[" << counter << "]" << VideoCollection.at(i).getInvNr()
				<< " " << VideoCollection.at(i).getTitle() << endl;
			counter++;
		}
	}
	cout << endl << "Enter your choice: ";
}

void PrintCustomers(vector<Customer>&CustomerCollection) {
	for (int i = 0; i < CustomerCollection.size(); i++) {
		cout << "[" << i + 1 << "]" << CustomerCollection.at(i).getLName()
			<< ", " << CustomerCollection.at(i).getFName()
			<< "(" << CustomerCollection.at(i).getCustNr() << ")" << endl;
	}
	cout << endl << "Enter your choice : ";
}

void PrintReports() {
	cout << "***RUN REPORTS ***" << endl;
	cout << "[1] Overdue video report" << endl
		<< "[2] Write new video database" << endl
		<< "[3] Write new customer database" << endl
		<< "[4] Main menu" << endl;

	cout << endl << "Your choice :";
}

void PrintOverDue(vector<Video>& VideoCollection, vector<Customer>& CustomerCollection) {
	cout << "***OVERDUE VIDEOS***" << endl;
	for (int i = 0; i < VideoCollection.size(); i++) {
		if (!(VideoCollection.at(i).getOverdue())) {

			cout << "Inventory #: " << VideoCollection.at(i).getInvNr()
				<< " Title: " << VideoCollection.at(i).getTitle() << endl;
			for (int j = 0; j < VideoCollection.size(); j++) {
				if (VideoCollection.at(i).getCustomer() == CustomerCollection.at(j).getCustNr()) {
					cout << "\tCustomer #:" << CustomerCollection.at(VideoCollection.at(i).getCheckedOut()).getCustNr()
						<< "(" << CustomerCollection.at(VideoCollection.at(i).getCheckedOut()).getLName()
						<< CustomerCollection.at(VideoCollection.at(i).getCheckedOut()).getFName() << ")" << endl;
				}
			}
		}
		else {
			cout << endl << "There's no overdue!" << endl;
		}
	}
}

void PrintInventory() {
	cout << "***MANAGE INVENTORY***" << endl;
	cout << "[1] Add video to inventory" << endl
		<< "[2] Remove video from inventory" << endl
		<< "[3] Update video data" << endl
		<< "[4] Return to main menu" << endl;

	cout << endl << "Your choice :";
}

void PrintMngCustomers() {
	cout << "***MANAGE CUSTOMERS***" << endl
		<< "[1] List customers" << endl
		<< "[2] Add customer" << endl
		<< "[3] Delete customer" << endl
		<< "[4] Update customer" << endl
		<< "[5] Return to main menu" << endl;

	cout << endl << "Your choice : ";
}

int main() {
	//initialization
	ifstream fin;
	ofstream fout;
	vector<Video>VideoCollection;
	vector<Customer>CustomerCollection;
	vector<int>Check;
	char select;
	int choice = 0, choice2 = 0, choice3 = 0,
		invenNum = 0, cust = 0, custNr = 0;
	bool over = false, checkOut = false;
	string title, str, str2, lName, fName, 
		vfilename = "videos", cfilename = "customers";

	//opening video database
	fin.open(vfilename + ".txt");
	//test if the database is successfully opened
	if (fin.is_open()) {
		while (getline(fin, title)) {
			getline(fin, str);
			stringstream(str) >> invenNum >> checkOut >> over >> cust;
			VideoCollection.push_back({ title, invenNum, checkOut, over, cust });			//populating the video vector
		}
		fin.close();
	}
	else {
		cout << "Error opening \"videos.txt\"" << endl;
	}

	//opening customer database
	fin.open(cfilename + ".txt");
	//test if the database is successfully opened
	if (fin.is_open()) {
		while (fin >> lName) {
			fin >> fName;
			fin >> custNr;
			CustomerCollection.push_back({ custNr, lName, fName });			//populating the customer vector
		}
		fin.close();
	}
	else {
		cout << "Error opening \"customers.txt\"" << endl;
	}

	//Print main menu
	while (PrintMain(choice) != 6) {
		// Check Out Videos Menu
		if (choice == 1) {
			if (!(VideoCollection.empty())) {																				//test if the vector is empty
				PrintCheckOutVideos(VideoCollection, Check);																		
				cin >> choice2;
				while (choice2 < 1 || choice2 > 5) {
					cout << "There is no such choice! Please input again!" << endl;
					cout << "Enter your choice: ";
					cin >> choice2;
				}

				cout << endl << "Choose the customer that checked this video:" << endl;

				PrintCustomers(CustomerCollection);
				cin >> choice3;

				while (choice3 < 1 || choice3 >(CustomerCollection.size() - 1)) {
					cout << "There is no such choice! Please input again!" << endl;
					cout << "Enter your choice: " << endl;
					cin >> choice3;
				}

				VideoCollection.at(Check.at(choice2-1)-1).setCustomer(CustomerCollection.at(choice3 - 1).getCustNr());
				VideoCollection.at(Check.at(choice2-1)-1).setCheckedOut(true);
				Check.erase(Check.begin() + choice2-1);
			}
			else {
				cout << "Videos list is empty!" << endl;
			}
		}

		//Check In Videos Menu
		else if (choice == 2) {
			if (!(VideoCollection.empty())) {
				PrintCheckInVideos(VideoCollection, Check);
				cin >> choice2;

				VideoCollection.at(choice2 - 1).setCustomer(0);
			}
			else {
				cout << "Videos list is empty!" << endl;
			}
		}

		//Run Reports
		else if (choice == 3) {

				PrintReports();
				cin >> choice2;

				if (choice2 == 1) {
					if (!(VideoCollection.empty()) || !(CustomerCollection.empty())) {
						PrintOverDue(VideoCollection, CustomerCollection);
					}
					else {
						cout << "Either the Video list or Customer list is empty!" << endl;
					}
				}
				else if (choice2 == 2) {

					cout << "Please input the name for new video database: ";
					getline(cin, vfilename);
					fout.open((vfilename += ".txt"));

					if (fout.is_open()) {
						do {
							cout << "Please input the name of video: ";
							getline(cin, title);

							cout << "Please input the inventory number of video: ";
							cin >> invenNum;
							while (invenNum < 100 || invenNum > 999) {
								cout << "The inventory number should be formed by 3 digits only! Please try again!" << endl;
								cout << "Please input the inventory number of video: ";
								cin >> invenNum;
							}

							cout << "Please input if the video is checked out or not, 1 for true, 0 for false: ";
							cin >> checkOut;

							cout << "Please input if the video is over dued or not, 1 for true, 0 for false: ";
							cin >> over;

							if (checkOut) {
								cout << "Please input if the customer number of that person if the video is rented, "
									<< "otherwise, enter \'0\'";
								cin >> cust;
								while (cust <1000 || cust > 10000) {
									cout << "The customer number should be formed by 4 digits only! Please try again!" << endl;
									cout << "Please input the customer number number of video: ";
									cin >> invenNum;
								}

							}
							else {
								cust = 0;
							}

							fout << title;
							fout << (to_string(invenNum) + " " + to_string(checkOut) + " " + to_string(over) + ' ' + to_string(cust));

							cout << "Do you want to stop adding? [YES/NO]" << endl;
							getline(cin, str);

						} while (str == "NO");

						fout.close();
					}
					else {
						cout << "Error opening the new database!" << endl;
					}
				}
				else if (choice2 == 3) {
					cout << "Please input the name for new customer database: ";
					getline(cin, cfilename);
					fout.open((cfilename += ".txt"));

					if (fout.is_open()) {
						do {
							cout << "Please input the last name of customer: ";
							getline(cin, lName);

							cout << "Please input the first number of customer: ";
							getline(cin, fName);

							cout << "Please input the customer number for this customer: ";
							cin >> custNr;

							while (cust < 1000 || cust > 10000) {
								cout << "The customer number should be formed by 4 digits only! Please try again!" << endl;
								cout << "Please input the customer number number of video: ";
								cin >> invenNum;
							}

							fout << lName;
							fout << fName;
							fout << custNr;

							cout << "Do you want to stop adding? [YES/NO]" << endl;
							getline(cin, str);

						} while (str == "NO");

						fout.close();
					}
					else {
						cout << "Error opening the new database!" << endl;
					}
				}
				else if (choice2 == 4) {
					break;
				}
				else {
					cout << "There's no such choice! Please try again." << endl;
				}
		}

		//Manage Inventory
		else if (choice == 4) {

			PrintInventory();
			cin >> choice2;
			if (choice2 == 1) {

				fout.open(vfilename += ".txt", std::fstream::app);

				cout << "Please input the video's title: ";
				cin >> title;

				cout << endl << "Please input the video's 3-digit inventory number: ";
				cin >> invenNum;

				while (invenNum < 100 || invenNum > 999) {
					cout << endl << "The inventory number should a 3-digt number! Please try again.";
					cout << endl << "Please input the video's 3-digit inventory number: ";
					cin >> invenNum;
				}

				fout << title;
				fout << (to_string(invenNum) + " 0 0 0");
				VideoCollection.push_back({ title, invenNum, 0, 0, 0 });
				fout.close();

			}
			else if (choice2 == 2) {
				if (VideoCollection.empty()) {
					cout << endl << "Customer list is empty!" << endl;
				}
				else {
					fout.open(vfilename += ".txt");
					PrintAllVideos(VideoCollection);

					cout << "Enter your choice: ";
					cin >> choice3;

					while (choice3 <= 0 || choice3 > VideoCollection.size()) {
						cout << "There's is no such video! Please try again!" << endl;
						PrintAllVideos(VideoCollection);
						cout << "Enter your choice: ";
						cin >> choice3;
					}
					VideoCollection.erase(VideoCollection.begin() + (choice3)-1);

					for (int i = 0; i < VideoCollection.size(); i++) {
						fout << VideoCollection.at(i).getTitle();
						fout << to_string(VideoCollection.at(i).getInvNr()) + to_string(VideoCollection.at(i).getCheckedOut())
							+ to_string(VideoCollection.at(i).getOverdue()) + to_string(VideoCollection.at(i).getCustomer());
					}
				}

				fout.close();
			}
			else if (choice2 == 3) {
				if (VideoCollection.empty()) {
					cout << endl << "Updated! The list is still empty." << endl;
				}
				else {
					fout.open(vfilename += ".txt");
					PrintAllVideos(VideoCollection);
					cout << "Enter your choice: ";
					cin >> choice3;

					cout << "Title currently is: " << VideoCollection.at(choice3 - 1).getTitle()
						<< " Update title? Y/N: ";
					cin >> select;

					while (toupper(select) != 'Y' && toupper(select) != 'N') {
						cout << "Please enter either Y or N." << endl;
						cout << "Title currently is: " << VideoCollection.at(choice3 - 1).getTitle()
							<< " Update title? Y/N: ";
						cin >> select;
					}

					if (toupper(select) == 'Y') {
						cout << "Enter new title: ";
						cin >> title;

						VideoCollection.at(choice3).setTitle(title);
					}

					cout << "Inventory # currently is: " << VideoCollection.at(choice3 - 1).getInvNr()
						<< " Update iinventory number? Y/N: ";
					cin >> select;

					while (toupper(select) != 'Y' && toupper(select) != 'N') {
						cout << "Please enter either Y or N." << endl;
						cout << "Inventory # currently is: " << VideoCollection.at(choice3 - 1).getInvNr()
							<< " Update iinventory number? Y/N: ";
						cin >> select;
					}

					if (toupper(select) == 'Y') {
						cout << "Enter New inventory number: ";
						cin >> invenNum;

						VideoCollection.at(choice3).setInvNr(invenNum);
					}

					for (int i = 0; i < VideoCollection.size(); i++) {
						fout << VideoCollection.at(i).getTitle();
						fout << to_string(VideoCollection.at(i).getInvNr()) + " " + to_string(VideoCollection.at(i).getCheckedOut())
							+ " " + to_string(VideoCollection.at(i).getOverdue()) + " " + to_string(VideoCollection.at(i).getCustomer());
					}
					fout.close();
					cout << "Updated!" << endl;
				}
			}
			else if (choice2 == 4) {
				continue;
			}
			else {
				do {
					cout << "There is no such choice! Please try again." << endl;
					cin >> choice2;
				} while (!(choice2 == 1 || choice2 == 2 || choice2 == 3 || choice2 == 4));
			}
		}

		//Manage Customers
		else if (choice == 5) {

			PrintMngCustomers();
			cin >> choice2;

			if (choice2 == 1) {
				if (CustomerCollection.empty()) {
					cout << endl << "Customer list is empty!" << endl;
				}
				else {
					PrintCustomers(CustomerCollection);
				}

				if (choice2 == 2) {

					fout.open(cfilename += ".txt", std::fstream::app);

					cout << "Please input customer's last name: ";
					cin >> lName;

					cout << endl << "Please input customer's last name: ";
					cin >> fName;

					cout << endl << "Please input the customer number: ";
					cin >> custNr;

					while (custNr < 1000 || custNr > 9999) {
						cout << endl << "The customer number should a 4-digt number! Please try again.";
						cin >> custNr;
					}

					fout << lName;
					fout << fName;
					fout << custNr;
					CustomerCollection.push_back({ custNr, lName, fName });

					fout.close();
				}
				else if (choice2 == 3) {
					if (CustomerCollection.empty()) {
						cout << endl << "Customer list is empty!" << endl;
					}
					else {
						fout.open(cfilename += ".txt");
						PrintCustomers(CustomerCollection);

						cout << "Enter your choice of deletion: ";
						cin >> choice3;

						while (choice3 <= 0 || choice3 > CustomerCollection.size()) {
							cout << "There's is no such video! Please try again!" << endl;
							PrintCustomers(CustomerCollection);
							cout << "Enter your choice: ";
							cin >> choice3;
						}
						CustomerCollection.erase(CustomerCollection.begin() + (choice3)-1);

						for (int i = 0; i < VideoCollection.size(); i++) {
							fout << CustomerCollection.at(i).getLName();
							fout << CustomerCollection.at(i).getFName();
							fout << CustomerCollection.at(i).getCustNr();
						}
						fout.close();
					}
				}
				else if (choice2 == 4) {
					if (CustomerCollection.empty()) {
						cout << endl << "Updated! The customer list is still empty." << endl;
					}
					else {

						fout.open(cfilename += ".txt");
						PrintCustomers(CustomerCollection);
						cout << "Enter your choice: ";
						cin >> choice3;

						cout << "Customer's last name currently is: " << CustomerCollection.at(choice3 - 1).getLName()
							<< " Update last name? Y/N: ";
						cin >> select;

						while (toupper(select) != 'Y' && toupper(select) != 'N') {
							cout << "Please enter either Y or N." << endl;
							cout << "Customer's last name currently is: " << CustomerCollection.at(choice3 - 1).getLName()
								<< " Update last name? Y/N: ";
							cin >> select;
						}

						if (toupper(select) == 'Y') {
							cout << "Enter new last name: ";
							cin >> lName;

							CustomerCollection.at(choice3 - 1).setLName(lName);
						}

						cout << "Customer's fast name currently is: " << CustomerCollection.at(choice3 - 1).getFName()
							<< " Update first name? Y/N: ";
						cin >> select;

						while (toupper(select) != 'Y' && toupper(select) != 'N') {
							cout << "Please enter either Y or N." << endl;
							cout << "Customer's first name currently is: " << CustomerCollection.at(choice3 - 1).getFName()
								<< " Update first name? Y/N: ";
							cin >> select;
						}

						if (toupper(select) == 'Y') {
							cout << "Enter new first name: ";
							cin >> fName;

							CustomerCollection.at(choice3 - 1).setFName(fName);
						}

						for (int i = 0; i < VideoCollection.size(); i++) {
							fout << CustomerCollection.at(i).getLName();
							fout << CustomerCollection.at(i).getFName();
							fout << CustomerCollection.at(i).getCustNr();
						}
						fout.close();

						cout << "Updated" << endl;
					}

				}
				else if (choice2 == 5) {
					continue;
				}
				else {
					do {
						cout << "There is no such option! Please try again." << endl;
						cin >> choice2;
					} while (!(choice2 == 1 || choice2 == 2 || choice2 == 3 || choice2 == 4 || choice2 == 5));
				}
			}

			


			cout << endl << "I attest that this code is my original programming work, and that I received " << endl
				<< "no help creating it.I attest that I did not copy this code or any portion of this" << endl
				<< "code from any source." << endl;

		}

		//Error input
		else if (choice < 1 || choice > 6) {
			cout << "Error! There's no such choice." << endl << endl;
		}
		
		//Exit program
		else {
			break;
		}
	}

	cout << "Program ending." << endl;
	cout << endl << "I attest that this code is my original programming work, and that I received" << endl
		<< "no help creating it.I attest that I did not copy this code or any portion of this" << endl
		<< "code from any source." << endl << endl;

	return 0;
}