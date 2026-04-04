/*
#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:

    int n  ; 
    int memo[301][5001] ;

    int solve(vector<int>&coins , int idx , int amount){

        if(amount == 0)return 1 ; 
        if(amount < 0 || idx >= n)return 0 ; 

        if(memo[idx][amount] != -1)
        return memo[idx][amount] ;


        int take = solve(coins , idx  , amount - coins[idx]) ; 
        int skip = solve(coins , idx + 1 , amount ) ; 

        return memo[idx][amount] = take + skip ; 

    }

    int change(int amount, vector<int>& coins) {
        
        n = coins.size()  ; 
        memset(memo , -1 , sizeof(memo)) ; 
        return solve(coins , 0 , amount) ; 

    }
};


int main() {
    Solution obj;

    // Test Case 1 (Example)
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 5;
    cout << "Test Case 1 Output: "
         << obj.change(amount1, coins1) << endl;

    // Test Case 2 (No combination)
    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "Test Case 2 Output: "
         << obj.change(amount2, coins2) << endl;

    // Test Case 3 (Single coin exact match)
    vector<int> coins3 = {10};
    int amount3 = 10;
    cout << "Test Case 3 Output: "
         << obj.change(amount3, coins3) << endl;

    // Test Case 4 (Amount = 0)
    vector<int> coins4 = {1, 2, 3};
    int amount4 = 0;
    cout << "Test Case 4 Output: "
         << obj.change(amount4, coins4) << endl;

    // Test Case 5 (Multiple combinations)
    vector<int> coins5 = {1, 3, 4};
    int amount5 = 6;
    cout << "Test Case 5 Output: "
         << obj.change(amount5, coins5) << endl;

    // Test Case 6 (Large amount small coins)
    vector<int> coins6 = {1, 2};
    int amount6 = 10;
    cout << "Test Case 6 Output: "
         << obj.change(amount6, coins6) << endl;

    // Test Case 7 (Single coin no solution)
    vector<int> coins7 = {5};
    int amount7 = 3;
    cout << "Test Case 7 Output: "
         << obj.change(amount7, coins7) << endl;

    // Test Case 8 (Mixed coins)
    vector<int> coins8 = {2, 5, 3, 6};
    int amount8 = 10;
    cout << "Test Case 8 Output: "
         << obj.change(amount8, coins8) << endl;

    // Test Case 9 (Edge case)
    vector<int> coins9 = {1};
    int amount9 = 1;
    cout << "Test Case 9 Output: "
         << obj.change(amount9, coins9) << endl;

    // Test Case 10 (Larger variety)
    vector<int> coins10 = {1, 2, 5, 10};
    int amount10 = 20;
    cout << "Test Case 10 Output: "
         << obj.change(amount10, coins10) << endl;

    return 0;
}
    Top Down Approach : 
    Time Complexity : O(n*amount)
    Space Complexity : O(n*amount)


    
#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:


    int change(int amount, vector<int>& coins) {
        
        int n = coins.size() ; 

        vector<vector<int>>dp(n+1 , vector<int>(amount+1 , 0)) ;

        for(int i = 0 ; i <= n ; i ++) 
          dp[i][0] = 1 ; 

        for(int idx = n - 1 ; idx >= 0 ; idx --){

           for(int amt = 0 ; amt <= amount ; amt ++){

               
               int take ;
               if(amt - coins[idx] >= 0 ) 
               take = dp[idx][amt - coins[idx]] ; 
               else
               take = 0 ; 


               int skip = dp[idx+1][amt] ; 


               dp[idx][amt] = take + skip ; 
           }
        }

        return dp[0][amount] ; 
    }
};


int main() {
    Solution obj;

    // Test Case 1 (Example)
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 5;
    cout << "Test Case 1 Output: "
         << obj.change(amount1, coins1) << endl;

    // Test Case 2 (No combination)
    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "Test Case 2 Output: "
         << obj.change(amount2, coins2) << endl;

    // Test Case 3 (Single coin exact match)
    vector<int> coins3 = {10};
    int amount3 = 10;
    cout << "Test Case 3 Output: "
         << obj.change(amount3, coins3) << endl;

    // Test Case 4 (Amount = 0)
    vector<int> coins4 = {1, 2, 3};
    int amount4 = 0;
    cout << "Test Case 4 Output: "
         << obj.change(amount4, coins4) << endl;

    // Test Case 5 (Multiple combinations)
    vector<int> coins5 = {1, 3, 4};
    int amount5 = 6;
    cout << "Test Case 5 Output: "
         << obj.change(amount5, coins5) << endl;

    // Test Case 6 (Large amount small coins)
    vector<int> coins6 = {1, 2};
    int amount6 = 10;
    cout << "Test Case 6 Output: "
         << obj.change(amount6, coins6) << endl;

    // Test Case 7 (Single coin no solution)
    vector<int> coins7 = {5};
    int amount7 = 3;
    cout << "Test Case 7 Output: "
         << obj.change(amount7, coins7) << endl;

    // Test Case 8 (Mixed coins)
    vector<int> coins8 = {2, 5, 3, 6};
    int amount8 = 10;
    cout << "Test Case 8 Output: "
         << obj.change(amount8, coins8) << endl;

    // Test Case 9 (Edge case)
    vector<int> coins9 = {1};
    int amount9 = 1;
    cout << "Test Case 9 Output: "
         << obj.change(amount9, coins9) << endl;

    // Test Case 10 (Larger variety)
    vector<int> coins10 = {1, 2, 5, 10};
    int amount10 = 20;
    cout << "Test Case 10 Output: "
         << obj.change(amount10, coins10) << endl;

    return 0;
}
//     Bottom Up Approach : 
//     Time Complexity : O(n*amount)
//     Space Complexity : O(n*amount)




*/



