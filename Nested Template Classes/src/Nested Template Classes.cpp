//============================================================================
// Name        : Nested.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "ring.h"
using namespace std;

int main() {

	ring<string>::iterator it;
	it.print();

	ring<int>::iterator it2;
	it2.print();

	return 0;
}
