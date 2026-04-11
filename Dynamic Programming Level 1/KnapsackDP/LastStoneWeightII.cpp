/*
#include<bits/stdc++.h>
using namespace std ; 
class Solution {
public:

    int memo[31][3000] ; 

    int solve(vector<int>& stones, int idx, int currSum , int totalSum){

        if(idx == stones.size()){

            int s1 = currSum ; 
            int s2 = totalSum - currSum ; 

            return abs(s1 - s2) ; 
        }

        if(memo[idx][currSum] != -1)
        return memo[idx][currSum] ;

        int include = solve(stones, idx+1, currSum + stones[idx], totalSum);
        int exclude = solve(stones, idx+1, currSum               , totalSum);

        return memo[idx][currSum] = min(include,exclude) ;

    }


    int lastStoneWeightII(vector<int>& stones) {

        int sum = accumulate(begin(stones), end(stones), 0) ; 

        memset(memo, -1, sizeof(memo)) ;

        return solve(stones, 0, 0, sum) ; 
        
    }
};


int main() {

    Solution obj;

    // Test Case 1
    vector<int> stones1 = {2,7,4,1,8,1};
    int result1 = obj.lastStoneWeightII(stones1);
    cout << "Output: " << result1 << " | Expected: 1" << endl;

    // Test Case 2
    vector<int> stones2 = {31,26,33,21,40};
    int result2 = obj.lastStoneWeightII(stones2);
    cout << "Output: " << result2 << " | Expected: 5" << endl;

    return 0;
}
    Top Down Approach :
    Time Complexity : O(n*sum)
    Space Complexity : O(n*sum)
*/


#include<bits/stdc++.h>
using namespace std ; 
class Solution {
public:

    int lastStoneWeightII(vector<int>& stones) {

        int n  = stones.size() ; 

        int sum = accumulate(begin(stones), end(stones), 0) ; 

        vector<vector<int>>t(n+1, vector<int>(sum+1, 0)) ;

        for(int currSum = 0 ; currSum <= sum ; currSum++){
            int s1 = currSum ; 
            int s2 = sum - currSum ; 

            t[n][currSum] = abs(s1-s2) ; 
        }


        for(int idx = n - 1 ; idx >= 0 ; idx --){
            
            for(int currSum = 0 ; currSum <= sum ; currSum ++){

            int include = INT_MAX ; 
            if(currSum + stones[idx] <= sum)
            include = t[idx+1][currSum + stones[idx]] ;
            int exclude = t[idx+1][currSum];

             t[idx][currSum] = min(include,exclude) ;

            }
        }
        

        return t[0][0] ; 
    }
};


int main() {

    Solution obj;

    // Test Case 1
    vector<int> stones1 = {2,7,4,1,8,1};
    int result1 = obj.lastStoneWeightII(stones1);
    cout << "Output: " << result1 << " | Expected: 1" << endl;

    // Test Case 2
    vector<int> stones2 = {31,26,33,21,40};
    int result2 = obj.lastStoneWeightII(stones2);
    cout << "Output: " << result2 << " | Expected: 5" << endl;

    return 0;
}


// Bottom Up : 
// Time Complexity : O(n*sum)
// Space Complexity : O(n*sum)