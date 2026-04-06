/*
#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {

        vector<vector<int>>events ; 

        for(vector<int>&flower : flowers){

            int start = flower[0] ; 
            int end   = flower[1] ; 

            events.push_back({start , +1}) ;
            events.push_back({end + 1 , -1}) ;
        }

        sort(begin(events) , end(events)) ;

        vector<int>result ; 

        for(int p : people){

            int cnt = 0 ; 

            for(vector<int>event : events){

                int pos  = event[0] ; 
                int type = event[1] ; 

                if(pos > p)
                break; 

                cnt += type ; 
            }

            result.push_back(cnt) ; 
        }

        return result ; 
    }
};

Time Complexity : O(p*n) + O(n*log(n)) 
Space Complexity : O(n) 
where n is the max size of flower and p is the max size of person

*/
#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {

        vector<vector<int>> events ; 

        for(vector<int>& flower : flowers){
            int start = flower[0] ; 
            int end   = flower[1] ; 

            events.push_back({start , +1}) ;
            events.push_back({end + 1 , -1}) ;
        }

        sort(begin(events) , end(events)) ;

        vector<int> prefix ;
        vector<int> eve ; 

        for(vector<int>& event : events){
            if(prefix.empty()){
                prefix.push_back(event[1]) ; 
            }
            else{
                prefix.push_back(prefix.back() + event[1]) ; 
            }

            eve.push_back(event[0]) ; 
        }

        vector<int> result ; 

        for(int p : people){

            int ub = upper_bound(begin(eve), end(eve), p) - begin(eve);

            if(ub == 0) result.push_back(0);
            else result.push_back(prefix[ub - 1]);
        }

        return result ; 
    }
};

int main() {

    Solution obj;

    // -------- Test Case 1 --------
    {
        vector<vector<int>> flowers = {{1,6},{3,7},{9,12},{4,13}};
        vector<int> people = {2,3,7,11};

        vector<int> res = obj.fullBloomFlowers(flowers, people);

        cout << "Test 1 Output: ";
        for(int x : res) cout << x << " ";
        cout << "\nExpected: 1 2 2 2\n\n";
    }

    // -------- Test Case 2 (single flower) --------
    {
        vector<vector<int>> flowers = {{1,10}};
        vector<int> people = {0,1,5,10,11};

        vector<int> res = obj.fullBloomFlowers(flowers, people);

        cout << "Test 2 Output: ";
        for(int x : res) cout << x << " ";
        cout << "\nExpected: 0 1 1 1 0\n\n";
    }

    // -------- Test Case 3 (overlapping flowers) --------
    {
        vector<vector<int>> flowers = {{1,5},{2,6},{3,7}};
        vector<int> people = {1,2,3,4,5,6,7};

        vector<int> res = obj.fullBloomFlowers(flowers, people);

        cout << "Test 3 Output: ";
        for(int x : res) cout << x << " ";
        cout << "\nExpected: 1 2 3 3 3 2 1\n\n";
    }

    // -------- Test Case 4 (no flowers active) --------
    {
        vector<vector<int>> flowers = {{5,8},{10,12}};
        vector<int> people = {1,2,3,4};

        vector<int> res = obj.fullBloomFlowers(flowers, people);

        cout << "Test 4 Output: ";
        for(int x : res) cout << x << " ";
        cout << "\nExpected: 0 0 0 0\n\n";
    }

    // -------- Test Case 5 (same start and end) --------
    {
        vector<vector<int>> flowers = {{3,3},{3,3},{3,3}};
        vector<int> people = {2,3,4};

        vector<int> res = obj.fullBloomFlowers(flowers, people);

        cout << "Test 5 Output: ";
        for(int x : res) cout << x << " ";
        cout << "\nExpected: 0 3 0\n\n";
    }

    return 0;
}


// Time Complexity : Time Complexity: O(n log n + p log n)
//                       = O((n + p) log n)
// Space Complexity : O(2*n) 
// where n is the max size of flower and p is the max size of person