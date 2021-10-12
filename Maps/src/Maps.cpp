//============================================================================
// Name        : Maps.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
using namespace std;

int main() {

	map<string, int> ages;

	ages["Hasan"] = 24;
	ages["Ahmet"] = 42;
	ages["Mike"] = 35;
	ages["Alican"] = 13;

	ages.insert(make_pair("Peter", 100));

	if(ages.find("Peter") != ages.end()){
		cout << "Element is found" << endl;
	}
	else{
		cout << "Element is NOT found" << endl;
	}

	for(map<string, int>::iterator it =ages.begin(); it != ages.end(); it++){
		cout << it->first << ": " << it->second << endl;
	}
	cout << endl;
	//ages["Ahmet"] = 88;

	for(map<string, int>::iterator it=ages.begin(); it != ages.end(); it++){
		pair<string, int> age = *it;

		cout << age.first << ": " << age.second << endl;
	}


	return 0;
}
