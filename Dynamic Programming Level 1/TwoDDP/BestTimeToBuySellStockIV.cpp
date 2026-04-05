/*
#include<bits/stdc++.h>
using namespace std ; 


class Solution {
public:

    int memo[1001][101][2] ;
    int solve(vector<int>&prices , int idx , int k , bool flag){

        if(idx >= prices.size() || k == 0){
            return 0 ; 
        }

        int ans = 0 ; 

        if(memo[idx][k][flag] != -1)
        return memo[idx][k][flag] ; 
      
        if(!flag){
            int buy = -prices[idx] + solve(prices , idx + 1 , k , !flag) ; 
            int skip = solve(prices , idx + 1 , k  , flag) ; 
            ans = max(buy , skip) ; 
        }

        else{
            int sell = prices[idx] + solve(prices , idx + 1 , k - 1 , !flag) ;  
            int skip = solve(prices , idx + 1 , k  , flag) ; 
            ans = max(sell , skip) ;
        }

        return memo[idx][k][flag] = ans ; 
    }

    int maxProfit(int k, vector<int>& prices) {
          
        memset(memo , -1 , sizeof(memo)) ;

        return solve(prices , 0 , k , false); 
    }
};

int main() {
    Solution obj;

    // Test Case 1
    int k1 = 2;
    vector<int> prices1 = {2, 4, 1};
    cout << "Output 1: " << obj.maxProfit(k1, prices1) << endl;

    // Test Case 2
    int k2 = 2;
    vector<int> prices2 = {3, 2, 6, 5, 0, 3};
    cout << "Output 2: " << obj.maxProfit(k2, prices2) << endl;

    // Additional Test Case
    int k3 = 3;
    vector<int> prices3 = {1, 2, 3, 4, 5};
    cout << "Output 3: " << obj.maxProfit(k3, prices3) << endl;

    return 0;
}


Top Down Approach : 
Time Complexity : O(n*k)
Space Complexity : O(n*k)
*/