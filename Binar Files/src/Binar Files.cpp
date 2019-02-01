/*
#pragma pack instructs the compiler to pack structure members with particular alignment. Most compilers, when you declare a struct, will insert padding between members to ensure that they are aligned to appropriate addresses in memory (usually a multiple of the type's size). This avoids the performance penalty (or outright error) on some architectures associated with accessing variables that are not aligned properly. For example, given 4-byte integers and the following struct:

struct Test
{
   char AA;
   int BB;
   char CC;
};
The compiler could choose to lay the struct out in memory like this:

|   1   |   2   |   3   |   4   |

| AA(1) | pad.................. |
| BB(1) | BB(2) | BB(3) | BB(4) |
| CC(1) | pad.................. |
and sizeof(Test) would be 4 × 3 = 12, even though it only contains 6 bytes of data. The most common use case for the #pragma (to my knowledge) is when working with hardware devices where you need to ensure that the compiler does not insert padding into the data and each member follows the previous one. With #pragma pack(1), the struct above would be laid out like this:

|   1   |

| AA(1) |
| BB(1) |
| BB(2) |
| BB(3) |
| BB(4) |
| CC(1) |
And sizeof(Test) would be 1 × 6 = 6.

With #pragma pack(2), the struct above would be laid out like this:

|   1   |   2   |

| AA(1) | pad.. |
| BB(1) | BB(2) |
| BB(3) | BB(4) |
| CC(1) | pad.. |
And sizeof(Test) would be 2 × 4 = 8.
*/

/*
The C++ standard guarantees the following:

static_casting a pointer to and from void* preserves the address. That is, in the following, a, b and c all point to the same address:

int* a = new int();
void* b = static_cast<void*>(a);
int* c = static_cast<int*>(b);
reinterpret_cast only guarantees that if you cast a pointer to a different type, and then reinterpret_cast it back to the original type, you get the original value. So in the following:

int* a = new int();
void* b = reinterpret_cast<void*>(a);
int* c = reinterpret_cast<int*>(b);
a and c contain the same value, but the value of b is unspecified. (in practice it will typically contain the same address as a and c, but that's not specified in the standard, and it may not be true on machines with more complex memory systems.)

For casting to and from void*, static_cast should be preferred.
*/

#include <iostream>
#include <fstream>
using namespace std;

#pragma pack(1)

struct Person{
	char name[50];
	int age;
	double height;

};

int main() {

	Person someone {"Frodo", 220, 0.8};

	string filename = "test.bin";

	/// Write File /////

	ofstream outputFile;

	outputFile.open(filename, ios::binary);

	if(outputFile.is_open()){

		outputFile.write(reinterpret_cast<char *>(&someone), sizeof(Person));
		outputFile.close();
	}
	else{
		cout << "Could not create file: " + filename << endl;
	}


	/// Read File /////

	Person someoneElse = {};
	ifstream inputFile;

		inputFile.open(filename, ios::binary);

		if(inputFile.is_open()){

			inputFile.read(reinterpret_cast<char *>(&someoneElse), sizeof(Person));
			inputFile.close();
		}
		else{
			cout << "Could not read file: " + filename << endl;
		}

		cout << someoneElse.name << "," << someoneElse.age << "," << someoneElse.height << endl;
	//cout << sizeof(Person) << endl;
	return 0;
}
