//******************************************************************************************************
//Program Name: Colors
//Author: Jin Han Ho
//IDE Used: Visual Studio 2019 
//Program description: output the RGB value of a color which is represented by a generated random value
//******************************************************************************************************



#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <iomanip>
using namespace std;


struct Color {
	int r;
	int g;
	int b;
};


int main(){

	srand(time(0));
	const int MAX = 50, MIN = 5;
	int num = (rand()%(MAX - MIN + 1) + MIN);
	vector <Color> ColorVec;

	for (int i = 0; i < num; i++) {

		int r = (rand() % 256), 
			g = (rand() % 256), 
			b = (rand() % 256);
		Color tempColor = { r, g, b };

		ColorVec.push_back(tempColor);

	}

	cout << setw(10) << "Color#" << setw(10) << "R value" << setw(10) << "G value" << setw(10) << "B value" << endl;

	cout << setw(10) << "------" << setw(10) << "-------" << setw(10) << "-------" << setw(10) << "-------" << endl;


	for (int i = 0; i < num; i++) {

		cout << setw(8) << (i + 1) << setw(10) << ColorVec.at(i).r
			<< setw(10) << ColorVec.at(i).g << setw(10) << ColorVec.at(i).b << endl;

	}


	cout << endl << endl;
	cout << "I attest that this code is my original programming work, and that I received" << endl
		<< "no help creating it.I attest that I did not copy this code or any portion of this" << endl
		<< "code from any source." << endl;

	return 0;
}
