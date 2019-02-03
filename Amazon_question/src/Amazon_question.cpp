//============================================================================
// Name        : Amazon_question.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <map>
#include <list>
using namespace std;

class Test{
private:
	int age;
	string name;
public:
	Test(): age(0), name(""){
	}
	Test(int age, string name): age(age), name(name){
	}
	//~Test(){}
	void print() const {
		cout << age << ": " << name << endl;
	}
	bool operator<(const Test &other) const{
		if(name == other.name)
			return age < other.age;

		return name < other.name;
	}
};

int main() {

	map<Test, int> test;
	//test.insert(make_pair(28, "Gokay"));
	//test.insert(make_pair(24, "Ýlkin"));
	test[Test(27, "Gokay")] = 1;
	test[Test(23, "Ilkin")] = 2;

	test.insert(make_pair(Test(49, "Sevim"),3));
	test.insert(make_pair(Test(89, "Sevim"),3));
	test.insert(make_pair(Test(55, "Murat"),0));
	test.insert(make_pair(Test(75, "Mahmut"),0));

	for(map<Test, int>::iterator it = test.begin(); it != test.end(); it++){
		cout << it->second << ": " << flush;
		it->first.print();
	}


	return 0;


}
