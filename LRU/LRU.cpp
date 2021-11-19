#include <iostream>
#include <unordered_map>

using namespace std;

/*
* constructor: determines the size of cache
* void display(): displays all elements at the cache
* void addElement(int val): adds element to the cache, if the cache is full, removes LRU element and adds this.
* boolean checkElementInCache(int val): checks if the element in list, returns true or false
*/
class LinkedList
{
	LinkedList* mNext;
	LinkedList* mpHead;
	int mVal;

public:
	LinkedList() : mVal(0), mNext(nullptr), mpHead(this) {}
	LinkedList(int val) : mVal(val), mNext(nullptr), mpHead(this) {}

	void addElementToFront(int val)
	{
		if (mpHead == nullptr)
		{
			mpHead = new LinkedList(val);
			return;
		}
		LinkedList* pNew = new LinkedList(val);
		pNew->mNext = mpHead;
		mpHead = pNew;
	}
	void removeElement(int val)
	{
		if (mpHead->mVal == val) //meaning HEAD
		{
			*mpHead = *(mpHead->mNext);
		}
		else
		{
			LinkedList* pNow = mpHead;
			LinkedList* pPrevious = pNow;
			pNow = pNow->mNext;
			while (pNow != nullptr)
			{
				if (pNow->mVal == val)
				{
					pPrevious->mNext = pNow->mNext;
					//delete pNow;
					break;
				}
				pPrevious = pNow;
				pNow = pNow->mNext;
			}
		}
	}
	int getLastElement()
	{
		LinkedList* pList = mpHead;
		while (pList != nullptr)
		{
			if(pList->mNext == nullptr)
				return pList->mVal;
			pList = pList->mNext;
		}
	}
	int getFirstElement()
	{
		if (mpHead != nullptr)
			return mpHead->mVal;
	}

	bool getElementIfExist(int val)
	{
		LinkedList* pList = mpHead;
		while (pList != nullptr)
		{
			if (pList->mVal == val)
				return true;
			pList = pList->mNext;
		}
		return false;

	}

	void displayList()
	{
		LinkedList* pList = mpHead;
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
class LRUCache
{
	const int mSize;
	LinkedList* pMyList;
	unordered_map<int, int> myCache;
public:
	LRUCache() : mSize(0), pMyList(nullptr) {}
	LRUCache(int size) : mSize(size), pMyList(nullptr) {}

	void addElementToTheCache(int val)
	{
		if (myCache.find(val) == myCache.end() ) // not present in the cache
		{
			if (myCache.size() == mSize) // cache is full
			{
				int last = pMyList->getLastElement();
				myCache.erase(last);
				pMyList->removeElement(last);
			}
			
		}
		else // present in the cache
		{
			pMyList->removeElement(val);
		}

		if (pMyList == nullptr) 
			pMyList = new LinkedList(val);
		else
			pMyList->addElementToFront(val);

		myCache[val] = pMyList->getFirstElement();

	}
	bool checkElementInCache(int val)
	{
		if (myCache.count(val)) // if exist, move val to front in the list
		{
			if (pMyList != nullptr)
			{
				pMyList->removeElement(val);
				pMyList->addElementToFront(val);
			}
			return true;
		}
		return false;

	}
	void displayCache()
	{
		unordered_map<int, int>::iterator it = myCache.begin();
		while (it != myCache.end())
		{
			cout << "myCache:" << it->second << endl;
			++it;
		}
	}
};

int main()
{
	//LinkedList* pList = new LinkedList(5);
	//pList->addElementToFront(8);
	//pList->addElementToFront(9);
	//pList->removeElement(5);
	//pList->addElementToFront(11);

	//pList->displayList();
	//cout << "Last: " << pList->getLastElement() << endl;
	//cout << "First: " << pList->getFirstElement() << endl;
	LRUCache* myCache = new LRUCache(2);
	myCache->addElementToTheCache(1);
	myCache->addElementToTheCache(2);
	myCache->displayCache();
	cout << "Element[1] Exist: " << myCache->checkElementInCache(1) << endl;
	cout << endl;
	myCache->addElementToTheCache(5);
	myCache->displayCache();
	cout << "Element[1] Exist: " << myCache->checkElementInCache(1) << endl;
	
	delete myCache;

	return 0;
}
