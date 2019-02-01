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

	Complex c1(3,5);
	Complex c2(3,5);

	if(c1 == c2)
		cout << "they are equal !" << endl;
	else
		cout << "they are not equal !" << endl;

	return 0;
}
