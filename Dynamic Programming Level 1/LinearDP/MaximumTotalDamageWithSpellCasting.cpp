#include<bits/stdc++.h>
using namespace std ; 
class Solution {
public:

    using ll = long long ;

    
    /*
    
    
    Memoization :--
    unordered_map<int , int>mpp ;
    vector<ll>memo ; 

    ll solve(vector<ll>&power , int idx ) {

        if(idx >= power.size())
        return 0 ; 

        if(memo[idx] != -1)
        return memo[idx]  ;  

        long long take = 0 ; 
        int j = lower_bound(begin(power) , end(power) , power[idx] + 3) - begin(power) ;
        take = power[idx]*mpp[power[idx]] + solve(power , j ) ; 

        long long skip = solve(power , idx + 1) ;

        return memo[idx]  = max(take , skip) ; 

    }

    
    
    long long maximumTotalDamage(vector<int>& power) {


        for(int pow : power)
        mpp[pow] ++ ; 

        vector<ll>temp ; 

        for(auto it : mpp){
            temp.push_back(it.first) ; 
        }

        sort(temp.begin() , temp.end()) ;
        
        memo.resize( temp.size() + 1 , -1) ; 

        return solve(temp , 0) ; 
        
    }

    */ 

    // Tabulation
    // dp[i] : Maximum total Damage if we start from index i 

     long long maximumTotalDamage(vector<int>& power) {

        unordered_map<int , int>mpp ; 

        for(int pow : power)
        mpp[pow] ++ ; 

        vector<long long>temp ; 

        for(auto it : mpp){
            temp.push_back(it.first) ; 
        }

        sort(begin(temp) , end(temp)) ; 

        int n = temp.size() ;

        vector<int>dp(n+1 , -1) ; 

        dp[n] = 0 ; 

        for(int i = n - 1 ; i >= 0 ; i --){

            if(dp[i] != -1)
            continue;

            int j = lower_bound(begin(temp) , end(temp) , temp[i] + 3) - begin(temp);
            ll take = temp[i]*mpp[temp[i]] + dp[j] ; 

            ll skip = dp[i+1] ;

            dp[i] = max(skip , take) ; 

        }

        return dp[0] ; 
    }
    
};


int main() {
    Solution sol;

    vector<int> test1 = {3, 4, 2};
    cout << sol.maximumTotalDamage(test1) << endl;  // Expected: 4

    vector<int> test2 = {2, 2, 3, 3, 3, 4};
    cout << sol.maximumTotalDamage(test2) << endl;  // Expected: 9

    vector<int> test3 = {1};
    cout << sol.maximumTotalDamage(test3) << endl;  // Expected: 1

    vector<int> test4 = {1,1,1,2,4,5,5,5,6};
    cout << sol.maximumTotalDamage(test4) << endl;  // Try manually

    vector<int> test5 = {10, 10, 10, 11, 12};
    cout << sol.maximumTotalDamage(test5) << endl;

    return 0;
}

// Time Complexity : O(n*log(n))
// Space Complexity : O(n*log(n))

