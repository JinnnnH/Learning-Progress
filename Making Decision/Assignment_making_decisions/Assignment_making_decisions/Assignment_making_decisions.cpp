/***********************************************************************************************
Problem#: Assignment_making_decision
Question: Write a program that calculates a customer s monthly bill. 
          It should ask which package the customer has purchased and how many hours were used. 
          It should then display the total amount due.
Name: Jin Han Ho
ID: 1790201
Date: 21/2/2020
Status: complete
***********************************************************************************************/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;


int main()
{
    string choices;
    char package;
    int hours;
    double sum=0;

   

    do{
        cout << "Please select the package you used [A/B/C]"
            << "and how long you used it in hours, "
            << "seperated with a space" << endl;
        getline(cin, choices);
        stringstream(choices) >> package >> hours;

        package = toupper(package);


        switch (package) {

        case 'A':

            if (hours >= 0 && hours <= 10) {

                sum = 9.95 * hours;
                cout << "The monthly bill is $" << sum;

            }
            else if (hours >= 10 && hours <= 744) {

                sum = 9.95 * 10 + 11.95 * (hours - 10);
                cout << "The monthly bill is $" << sum;

            }
            break;


        case 'B':

            if (hours >= 0 && hours <= 20) {

                sum = 14.95 * hours;
                cout << "The monthly bill is $" << sum;

            }
            else if (hours >= 20 && hours <= 744) {

                sum = 14.95 * 20 + 15.95 * (hours - 20);
                cout << "The monthly bill is $" << sum;

            }
            break;

        case 'C':

            if (hours <= 744) {

                sum = 19.95 * hours;
                cout << "The monthly bill is $" << sum;

            }
            break;

        default:
            cout << "Error! Please enter the information again.";
            cout << endl;


            break;
        }




    } while (!(package == 'A' || package == 'B' || package == 'C'));

    
    
    
    return 0;
}