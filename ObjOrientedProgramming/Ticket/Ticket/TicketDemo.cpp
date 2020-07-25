//****************************************************************************************************
//Program Name: Tickets
//Author: Jin Han Ho
//IDE Used: Visual Studio 2019
//Program description: This program will show the status of ticket that is issued the police in a day
//****************************************************************************************************

#include "Police.h"
#include "Ticket.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

//************************************************************************************
//Function name: Print1
//Purpose: Print out the daily report before payments are done
//List of parameters: vector<Ticket> TicketInfo, double sum
//Returns: no return variable
//Return type: void
//************************************************************************************
//************************************************************************************
//Function name: Print2
//Purpose: Print out the daily report after payments are done
//List of parameters: vector<Ticket> TicketInfo, double sum, double sum2, int counter
//Returns: no return variable
//Return type: void
//************************************************************************************

void Print1(vector<Ticket> TicketInfo, double &sum) {
    cout << "Daily ticket report: " << endl;
    for (int i = 0; i < TicketInfo.size(); i++) {

        TicketInfo.at(i).printTicket();
        sum += TicketInfo.at(i).getFine();
    }
    cout << "Number of tickets: " << TicketInfo.size() << endl;
    cout << "Revenues due: $" << fixed << setprecision(2) << sum << endl << endl;
}

void Print2(vector<Ticket> TicketInfo, double &sum, double &sum2, int counter) {
    cout << "Payment processing complete; new status report: " << endl;

    for (int i = 0; i < TicketInfo.size(); i++) {
        TicketInfo.at(i).printTicket();

        TicketInfo.at(i).getStatus() ? counter++             //counter + 1 if the status is paid;
            : sum2 += TicketInfo.at(i).getFine();
    }
    cout << "Number paid: " << counter 
         << " (Total: $" << (sum - sum2) << ")" << endl;     //Total due before payment minus unpaid

    cout << "Number unpaid: " << TicketInfo.size() - counter 
         << " (Total: $" << fixed << setprecision(2) << sum2 << ")" << endl;
}

int main()
{
    vector<Ticket>TicketInfo;
    ifstream fin;
    int tnum, badgenum, counter = 0;
    double due, sum = 0, sum2 = 0;
    bool pay;
    string vio, name;

    fin.open("tickets.txt");
    while (fin >> vio) {
        fin >> tnum;
        fin >> due;
        fin >> name;
        fin >> badgenum;
        TicketInfo.push_back(Ticket(vio, tnum, due, name, badgenum));
    }

    Print1(TicketInfo, sum);                            //print first report
    fin.close();

    fin.open("payments.txt");

    int i = 0;
    while (fin >> pay) {
        TicketInfo.at(i).setStatus(pay);                //setting new payment status
        i++;
    } 

    Print2(TicketInfo, sum, sum2, counter);             //print second report

    fin.close();

    cout << endl << endl << endl;
    cout << "I attest that this code is my original programming work, and that I received" << endl
        << "no help creating it.I attest that I did not copy this code or any portion of this" << endl
        << "code from any source." << endl;

    return 0;
}