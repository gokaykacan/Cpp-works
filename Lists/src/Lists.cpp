//============================================================================
// Name        : Lists.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
using namespace std;

int main() {

	list<int> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(0);
	//list lerde random access, vector ve arraylerde olduğu gibi yoktur
	//cout << "Access to element 3: " << numbers[3];
	list<int>::iterator it = numbers.begin();
	it++; // ikinci sıraya geçildi.
	it = numbers.insert(it, 4214); // 4214 2. sıraya konuldu
	cout << "Element: " << *it << endl; // 2. element 4214

	list<int>::iterator eraseIt = numbers.begin();
	eraseIt++;
	/*eraseIt =*/ numbers.erase(eraseIt); // 4214 2. sıradan çıkarıldı
	cout << "Erased: " << *eraseIt << endl;

	for(list<int>::iterator it = numbers.begin(); it!=numbers.end();){
		if(*it == 2)
			numbers.insert(it, 4356);
		if(*it == 1)
			it = numbers.erase(it);
		else
			it++;
	}

	for(list<int>::iterator it = numbers.begin(); it!=numbers.end(); it++){
		cout << *it << endl;
	}

	return 0;
}
