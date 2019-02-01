//============================================================================
// Name        : Object.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Parent{
private:
	int one;
public:
	Parent(): one(0){

	}
	Parent(const Parent &other): one(0){
		one = other.one;
		cout << "Copy Parent Class" << endl;
	}
	virtual void print(){
		cout << "Parent Class" << endl;
	}

	virtual ~Parent(){

	}

};

class Child: public Parent{
private:
	int two;
public:
	Child(): two(0){

	}

	void print() {
		cout << "Child Class" << endl;
	}

	~Child(){

	}
};
int main() {

Child c1;

Parent &p1 = c1;
p1.print(); // virtual fonk sayesinde child class ýn fonk u çaðýrýldý

Parent p2 = Child(); // burada kopya const olayý var
p2.print();

	return 0;
}
