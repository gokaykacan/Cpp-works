//============================================================================
// Name        : The.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

bool check(string test)
{
	return test.size() == 5;
}

class Check
{
public:
	bool operator()(string& x)
	{
		return x.size() == 4;
	}
}check1;

void run(function<bool(string&)> check)
{
	string test = "stars";
	cout << check(test) << endl;
}

int main() {

	vector<string> vec{"one", "two", "three", "four", "seven"};
	auto size = 5;

	auto lambda = [size](string test){ return test.size() == 5; };

	int count = count_if( vec.begin(), vec.end(),lambda );
	cout << count << endl;

	count = count_if( vec.begin(), vec.end(), check );
	cout << count << endl;

	count = count_if( vec.begin(), vec.end(), check1 );
	cout << count << endl;

	run(lambda);
	run(check1);
	run(check);

	function<int(int, int)> add = [](int a, int b){ return a+b; };
	cout << add(7,5) << endl;

	return 0;
}
