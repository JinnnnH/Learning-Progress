/************************************************************************************************************
Problem#: Assignment_making_decision_part3
Question: Months with 30 days have 720 hours, and months with 31 days have 744 hours. 
          February, with 28 days, has 672 hours. Enhance the input validation of the 
          Internet Service Provider program by asking the user for the month (by name), 
          and validating that the number of hours entered is not more than the maximum for the entire month.
          Here is a table of the months, their days, and number of hours in each.

Name: Jin Han Ho
ID: 1790201
Date: 22/2/2020
Status: complete
************************************************************************************************************/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;




void calculation(char package, int hours, double sumA, double sumB, double sumC) {

    switch (package) {

    case 'A':

        if (hours >= 0 && hours <= 10) {

            sumA = 9.95 * hours;

            cout << "The monthly bill is $" << sumA << endl;

        }
        else if (hours >= 10 && hours <= 744) {

            sumA = 9.95 * 10 + 11.95 * (hours - 10);
            sumB = 14.95 * 20 + 15.95 * (hours - 20);
            sumC = 19.95 * hours;
            cout << "The monthly bill is $" << sumA << endl;
            if (sumB < sumA && sumB < sumC) {
                cout << "You can save $" << (sumB - sumA)
                    << " if you purchased Plan B";
            }
            else if (sumC < sumA && sumC < sumB) {

                cout << "You can save $" << (sumC - sumA)
                    << " if you purchased Plan C";
            }

        }
        break;


    case 'B':


        if (hours >= 0 && hours <= 10) {

            sumB = 14.95 * hours;
            cout << "The monthly bill is $" << sumB;

        }

        if (hours > 10 && hours <= 20) {

            sumB = 14.95 * 20 + 15.95 * (hours - 20);
            sumC = 19.95 * hours;


            cout << "The monthly bill is $" << sumB;
            if (sumC < sumB) {

                cout << "You can save $" << (sumB - sumC)
                    << " if you purchased Plan C";
            }


        }
        else if (hours >= 20 && hours <= 744) {

            sumB = 14.95 * 20 + 15.95 * (hours - 20);
            sumC = 19.95 * hours;


            cout << "The monthly bill is $" << sumB;

            if (sumC < sumB) {

                cout << "You can save $" << (sumB - sumC)
                    << " if you purchased Plan C";
            }
        }
        break;

    case 'C':

        if (hours <= 744) {

            sumA = 19.95 * hours;
            cout << "The monthly bill is $" << sumA;

        }
        break;

    default:

        cout << "Error!" << endl;
        break;
    }
    
};





bool validation(string month, int hours, bool valid) {

    if (month == "January" || month == "january") {
        if (hours <= 744) {
            valid = false;
        }
        else {
            cout << "the number of hours entered is"
                 << " more than the maximum for the entire month." << endl;
            cout << "Please enter the information again." << endl;
            valid = true;
        }
    }
    else if (month == "February" || month == "february") {
        if (hours <= 672) {
            valid = false;
        }
        else {
            cout << "the number of hours entered is"
                << " more than the maximum for the entire month." << endl;
            cout << "Please enter the information again." << endl;
            valid = true;
        }
    }
    else if (month == "March" || month == "march") {
        if (hours <= 744) {
            valid = false;
        }
        else {
            cout << "the number of hours entered is"
                << " more than the maximum for the entire month." << endl;
            cout << "Please enter the information again." << endl;
            valid = true;
        }
    }
    else if (month == "April" || month == "april") {
        if (hours <= 720) {
            valid = false;
        }
        else {
            cout << "the number of hours entered is"
                << " more than the maximum for the entire month." << endl;
            cout << "Please enter the information again." << endl;
            valid = true;
        }
    }
    else if (month == "May" || month == "may") {
        if (hours <= 744) {
            valid = false;
        }
        else {
            cout << "the number of hours entered is"
                << " more than the maximum for the entire month." << endl;
            cout << "Please enter the information again." << endl;
            valid = true;
        }
    }
    else if (month == "June" || month == "june") {
        if (hours <= 720) {
            valid = false;
        }
        else {
            cout << "the number of hours entered is"
                << " more than the maximum for the entire month." << endl;
            cout << "Please enter the information again." << endl;
            valid = true;
        }
    }
    else if (month == "July" || month == "july") {
        if (hours <= 744) {
            valid = false;
        }
        else {
            cout << "the number of hours entered is"
                << " more than the maximum for the entire month." << endl;
            cout << "Please enter the information again." << endl;
            valid = true;
        }
    }
    else if (month == "Augest" || month == "augest") {
        if (hours <= 744) {
            valid = false;
        }
        else {
            cout << "the number of hours entered is"
                << " more than the maximum for the entire month." << endl;
            cout << "Please enter the information again." << endl;
            valid = true;
        }
    }
    else if (month == "September" || month == "september") {
        if (hours <= 720) {
            valid = false;
        }
        else {
            cout << "the number of hours entered is"
                << " more than the maximum for the entire month." << endl;
            cout << "Please enter the information again." << endl;
            valid = true;
        }
    }
    else if (month == "October" || month == "october") {
        if (hours <= 744) {
            valid = false;
        }
        else {
            cout << "the number of hours entered is"
                << " more than the maximum for the entire month." << endl;
            cout << "Please enter the information again." << endl;
            valid = true;
        }
    }
    else if (month == "November" || month == "november") {
        if (hours <= 720) {
            valid = false;
        }
        else {
            cout << "the number of hours entered is"
                << " more than the maximum for the entire month." << endl;
            cout << "Please enter the information again." << endl;
            valid = true;
        }
    }
    else if (month == "December" || month == "december") {
        if (hours <= 744) {
            valid = false;
        }
        else {
            cout << "the number of hours entered is"
                << " more than the maximum for the entire month." << endl;
            cout << "Please enter the information again." << endl;
            valid = true;
        }
    }
    else {

        valid = true;
        cout << "the number of hours entered is"
            << " more than the maximum for the entire month." << endl;
        cout << "Please enter the information again." << endl;

    }

    return valid;
};











int main() {
    string choices, month;
    bool valid = false;
    char package;
    int hours;
    double sumA = 0, sumB = 0, sumC = 0;



    do {
            
            do {

                cout << "Please select the package you used [A/B/C]"
                     << "and how long you used it in hours, " << endl;
                cout << "and the month of the bill, "
                     << "seperated with a space" << endl;
                getline(cin, choices);
                stringstream(choices) >> package >> hours >> month;

                package = toupper(package);

                validation(month, hours, valid);
               
            } while (valid);
            

            calculation(package, hours, sumA, sumB, sumC);
      

    } while (!(package == 'A' || package == 'B' || package == 'C') || hours > 744);




    return 0;
}