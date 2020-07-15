//****************************************************************************************************
//Program Name: shapes
//Author: Jin Han Ho
//IDE Used: Visual Studio 2019
//Program description: calculate area, perimeter, surface area, and volume of common 2D and 3D shapes
//****************************************************************************************************

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

const double PI = 3.14159;

int main()
{
	
	ifstream fin;
	ofstream fout;
	fin.open("shapes.txt");
	fout.open("output.txt");
	string str;
	double side = 0, length = 0, width = 0;

	
	while (fin >> str >> side >> length >> width) {                          // don't have a common name for all shapes, so height of a shape might be stored in "length" too

		if (str == "CIRCLE") {

			cout << str << " radius=" << fixed << setprecision(2)
				 << side << " area=" << (PI * side * side) << " perimeter="
				 << (2 * PI * side) << endl;

			fout << str << " radius=" << fixed << setprecision(2)
				 << side << " area=" << (PI * side * side) << " perimeter="
				 << (2 * PI * side) << endl;
	
		}
		else if (str == "SQUARE") {

			cout << str << " side=" << side
				 << " area=" << (side * side) << " perimeter="
				 << (4 * side) << endl;

			fout << str << " side=" << side
				 << " area=" << (side * side) << " perimeter="
				 << (4 * side) << endl;
		}
		else if (str == "TRIANGLE") {

			cout << str << " side=" << side
				 << " area=" << (side * side / 2) << " perimeter="
				 << (3 * side) << endl;

			fout << str << " side=" << side
				 << " area=" << (side * side / 2) << " perimeter="
				 << (3 * side) << endl;
		}
		else if (str == "RECTANGLE") {

			cout << str << " length=" << side << " width=" << length		// width is stored in length
				 << " area=" << (side * length) << " perimeter="  
				 << 2*(length + side) << endl;

			fout << str << " length=" << side << " width=" << length
				<< " area=" << (side * length) << " perimeter="
				<< 2 * (length + side) << endl;


		}
		else if (str == "CUBE") {

			cout << str << " side=" << side << " volume=" 
				 << (side * side * side) << " surface="
				 << (6 * side * side) << endl;

			fout << str << " side=" << side << " volume="
				 << (side * side * side) << " surface="
				 << (6 * side * side) << endl;

		}
		else if (str == "BOX") {

			cout << str << " length=" << side << " width=" << length			// width is stored in length
				 << " height=" << width << " volume=" << (side * length * width)		// height is stored in width
				 << " surface=" << 2*(side * length + length * width + side * width) << endl;

			fout << str << " length=" << side << " width=" << length
				<< " height=" << width << " volume=" << (side * length * width)
				<< " surface=" << 2 * (side * length + length * width + side * width) << endl;

		}
		else if (str == "CYLINDER") {

			cout << str << " side=" << side << " height=" << length				// height of shape is stored in length
				 << " volume=" << (PI * side * side * length) << " surface="
				 << 2 * (PI * side * side) + 2 * (PI * side * length) << endl;

			fout << str << " side=" << side << " height=" << length
				 << " volume=" << (PI * side * side * length) << " surface="
				 << 2 * (PI * side * side) + 2 * (PI * side * length) << endl;

		}
		else {
			
			cout << str << " invalid object" << endl;

			fout << str << " invalid object" << endl;

		}

	}

	fout.close();
	fin.close();

	cout << endl << endl;
	cout << "I attest that this code is my original programming work, and that I received" << endl
		<< "no help creating it.I attest that I did not copy this code or any portion of this" << endl
		<< "code from any source." << endl;


	return 0;
}

