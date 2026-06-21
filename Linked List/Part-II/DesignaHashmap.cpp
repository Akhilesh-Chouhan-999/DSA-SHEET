#include<bits/stdc++.h>
using namespace std;

class MyHashMap {
public:

    vector<list<pair<int, int>>> buckets;

    MyHashMap() {

        buckets.resize(10);
    }

    void put(int key, int value) {

        auto& bucket = buckets[key % 10];

        for(auto it = bucket.begin(); it != bucket.end(); it++) {

            if(it->first == key) {

                it->second = value;
                return;
            }
        }

        bucket.emplace_back(key, value);
    }

    int get(int key) {

        auto& bucket = buckets[key % 10];

        for(auto it = bucket.begin(); it != bucket.end(); it++) {

            if(it->first == key) {

                return it->second;
            }
        }

        return -1;
    }

    void remove(int key) {

        auto& bucket = buckets[key % 10];

        for(auto it = bucket.begin(); it != bucket.end(); it++) {

            if(it->first == key) {

                bucket.erase(it);
                return;
            }
        }
    }
};

int main() {
    MyHashMap obj;

    obj.put(1, 10);
    obj.put(2, 20);

    cout << obj.get(1) << endl; // 10
    cout << obj.get(2) << endl; // 20
    cout << obj.get(3) << endl; // -1

    obj.put(2, 200);
    cout << obj.get(2) << endl; // 200

    obj.remove(2);
    cout << obj.get(2) << endl; // -1

    return 0;
}

/*
    
*/