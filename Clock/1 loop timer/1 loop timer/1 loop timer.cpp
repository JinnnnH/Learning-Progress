/***************************************************************
Problem#: Assignment Clock
Question: 1 loop timer
Name: Jin Han Ho
ID: 1790201
Date: 21/2/2020
Status: complete
****************************************************************/


#include <iostream>
#include<iomanip>
#include<thread>
using namespace std;


const int MAX_SECONDS = 60;

int main() {
    int hours, minutes = 0, seconds = 0;


    for (seconds = 0; seconds <= MAX_SECONDS; seconds++) {

        minutes = seconds / 60 % 24;
        hours = seconds / 60 / 24;

        cout << " " << "Timer : "
            << setfill('0') << setw(2) << hours << ":"
            << setw(2) << minutes << ":"
            << setw(2) << seconds % 60 << '\r';

        this_thread::sleep_for(chrono::seconds(1));
    }
    return 0;
}
