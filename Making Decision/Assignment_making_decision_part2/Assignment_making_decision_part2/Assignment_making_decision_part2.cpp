/***************************************************************************************************
Problem#: Assignment_making_decision_part2
Question: Modify the Program in Programming Challenge 23(Part 1) so that it also displays how much
          money Package A customers would save if they purchased packages B or C, and how
          much money Package B customers would save if they purchased Package C. If there
          would be no savings, no message should be printed.
Name: Jin Han Ho
ID: 1790201
Date: 22/2/2020
Status: complete
***************************************************************************************************/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;



int main() {
    string choices, month;
    char package;
    int hours;
    double sumA = 0, sumB = 0, sumC = 0;



    do {

        cout << "Please select the package you used [A/B/C]"
            << "and how long you used it in hours, "
            << "seperated with a space" << endl;
        getline(cin, choices);
        stringstream(choices) >> package >> hours >> month;

        package = toupper(package);

        if ((package == 'A' || package == 'B' || package == 'C') && hours <= 744) {

            switch (package) {

            case 'A':

                if (hours >= 0 && hours <= 10) {

                    sumA = 9.95 * hours;

                    cout << "The monthly bill is $" << sumA << endl;

                }
                else if (hours >= 10 && hours <= 20) {

                    sumA = 9.95 * 10 + 11.95 * (hours - 10);
                    sumB = 14.95 * hours;
                    sumC = 19.95 * hours;

                    cout << "The monthly bill is $" << sumA << endl;

                }
                else if (hours > 20) {

                    sumA = 9.95 * 10 + 11.95 * (hours - 10);
                    sumB = 14.95 * 20 + 15.95 * (hours - 20);
                    sumC = 19.95 * hours;
                    cout << "The monthly bill is $" << sumA << endl;
                    if (sumB < sumA && sumB < sumC) {
                        cout << "You can save $" << (sumA - sumB)
                            << " if you purchased Plan B";
                    }
                    else if (sumC < sumA && sumC < sumB) {

                        cout << "You can save $" << (sumA - sumC)
                            << " if you purchased Plan C";
                    }



                }
                break;


            case 'B':


                if (hours >= 0 && hours <= 20) {

                    sumB = 14.95 * hours;
                    cout << "The monthly bill is $" << sumB;

                }


                if (hours > 20) {

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

                sumA = 19.95 * hours;
                cout << "The monthly bill is $" << sumA;


                break;


            }
        }
        else {
            cout << "Error! Please enter the information again.";
            cout << endl;

        }


    } while (!(package == 'A' || package == 'B' || package == 'C') || hours > 744);




    return 0;
}