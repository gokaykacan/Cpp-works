//============================================================================
// Name        : Abstract.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 * A pure virtual function in C++ means that we have declared a virtual function
 * in some class but not have implemented the function body. In that case, this
 * class is called abstract class, and an abstract class can not be instantiated.
 *
*/

#include <iostream>
using namespace std;

class Animal{ // @suppress("Class has a virtual method and non-virtual destructor")
public:
	virtual void speak();
	virtual void run();

};

class Dog: public Animal{ // @suppress("Class has a virtual method and non-virtual destructor")
public:
	virtual void speak(){
		cout << "Hav" << endl;
	}

};

class Labrador: public Dog{ // @suppress("Class has a virtual method and non-virtual destructor")
public:
	virtual void run(){
		cout << "Labrador running" << endl;
	}
};
int main() {

	Labrador lab;
	lab.speak();
	lab.run();

	return 0;
}
