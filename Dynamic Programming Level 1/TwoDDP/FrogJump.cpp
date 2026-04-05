/*
#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:
    unordered_map<pair<int,int>, bool>dp ;
    
    bool solve(vector<int>& stones , unordered_set<int>&st , int pos , int jump ){

        if(pos == stones.back())
        return true ; 

        if(jump <= 0)
        return false ; 

        if(dp.count({pos , jump}))
        return dp[{pos , jump}] ;


        bool option1 = false ; 
        bool option2 = false ; 
        bool option3 = false ; 

        if(st.count(pos + jump))
        option1 = solve(stones , st , pos + jump      , jump   )  ; 
        
        if(jump > 1 && st.count(pos + jump -1))
        option2 = solve(stones , st , pos + jump - 1  , jump - 1) ; 

        if(st.count(pos + jump + 1))
        option3 = solve(stones , st , pos + jump + 1  , jump + 1) ;

        return dp[{pos , jump}] = option1 || option2 || option3 ; 

    }
    bool canCross(vector<int>& stones) {
        
        int n = stones.size() ; 

        unordered_set<int>st(stones.begin() , stones.end()) ;

        if(st.count(1) == 0)
            return false;


        return solve(stones , st , 1 , 1)  ; 
        
    }
};


int main() {

    Solution sol;

    // Test Case 1
    vector<int> stones1 = {0,1,3,5,6,8,12,17};
    cout << "Output: " << (sol.canCross(stones1) ? "true" : "false")
         << " | Expected: true" << endl;

    // Test Case 2
    vector<int> stones2 = {0,1,2,3,4,8,9,11};
    cout << "Output: " << (sol.canCross(stones2) ? "true" : "false")
         << " | Expected: false" << endl;

    // Edge Case 1
    vector<int> stones3 = {0,1};
    cout << "Output: " << (sol.canCross(stones3) ? "true" : "false")
         << " | Expected: true" << endl;

    // Edge Case 2
    vector<int> stones4 = {0,1,3,6,10,15,16,21};
    cout << "Output: " << (sol.canCross(stones4) ? "true" : "false")
         << " | Expected: true" << endl;

    // Custom Case
    vector<int> stones5 = {0,1,2,3,5,6,8,12,17};
    cout << "Output: " << (sol.canCross(stones5) ? "true" : "false")
         << " | Expected: true" << endl;

    return 0;
}

// Top Down Approach : 
// Time Complexity : O(n^2)
// Space Complexity : O(n^2)

*/

#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:
    unordered_map<pair<int,int>, bool>dp ;
    
    bool solve(vector<int>& stones , unordered_set<int>&st , int pos , int jump ){

        if(pos == stones.back())
        return true ; 

        if(jump <= 0)
        return false ; 

        if(dp.count({pos , jump}))
        return dp[{pos , jump}] ;


        bool option1 = false ; 
        bool option2 = false ; 
        bool option3 = false ; 

        if(st.count(pos + jump))
        option1 = solve(stones , st , pos + jump      , jump   )  ; 
        
        if(jump > 1 && st.count(pos + jump -1))
        option2 = solve(stones , st , pos + jump - 1  , jump - 1) ; 

        if(st.count(pos + jump + 1))
        option3 = solve(stones , st , pos + jump + 1  , jump + 1) ;

        return dp[{pos , jump}] = option1 || option2 || option3 ; 

    }
    bool canCross(vector<int>& stones) {
        
        int n = stones.size() ; 

        unordered_set<int>st(stones.begin() , stones.end()) ;

        if(st.count(1) == 0)
            return false;


        return solve(stones , st , 1 , 1)  ; 
        
    }
};


int main() {

    Solution sol;

    // Test Case 1
    vector<int> stones1 = {0,1,3,5,6,8,12,17};
    cout << "Output: " << (sol.canCross(stones1) ? "true" : "false")
         << " | Expected: true" << endl;

    // Test Case 2
    vector<int> stones2 = {0,1,2,3,4,8,9,11};
    cout << "Output: " << (sol.canCross(stones2) ? "true" : "false")
         << " | Expected: false" << endl;

    // Edge Case 1
    vector<int> stones3 = {0,1};
    cout << "Output: " << (sol.canCross(stones3) ? "true" : "false")
         << " | Expected: true" << endl;

    // Edge Case 2
    vector<int> stones4 = {0,1,3,6,10,15,16,21};
    cout << "Output: " << (sol.canCross(stones4) ? "true" : "false")
         << " | Expected: true" << endl;

    // Custom Case
    vector<int> stones5 = {0,1,2,3,5,6,8,12,17};
    cout << "Output: " << (sol.canCross(stones5) ? "true" : "false")
         << " | Expected: true" << endl;

    return 0;
}

// Bottom Up Approach : 
// Time Complexity : O(n^2)
// Space Complexity : O(n^2)