#include <iostream>
#include <exception>
using namespace std;

void goesWrong(){

	bool error1detected = false;
	bool error2detected = true;

	if (error1detected){
		throw exception();
	}
	if (error2detected){
		throw bad_alloc();
	}
}

int main(){

	try{
		goesWrong();
	}
	catch(exception &e){
		cout << "Catching Exception: " << e.what() << endl;
	}
	/*
	   bad_alloc önce yakalanmaya çalýþýlmalý, çünkü exception sýnýfýnýn bir alt sýnýfýdýr.
	   Bu yüzden Yukarýdaki catch önce yakalar.
	   Subclass lar hata yakalamaya çalýþýrken üstte yakalanmaya çalýþýlmalýdýr
	*/
	catch(bad_alloc &e){
		cout << "Catching bad_alloc" << e.what() << endl;
	}

	return 0;
}
