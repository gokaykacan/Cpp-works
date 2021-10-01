//============================================================================
// Name        : Mutable.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	auto cat = 5;

	//mutable keyword ile yukarıdaki değişkene lambda fonk içinde başka değer atayabiliyorum.
	[cat]() mutable {
		cat = 8;
		cout << cat << endl;
	}();

	cout << cat << endl;

	return 0;
}
