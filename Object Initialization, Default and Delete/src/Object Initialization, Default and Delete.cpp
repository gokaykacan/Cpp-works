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
	Test() {};// = default;
	Test(int id): id(id) {}
	Test(int id, string name): id(id), name(name) {}
	Test(const Test &other) = delete;
	Test &operator=(const Test &other) = delete;
	void print() {
		cout << id << ": " << name << endl;
	}
};
int main() {
	Test test;
	test.print();

	Test test2(77);
	test2.print();

	Test test3(15, "Bob");
	test3.print();

	Test test4(727);
	test4.print();


   //Wont work- we deleted them
   //Test test4 = test;
	//test2 = test4;
	return 0;
}
