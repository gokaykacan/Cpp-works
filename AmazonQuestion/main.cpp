/*
* Bir vector verilsin ve i�inde stringler olsun.G�r�ld��� gibi ayn� stringlerden birden fazla var.
* vector = ["bin", "can", "bin", "lay", "can", "can" ]
* ��kt� olarak �u isteniyor:
* result = ["can 3", "bin 2", "lay 1"]
* Yani o kelime ka� kez ge�iyorsa o kelime bo�luk ka� kez ge�ti�ini yazmam�z gerekiyor. 
* Ayr�ca En �ok ge�eni listenin ba��na yazmam�z bekleniyor
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

//template for
template <typename T1, typename T2>
struct greater_second {
	typedef pair<T1, T2> type;
	bool operator ()(type const& a, type const& b) const {
		return a.second > b.second;
	}
};


vector<string> solution(vector<string> givenVector)
{
	map<string, int> myMap;
	vector<string> result;

	for (auto it = givenVector.begin(); it != givenVector.end(); ++it)
	{
		myMap[*it] = myMap[*it] + 1;
	}

	//copy map to a vector
	vector<pair<string, int> > mapcopy(myMap.begin(), myMap.end());

	//sort vector descending order
	sort(mapcopy.begin(), mapcopy.end(), greater_second<string, int>());

	//copy elements to a vector for the result
	for (auto it = mapcopy.begin(); it != mapcopy.end(); ++it)
	{
		string resultString = it->first + " " + to_string(it->second);
		result.push_back(resultString);
	}

	return result;
}
int main()
{
	vector<string> v{ "bin", "an", "bin", "lay", "an", "an", "bin", "bin", "an", "bin"};

	for (auto x : solution(v))
		cout << x << endl;

	return 0;
}