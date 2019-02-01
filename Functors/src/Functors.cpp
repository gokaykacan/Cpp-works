//============================================================================
// Name        : Functors.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 * A functor (or function object) is a C++ class that acts like a function.
 * Functors are called using the same old function call syntax. To create a functor,
 * we create a object that overloads the operator(). ... Thus, an object a is created
 * that overloads the operator().
*/
#include <iostream>
using namespace std;

struct Test{
	virtual bool operator()(string &test)=0;
	virtual ~Test(){}
};
struct Matchtest: public Test{
	bool operator() (string &text){
		return text == "lion";
	}
};

void check(string text, Test &test){
	if(test(text)){
		cout << "String Matches !" << endl;
	}
	else{
		cout << "String does not match !" << endl;
	}
}
int main() {

	Matchtest pred;

	string value = "lion";

	Matchtest t;
	check("lion", t);

	return 0;
}
