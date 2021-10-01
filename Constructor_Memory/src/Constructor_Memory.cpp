//============================================================================
// Name        : Constructor_Memory.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Test
{
private:
	static const int SIZE = 500;
	int *_pBuffer;

public:
	Test()
	{
		cout << "Default const" << endl;
		_pBuffer = new int[SIZE]{};
	}
	Test(int i)
	{
		cout << "Parameter const" << endl;
		_pBuffer = new int[SIZE]{};

		for(auto i=0; i<SIZE; ++i)
		{
			_pBuffer[i] = 7*i;
		}
	}
	Test(const Test &other)
	{
		cout << "Copy const" << endl;
		_pBuffer = new int[SIZE]{};
		memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int));
	}
	Test &operator=(const Test &other)
	{
		cout << "assignment" << endl;
		memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int));

		return *this;
	}
	~Test()
	{
		cout << "Destructor" << endl;
		delete [] _pBuffer;
	}

	friend ostream &operator<<(ostream &out, const Test &test );

};

ostream &operator <<(ostream &out, const Test &test)
{
	out << "Hello from test";
	return out;
}

Test getTest()
{
	return Test();
}

int main() {

	Test test1 = getTest();

	cout << test1 << endl;
	return 0;
}
