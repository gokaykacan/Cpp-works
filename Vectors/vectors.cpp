
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //cout<<"Hello World this is my first time !!";
    //vector example
    vector<string> strings;

    strings.push_back("one");
    strings.push_back("two");
    strings.push_back("three");


    for(vector<string>::iterator it = strings.begin(); it != strings.end(); it++){
    	//C++11 vector<string>::iterator = auto yapýlabilir
        cout << *it << endl;
    }
    vector<string>::iterator it = strings.begin();
    it +=2;

    cout << *it << endl;

    //two dimensional array example
    int allocations[2][2] = { {0,0},{0,1} };
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cout << allocations[i][j] << " " ;
        }
    }


    return 0;
}