#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:

     using ll = unsigned long long ; 

    int change(int amount, vector<int>& coins) {
        
        int n = coins.size() ; 

        vector<ll>dp(amount + 1 , 0) ; 
        dp[0] = 1 ; 

        for(int coin : coins){

           for(int amt = coin ; amt <= amount ; amt ++){

               dp[amt] += dp[amt-coin] ;
           }
        }

        return dp[amount] ; 

    }
};


int main() {
    Solution obj;

    // Test Case 1 (Example)
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 5;
    cout << "Test Case 1 Output: "
         << obj.change(amount1, coins1) << endl;

    // Test Case 2 (No combination)
    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "Test Case 2 Output: "
         << obj.change(amount2, coins2) << endl;

    // Test Case 3 (Single coin exact match)
    vector<int> coins3 = {10};
    int amount3 = 10;
    cout << "Test Case 3 Output: "
         << obj.change(amount3, coins3) << endl;

    // Test Case 4 (Amount = 0)
    vector<int> coins4 = {1, 2, 3};
    int amount4 = 0;
    cout << "Test Case 4 Output: "
         << obj.change(amount4, coins4) << endl;

    // Test Case 5 (Multiple combinations)
    vector<int> coins5 = {1, 3, 4};
    int amount5 = 6;
    cout << "Test Case 5 Output: "
         << obj.change(amount5, coins5) << endl;

    // Test Case 6 (Large amount small coins)
    vector<int> coins6 = {1, 2};
    int amount6 = 10;
    cout << "Test Case 6 Output: "
         << obj.change(amount6, coins6) << endl;

    // Test Case 7 (Single coin no solution)
    vector<int> coins7 = {5};
    int amount7 = 3;
    cout << "Test Case 7 Output: "
         << obj.change(amount7, coins7) << endl;

    // Test Case 8 (Mixed coins)
    vector<int> coins8 = {2, 5, 3, 6};
    int amount8 = 10;
    cout << "Test Case 8 Output: "
         << obj.change(amount8, coins8) << endl;

    // Test Case 9 (Edge case)
    vector<int> coins9 = {1};
    int amount9 = 1;
    cout << "Test Case 9 Output: "
         << obj.change(amount9, coins9) << endl;

    // Test Case 10 (Larger variety)
    vector<int> coins10 = {1, 2, 5, 10};
    int amount10 = 20;
    cout << "Test Case 10 Output: "
         << obj.change(amount10, coins10) << endl;

    return 0;
}