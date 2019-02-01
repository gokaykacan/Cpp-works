//============================================================================
// Name        : Using.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 * Function pointers can be useful when you want to create callback mechanism,
 * and need to pass address of an function to another function. They can also be
 * useful when you want to store an array of functions, to call dynamically for example. ...
 * It is a way of calling function by call by value.
 *
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool match(string test){

	return test.size() == 3;
}

int countString(vector<string> &texts, bool (*match)(string test)){

	int total = 0;

	for(vector<string>::iterator it = texts.begin(); it != texts.end(); it++){
		if(match(*it))
			total++;
	}

	return total;
}

int main() {

	vector<string> texts;

	texts.push_back("one");
	texts.push_back("two");
	texts.push_back("three");
	texts.push_back("four");
	texts.push_back("one");
	texts.push_back("two");
	texts.push_back("five");
	texts.push_back("six");
	texts.push_back("eleven");

	//for(vector<string>::iterator it = texts.begin(); it != texts.end(); it++ ){
	//	cout << match(*it) << endl;
	//}
	//cout << count_if(texts.begin(), texts.end(), match) << endl;

	cout << countString(texts, match) << endl;
	return 0;
}
