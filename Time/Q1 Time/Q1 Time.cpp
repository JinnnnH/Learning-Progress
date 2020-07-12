#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h> 
#include <sstream>
using namespace std;

int Time(int hour, int min, int sec) {

        hour -= (hour > 12)*10;
        return sec += hour * 60 * 60 + min * 60;

}



int main()
{
    int hour, min, sec;
    string str;

    cout << "Input time:";
    getline(cin, str);


    stringstream(str) >> hour >> min >> sec;

    cout << Time(hour, min, sec);


    return 0;
}
