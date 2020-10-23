//============================================================================
// Name        : Introducing.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void test( void (*pFunc)() )
{
	pFunc();
}

void test2( void (*pFunc2)(int m) )
{
	pFunc2( 5 );
}

int main() {

	auto func = [](){ cout << "Hello Gokay" << endl; };
	auto func2 = [](auto n){ cout << "n = "<< n << endl; };

	func();
	test(func);

	test( [](){ cout << "Hello again Gokay" << endl; } );

	func2(9);

	test2(func2);

	test2( [](auto n){ cout << "n = "<< n << endl; } );

	return 0;
}
