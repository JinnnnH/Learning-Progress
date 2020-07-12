#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

bool PrimeNum(int num) {

    if (num <= 1) {
        return false;
    }

    for (int i = 2; i < sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}


int main()
{
    
    for (int i = 2; i <= 10000; i++) {

        if (PrimeNum(i)) {

            cout << i << endl;

        }

    }


    return 0;
}

