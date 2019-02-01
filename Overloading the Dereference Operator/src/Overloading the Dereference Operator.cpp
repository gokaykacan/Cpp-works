//============================================================================
// Name        : Overloading.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Complex.h"
#include <iostream>
using namespace std;

int main() {

	Complex c1(2,4);

	cout << *c1  + *Complex(3,4)<< endl;
	return 0;
}
