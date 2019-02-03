//============================================================================
// Name        : Vectors.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// Bu derste, capacity ve size'larýn ayný þey olmadýðý vurgulanmaktadýr
// capacity reserve fonksiyonu ile deðiþtirilebilir
// vectorü clear yapmadan, size'ýný düþürürsek, önceki elemanlar silinmez
#include <iostream>
#include <vector>
using namespace std;

int main() {
	//cout << "!!!Hello World it's me again!!!" << endl; // prints !!!Hello World!!!

	vector<double> numbers;
	cout << "Size: " << numbers.size() << endl;

	unsigned int capacity = numbers.capacity();
	cout << "Capacity: " << capacity << endl;

	for(int i=0; i<10000; i++){
		if(numbers.capacity() != capacity){
			capacity = numbers.capacity();
			cout << "Capacity(" << i << ")" << capacity << endl;
		}
		numbers.push_back(i);
	}
	cout << endl;
	vector<string> strings;
	cout << "Size: " << strings.size() << endl;
	unsigned int capacity2 = strings.capacity();

	strings.push_back("one");
	if(strings.capacity() != capacity2){
		capacity2 = strings.capacity();
		cout << "Capacity2: " << capacity2 << endl;
	}
	strings.push_back("two");
	if(strings.capacity() != capacity2){
		capacity2 = strings.capacity();
		cout << "Capacity2: " << capacity2 << endl;
	}
	strings.push_back("three");
	if(strings.capacity() != capacity2){
		capacity2 = strings.capacity();
		cout << "Capacity2: " << capacity2 << endl;
	}
	strings.push_back("four");
	if(strings.capacity() != capacity2){
		capacity2 = strings.capacity();
		cout << "Capacity2: " << capacity2 << endl;
	}
	strings.push_back("five");
	if(strings.capacity() != capacity2){
		capacity2 = strings.capacity();
		cout << "Capacity2: " << capacity2 << endl;
	}
	strings.push_back("six");
	if(strings.capacity() != capacity2){
		capacity2 = strings.capacity();
		cout << "Capacity2: " << capacity2 << endl;
	}
	strings.push_back("seven");
	if(strings.capacity() != capacity2){
		capacity2 = strings.capacity();
		cout << "Capacity2: " << capacity2 << endl;
	}
	strings.push_back("eight");
	if(strings.capacity() != capacity2){
		capacity2 = strings.capacity();
		cout << "Capacity2: " << capacity2 << endl;
	}
	strings.push_back("nine");
	if(strings.capacity() != capacity2){
		capacity2 = strings.capacity();
		cout << "Capacity2: " << capacity2 << endl;
	}
	cout << endl;
	//numbers.clear(); // clear numbers vector
	//it is not changed
	//cout << "Size: " << numbers.size() << endl;
	//cout << "Capacity of numbers after clear operation: " << numbers.capacity() << endl;
	cout << endl;
	numbers.resize(200);
	cout <<"Index 2: " << numbers[2] << endl;
	cout << "Resized value: " << numbers.size() << endl;
	cout << endl;
	cout << "Capacity before reserve: " << numbers.capacity() << endl;
	numbers.reserve(100000); // now capacity is also this much
	cout << "Capacity: " << numbers.capacity() << endl;

	return 0;
}
