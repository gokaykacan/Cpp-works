/*
* Bir vector verilsin ve içinde stringler olsun.Görüldüðü gibi ayný stringlerden birden fazla var.
* vector = ["bin", "can", "bin", "lay", "can", "can" ]
* Çýktý olarak þu isteniyor:
* result = ["can 3", "bin 2", "lay 1"]
* Yani o kelime kaç kez geçiyorsa o kelime boþluk kaç kez geçtiðini yazmamýz gerekiyor. 
* Ayrýca En çok geçeni listenin baþýna yazmamýz bekleniyor
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