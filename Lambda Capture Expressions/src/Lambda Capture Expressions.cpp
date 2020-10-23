//============================================================================
// Name        : Lambda.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int one = 1;
	auto two = 2;
	double three = 3.0;

	//Capture one, two
	[one, two](){ cout << one << ", " << two  << endl; }();

	//Capture all local variables by value
     [=](){ cout << one << ", " << two << ", " << three << endl; }();

	//Default Capture all local variables by value, but capture three by reference
    [=, &three](){three = 7.0; cout << one << ", " << two << ", " << three << endl; }();
	cout << three << endl;

	//Default Capture all local variables by reference
    [&](){three = 7, two = 8; cout << one << ", " << two << ", " << three << endl; }();

	//Default Capture all local variables by reference, but capture one and two by value
    [&, one, two ](){three = 88, cout << one << ", " << two << ", " << three << endl; }();


	return 0;
}
