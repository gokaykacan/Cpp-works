//============================================================================
// Name        : Range-Based.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int main() {

	vector<string> V = {"one", "two", "three"};
	V.push_back("four");

	for(auto text: V){
		cout << text << " ";
	}

	cout << endl;
	string value = "Hello World";

	for(auto text: value){
		cout << text << " ";
	}
	return 0;
}
