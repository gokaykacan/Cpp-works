//============================================================================
// Name        : Overloading.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Test{

private:
	int id;
	string name;

public:
	Test(): id(0), name(""){
	}

	Test(int id, string name): id(id), name(name){
	}

	~Test(){}

	void print(){
		cout << id << ": " << name << endl;
	}
	//& önemli
	const Test &operator=(const Test &other){
		cout << "Assignment Running" << endl;
		id = other.id;
		name = other.name;

		return *this;
	}

	Test(const Test &other){
		cout << "Copy constructor running" << endl;
		id = other.id;
		name = other.name;

		//*this = other;
	}

};



class Test2
{
	int *ptr;
public:
	Test2 (int i = 0)	 { ptr = new int(i); }
	void setValue (int i) { *ptr = i; }
	void print()		 { cout << *ptr << endl; }
/*	Test2(const Test2 &other){
		cout << "Copy constructor2 running" << endl;
		*this = other;
	}*/
	Test2 & operator=(const Test2 &t);

};

Test2 &Test2::operator=(const Test2 &t)
{
// Check for self assignment
if(this != &t) // this if check is recommended
	*ptr = *(t.ptr);

cout << "Assignment2 Running" << endl;
return *this;
}



int main() {

	Test test1(10, "Mike");
	test1.print();

	Test test2;
	test2 = test1;
	test2.print();

	Test test3;
	test3.operator=(test2);
	test3.print();

	cout << endl;

	//Copy initialization
	// Eðer assignment overload yapýyorsak, kopya constructor yazmamýz gerekir. Bu bir kuraldýr
	Test test4= test1; // böyle bir þey yazdýðýmýz için copy constructor yazdýk
	test4.print();

	cout << endl;

	Test2 t1(5);
	Test2 t2;
	t2 = t1;
	t1.setValue(10);
	t2.print(); // Eðer assignment operator yapmasaydýk, 10 print edilecekti, assign operator ile bundan kurtulduk

	Test2 t3 = t2;
	t3.print();


	return 0;
}
