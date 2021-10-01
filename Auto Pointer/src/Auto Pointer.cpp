//============================================================================
// Name        : Auto.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>
using namespace std;

class Test{
public:
	Test(){
		cout << "Constructor" << endl;
	}
	void greet(){
		cout << "Hello World!" << endl;
	}

	~Test(){
		cout << "Destructor" << endl;
	}

};

class Temp{
private:
	unique_ptr<Test[]> pTest;
public:
	Temp(): pTest(new Test[2]){}
};

int main() {

	{ // scope bitince unique pointer ya da auto pointer kendini temizler
	cout << "1- -----------------------" << endl;
	unique_ptr<Test[]> pTest1(new Test[2]); // arraylarda auto_ptr kullanamayız !

	pTest1[1].greet();

	cout << "1- Finished" << endl;
	}

	{
	cout << "2- -----------------------" << endl;
	auto_ptr<Test> pTest(new Test); // burada unique_ptr yerine auto_ptr de kullanabiliriz

	pTest->greet();
	cout << "2- Finished" << endl;
	}

	{
	cout << "3- -----------------------" << endl;
	Temp pTemp;

	cout << "3- Finished" << endl;
	}
	return 0;
}
