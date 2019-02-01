//============================================================================
// Name        : Sets.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <set>
using namespace std;

class Test{
	int id;
	string name;

public:
	Test(int id, string name):
		id(id), name(name){
	}
	~Test(){}
	void print() const{
		cout << id << ": " << name << endl;
	}

	bool operator<(const Test &other) const {
		/* Bu bloğu da yazarsak aşağıdaki Test(102, "Ali") print ettirilir
		if(name == other.name)
			return id < other.id;
		*/
		return name < other.name;
	}
};

int main() {

	set<int> numbers;

	numbers.insert(30);
	numbers.insert(10);
	numbers.insert(20);
	numbers.insert(30); // bir kez eklendiği için tekrar eklemez
	numbers.insert(60);

	// ordered şekilde yazar
	for(set<int>::iterator it = numbers.begin(); it != numbers.end(); it++){
		cout << *it << endl;
	}

	//bir elemanı buldurma
	set<int>::iterator itFinds = numbers.find(30);
	if(itFinds != numbers.end())
		cout << "Found: "<< *itFinds << endl;
	else
		cout << "Cannot Found !" << endl;

	if(numbers.count(30))
		cout << "Number found." << endl;

	set<Test> tests;

	tests.insert(Test(20, "Mike"));
	tests.insert(Test(10, "Ali"));
	// bunu print etmez çünkü yukarda operator overload yaparken isimlere bakarak yaptık, bu isimden zaten var.
	tests.insert(Test(102, "Ali"));
	tests.insert(Test(40, "Ahmet"));
	tests.insert(Test(30, "Mehmet"));

	for(set<Test>::iterator it = tests.begin(); it != tests.end(); it++){
			it->print();
	}

	return 0;
}
