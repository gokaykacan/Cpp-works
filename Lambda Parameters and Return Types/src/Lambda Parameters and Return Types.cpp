//============================================================================
// Name        : Lambda.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void test( void(*pFunc)(string) )
{
	pFunc("Bob");
}

double test2( double(*pFunc)(double, double) )
{
	return pFunc(9.8, 2);
}

void test3( double(*pFunc)(double, double) )
{
	cout << pFunc(8,3) << endl;
}

int main() {

	auto func = []( string name ){ cout << "Hello " << name << endl; };

	func("Mike");
	test(func);

	auto divide = [](auto n, auto m) -> double // fonksiyon double mi int mi dönecek karar veremiyor aþaðýda, bu sebeple return type koyduk
	{
		if( m == 0)
		{
			return 0;
		}
		return n/m;
	};

	cout << divide(7.5, 2) << endl;
	cout << test2(divide) << endl;
	cout << divide(8, 0) << endl;

	test3(divide);

	return 0;
}
