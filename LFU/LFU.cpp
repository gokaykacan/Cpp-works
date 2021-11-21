#include <iostream>
#include <memory>
#include <unordered_map>

using namespace std;

class LFUCache {
    int CAPACITY;
    unordered_map<int, int> myCache; // value, counter
    unordered_map<int, int>::iterator it;
public:
    LFUCache(int capacity): CAPACITY(capacity) {
        myCache.clear();
    }

    int get(int value) {
        if (myCache[value] > 0)
        {
            myCache[value] += 1;
            return value;
        }
        myCache.erase(value);
        return -1;
    }

    void put(int value) {
        if (myCache.size() == CAPACITY)
        {
            if (myCache[value] == 0)
            {
                myCache.erase(findLFUValueFromCache(myCache));
            }
        }
        myCache[value] += 1;

    }

    void printCache()
    {
        it = myCache.begin();
        cout << endl;
        while (it != myCache.end() )
        {
            cout << "Value: " << it->first << " Freq: " << it->second << endl;
            it++;
        }
        cout << endl;
    }
    int findLFUValueFromCache(unordered_map<int, int> myCache) // value, counter
    {
        it = myCache.begin();
        int LFUColunter = 0;
        int LFUValue = 0;
        while (it != myCache.end())
        {
            if (it->second != 0)
            {
                LFUColunter = it->second;
                LFUValue = it->first;
                break;
            }
            it++;
        }

        it = myCache.begin();
        while (it != myCache.end()) // find LFU value
        {
            if (it->second != 0 && it->second < LFUColunter)
            {
                LFUColunter = it->second;
                LFUValue = it->first;
            }
            it++;
        }
        return LFUValue;
    }
};


int main()
{
    std::unique_ptr<LFUCache> pLFU(new LFUCache(2));

    pLFU->put(5);// value 5, freq 1
    pLFU->put(2);// value 2, freq 1
    cout << "Get(5): " << pLFU->get(5) << endl; // print 5, value 5, freq 2
    pLFU->put(5);// value 5, freq 3
    pLFU->printCache();// 5->3, 2->1

    pLFU->put(8);// delete 2(LFU) and put 8, value 8, freq 1
    pLFU->put(8);// value 8, freq 2
    pLFU->printCache();// 5->3, 8->2
    cout << "Get(8): " << pLFU->get(8) << endl; //5->3, 8->3
    cout << "Get(2): " << pLFU->get(2) << endl; // returns -1, no 2

    pLFU->put(9);//8->3, 9->1
    pLFU->printCache();


	return 0;
}