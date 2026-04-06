/*

    #include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:

    vector<vector<int>>memo ; 

    int solve(vector<int>&prices , int fee , int idx , bool flag){

        if(idx >= prices.size())
         return 0 ; 

         if(memo[idx][flag] != -1)
         return memo[idx][flag] ; 

        if(!flag){

            int buy = -prices[idx] + solve(prices , fee , idx + 1, !flag) ; 
            int skip = solve(prices , fee , idx + 1 , flag) ; 

            return memo[idx][flag] = max(buy , skip) ; 

        }else{

            int sell = prices[idx] - fee + solve(prices , fee , idx + 1 , !flag) ; 
            int skip = solve(prices , fee , idx + 1 , flag) ; 

            return memo[idx][flag] = max(sell , skip) ; 
        }
        
    }


    int maxProfit(vector<int>& prices, int fee) {

        memo.resize(prices.size() + 1 , vector<int>(2 , -1)) ;

        return solve(prices , fee , 0 , false) ; 
    }
};

int main() {
    Solution obj;

    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;

    int result = obj.maxProfit(prices, fee);

    cout << "Max Profit: " << result << endl;

    return 0;
}

Time Complexity : O(2*n)
Space Complexity : O(2*n)
*/

#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:

    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size() ; 

        vector<vector<int>>dp(n+1 , vector<int>(2 , 0)) ;

        for(int idx = n - 1 ; idx >= 0 ; idx --){

            for(int flag = 0 ; flag <= 1 ; flag ++){

                
        if(!flag){

            int buy = -prices[idx] + dp[idx + 1] [!flag] ; 
            int skip = dp[idx + 1] [flag] ; 

             dp[idx][flag] = max(buy , skip) ; 

        }else{

            int sell = prices[idx] - fee + dp[ idx + 1] [!flag] ; 
            int skip = dp[idx + 1] [flag] ; 

             dp[idx][flag] = max(sell , skip) ; 
        }
            
        }

        
    }
    
    return dp[0][0] ;
}
};

int main() {
    Solution obj;

    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;

    int result = obj.maxProfit(prices, fee);

    cout << "Max Profit: " << result << endl;

    return 0;
}

// Time Complexity : O(n)
// Space Complexity : O(n)

