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

	cout << typeid(value).name() << endl; // tipini d�nen fonk

	decltype(value) name = "Bob"; // value tipinde de�i�ken tan�mlama

	cout << name << endl;

	cout << typeid(name).name() << endl; // tipini d�nen fonk

	return 0;
}
