//============================================================================
// Name        : Delegating.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

//C++98 de bir constructor u başka constructor içinde çağıramıyorduk. C++11 ile yapabiliriz.
class Parent
{
	int dogs;
	string text;

public:
	Parent(): Parent("hello") // burada oldugu gibi.
	{
		dogs = 7;
		cout << "No parameter parent constructor" << " " << text << " " << dogs << endl;
	}

	Parent(string _text)
	{
		this->text = _text;
		dogs = 5;
		cout << "String parameter parent constructor" << " " << text << " " << dogs << endl;
	}
	//virtual ~Parent();
};

class Child: public Parent
{
public:
	Child() = default; // {} // = Parent("hello");

	//virtual ~Child();
};

int main() {

	Parent parent("Hello");
	Child child;

	return 0;
}
