#include <iostream>
#include <memory>
#include <list>
#include<vector>

using namespace std;

class LinkedList
{
	LinkedList* next = nullptr;
	int data;
public:
	LinkedList(int data) : data(data) {}
	void addElementToTheList(int data)
	{
		LinkedList* n = this;
		LinkedList* newElement = new LinkedList(data);
		while (n->next != nullptr)
		{
			n = n->next;
		}
		n->next = newElement;
	}

	void printElements()
	{
		LinkedList* n = this;
		while (n != nullptr)
		{
			cout << n->data;
			if (n->next != nullptr) 
				cout << "->";
			n = n->next;
		}
		cout << endl;
	}
};
class HashTable
{
	const int BUCKET;
	list<int>* pList; // listemiz olsun bu liste içinde index'lerde  list tutacagiz

public:
	HashTable(int bucketSize) : BUCKET(bucketSize)
	{
		pList = new list<int>[BUCKET];
	}
	void AddItemToHashTable(int value)
	{
		pList[HashIndex(value)].push_back(value);
	}
	int HashIndex(int value)
	{
		return value % BUCKET;
	}
	void printList()
	{
		for (auto i = 0; i < BUCKET; ++i)
		{
			cout << i << ":";
			for (auto j: pList[i] )
			{
				cout << "->" << j;
			}
			cout << endl;
		}
	}
};

class HashTable2
{
	const int BUCKET;
	LinkedList** pList; // bu kez hash tablelarý list deðil linked list ile tutacagýz
public:
	HashTable2(int value): BUCKET(value)
	{
		pList = new LinkedList* [BUCKET];
		for (int i = 0; i < BUCKET; i++) //fill table with NULL values
		{
			pList[i] = nullptr;
		}
	}
	void AddItemToHashTable(int value)
	{
		if (pList[HashIndex(value)] == nullptr)
		{
			pList[HashIndex(value)] = new LinkedList(value);
		}
		else
		{
			pList[HashIndex(value)]->addElementToTheList(value);
		}
	}
	int HashIndex(int value)
	{
		return value % BUCKET;
	}
	void printList()
	{
		for (int i=0; i<BUCKET; i++ )
		{
			cout << i << ":";
			pList[i]->printElements();
			//cout << endl;
		}
	}
};
int main()
{
	cout << "-------WITH LIST--------" << endl;

	vector<int> a{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
	std::unique_ptr<HashTable> p_table{ new HashTable(2) };

	for (auto i : a)
	{
		p_table->AddItemToHashTable(i);
	}

	p_table->printList();

	cout << "-------WITH LINKED LIST--------" << endl;

	std::shared_ptr<HashTable2> p_table2{ new HashTable2(2) };

	for (auto i : a)
	{
		p_table2->AddItemToHashTable(i);
	}

	p_table2->printList();

	return 0;
}