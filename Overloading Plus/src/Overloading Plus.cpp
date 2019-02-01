//============================================================================
// Name        : Overloading.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Complex.h"
using namespace std;

int main() {

	Complex c1(3,4);
	Complex c2(4,5);
	Complex c3(2,5);
	cout << c1+c2+c3 << endl;
	Complex c4(3.4, 9);

	cout << 2.4 + c4 << endl;
	cout << 5 + 4.2 + c1 + c2 + c3 + 2.4 + 1 << endl;

	return 0;
}
