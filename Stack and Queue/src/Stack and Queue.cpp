//============================================================================
// Name        : Stack.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Test{
	string name;
public:
	Test(string name): name(name){
	}
	~Test(){
		//cout << "Object Destroyed " << endl;
	}
	void print(){
		cout << name << endl;
	}
};

int main() {
	//LIFO
	stack<Test> testStack;
	testStack.push(Test("Ali"));
	testStack.push(Test("Sue"));
	testStack.push(Test("Bob"));

	/*
	 * This is invalid code, object is destroyed !
	Test &test1 = testStack.top();
	testStack.pop();
	test1.print(); // reference refers the destroyed object
	 */
	while(testStack.size() > 0){
		Test &test = testStack.top();
		test.print();
		testStack.pop();
	}

	cout << endl;

	//FIFO
	queue<Test> testQueue;
	testQueue.push(Test("Ali"));
	testQueue.push(Test("Sue"));
	testQueue.push(Test("Bob"));

	testQueue.back().print(); // queue nin en arkasýndaki.

	cout << endl;

	while(testQueue.size() > 0){
		Test &test = testQueue.front(); // queue nin önündeki.
		test.print();
		testQueue.pop();
	}


	return 0;
}
