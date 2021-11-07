#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;


vector <int> reassignedPriorities(vector <int> p) {
    set <int> mySet;
    unordered_map <int, int> myMap;
    vector <int> ans;

    for (auto x : p)
    {
        mySet.insert(x);
    }

    int i = 1;
    for (auto it = mySet.begin(); it != mySet.end(); it++) {
        myMap[*it] = i;
        i++;
    }
    for (auto x : p) 
        ans.push_back(myMap[x]);

    return ans;
}

int main()
{
    vector<int> v{ 1,7,3,3 };
    reassignedPriorities(v);

    for ( auto x : reassignedPriorities(v) )
        cout << x << " ";
    return 0;
}