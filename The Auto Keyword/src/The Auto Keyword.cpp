//============================================================================
// Name        : The.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

auto test() -> int {
	return 7;
}

template <class T, class S>
auto test2(T value, S value2) -> decltype(value + value2){
	return value + value2;
}

int get(){
	return 999;
}

auto test3() -> decltype(get()){ // return tipini decltype ile yazabiliriz
	return get();
}
int main() {

	cout << test2(6.1,5) << endl;
	cout << test3() << endl;
	return 0;
}
