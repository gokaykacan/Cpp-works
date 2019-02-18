//============================================================================
// Name        : Initialization.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int main() {

	int value{5};
	cout << value << endl;

	string texts[]{"one", "two", "three"};
	cout << texts[2] << endl;

	int *pInt = new int[3]{1,2,3};
	cout << pInt[1] << endl;
	delete pInt;

	int value1{}; // leaving empty means initialize to 0
	cout << value1 << endl;

	int *pSmthng = {}; // equavilent to int *pSmthng = nullptr
	cout << pSmthng << endl;

	vector<string> string{"one", "two", "three"}; //C++11 initialization for vectors.

	cout << string[2] << endl;

	return 0;
}
