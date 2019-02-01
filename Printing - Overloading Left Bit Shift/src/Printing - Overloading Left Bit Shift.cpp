//============================================================================
// Name        : Printing.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Test{
private:
	int age;
	string name;
public:
	Test(int age, string name): age(age), name(name){
	}
	~Test(){}
	friend ostream &operator<<(ostream &out, const Test &test){
		out << test.age << ": " << test.name;
		return out;
	}
};

int main() {
	Test test1(27, "Gökay");
	Test test2(23, "Ýlkin");

	cout << test1 << endl << test2 << endl; // yukarýda overload ile bunu compile edilebilir yaptýk

	return 0;
}
