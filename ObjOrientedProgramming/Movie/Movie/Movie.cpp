//*************************************************************************************
//Program Name: Movie
//Author: Jin Han Ho
//IDE Used: Visual Studio 2019
//Program description: read inputs from input file and output them as 4 sets of object
//*************************************************************************************

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

/*----------------------------
Movie
----------------------------
- screenWriter: string
- yearReleased : int
- title : string
----------------------------
+ getScreenWriter() : string
+ getYearReleased() : int
+ getTitle() : string
+ setScreenWriter(a : string) : void
+ setYearReleased(y : int) : void
+ setTitle(t : string) : void
----------------------------*/

class Movie {

    private:
        string screenWriter;
        int yearReleased =0;
        string title;

    public:
        string getScreenWriter();
        int getYearReleased();
        string getTitle();
        void setScreenWriter(string a);
        void setYearReleased(int y);
        void setTitle(string t);
};

string Movie::getScreenWriter() {
    return screenWriter;
}
int Movie::getYearReleased() {
    return yearReleased;
}
string Movie::getTitle() {
    return title;
}
void Movie::setScreenWriter(string a) {
    screenWriter = a;
}
void Movie::setYearReleased(int y) {
    yearReleased = y;
}
void Movie::setTitle(string t) {
    title = t;
}

int main(){

    ifstream fin;
    string name, writer;
    int i=0,year = 0;
    const int SIZE = 4;
    Movie Arr[SIZE];
    fin.open("input.txt");

    while (getline(fin, writer)) {
        fin >> year;
        fin.ignore();
        getline(fin, name);
        Arr[i].setScreenWriter(writer);
        Arr[i].setYearReleased(year);
        Arr[i].setTitle(name);
        i++;
    }

    cout << "This program will create several objects depicting movies." << endl
         << "Reading input file..." << endl
         << "...done." << endl;

    for (int i = 0; i < SIZE; i++) {

        cout << "Movie: " << Arr[i].getTitle() << endl;
        cout << setw(10) << " > " << "Year released: " << Arr[i].getYearReleased() << endl;
        cout << setw(10) << " > " << "Screenwriter: " << Arr[i].getScreenWriter() << endl;
    }

    fin.close();

    cout << endl;
    cout << "I attest that this code is my original programming work, and that I received" << endl
        << "no help creating it. I attest that I did not copy this code or any portion of this" << endl
        << "code from any source." << endl;

    return 0;
}