//============================================================================
// Name        : Capturing.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Test
{
private:
	int one{1};
	int two{2};

public:
	void run(){
		int three{3};

		auto func = [&, this]()
			{
				one = 999;
				cout << one << endl;
				cout << two << endl;
				cout << three << endl;
			};

		func();
	}
};

int main() {

	Test test;
	test.run();

	return 0;
}
