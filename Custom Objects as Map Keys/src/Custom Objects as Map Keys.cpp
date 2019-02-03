//============================================================================
// Name        : Custom.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

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
	Person(string name, int age):
		name(name), age(age){
	}
	void print() const {
		cout << name << ": " << age << endl;
	}
	//operator overload yapmasaydýk, compile aþaðýdaki for döngüsünde
	//önce hangisini yazdýracaðýný bilemezdi, çünkü hangi sýraya göre
	//yazdýracaðýný bilmiyor.! Burada < (küçüktür) operatorunu overload yaptýk
	bool operator<(const Person &other) const{
		if(name == other.name)//eðer isimler aynýysa yaþa göre
			return age < other.age;
		else // isimler ayný deðilse alfabetik duruma göre
			return name < other.name;
	}
};

int main() {
	map<Person, int> people;
	people[Person("Andy", 40)] = 40;
	people[Person("Andy", 40)] = 50; // aynýsýný tanýmladýk, artýk bu geçerli
	//burada bunu da artýk yazdýracak, isim ayný yaþ sýrasýna göre !
	//çünkü yukarda overload tanýmladýk
	people[Person("Andy", 440)] = 120;
	people[Person("Sue", 30)] = 30;
	people[Person("Gokay", 27)] = 27;

	for(map<Person, int>::iterator it = people.begin(); it != people.end(); it++){
		cout << it->second << ": " << flush;
		it->first.print();
	}

	return 0;
}
