/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int memo[1001] ; 

    int solve(vector<int>&costs , int idx){

        if(idx < 0)
        return 0 ; 

        if(memo[idx] != -1)
        return memo[idx] ; 

        int takeOneStep = costs[idx] + solve(costs , idx-1) ; 
        int takeTwoStep = costs[idx] + solve(costs , idx-2) ; 
        
        return memo[idx] = min(takeOneStep , takeTwoStep) ; 

    }
    int minCostClimbingStairs(vector<int>& cost){

        int n = cost.size() ; 

        memset(memo , -1 , sizeof(memo)) ; 

        return min(solve(cost , n - 1) , solve(cost , n - 2))  ;

    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> cost1 = {10, 15, 20};
    cout << "Test Case 1 Output: "
         << obj.minCostClimbingStairs(cost1) << endl;

    // Test Case 2
    vector<int> cost2 = {1,100,1,1,1,100,1,1,100,1};
    cout << "Test Case 2 Output: "
         << obj.minCostClimbingStairs(cost2) << endl;

    // Test Case 3 (Edge Case - small size)
    vector<int> cost3 = {0, 0};
    cout << "Test Case 3 Output: "
         << obj.minCostClimbingStairs(cost3) << endl;

    // Test Case 4
    vector<int> cost4 = {5, 10, 5, 10, 5};
    cout << "Test Case 4 Output: "
         << obj.minCostClimbingStairs(cost4) << endl;

    // Test Case 5 (All same values)
    vector<int> cost5 = {3, 3, 3, 3, 3, 3};
    cout << "Test Case 5 Output: "
         << obj.minCostClimbingStairs(cost5) << endl;

    return 0;
}

Top Down Approach :
Time Complexity : O(n)
Space Complexity : O(n)



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:


    int solve(vector<int>&costs){

        int n = costs.size() ; 

        vector<int>dp(n+2 , 0) ; 

        for(int i = n - 1 ; i >= 0 ; i --){
            dp[i] = costs[i] + min(dp[i+1] , dp[i+2])  ; 
        }

        return min(dp[0] , dp[1]) ; 

    }

    int minCostClimbingStairs(vector<int>& cost){

        return solve(cost) ; 
    
    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> cost1 = {10, 15, 20};
    cout << "Test Case 1 Output: "
         << obj.minCostClimbingStairs(cost1) << endl;

    // Test Case 2
    vector<int> cost2 = {1,100,1,1,1,100,1,1,100,1};
    cout << "Test Case 2 Output: "
         << obj.minCostClimbingStairs(cost2) << endl;

    // Test Case 3 (Edge Case - small size)
    vector<int> cost3 = {0, 0};
    cout << "Test Case 3 Output: "
         << obj.minCostClimbingStairs(cost3) << endl;

    // Test Case 4
    vector<int> cost4 = {5, 10, 5, 10, 5};
    cout << "Test Case 4 Output: "
         << obj.minCostClimbingStairs(cost4) << endl;

    // Test Case 5 (All same values)
    vector<int> cost5 = {3, 3, 3, 3, 3, 3};
    cout << "Test Case 5 Output: "
         << obj.minCostClimbingStairs(cost5) << endl;

    return 0;
}


Bottom Up Approach : 
Time Complexity : O(n)
Space Complexity : O(n)
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:


    int solve(vector<int>&costs){

        int n = costs.size() ;

        int next1 = 0 ; 
        int next2 = 0 ; 

        for(int i = n - 1 ; i >= 0 ; i --){

            int cost = costs[i] + min(next1 , next2) ; 
            next2 = next1 ;
            next1 = cost  ; 
        }

        return min(next1 , next2) ; 

    }

    int minCostClimbingStairs(vector<int>& cost){

        return solve(cost) ; 
    
    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> cost1 = {10, 15, 20};
    cout << "Test Case 1 Output: "
         << obj.minCostClimbingStairs(cost1) << endl;

    // Test Case 2
    vector<int> cost2 = {1,100,1,1,1,100,1,1,100,1};
    cout << "Test Case 2 Output: "
         << obj.minCostClimbingStairs(cost2) << endl;

    // Test Case 3 (Edge Case - small size)
    vector<int> cost3 = {0, 0};
    cout << "Test Case 3 Output: "
         << obj.minCostClimbingStairs(cost3) << endl;

    // Test Case 4
    vector<int> cost4 = {5, 10, 5, 10, 5};
    cout << "Test Case 4 Output: "
         << obj.minCostClimbingStairs(cost4) << endl;

    // Test Case 5 (All same values)
    vector<int> cost5 = {3, 3, 3, 3, 3, 3};
    cout << "Test Case 5 Output: "
         << obj.minCostClimbingStairs(cost5) << endl;

    return 0;
}

// Time Complexity : O(n)
// Space Complexity : O(1) 