//============================================================================
// Name        : A.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Complex.h"
using namespace std;

int main() {
	Complex c1(3, 7);
	cout <<"c1: " << c1 << endl;
	Complex c2 = c1;
	c2.setReal(9);
	cout << "c2: " << c2 << endl;
	Complex c3;
	c3 = c1;
	c3.setReal(8);
	cout << "c3: " << c3 << endl;

	return 0;
}
