//============================================================================
// Name        : STL.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {

	map<string, vector<int> > scores;

	scores["Mike"].push_back(10);
	scores["Mike"].push_back(30);
	scores["Vicky"].push_back(43);

	vector<int> k;

	k = {4,5,7};
	k.pop_back();

	scores.insert(make_pair("Ali", k));
	scores.insert(make_pair("Ahmet", 6));// Böyle eleman eklenmiyor, 6 tane sýfýr ekliyor

	scores["Ahmet"].pop_back();


	for(auto it = scores.begin(); it != scores.end(); it++){

		cout << it->first << ": " << flush;
		vector<int> _scores = it->second;

		for(unsigned int i = 0; i<_scores.size(); i++){
			cout << _scores[i] << " " << flush;
		}

		cout << endl;
	}

	return 0;
}
