#include <iostream>
#include<map>

using namespace std;
map<int, int> myMap;

int fibonacci(int n)
{
	for (int i = 3; i <= n; i++)
	{
		myMap[i] = myMap[i - 1] + myMap[i - 2];
	}
	return myMap[n];
}

int main()
{
	int n;
	myMap.insert(pair<int, int>(1, 0));
	myMap.insert(pair<int, int>(2, 1));
	cout << "Enter n to find the nth number in the Fibonacci Sequence : ";
	cin >> n;

	cout << "Result: " << fibonacci(n);


	return 0;
}