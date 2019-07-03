//============================================================================
// Name        : Object.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Test {
	int id{5};
	string name{"Mike"};

public:
	Test() = default;
	Test(int id): id(id){
	}
	Test(const Test &other) = delete;
	Test &operator=(const Test &other) = delete;
	void print() {
		cout << id << ": " << name << endl;
	}
};
int main() {
	//cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Test test;
	test.print();

	Test test2(77);
	test2.print();

/*
 *  Wont work- we deleted them
 *  Test test3 = test2;
	test3 = test;*/
	return 0;
}
