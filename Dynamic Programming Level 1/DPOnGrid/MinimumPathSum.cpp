/*
#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:
    int m ; 
    int n ; 
    int memo[201][201] ;

    int solve(vector<vector<int>>&grid, int i, int j ){

        if( i >= m || j >= n){
            return INT_MAX ; 
        }

        if( i == m - 1 && j == n -1)
        return grid[i][j] ; 

        if(memo[i][j] != -1)
        return memo[i][j] ; 

        int bottom = solve(grid, i+1, j) ; 
        int right  = solve(grid, i, j+1) ;


        return memo[i][j] = min(bottom == INT_MAX ? INT_MAX : grid[i][j] + bottom , right == INT_MAX ? INT_MAX : grid[i][j] + right);

    }
    int minPathSum(vector<vector<int>>& grid) {

        m = grid.size() ; 
        n = grid[0].size() ; 

        memset(memo , -1 , sizeof(memo)) ; 

        return solve(grid, 0, 0) ; 
    }

};
int main() {
    Solution obj;

    vector<vector<int>> grid1 = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    vector<vector<int>> grid2 = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int expected1 = 7;
    int expected2 = 12;

    int result1 = obj.minPathSum(grid1);
    int result2 = obj.minPathSum(grid2);

    cout << "Test Case 1:\n";
    cout << "Output   : " << result1 << endl;
    cout << "Expected : " << expected1 << endl;
    cout << (result1 == expected1 ? "PASS" : "FAIL") << endl;

    cout << "\nTest Case 2:\n";
    cout << "Output   : " << result2 << endl;
    cout << "Expected : " << expected2 << endl;
    cout << (result2 == expected2 ? "PASS" : "FAIL") << endl;

    return 0;
}
    Top Down Approach : 
    Time Complexity : O(m*n)
    Space Complexity : O(m*n)
*/