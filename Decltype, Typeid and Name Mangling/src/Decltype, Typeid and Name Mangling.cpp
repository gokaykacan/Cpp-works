//============================================================================
// Name        : Decltype,.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <typeinfo>
using namespace std;

int main() {

	string value;

	cout << typeid(value).name() << endl; // tipini dönen fonk

	decltype(value) name = "Bob"; // value tipinde deðiþken tanýmlama

	cout << name << endl;

	return 0;
}
