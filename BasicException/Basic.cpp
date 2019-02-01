#include <iostream>

using namespace std;

void mightgoWrong(){

	bool error1 = true; //true;
	bool error2 = false; //true;
	bool error3 = true;

	if (error1){
		throw "Something went WRONG";
	}
	if (error2){
		throw string("Someting else went WRONG");
	}
	if (error3){
		throw 8;
	}
}

void usesmightgoWrong(){
	mightgoWrong();
}

int main(){

	try {
	usesmightgoWrong();
	}
	catch (int e){
		cout << "Error code: " << e << endl;
	}
	catch (char const *e){
		cout << "Error message: " << e << endl;
	}
	catch (string &e){
		cout << "String Error message: " << e << endl;
	}

	cout << "Still running" << endl;
	return 0;
}
