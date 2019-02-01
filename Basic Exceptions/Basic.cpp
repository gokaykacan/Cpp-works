#include <iostream>
using namespace std;

void mightgoWrong(){

	bool error = true;

	if (error){

		throw 8;
	}
}


int main(){

	mightgoWrong();

	return 0;
}
