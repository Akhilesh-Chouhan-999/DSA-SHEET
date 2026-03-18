#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {

        int n = items.size() ; 

        sort(items.begin() , items.end()) ; 

        vector<pair<int, int>>priceBeauty ; 

        priceBeauty.push_back({items[0][0] , items[0][1]}) ;

        for(int i = 1 ; i < n ; i ++ ){

            int currPrice = items[i][0] ;
            int currBeauty = items[i][1] ; 

                int prevPrice = priceBeauty.back().first; 
                int prevBeauty = priceBeauty.back().second ; 

                if(prevPrice == currPrice){
                    priceBeauty.back() = {prevPrice , max(prevBeauty , currBeauty)} ;
                }
                else {
                    priceBeauty.push_back({ currPrice , max(prevBeauty , currBeauty)}) ; 
                }
        }

        

        vector<int>result ; 

        for(int query : queries){

            int low = 0; 
            int high = priceBeauty.size() - 1 ; 
            int maxBeauty = 0 ; 


            while(low <= high){

                int mid = low + ( high - low ) / 2 ; 

                int price = priceBeauty[mid].first ; 
                int beauty = priceBeauty[mid].second ; 

                if(price == query){
                    maxBeauty = beauty ; 
                    break; 
                }

                else if(price < query){
                    maxBeauty = beauty ; 
                    low = mid + 1 ; 
                }

                else{
                    high = mid - 1 ; 
                }

            }

            result.push_back(maxBeauty) ; 
        }
        

        return result ; 
    }
};

int main() {
    Solution sol;

    // -------- Test Case 1 --------
    {
        vector<vector<int>> items = {{1,2},{3,2},{2,4},{5,6},{3,5}};
        vector<int> queries = {1,2,3,4,5,6};

        vector<int> result = sol.maximumBeauty(items, queries);

        cout << "Test 1: ";
        for(int x : result) cout << x << " ";
        cout << endl;
    }

    // -------- Test Case 2 (same price) --------
    {
        vector<vector<int>> items = {{1,2},{1,2},{1,3},{1,4}};
        vector<int> queries = {1};

        vector<int> result = sol.maximumBeauty(items, queries);

        cout << "Test 2: ";
        for(int x : result) cout << x << " ";
        cout << endl;
    }

    // -------- Test Case 3 (no valid item) --------
    {
        vector<vector<int>> items = {{10,1000}};
        vector<int> queries = {5};

        vector<int> result = sol.maximumBeauty(items, queries);

        cout << "Test 3: ";
        for(int x : result) cout << x << " ";
        cout << endl;
    }

    // -------- Test Case 4 (unsorted input) --------
    {
        vector<vector<int>> items = {{5,10},{1,1},{3,7},{2,5}};
        vector<int> queries = {3,5};

        vector<int> result = sol.maximumBeauty(items, queries);

        cout << "Test 4: ";
        for(int x : result) cout << x << " ";
        cout << endl;
    }

    // -------- Test Case 5 (large queries) --------
    {
        vector<vector<int>> items = {{2,100},{4,200},{6,300}};
        vector<int> queries = {1,2,3,4,5,6,7};

        vector<int> result = sol.maximumBeauty(items, queries);

        cout << "Test 5: ";
        for(int x : result) cout << x << " ";
        cout << endl;
    }

    return 0;
}

// Time Complexity : O(nlogn+qlogn)
// Space Complexity : O(n+q)


