#include<bits/stdc++.h>
using namespace std;

class LFUCache {
public:

    int capacity;
    int currSize;

    unordered_map<int, list<vector<int>>::iterator> keyToNode;
    map<int, list<vector<int>>> freqToList;

    LFUCache(int capacity) {

        this->capacity = capacity;
        currSize = 0;
    }

    int get(int key) {

        if(!keyToNode.count(key)) {
            return -1;
        }

        auto itr = keyToNode[key];

        int value = (*itr)[1];
        int freq  = (*itr)[2];

        freqToList[freq].erase(itr);

        if(freqToList[freq].empty()) {

            freqToList.erase(freq);
        }

        freqToList[freq + 1].push_front({key, value, freq + 1});
        keyToNode[key] = freqToList[freq + 1].begin();

        return value;
    }

    void put(int key, int value) {

        if(capacity == 0) 
        return;

        if(keyToNode.count(key)) {

            auto itr = keyToNode[key];
            int freq = (*itr)[2];

            freqToList[freq].erase(itr);

            if(freqToList[freq].empty()) {

                freqToList.erase(freq);
            }

            freqToList[freq + 1].push_front({key, value, freq + 1});
            keyToNode[key] = freqToList[freq + 1].begin();

            return;
        }

        if(currSize == capacity) {

           auto itr = freqToList.begin();

           int keyToEvict = itr->second.back()[0];

           itr->second.pop_back();

           if(itr->second.empty()) {

            freqToList.erase(itr);
           }

           keyToNode.erase(keyToEvict);
           currSize --;
        }

        freqToList[1].push_front({key, value, 1});
        keyToNode[key] = freqToList[1].begin();

        currSize++;
    }
};


int main() {
    // Example from LeetCode problem 460
    // LFUCache lfu = new LFUCache(2);
    // lfu.put(1, 1); // cache=[1,_], cnt(1)=1
    // lfu.put(2, 2); // cache=[1,2], cnt(2)=1. key 1 is least frequently used? No, both freq 1. LRU is 1.
    // lfu.get(1);    // return 1, cache=[1,2], cnt(1)=2.
    // lfu.put(3, 3); // 2 is LFU? No, 1 has freq 2, 2 has freq 1. Evict 2. cache=[1,3], cnt(2)=0, cnt(3)=1
    // lfu.get(2);    // return -1 (not found)
    // lfu.get(3);    // return 3, cnt(3)=2.
    // lfu.put(4, 4); // 1 has freq 2, 3 has freq 2. LRU is 1. Evict 1. cache=[3,4], cnt(1)=0, cnt(4)=1
    // lfu.get(1);    // return -1
    // lfu.get(3);    // return 3
    // lfu.get(4);    // return 4

    LFUCache lfu(2);

    lfu.put(1, 1);
    lfu.put(2, 2);
    cout << "Get(1): " << lfu.get(1) << endl; // Expected: 1

    lfu.put(3, 3); // Evicts key 2 (freq 1, LRU)
    cout << "Get(2): " << lfu.get(2) << endl; // Expected: -1
    cout << "Get(3): " << lfu.get(3) << endl; // Expected: 3

    lfu.put(4, 4); // Evicts key 1 (freq 2, but 3 was just accessed so 1 is LRU among freq 2)
    cout << "Get(1): " << lfu.get(1) << endl; // Expected: -1
    cout << "Get(3): " << lfu.get(3) << endl; // Expected: 3
    cout << "Get(4): " << lfu.get(4) << endl; // Expected: 4

    return 0;
}

/*

    Time Complexity : O(log(F)) { O (log(n))}
    Space Complexity : 
*/