/*-----------------------
Ticket :: Police
-----------------------
- violation: string
- ticketNumber: int
- fine: double
- paid: bool
-----------------------
+ Ticket() : Police()
+ Ticket(string, int, double, string, int) :
     Police(string, int)
+ getViolation() : string
+ getTicketNr() : int
+ getFine() : double
+ getStatus() : bool
+ setStatus(bool) : void
+ printTicket() : void
----------------------*/

#ifndef TICKET_H
#define TICKET_H
#include "Police.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Ticket : public Police {

private:
    string violation;
    int ticketNumber;
    double fine;
    bool paid;

public:
    Ticket() : Police() {
        violation = "";
        ticketNumber = 0;
        fine = 0.0;
        paid = false;
    };
    Ticket(string v, int tnum, double fnum, string name, int bnum) : Police(name, bnum){
        violation = v;
        ticketNumber = tnum;
        fine = fnum;
        paid = false;
    };
    string getViolation()
        {return violation;}
    int getTicketNr() 
        { return ticketNumber; }
    double getFine() 
        { return fine; }
    bool getStatus() 
        { return paid; }
    void setStatus(bool p) 
        { paid = p; }
    void printTicket() {
        cout << "Ticket #" << getTicketNr()                                      //print ticketnumber
             << " (" << getViolation()<< ", ";                                   //print violation type
        printOfficer();                                                          //print police information
        cout << "): ";                                  
        getStatus() ? cout << "paid" << " (0 due)" << endl
                    : cout << "unpaid ($" << fixed << setprecision(2) 
                           << getFine() << " due)" << endl;                      //print amount of fine due
        }
};
#endif