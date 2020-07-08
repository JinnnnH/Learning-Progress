/*****************************************************************************************
Problem#: #2 Random Number Guessing Game
Question: Write a program that generates a random number between 1...100 
          and asks the user to guess what the number is. If the user's guess 
          is higher than the random number, the program should display 
          “Too high, try again”. If the user s guess is lower than the random 
          number, the program should display “Too low, try again”. The program 
          should use a loop that repeats until the user correctly guesses the 
          random number.

          The program will keep a count of the number of guesses that the user makes.
          When the user correctly guesses the random number, the program should display 
          the number of guesses.

Name: Jin Han Ho
ID: 1790201
Date: 28/2/2020
Status: complete
******************************************************************************************/

#include <iostream>
#include <sstream>
#include <iomanip>
#include <random>
using namespace std;

#include <iostream>

int main()
{
    
    string convert;
    int guessnum, correctnum, counter = 0;

    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(1, 100);

    correctnum = distribution(generator);


    do{

        cout << "Please guess a number between 1 and 100: ";
        getline(cin, convert);
        stringstream(convert) >> guessnum;
        counter++;

        if (guessnum < correctnum) {

            cout << "Too low. Please try again." << endl;

        }
        else if(guessnum > correctnum ){

            cout << "Too high. Please try again." << endl;

        }
        else {

            cout << "You are correct! the correct number is " << correctnum << endl;
            cout << "You have guessed " << counter << " times." << endl;

        }



      } while (guessnum != correctnum);





    return 0;
}