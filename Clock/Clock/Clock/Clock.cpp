/***************************************************************
Problem#: Clock
Question: Make an actual clock
Name: Jin Han Ho
ID: 1790201
Date: 21/2/2020
Status: complete
****************************************************************/


#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{

    while (true)
    {
        int seconds, minutes, hours;
        string indicator;

        time_t now = time(0);

        #pragma warning(suppress : 4996)
        struct tm* clock = localtime(&now);

        seconds = clock->tm_sec;
        minutes = clock->tm_min;
        hours = clock->tm_hour;

        if (hours >= 12) {

            indicator = "PM";
        }
        else {

            indicator = "AM";
        }

            cout << (hours < 10 ? "0" : "") << hours << ":" 
                 << (minutes < 10 ? "0" : "") << minutes << ":" 
                 << (seconds < 10 ? "0" : "") << seconds << indicator << '\r';

    }

    return 0;
}

































/*#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <stdio.h>
#include <time.h>  
#include <chrono>
#include <thread>
using namespace std;

 int main(){

     while (true) {
         using std::chrono::system_clock;

         int seconds, minutes, hours;
            
         time_t now = time(0);
         #pragma warning(suppress : 4996)
         struct tm* clock=localtime(&now);

         seconds = clock->tm_sec;
         minutes = clock->tm_min;
         hours = clock->tm_hour;

  
         cout << setfill('0') << setw(2) 
              << hours << setw(2) << minutes 
              << setw(2) << minutes;
         
         
     
 //        cout << "The local date and time is: " << asctime(localtime(&now));
 //        this_thread::sleep_for(chrono::seconds(1));
     }











     return 0;
 }*/


