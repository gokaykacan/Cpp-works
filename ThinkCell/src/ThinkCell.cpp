//============================================================================
// Name        : ThinkCell.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <bits/stdc++.h>

using namespace std;

template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;

public:
	// constructor associates whole range of K with val
	interval_map(V const& val)
	: m_valBegin(val)
	{}
	std::map<K,V> m_map;
	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign( K const& keyBegin, K const& keyEnd, V const& val ) {

		//return if given wrong ranges
		if( (keyBegin < keyEnd) == false )
		{
			return;
		}
		auto mymap = m_map.begin();

		//if the value is already exist in the map then return
		for ( ; mymap != m_map.end(); ++mymap)
		{
			 if (mymap->second == val)
			 {
				 return;
			 }
		}

		//assign keyBegin and keyEnd values to i and y with using less-then operator only
		auto i = 0;
		auto y = 0;
		while(i<keyEnd)
		{
			i+=1;
		}
		while(y<keyBegin)
		{
			y+=1;
		}

		//insert elements between given ranges. If the value is the same value as m_valBegin, do not insert
		for(auto it = y; it<i; ++it)
		{
			if((it == m_map.begin()->first && val == m_valBegin)== false)
			{
				m_map.erase(it);
				m_map.insert(make_pair(it, val));
			}
		}

		//find the largest key value in the map
		auto maxKeyValue = m_map.rbegin()->first;

		//fill empty places in the map in order to apply consecutive map entries
		for(auto it = m_map.begin()->first; it<= maxKeyValue; ++it)
		{
			if(m_map.find(it) == m_map.end())
			{
				m_map.insert({it,m_map[it-1] });
			}
		}


	}

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}

/*	bool const& operator==(V const& val) const{
		bool rVal = false;
		auto mymap = m_map.begin();

		for ( ; mymap != m_map.end(); ++mymap)
		{
			 if (mymap->second == val)
			 {
				 cout << "val: " << val << " is found !!" << endl;
				 rVal = true;
				 break;
			 }
		}

		return rVal;
	}*/
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.

int main() {

	 interval_map<int,char> M('A');
	 M.assign(1,3,'B');
	 M.assign(4,6,'C');
	 M.assign(1,4,'X');
	 M.assign(8,12,'D');
	 M.assign(8,12,'H');
	 M.assign(11,15,'P');
	 M.assign(1,3,'G');
	 //M.assign(2,6, 'X');
	 cout << "M[3]:" <<  M[3] << endl;
	 auto it = M.m_map.begin();
	 for(; it!=M.m_map.end(); it++ )
	 {
		 cout << it->first << "," << it->second << endl;
	 }


}
