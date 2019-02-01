#include <iostream>
#include <fstream>
using namespace std;

int main (){
	string filename = "stats.txt";
	fstream input;

	input.open(filename);
	if(!input.is_open()){
		return 1;
	}

	while(input){
		string line;

		getline(input, line, ':');

		int population;
		input >> population;

		input >> ws; // C++11 reading white space

		if(!input){
			break;
		}

		cout << "'" << line << "'" << " -- '" << population << "'" << endl;
	}
	input.close();

	return 0;
}
