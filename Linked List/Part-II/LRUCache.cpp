#include<bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    int cap;
    list<int> dll; // front = LRU, back = MRU

    unordered_map<int, pair<int, list<int>::iterator>> mpp;

    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {

        if(!mpp.count(key))
            return -1;

        int val = mpp[key].first;

        dll.erase(mpp[key].second);
        dll.push_back(key);

        mpp[key].second = prev(dll.end());

        return val;
    }

    void put(int key, int value) {

        if(mpp.count(key)) {

            dll.erase(mpp[key].second);
            dll.push_back(key);

            mpp[key] = {value, prev(dll.end())};
            return;
        }

        if(mpp.size() == cap) {

            int lru = dll.front();

            dll.pop_front();
            mpp.erase(lru);
        }

        dll.push_back(key);
        mpp[key] = {value, prev(dll.end())};
    }
};