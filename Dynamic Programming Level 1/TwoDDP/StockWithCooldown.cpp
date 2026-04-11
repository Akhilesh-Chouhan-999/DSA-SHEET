/*
#include<bits/stdc++.h>
using namespace std ; 


class Solution {
public:

    int memo[5001][2] ; 
    int solve(vector<int>&prices , int idx , bool flag){

        if(idx >= prices.size())
        return 0 ; 

        if(memo[idx][flag] != -1) 
        return memo[idx][flag] ; 

        if(!flag){

            int buy = -prices[idx] + solve(prices , idx + 1 , !flag) ; 
            int skip = solve(prices , idx + 1 , flag) ; 
            
            return memo[idx][flag] = max(buy , skip) ; 
        }
        else{

            // Cooldown Perion => idx + 2 
            int sell = prices[idx] + solve(prices , idx + 2 , !flag ) ; 
            int skip = solve(prices , idx + 1 , flag) ; 

            return memo[idx][flag] = max(sell , skip) ; 
        }

    }

    int maxProfit(vector<int>& prices) {


        memset(memo , -1 , sizeof(memo)) ; 

        return solve(prices , 0 , false) ; 
    
    }
};


int main() {

    Solution obj;

    // Test Case 1
    vector<int> t1 = {1, 2, 3, 0, 2};
    cout << "Test 1 Output: " << obj.maxProfit(t1) << " (Expected: 3)" << endl;

    // Test Case 2
    vector<int> t2 = {1};
    cout << "Test 2 Output: " << obj.maxProfit(t2) << " (Expected: 0)" << endl;

    // Test Case 3 (strictly increasing)
    vector<int> t3 = {1, 2, 3, 4, 5};
    cout << "Test 3 Output: " << obj.maxProfit(t3) << " (Expected: 4)" << endl;

    // Test Case 4 (strictly decreasing)
    vector<int> t4 = {5, 4, 3, 2, 1};
    cout << "Test 4 Output: " << obj.maxProfit(t4) << " (Expected: 0)" << endl;

    // Test Case 5 (cooldown effect important)
    vector<int> t5 = {6, 1, 6, 4, 3, 0, 2};
    cout << "Test 5 Output: " << obj.maxProfit(t5) << " (Expected: 7)" << endl;

    // Test Case 6 (multiple cooldown decisions)
    vector<int> t6 = {1, 2, 4};
    cout << "Test 6 Output: " << obj.maxProfit(t6) << " (Expected: 3)" << endl;

    return 0;
}



Top Down Approach :
Time Complexity : O(2*n)
Space Complexity : O(2*n)




#include<bits/stdc++.h>
using namespace std ; 


class Solution {
public:

    int maxProfit(vector<int>& prices) {

        int n = prices.size() ; 

        vector<vector<int>>dp(n+2 , vector<int>(2 , 0)) ;

        for(int idx = n - 1 ; idx >= 0 ; idx --){

            for(int flag = 0 ; flag < 2 ; flag ++){

                if(!flag){

                int buy = -prices[idx] + dp[idx+1][!flag] ; 
                int skip = dp[idx+1][flag] ; 
        
                 dp[idx][flag] = max(buy , skip) ; 
                }
                else{

                int sell = prices[idx] + dp[idx+2][!flag] ;
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

    // Test Case 1
    vector<int> t1 = {1, 2, 3, 0, 2};
    cout << "Test 1 Output: " << obj.maxProfit(t1) << " (Expected: 3)" << endl;

    // Test Case 2
    vector<int> t2 = {1};
    cout << "Test 2 Output: " << obj.maxProfit(t2) << " (Expected: 0)" << endl;

    // Test Case 3 (strictly increasing)
    vector<int> t3 = {1, 2, 3, 4, 5};
    cout << "Test 3 Output: " << obj.maxProfit(t3) << " (Expected: 4)" << endl;

    // Test Case 4 (strictly decreasing)
    vector<int> t4 = {5, 4, 3, 2, 1};
    cout << "Test 4 Output: " << obj.maxProfit(t4) << " (Expected: 0)" << endl;

    // Test Case 5 (cooldown effect important)
    vector<int> t5 = {6, 1, 6, 4, 3, 0, 2};
    cout << "Test 5 Output: " << obj.maxProfit(t5) << " (Expected: 7)" << endl;

    // Test Case 6 (multiple cooldown decisions)
    vector<int> t6 = {1, 2, 4};
    cout << "Test 6 Output: " << obj.maxProfit(t6) << " (Expected: 3)" << endl;

    return 0;
}

// Time Complexity : O(2*n)
// Space Complexity : O(2*n)


*/




#include<bits/stdc++.h>
using namespace std ; 


class Solution {
public:

    int maxProfit(vector<int>& prices) {

        int n = prices.size() ; 

        vector<vector<int>>dp(n+2 , vector<int>(2 , 0)) ;
        int aheadBuy  = 0 ; 
        int aheadSell = 0 ; 
        int aheadBuy2 = 0 ; 

        for(int idx = n - 1 ; idx >= 0 ; idx --){

            int currBuy = 0 ;
            int currSell = 0 ; 

            for(int flag = 0 ; flag < 2 ; flag ++){

                if(!flag){

                int buy = -prices[idx] + aheadSell ; 
                int skip = aheadBuy ; 
        
                 currBuy = max(buy , skip) ; 
                }
                else{

                int sell = prices[idx] + aheadBuy2;
                int skip = aheadSell; 

                currSell = max(sell , skip) ; 
                }
            }


            aheadBuy2 = aheadBuy;
            aheadBuy  = currBuy ;
            aheadSell = currSell;

        }

        return aheadBuy ; 
    
    }
};


int main() {

    Solution obj;

    // Test Case 1
    vector<int> t1 = {1, 2, 3, 0, 2};
    cout << "Test 1 Output: " << obj.maxProfit(t1) << " (Expected: 3)" << endl;

    // Test Case 2
    vector<int> t2 = {1};
    cout << "Test 2 Output: " << obj.maxProfit(t2) << " (Expected: 0)" << endl;

    // Test Case 3 (strictly increasing)
    vector<int> t3 = {1, 2, 3, 4, 5};
    cout << "Test 3 Output: " << obj.maxProfit(t3) << " (Expected: 4)" << endl;

    // Test Case 4 (strictly decreasing)
    vector<int> t4 = {5, 4, 3, 2, 1};
    cout << "Test 4 Output: " << obj.maxProfit(t4) << " (Expected: 0)" << endl;

    // Test Case 5 (cooldown effect important)
    vector<int> t5 = {6, 1, 6, 4, 3, 0, 2};
    cout << "Test 5 Output: " << obj.maxProfit(t5) << " (Expected: 7)" << endl;

    // Test Case 6 (multiple cooldown decisions)
    vector<int> t6 = {1, 2, 4};
    cout << "Test 6 Output: " << obj.maxProfit(t6) << " (Expected: 3)" << endl;

    return 0;
}

// Time Complexity : O(2*n)
// Space Complexity : O(1)

