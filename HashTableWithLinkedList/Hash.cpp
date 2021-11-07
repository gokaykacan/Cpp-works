#include <iostream>
#include <map>
using namespace std;

/*
* Let's say has table has 5 hash and 15 elements to implement, it looks like below:
* myHash[0]: 0->5->10
* myHash[1]: 1->6->11
* myHash[2]: 2->7->12
* myHash[3]: 3->8->13
* myHash[4]: 4->9->14
*/

class LinkedList
{
	LinkedList* mNext;
	int mVal;

public:
	LinkedList() : mVal(0), mNext(nullptr) {}
	LinkedList(int val) : mVal(val), mNext(nullptr) {}
	LinkedList(int val, LinkedList* next) : mVal(val), mNext(next) {}

	void addValueToList(int val)
	{
		LinkedList* pNew = new LinkedList(val);
		LinkedList* pList = this;

		while (pList->mNext != nullptr)
		{
			pList = pList->mNext;
		}
		pList->mNext = pNew;
	}
	void displayList()
	{
		LinkedList* pList = this;
		while (pList != nullptr)
		{
			if (pList->mNext != nullptr)
				cout << pList->mVal << "->";
			else
				cout << pList->mVal << " ";

			pList = pList->mNext;
		}
		cout << endl;
	}
};

class HashTable
{
	int BUCKET_SIZE;
	map<int, LinkedList*> myHash;

public:
	HashTable(int hashSize) : BUCKET_SIZE(hashSize)
	{
		//initialize hash table
		for (int i = 0; i < BUCKET_SIZE; i++)
		{
			myHash[i] = nullptr;
		}
	}

	int findHashIndex(int val)
	{
		return val % BUCKET_SIZE;
	}

	void addElementToTable(int val)
	{
		LinkedList* pList = myHash[findHashIndex(val)];
		if (pList != nullptr)
		{
			myHash[findHashIndex(val)]->addValueToList(val);
		}
		else
		{
			myHash[findHashIndex(val)] = new LinkedList(val);
		}
	}
	void displayHashTable()
	{
		HashTable* pTable = this;
		for (int i = 0; i < BUCKET_SIZE; i++)
		{
			cout << "myHash[" << i << "]" << ": ";
			myHash[i]->displayList();
		}
	}
};

int main()
{
	int b[]{ 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,55,23,78,32,44,64,51 };
	HashTable* myTable = new HashTable(5);
	for (auto x : b)
	{
		myTable->addElementToTable(x);
	}

	myTable->displayHashTable();
	return 0;
}