#include <iostream>
#include <fstream>
using namespace std;

int main(){

	//ofstream outFile;
	fstream outFile;
	string outFileName = "text.txt";

	//outFile.open(outFileName);
	outFile.open(outFileName, ios::out);


	if(outFile.is_open()){
		outFile << "Hello There" << endl;
		outFile << 12345567 << endl;

		outFile.close();
	}
	else {
		cout << "Could not open File: " << outFileName << endl;
	}

	return 0;
}
