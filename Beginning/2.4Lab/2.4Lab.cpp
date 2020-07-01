// This progrma demonstrates the use of characters ans strings


// Jin Han Ho


#include <iostream>
#include <string>
using namespace std;

//Definition of constants
const string FAVORITESODA = "Dr. Dolittle"; // use double quotes for strings
const char BESTRATING = 'A';                // use single quotes for characters


int main()
{
    char rating;
    string favoriteSnack;
    int numberOfPeople;
    int topChoiceTotal;

    favoriteSnack = "crackers";
    rating = 'B';
    numberOfPeople = 250;
    topChoiceTotal = 148;





    cout << "The preferred soda is " << FAVORITESODA << endl;
    cout << "The preferred snack is " << favoriteSnack << endl;
    cout << "Out of " << numberOfPeople << " People "
        << topChoiceTotal << " chose these items!" << endl; 
    cout << "Each of these  products were given a rating of " << BESTRATING;
    cout << " from our expert tasters" << endl;
    cout << "The oher products were rated no higher than a " << rating
         << endl;
        
    return 0;
}

