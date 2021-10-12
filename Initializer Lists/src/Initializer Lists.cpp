//============================================================================
// Name        : Initializer.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

class Test{
public:
	Test(initializer_list<string> texts){
		for(auto value: texts){
			cout << value << endl;
		}
	}
	void print(initializer_list<string> texts){
		for(auto value: texts){
			cout << value << endl;
		}
	}
};
int main() {

	vector<int> sayilar{1,2,4,6};

	cout << sayilar[2] << endl;

	Test p1({"apple", "banana", "orange"});
	p1.print({"one","two","three","four", "five"});

	return 0;
}
