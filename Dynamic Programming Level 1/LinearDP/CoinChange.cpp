/*
#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:

    vector<vector<int>>memo ;

    int solve(vector<int>&coins , int idx , int amount){

        if(amount == 0 ){
            return 0 ; 
        }

        if(amount < 0 || idx >= coins.size()){
            return INT_MAX ; 
        }

        if(memo[idx][amount] != -1){t
            return memo[idx][amount]  ; 
        }

        int takeCoin = INT_MAX ; 
        int temp = solve(coins , idx , amount - coins[idx]) ; 

        if(temp != INT_MAX){
            takeCoin = 1 + temp ; 
        }
        int skipCoin = solve(coins , idx + 1 , amount) ; 

        return memo[idx][amount] = min(takeCoin , skipCoin) ;

    }
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size() ; 

        memo.resize(n + 1 , vector<int>(amount + 1 , -1))  ;

        int ans = solve(coins , 0 , amount) ; 

        return ans == INT_MAX ? -1 : ans ; 

    }
};



int main() {
    Solution obj;

    // Test Case 1 (Example)
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    cout << "Test Case 1 Output: "
         << obj.coinChange(coins1, amount1) << endl;

    // Test Case 2 (Not possible)
    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "Test Case 2 Output: "
         << obj.coinChange(coins2, amount2) << endl;

    // Test Case 3 (Zero amount)
    vector<int> coins3 = {1};
    int amount3 = 0;
    cout << "Test Case 3 Output: "
         << obj.coinChange(coins3, amount3) << endl;

    // Test Case 4 (Single coin repeated)
    vector<int> coins4 = {3};
    int amount4 = 9;
    cout << "Test Case 4 Output: "
         << obj.coinChange(coins4, amount4) << endl;

    // Test Case 5 (Greedy fails case)
    vector<int> coins5 = {1, 6, 7, 9, 11};
    int amount5 = 13;
    cout << "Test Case 5 Output: "
         << obj.coinChange(coins5, amount5) << endl;

    // Test Case 6 (Large amount)
    vector<int> coins6 = {1, 2, 5};
    int amount6 = 100;
    cout << "Test Case 6 Output: "
         << obj.coinChange(coins6, amount6) << endl;

    // Test Case 7 (No solution)
    vector<int> coins7 = {4, 6};
    int amount7 = 7;
    cout << "Test Case 7 Output: "
         << obj.coinChange(coins7, amount7) << endl;

    // Test Case 8 (Mixed values)
    vector<int> coins8 = {2, 5, 10, 1};
    int amount8 = 27;
    cout << "Test Case 8 Output: "
         << obj.coinChange(coins8, amount8) << endl;

    // Test Case 9 (Edge case)
    vector<int> coins9 = {1};
    int amount9 = 1;
    cout << "Test Case 9 Output: "
         << obj.coinChange(coins9, amount9) << endl;

    // Test Case 10 (Large random case)
    vector<int> coins10 = {186, 419, 83, 408};
    int amount10 = 6249;
    cout << "Test Case 10 Output: "
         << obj.coinChange(coins10, amount10) << endl;

    return 0;
}

Top Down Approach : 
Time Complexity : O(n)
Space Complexity : O(1)

*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size(); 

        vector<vector<int>> dp(n+1, vector<int>(amount + 1, INT_MAX));

        for(int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

   
        for(int idx = n - 1; idx >= 0; idx--) {

            for(int amt = 1; amt <= amount; amt++) {

                int takeCoin = INT_MAX;

               
                if(amt - coins[idx] >= 0) {
                    int temp = dp[idx][amt - coins[idx]];
                    if(temp != INT_MAX) {
                        takeCoin = 1 + temp;
                    }
                }

                int skipCoin = dp[idx + 1][amt];

                dp[idx][amt] = min(takeCoin, skipCoin);
            }
        }

        return dp[0][amount] == INT_MAX ? -1 : dp[0][amount];
    }
};

int main() {
    Solution obj;

    vector<int> coins1 = {1, 2, 5};
    cout << obj.coinChange(coins1, 11) << endl; // 3

    vector<int> coins2 = {2};
    cout << obj.coinChange(coins2, 3) << endl; // -1

    vector<int> coins3 = {1};
    cout << obj.coinChange(coins3, 0) << endl; // 0

    vector<int> coins4 = {3};
    cout << obj.coinChange(coins4, 9) << endl; // 3

    vector<int> coins5 = {1, 6, 7, 9, 11};
    cout << obj.coinChange(coins5, 13) << endl; // 2

    vector<int> coins6 = {1, 2, 5};
    cout << obj.coinChange(coins6, 100) << endl;

    vector<int> coins7 = {4, 6};
    cout << obj.coinChange(coins7, 7) << endl; // -1

    vector<int> coins8 = {2, 5, 10, 1};
    cout << obj.coinChange(coins8, 27) << endl;

    vector<int> coins9 = {1};
    cout << obj.coinChange(coins9, 1) << endl; // 1

    vector<int> coins10 = {186, 419, 83, 408};
    cout << obj.coinChange(coins10, 6249) << endl;

    return 0;
}

// Bottom Up : 
// Time Complexity : O(n*amount)
// Space Complexity : O(n*amount)

