//============================================================================
// Name        : Custom.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
// fazladan constructor kullanýrsak programý her çaðýrdýðýmýzda gereksiz
// yere çaðýrýlýr. Burada ondan da bahsediliyor. Onun dýþýnda map genel olarak
// nasýl kullanýlýr o anlatýlýyor.
//

#include <iostream>
#include <map>
using namespace std;

class Person{
private:
	string name;
	int age;

public:
	Person(): name(""), age(0){

	}

	Person(const Person &other){
		cout << "Copy Constructor is running !" << endl;
		name = other.name;
		age = other.age;
	}
	Person(string name, int age):
		name(name), age(age){
	}
	void print() const {
		cout << name << ": " << age << endl;
	}
};

int main() {

	map<int, Person> people;

	people[0] = Person("Mike", 40);
	people[34] = Person("Vicky", 30);
	people[25] = Person("Roj", 20);

	people.insert(make_pair(55, Person("Bob", 45))); // eleman ekleme
	people.insert(make_pair(43, Person ("Gokay", 27)));

	for(map<int, Person>::iterator it = people.begin(); it != people.end(); it++){
		cout << it->first << "::: " << flush;
		//cout << it->second << flush; //bu çalýþmaz
		it->second.print();
	}

	return 0;
}
