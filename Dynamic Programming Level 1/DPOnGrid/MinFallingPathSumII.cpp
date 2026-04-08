/*
#include<bits/stdc++.h>
using namespace std ; 
class Solution {
public:

    int m ; 
    int n ; 
    int memo[201][201] ; 

    int solve(vector<vector<int>>&grid, int i, int j){

        if( j >= n)
        return INT_MAX ;
        
        if(i == m -1 )
        return grid[i][j] ; 

        if(memo[i][j] != -1)
        return memo[i][j] ; 

        int result = INT_MAX ;

        for(int k = 0 ; k < n ; k ++){

        if(j == k)
        continue;


        int cal = solve(grid , i + 1 , k);

        if(cal != INT_MAX){
            result = min(result , grid[i][j] + cal);
        }

        }


        return memo[i][j] = result ; 
        
    }
    int minFallingPathSum(vector<vector<int>>& grid) {

        this->m = grid.size() ; 
        this->n = grid[0].size() ;
        
        memset(memo , -1 , sizeof(memo)) ; 

        int result = INT_MAX ; 

        for(int i = 0 ; i < n ; i ++){
        result = min(result, solve(grid, 0, i));
        }

        return result ; 
    }
};


int main() {

    Solution obj;

    // Test Case 1
    vector<vector<int>> grid1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Output 1: " << obj.minFallingPathSum(grid1) << endl;  // Expected: 13


    // Test Case 2
    vector<vector<int>> grid2 = {
        {7}
    };

    cout << "Output 2: " << obj.minFallingPathSum(grid2) << endl;  // Expected: 7


    // Custom Test Case (edge + negative values)
    vector<vector<int>> grid3 = {
        {-73, 61, 43, -48, -36},
        {3, 30, 27, 57, 10},
        {96, -76, 84, 59, -15},
        {5, -49, 76, 31, -7},
        {97, 91, 61, -46, 67}
    };

    cout << "Output 3: " << obj.minFallingPathSum(grid3) << endl;

    return 0;
}

    Top Down Approach :
    Time Complexity : O(n*n*n)
    Space Complexity : O(n*n)




#include<bits/stdc++.h>
using namespace std ; 
class Solution {
public:


    int minFallingPathSum(vector<vector<int>>& grid) {

      int n = grid.size() ;

      vector<vector<int>>dp(n, vector<int>(n , -1)) ;

      for(int i = 0 ; i < n ; i ++){
        dp[n-1][i] = grid[n-1][i] ;
      }

      for(int i = n - 2 ; i >= 0 ; i --){

        for(int j = 0 ; j < n ; j ++ ){


            int result = INT_MAX ;

            for(int k = 0 ; k < n ; k ++){

            if(j == k)
            continue;


            int cal = dp[i+1][k];

            if(cal != INT_MAX){
                result = min(result , grid[i][j] + cal);
            }

            }


         dp[i][j] = result ; 
        }


      }

      int result = INT_MAX ; 

      for(int i = 0 ; i < n ; i ++){
        result = min(result , dp[0][i]) ; 
      }

      return result ;
    }
};


int main() {

    Solution obj;

    // Test Case 1
    vector<vector<int>> grid1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Output 1: " << obj.minFallingPathSum(grid1) << endl;  // Expected: 13


    // Test Case 2
    vector<vector<int>> grid2 = {
        {7}
    };

    cout << "Output 2: " << obj.minFallingPathSum(grid2) << endl;  // Expected: 7


    // Custom Test Case (edge + negative values)
    vector<vector<int>> grid3 = {
        {-73, 61, 43, -48, -36},
        {3, 30, 27, 57, 10},
        {96, -76, 84, 59, -15},
        {5, -49, 76, 31, -7},
        {97, 91, 61, -46, 67}
    };

    cout << "Output 3: " << obj.minFallingPathSum(grid3) << endl;

    return 0;
}

 
 Bottom Up :
 Time Complexity : O(n*n*n)
 Space Complexity : O(n*n)

*/


#include<bits/stdc++.h>
using namespace std ; 
class Solution {
public:


    int minFallingPathSum(vector<vector<int>>& grid) {

      int n = grid.size() ;

      vector<int>prevRow = grid[n-1] ;

      for(int i = n - 2 ; i >= 0 ; i --){

        int min1 = INT_MAX ;
        int min2 = INT_MAX ;
        int minCol = -1 ; 

        vector<int>currRow(n , 0) ; 

        for(int j = 0 ; j < n ; j ++){

            if(prevRow[j] < min1){
                min2 = min1 ; 
                min1 = prevRow[j] ;
                minCol = j ;
            }
            else if(prevRow[j] < min2){
                min2 = prevRow[j] ;  
            }
        }


        for(int j = 0 ; j < n ; j ++){
            currRow[j] = grid[i][j] + ((minCol != j ) ? min1 : min2) ; 
        }

        prevRow = currRow ;
      }

      int result = INT_MAX ;

      for(int i = 0 ; i < n ; i ++){
        result = min(result , prevRow[i]) ; 
      }


      return result ; 
    }
};


int main() {

    Solution obj;

    // Test Case 1
    vector<vector<int>> grid1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Output 1: " << obj.minFallingPathSum(grid1) << endl;  // Expected: 13


    // Test Case 2
    vector<vector<int>> grid2 = {
        {7}
    };

    cout << "Output 2: " << obj.minFallingPathSum(grid2) << endl;  // Expected: 7


    // Custom Test Case (edge + negative values)
    vector<vector<int>> grid3 = {
        {-73, 61, 43, -48, -36},
        {3, 30, 27, 57, 10},
        {96, -76, 84, 59, -15},
        {5, -49, 76, 31, -7},
        {97, 91, 61, -46, 67}
    };

    cout << "Output 3: " << obj.minFallingPathSum(grid3) << endl;

    return 0;
}

 
 // Optimization :
 // Time Complexity : O(n)
 // Space Complexity : O(n)

 