//============================================================================
// Name        : Vectors__.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <vector>
using namespace std;

int main()
{

    //vector example
    vector<string> strings; // an empty vector definition

    strings.push_back("one");
    strings.push_back("two");
    strings.push_back("three");

    for(vector<string>::iterator it = strings.begin(); it != strings.end(); it++){
        cout << *it << endl;
    }
    vector<string>::iterator it = strings.begin();
    it +=1;

    cout << *it << endl;

    cout << "OK it is working NOW" << endl;
    return 0;
}
