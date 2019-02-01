//============================================================================
// Name        : Temple.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

template<class T>

class Test{
	T obj;
public:
	Test(T obj){
		this->obj = obj;
	}
	void print(){
		cout << obj << endl;
	}
};

// BONUS:  template function

template<class P>

P GetMax(P a1, P a2){
	P result;
	result = (a1>a2?a1:a2);
	return result;
}
//

template<typename R>

void print(R n){
	cout <<"Template class: "<< n << endl;
}

void print(int m){
	cout <<"Non-Template class: "<< m << endl;
}

template<class T>
void show(){
	cout << T() << endl;
}

int main() {

	Test<string> test1("Hello Worlddd !");
	test1.print();

	int k=15, l=9;
	double m=10.1, n=3;

	cout << GetMax(k,l) << endl;
	cout << GetMax(m,n) << endl;

	print("Hello Hi");
	print<>(4);
	print(4);

	show<double>();

	return 0;
}
