#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache
{
	const int CACHE_SIZE;
	list<int> mMyList;
	unordered_map<int, int> mCache;
public:
	LRUCache() : CACHE_SIZE(0) {}
	LRUCache(int size) : CACHE_SIZE(size) {}

	void addElementToCache(int val)
	{
		if(mCache.count(val) == false ) // if element DOES NOT exist
		{
			if (mCache.size() == CACHE_SIZE) // if cache is full
			{
				int val = mMyList.back();
				mMyList.pop_back();
				mCache.erase(val);
			}
		}
		else
		{
			for (list<int>::iterator it = mMyList.begin(); it != mMyList.end(); it++)
			{
				if (*it == val)
				{
					mMyList.erase(it);
					break;
				}
			}
			//mMyList.push_front(val);
		}
		mMyList.push_front(val);
		mCache[val] = mMyList.front();
	}

	bool checkElementExistInCache(int val)
	{
		if (mCache.count(val))
		{
			for (list<int>::iterator it = mMyList.begin(); it != mMyList.end(); it++)
			{
				if (*it == val)
				{
					mMyList.erase(it);
					break;
				}
			}
			mMyList.push_front(val);
			return true;
		}
		return false;
	}
	void displayCache()
	{
		unordered_map<int, int>::iterator it = mCache.begin();
		while (it != mCache.end())
		{
			cout << "Cache: " << it->second << endl;
			++it;
		}
	}

};

int main()
{
	LRUCache* myCache = new LRUCache(2);
	myCache->addElementToCache(0);
	myCache->addElementToCache(2);
	cout << "Element 0 Exits: " << myCache->checkElementExistInCache(0) << endl;;
	myCache->addElementToCache(3);
	cout << "Element 2 Exits: " << myCache->checkElementExistInCache(2) << endl;;
	myCache->addElementToCache(4);
	cout << "Element 0 Exits: " << myCache->checkElementExistInCache(0) << endl;;
	cout << "Element 3 Exits: " << myCache->checkElementExistInCache(3) << endl;;
	cout << "Element 4 Exits: " << myCache->checkElementExistInCache(4) << endl;;

	myCache->displayCache();
	return 0;
}