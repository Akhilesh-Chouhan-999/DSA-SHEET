#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int lowerBound(vector<vector<int>>&intervals , int endi , unordered_map<int ,int>&mpp ){

        // startj >= endi => with minimization 

        int low = 0 ; 
        int high = intervals.size() - 1 ; 
        int result = INT_MIN ; 

        while(low <= high){

            int mid = low + (high - low) / 2 ; 

            int startj =  intervals[mid][0] ; 

            if(startj < endi){
               low = mid + 1 ; 
            }
            else{
                result = startj ; 
                high = mid - 1 ;  
            }

        }

        if(result == INT_MIN)
        return -1 ;

        return mpp[result] ; 

    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {

        int n = intervals.size() ; 

        unordered_map<int , int>mpp ;

        for(int i = 0 ; i < n ; i ++ ){
            mpp[intervals[i][0]] = i ; 
        }

        sort(begin(intervals) , end(intervals)) ;
        vector<int>result(n) ; 
        
        
        for(vector<int>interval : intervals){

            int starti = interval[0] ;
            int endi = interval[1]  ;

            result[mpp[starti]] = lowerBound(intervals , endi , mpp); 

        }

        return result ; 
       
    }
};

void printResult(const vector<int>& result) {
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Test 1: Expected [-1]
    vector<vector<int>> t1 = {{1, 2}};
    cout << "Test 1: "; printResult(sol.findRightInterval(t1));

    // Test 2: Expected [-1, 0, 1]
    vector<vector<int>> t2 = {{3, 4}, {2, 3}, {1, 2}};
    cout << "Test 2: "; printResult(sol.findRightInterval(t2));

    // Test 3: Expected [-1, 2, -1]
    vector<vector<int>> t3 = {{1, 4}, {2, 3}, {3, 4}};
    cout << "Test 3: "; printResult(sol.findRightInterval(t3));

    // Test 4: Self-referencing — Expected [0, -1]
    vector<vector<int>> t4 = {{1, 1}, {3, 4}};
    cout << "Test 4: "; printResult(sol.findRightInterval(t4));

    // Test 5: Single self-referencing — Expected 
    vector<vector<int>> t5 = {{4, 4}};
    cout << "Test 5: "; printResult(sol.findRightInterval(t5));

    return 0;
}


// Time Complexity : O(n*log(n))
// Space Complexity : O(n)

