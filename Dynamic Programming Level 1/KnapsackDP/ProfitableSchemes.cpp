/*

#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:

    // Total ways to achieve the scheme :

    const int MOD = 1e9 + 7;
    int memo[101][101][101] ;

    int solve(vector<int>& group, vector<int>& profit, int idx, int member, int currProfit ,int minProfit){

        if(idx >= group.size()){
            return currProfit >= minProfit ; 
        }

        if(memo[idx][member][currProfit] != -1)
        return memo[idx][member][currProfit] ; 

        int ways = 0 ; 
        
        ways = solve(group, profit, idx+1, member, currProfit, minProfit);

        if(member >= group[idx]){
            int newProfit = min(minProfit, currProfit + profit[idx]);
            ways = (ways + solve(group, profit, idx+1, member - group[idx], newProfit,  minProfit)) % MOD;
        }


        return memo[idx][member][currProfit] = ways ; 

    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {

        memset(memo, -1, sizeof(memo)) ; 

        return solve(group, profit, 0, n, 0, minProfit) ; 

    }
};

int main() {

    Solution obj;

    // Test Case 1
    int n1 = 5, minProfit1 = 3;
    vector<int> group1 = {2, 2};
    vector<int> profit1 = {2, 3};
    cout << "Output: " << obj.profitableSchemes(n1, minProfit1, group1, profit1)
         << " | Expected: 2" << endl;

    // Test Case 2
    int n2 = 10, minProfit2 = 5;
    vector<int> group2 = {2, 3, 5};
    vector<int> profit2 = {6, 7, 8};
    cout << "Output: " << obj.profitableSchemes(n2, minProfit2, group2, profit2)
         << " | Expected: 7" << endl;

    // Test Case 3 (edge case)
    int n3 = 1, minProfit3 = 1;
    vector<int> group3 = {1};
    vector<int> profit3 = {1};
    cout << "Output: " << obj.profitableSchemes(n3, minProfit3, group3, profit3)
         << " | Expected: 1" << endl;

    return 0;
}
    Top Down Approach : 
    Time Complexity  : O(n * members * minProfit)
    space Complexity : O(n * memvers * minProfit)

*/