//============================================================================
// Name        : Sorting.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

class Test{
	int id;
	string name;

public:
	Test(int id, string name): id(id), name(name) {
	}
	~Test(){}
	void print(){
		cout << id << ": " << name << endl;
	}
/*	bool operator<(const Test &other) const{
		return id < other.id;
	}*/
	//friend ile private olan elemanlar aþaðýda kullanýlabildi.
	friend bool comp(const Test &a, const Test &b);
};
bool comp(const Test &a, const Test &b){
	return a.id<b.id; // return a.name<b.name for string compare
}
int main() {

	vector<Test> tests;

	tests.push_back(Test(21, "Sue"));
	tests.push_back(Test(13, "John"));
	tests.push_back(Test(42, "Roj"));
	tests.push_back(Test(1, "Bob"));
	tests.push_back(Test(87, "Mike"));

	sort(tests.begin(), tests.end(), comp); // yukarýdaki operator overload ile bunu hallettik

	for(unsigned int i=0; i<tests.size(); i++){
		tests[i].print();
	}

	cout << endl;

	deque<Test> tests2;

	tests2.push_front(Test(13, "Aaa")); // Aaa
	tests2.push_front(Test(22, "Bbb")); // Bbb Aaa
	tests2.push_front(Test(2, "Ccc")); // Ccc Bbb Aaa
	tests2.push_front(Test(7, "Ddd")); // Ddd Ccc Bbb Aaa
	tests2.push_back(Test(9, "Eee")); // Ddd Ccc Bbb Aaa Eee, sone ekledi

	tests2.pop_front(); // en öndeki silindi
	tests2.pop_back(); // en arkadaki silindi

	//sort(tests2.begin(), tests2.end(), comp);

	for(unsigned int i=0; i<tests2.size(); i++){
		tests2[i].print();
	}

	return 0;
}
