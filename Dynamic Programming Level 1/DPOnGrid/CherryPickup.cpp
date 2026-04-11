#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:

    int m ;
    int n ; 
    int memo[51][51][51] ;

    int solve(int r1 , int c1 , int r2 , vector<vector<int>>&grid){

        int c2 = r1 + c1 - r2 ; 

        if(r1 >= m || r2 >= m || c1 >= n || c2 >= n || c2 < 0 || grid[r1][c1] == -1 || grid[r2][c2] == -1)
        return INT_MIN ; 

        int cherries ; 

        if(r1 == r2 && c1 == c2){
            cherries = grid[r1][c1] ; 
        }
        else{
            cherries = grid[r1][c1] + grid[r2][c2] ; 
        }

        if(r1 == m - 1 && c1 == n - 1) 
        return cherries ; 

        if(memo[r1][c1][r2] != -1)
        return memo[r1][c1][r2] ; 

        int firstDir  = solve(r1 + 1 , c1      , r2 + 1  , grid) ; 
        int secondDir = solve(r1     , c1 + 1  , r2      , grid) ;
        int thirdDir  = solve(r1 + 1 , c1      , r2      , grid) ; 
        int fouthDir  = solve(r1     , c1 + 1  , r2 + 1  , grid) ;  

        int best = max({firstDir , secondDir , thirdDir , fouthDir}) ; 

        if(best == INT_MIN)
        return memo[r1][c1][r2] = INT_MIN;

        return memo[r1][c1][r2] = cherries + best ; 
    }
    int cherryPickup(vector<vector<int>>& grid) {
        
        this -> m = grid.size() ; 
        this -> n = grid[0].size() ; 

        memset(memo , -1 , sizeof(memo)) ; 

        return max(0 , solve(0, 0, 0, grid)) ;

    }
};

int main() {

    Solution obj;

    // Test Case 1
    vector<vector<int>> grid1 = {
        {0, 1, -1},
        {1, 0, -1},
        {1, 1, 1}
    };

    cout << "Output 1: " << obj.cherryPickup(grid1) << endl;


    // Test Case 2
    vector<vector<int>> grid2 = {
        {1, 1, -1},
        {1, -1, 1},
        {-1, 1, 1}
    };

    cout << "Output 2: " << obj.cherryPickup(grid2) << endl;


    return 0;
}