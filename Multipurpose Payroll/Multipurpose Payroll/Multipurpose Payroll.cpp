/**********************************************************************************************
Problem#: Multipurpose Payroll
Question:Write a program that calculates pay for either an hourly paid worker or a salaried
         worker. Hourly paid workers are paid their hourly pay rate times the number of
         hours worked. Salaried workers are paid their regular salary plus any bonus they may
         have earned. 
         The program should also declare a union with two members. Each member should be
         a structure variable: one for the hourly paid worker and another for the salaried
         worker.
         The program should ask the user whether he or she is calculating the pay for an
         hourly paid worker or a salaried worker. Regardless of which the user selects, the
         appropriate members of the union will be used to store the data that will be used to
         calculate the pay.

Name: Jin Han Ho
ID: 1790201
Date: 4/4/2020
Status: complete
*********************************************************************************************/


#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include<cmath>
#include<string>
#include <vector>
using namespace std;


struct HourlyPaid{

    int HoursWorked;
    int HourlyRate;

};

struct Salaried {

    int Salary;
    int Bonus;

};



int main()
{
    int counter = 0, sum;
    string str, str2;
    HourlyPaid worker1;
    Salaried worker2;

    
    cout << "Which kind of pay of worker are you calculating for? "
         << "[Hourly Paid / Salaried]";
    getline(cin, str);

    for (int i = 0; i < str.length(); i++) {

        str.at(i) = toupper(str.at(i));

    }

    if (str == "HOURLY PAID" || str == "HOURLYPAID") {
        
        do {

            if (counter >= 1) {
                cout << "Wrong input! Try again please." << endl;
            }

            cout << "Input the hours worked and the hourly pay rate the worker worked"
                << ", seperated by a space";
            getline(cin, str2);
            stringstream(str2) >> worker1.HoursWorked >> worker1.HourlyRate;
            counter++;

        } while (worker1.HoursWorked < 0 || worker1.HoursWorked > 80 || worker1.HourlyRate < 0);

        sum = worker1.HoursWorked* worker1.HourlyRate;

        cout << "The salary of the worker is " << "$" << sum;


    }
    else {

        do {

            if (counter >= 1) {
                cout << "Wrong input! Try again please." << endl;
            }

            cout << "Input the Salary and the Bonus the worker earned"
                << ", seperated by a space";
            getline(cin, str2);
            stringstream(str2) >> worker2.Salary >> worker2.Bonus;
            counter++;

        } while (worker2.Salary < 0 || worker2.Bonus < 0);

        sum = worker2.Salary * worker2.Bonus;

        cout << "The salary of the worker is " << "$" << sum;

    }
    
    
    
    return 0;

}
