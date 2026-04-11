/*
#include<bits/stdc++.h>
using namespace std ; 

class Solution {
  public:

    int m ;
    int n ;

    int solve(vector<vector<int>>&mat , int i , int j , vector<vector<int>>&dp ){

        if( i >= m){
            return 0 ; 
        }


        if(dp[i][j] != -1)
        return dp[i][j] ; 

        int maxPoint = INT_MIN;


        for(int k = 0 ; k < n ; k ++){

            if(k == j)
            continue;

            int point =  mat[i][k] + solve(mat , i + 1 , k , dp ) ; 
            maxPoint = max(point , maxPoint) ; 
            
        }

        return dp[i][j] = maxPoint ; 

    }

    int maximumPoints(vector<vector<int>>& mat) {
        
        this->m = mat.size() ; 
        this->n = mat[0].size() ; 

        vector<vector<int>>dp(m , vector<int>(n , -1)) ; 

        int ans = 0 ; 

        for(int col = 0 ; col < n ;  col ++){
            ans = max(ans , mat[0][col] + solve(mat , 1 , col , dp)) ; 
        }

        return ans ; 
    }
};


int main() {

    Solution obj;

    // Test Case 1
    vector<vector<int>> mat1 = {
        {1, 2, 3},
        {1, 5, 1},
        {3, 1, 1}
    };
    cout << "Test 1 Output: " << obj.maximumPoints(mat1) << endl;
    // Expected: 11 
    // Path: 3 -> 5 -> 3

    // Test Case 2
    vector<vector<int>> mat2 = {
        {10, 50, 40},
        {5, 100, 11}
    };
    cout << "Test 2 Output: " << obj.maximumPoints(mat2) << endl;
    // Expected: 150
    // Path: 50 -> 100

    // Test Case 3
    vector<vector<int>> mat3 = {
        {1, 2},
        {3, 4}
    };
    cout << "Test 3 Output: " << obj.maximumPoints(mat3) << endl;
    // Expected: 6
    // Path: 2 -> 4 OR 1 -> 4

    // Test Case 4
    vector<vector<int>> mat4 = {
        {7, 8, 9}
    };
    cout << "Test 4 Output: " << obj.maximumPoints(mat4) << endl;
    // Expected: 9

    // Test Case 5 (Edge Case)
    vector<vector<int>> mat5 = {
        {5}
    };
    cout << "Test 5 Output: " << obj.maximumPoints(mat5) << endl;
    // Expected: 5

    // Test Case 6
    vector<vector<int>> mat6 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    cout << "Test 6 Output: " << obj.maximumPoints(mat6) << endl;
    // Expected: 17
    // Path: 3 -> 5 -> 9

    return 0;
}

Top Down Approach : 
Time Complexity : O(m*n*n)
Space Complexity : O(m*n)

*/



// Bottom Up : 
