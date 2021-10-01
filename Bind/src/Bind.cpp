//============================================================================
// Name        : Bind.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <functional>

using namespace std;
using namespace placeholders;

class Test {
public:
	int add(int a, int b, int c) {
		cout << a << ", " << b << ", " << c << endl;
		return a + b + c;
	}
};

int _add(int a, int b, int c) {
	cout << a << ", " << b << ", " << c << endl;
	return a + b + c;
}

int run(function<int(int, int)> func) {
	return func(7, 3);
}

int main() {

	auto calc = bind(_add, _2, _3, _1); // argümanların sırası karışık veriyoruz, placeholders..
	cout << calc(10,20,30) << endl; // yukarıdaki sıraya göre 1. arg = 20, 2. arg = 30, 3. arg = 10 oldu.

	auto calc2 = bind(_add, _2, 100, _1);
	cout << calc2(10,20,30) << endl; // 20, 100, 10

	Test* test;

	auto calculate = bind(Test::add, test, _2, 100, _1);

	cout << run(calculate) << endl;

	return 0;
}
