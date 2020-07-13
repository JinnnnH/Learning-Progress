/*************************************************************************
Problem#: Theater Seating
Question: Write a program that can be used by a small theater to sell 
          tickets for performances. 

Name: Jin Han Ho
ID: 1790201
Date: 3/20/2020
Status: incomplete
**************************************************************************/



#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include<cmath>
#include<string>
#include <vector>
using namespace std;




void setup_option(fstream& outputfile, string str, int& totalrow, int& seat_per_row, double& defaultprice) {

    cout << "The DEFAULT size of theater’s auditorium is 15 rows of seats,"
        << " with 30 seats in each row. Default seat price is $10.50"
        << endl;

    cout << "The setup menu can overwrite the default settings, "
        << "do you want to use this option? [Yes/No]";
    getline(cin, str);
    cout << endl;




    if (str == "Yes" || str =="yes") {


            cout << "Input the number of rows and the seats per row.";
            getline(cin, str);
            stringstream(str) >> totalrow >> seat_per_row;

            outputfile << "Number of rows: " << totalrow << endl;
            outputfile << "Number of seats per row: " << seat_per_row << endl;

            str.clear();

            cout << "Input the number default seat price.";
            getline(cin, str);
            stringstream(str) >> defaultprice;

            outputfile << "Default seat price: " << defaultprice << endl;


            cout << "Input special row prices";
            getline(cin, str);
            outputfile << "List of special row prices: " << str << endl;


            cout << "Input list of blocked seats";
            getline(cin, str);
            outputfile << "List of blocked seats: " << str << endl;

            outputfile.close();
   
    }
    else {

        outputfile << "Number of rows: " << totalrow << endl;
        outputfile << "Number of seats per row: " << seat_per_row << endl;
        outputfile << "Default seat price: " << defaultprice << endl;
        outputfile << "List of special row prices: " << endl;
        outputfile << "List of blocked seats: " << endl;

    }

}



void display_option(int& seat_per_row, int& totalrow, vector<string>& Seatmap, string str, string str2, int ticketsale) {


    int count = 0, totalcount = 0;

    if (str == "Yes" || str == "yes") {

        int count = 0, totalcount = 0;

        cout << setw((8 + seat_per_row * 2) / 2) << "Seats" << endl;
        cout << setw(8);

        for (int i = 1; i <= seat_per_row; i++) {

            cout << i % 10 << ' ';

        }


        cout << endl;




        for (int i = 1; i <= totalrow; i++) {

            cout << "Row " << left << setw(3) << i;

            for (int j = 1; j <= seat_per_row; j++) {

                cout << Seatmap.at(i - 1).at(j - 1) << ' ';
                count += (Seatmap.at(i - 1).at(j - 1) == '#');
            }

            cout << "Seat available: " << count
                << "   Seat unavailable: " << (seat_per_row - count);

            cout << endl;

            totalcount += count;

            count = 0;
        }

        cout << "Total available seat: " << totalcount << endl;



        if (str2 == "Yes" || str2 == "yes") {

            cout << "Total amount of ticket sold: "
                << ticketsale << endl;

        }



    }
    else {

        cout << setw((8 + seat_per_row * 2) / 2) << "Seats" << endl;
        cout << setw(8);

        for (int i = 1; i <= seat_per_row; i++) {

            cout << i % 10 << ' ';

        }


        cout << endl;




        for (int i = 1; i <= totalrow; i++) {

            cout << "Row " << left << setw(3) << i;

            for (int j = 1; j <= seat_per_row; j++) {

                cout << Seatmap.at(i - 1).at(j - 1) << ' ';

            }

            cout << endl;

        }


        if (str2 == "Yes" || str2 == "yes") {

            cout << "Total amount of ticket sold: "
                << ticketsale << endl;

        }

    }
}



bool exit_option(bool option, string str3, vector<string> &Seatmap, int totalrow, int seat_per_row) {


    cout << "Extra option: input ""Exit"" to exit the program." << endl;
    cout << setw(15) << "input ""Clear"" to clear the sale." << endl;
    cout << setw(15) << "input ""-1"" to skip option." << endl;

    getline(cin, str3);
    if (str3 == "Clear" || str3 == "clear") {

        for (int i = 0; i < totalrow; i++) {

            for (int j = 0; j < seat_per_row; j++) {

                if (Seatmap.at(i).at(j) == '*') {
                    Seatmap.at(i).at(j) = '#';
                }

            }

        }

    }
    else if(str3 == "Exit" || str3 == "exit") {

        option = false;
        return option;
    }
    else{
        return option;
        
        }

}










int main() {

    bool option = true, confirm;
    char rchar, schar;
    int totalrow = 15, specialrow = 0, seat_per_row = 30,
        ticketsale = 0, buyrow, buyseat, num1, num2,
        blockseat, blockrow;
    double defaultprice = 10.50, specialprice = 0;
    fstream outputfile;
    vector<double> $(totalrow*seat_per_row, defaultprice);
    vector<string> Seatmap;
    string str, str2, str3, buystr;

    
        outputfile.open("setup.txt", ios::in || ios::out);

        if (outputfile.is_open()) {

            setup_option(outputfile, str, totalrow, seat_per_row, defaultprice);
       
        }
        else {

        cout << "Error opening file." << endl;

        }



        for (int i = 0; i < totalrow; i++) {

            Seatmap.push_back(string(seat_per_row, '#'));

        }

        while (getline(outputfile, str)) {

            stringstream(str) >> rchar >> blockrow >> schar >> blockseat;

            
        }

        outputfile.close();
        cout << "Do you want to show availability of seats? ";
        getline(cin, str);
        cout << endl;

        cout << "Do you want to see the total amount of ticket sold? ";
        getline(cin, str2);
        cout << endl;



        while (option) {

                display_option(seat_per_row, totalrow, Seatmap, str, str2, ticketsale);

            
            do {

                cout << "Which one do you want to buy? ";
                getline(cin, buystr);
                cout << endl;
                stringstream(buystr) >> rchar >> buyrow >> schar >> buyseat;

                buystr.clear();

                cout << "The total price is: $" << $.at(((buyrow - 1) * seat_per_row + buyseat));
                cout << " Confirm to buy? [T/F]";
                getline(cin, buystr);
                stringstream(buystr) >> confirm;


                if (Seatmap.at(buyrow).at(buyseat) == '#' || Seatmap.at(buyrow).at(buyseat) == 'X') {
                    cout << "The seat is unavailable!"
                        << " Please select again." << endl;

                }


            } while (!(Seatmap.at(buyrow).at(buyseat) == '#'));


            Seatmap.at(buyrow - 1).at(buyseat - 1) = '*';

            confirm*ticketsale++;


            exit_option(option, str3, Seatmap, totalrow, seat_per_row);

        }





    return 0;
}