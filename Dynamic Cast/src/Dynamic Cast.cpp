//============================================================================
// Name        : Dynamic.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Parent {
public:
	virtual void speak() {
		cout << "parent!" << endl;
	}
};

class Brother: public Parent {

};

class Sister: public Parent {

};

int main() {

	Parent parent;
	Brother brother;

	Parent *ppb = &brother;

	Brother *pbb = dynamic_cast<Brother *>(ppb);

	if (pbb == nullptr) {
		cout << "Invalid cast" << endl;
	} else {
		cout << pbb << endl;
	}

	Parent *ppb2 = &parent;

	Brother *pbb2 = dynamic_cast<Brother *>(ppb2);

	if (pbb2 == nullptr) {
		cout << "From parent to child class dynamic cast is Invalid cast" << endl;
	} else {
		cout << pbb2 << endl;
	}

	return 0;
}
