#include <iostream>
using namespace std;

class CanGoWrong{
public:
	 CanGoWrong(){
		 char *pMemory = new char[9999999999999999];
		 delete[] pMemory;
	 }
};

int main(){

	try{
	CanGoWrong();
	}
	catch(bad_alloc &e){

		cout << "Caught Exception: " << e.what() << endl;
	}

	cout << "Still running code" << endl;

	return 0;
}
