/*
#include<bits/stdc++.h>
using namespace std ; 


class Solution {
public:


    int m ;
    int n ; 
    int memo[101][101] ;

    int solve(vector<vector<int>>&grid , int i , int j ){

        if( i > m - 1 || j > n - 1)
        return 0 ; 

        if(grid[i][j] == 1)
        return 0 ; 

        if(i == m - 1 && j == n - 1)
        return 1 ; 

        if(memo[i][j] != -1)
        return memo[i][j] ; 


        int totPath = 0 ; 

        // Right Direction 
        totPath += solve(grid , i , j + 1) ; 

        // Bottom Direction 
        totPath += solve(grid , i + 1 , j ) ; 


        return memo[i][j] = totPath ; 
    }

    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        this -> m = obstacleGrid.size() ; 
        this -> n = obstacleGrid[0].size() ; 

        memset(memo , -1 , sizeof(memo)) ; 

        if(obstacleGrid[m-1][n-1] == 1)
        return 0 ; 

        return solve(obstacleGrid , 0  , 0) ; 

    }
};

int main() {

    Solution obj;

    // Test 1: Basic (no obstacles)
    vector<vector<int>> t1 = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };
    cout << "Test 1: " << obj.uniquePathsWithObstacles(t1) << endl; // 6


    // Test 2: Start blocked
    vector<vector<int>> t2 = {
        {1,0},
        {0,0}
    };
    cout << "Test 2: " << obj.uniquePathsWithObstacles(t2) << endl; // 0


    // Test 3: End blocked
    vector<vector<int>> t3 = {
        {0,0},
        {0,1}
    };
    cout << "Test 3: " << obj.uniquePathsWithObstacles(t3) << endl; // 0


    // Test 4: Full blocked row
    vector<vector<int>> t4 = {
        {0,0,0},
        {1,1,1},
        {0,0,0}
    };
    cout << "Test 4: " << obj.uniquePathsWithObstacles(t4) << endl; // 0


    // Test 5: Single row
    vector<vector<int>> t5 = {
        {0,0,1,0,0}
    };
    cout << "Test 5: " << obj.uniquePathsWithObstacles(t5) << endl; // 0


    // Test 6: Single column
    vector<vector<int>> t6 = {
        {0},
        {0},
        {1},
        {0}
    };
    cout << "Test 6: " << obj.uniquePathsWithObstacles(t6) << endl; // 0


    // Test 7: Narrow path
    vector<vector<int>> t7 = {
        {0,1,0},
        {0,1,0},
        {0,0,0}
    };
    cout << "Test 7: " << obj.uniquePathsWithObstacles(t7) << endl; // 1


    // Test 8: Obstacle at turning
    vector<vector<int>> t8 = {
        {0,0,0},
        {0,1,1},
        {0,0,0}
    };
    cout << "Test 8: " << obj.uniquePathsWithObstacles(t8) << endl; // 1


    // Test 9: Almost full obstacles
    vector<vector<int>> t9 = {
        {0,1,1},
        {1,1,1},
        {1,1,0}
    };
    cout << "Test 9: " << obj.uniquePathsWithObstacles(t9) << endl; // 0


    // Test 10: 1x1 valid
    vector<vector<int>> t10 = {
        {0}
    };
    cout << "Test 10: " << obj.uniquePathsWithObstacles(t10) << endl; // 1


    // Test 11: 1x1 blocked
    vector<vector<int>> t11 = {
        {1}
    };
    cout << "Test 11: " << obj.uniquePathsWithObstacles(t11) << endl; // 0


    // Test 12: Diagonal obstacles
    vector<vector<int>> t12 = {
        {0,0,0,0},
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,0}
    };
    cout << "Test 12: " << obj.uniquePathsWithObstacles(t12) << endl; // 4


    return 0;
}

Time Complexity : O(m*n)
Space Complexity : O(m*n)




#include<bits/stdc++.h>
using namespace std ; 


class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
      int m = grid.size() ;
      int n = grid[0].size() ; 

      if(grid[m-1][n-1] == 1)
      return 0 ; 

      vector<vector<int>>t(m + 1 , vector<int>(n + 1 , 0)) ; 

      t[m-1][n-1] = 1 ; 

      for(int i = m - 1 ; i >= 0 ; i --){

        for(int j = n - 1 ; j >= 0 ; j --){

            if(grid[i][j] == 1){
                t[i][j] = 0 ; 
                continue;
            }

            if( i == m - 1 && j == n - 1)
            continue;

            int totPath = 0 ; 

            // Right Direction 
            totPath += t[i][j + 1] ; 

            // Bottom Direction 
            totPath += t[i + 1][j] ; 

             t[i][j] = totPath ; 
        }
      }

      return t[0][0] ;

    }
};

int main() {

    Solution obj;

    // Test 1: Basic (no obstacles)
    vector<vector<int>> t1 = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };
    cout << "Test 1: " << obj.uniquePathsWithObstacles(t1) << endl; // 6


    // Test 2: Start blocked
    vector<vector<int>> t2 = {
        {1,0},
        {0,0}
    };
    cout << "Test 2: " << obj.uniquePathsWithObstacles(t2) << endl; // 0


    // Test 3: End blocked
    vector<vector<int>> t3 = {
        {0,0},
        {0,1}
    };
    cout << "Test 3: " << obj.uniquePathsWithObstacles(t3) << endl; // 0


    // Test 4: Full blocked row
    vector<vector<int>> t4 = {
        {0,0,0},
        {1,1,1},
        {0,0,0}
    };
    cout << "Test 4: " << obj.uniquePathsWithObstacles(t4) << endl; // 0


    // Test 5: Single row
    vector<vector<int>> t5 = {
        {0,0,1,0,0}
    };
    cout << "Test 5: " << obj.uniquePathsWithObstacles(t5) << endl; // 0


    // Test 6: Single column
    vector<vector<int>> t6 = {
        {0},
        {0},
        {1},
        {0}
    };
    cout << "Test 6: " << obj.uniquePathsWithObstacles(t6) << endl; // 0


    // Test 7: Narrow path
    vector<vector<int>> t7 = {
        {0,1,0},
        {0,1,0},
        {0,0,0}
    };
    cout << "Test 7: " << obj.uniquePathsWithObstacles(t7) << endl; // 1


    // Test 8: Obstacle at turning
    vector<vector<int>> t8 = {
        {0,0,0},
        {0,1,1},
        {0,0,0}
    };
    cout << "Test 8: " << obj.uniquePathsWithObstacles(t8) << endl; // 1


    // Test 9: Almost full obstacles
    vector<vector<int>> t9 = {
        {0,1,1},
        {1,1,1},
        {1,1,0}
    };
    cout << "Test 9: " << obj.uniquePathsWithObstacles(t9) << endl; // 0


    // Test 10: 1x1 valid
    vector<vector<int>> t10 = {
        {0}
    };
    cout << "Test 10: " << obj.uniquePathsWithObstacles(t10) << endl; // 1


    // Test 11: 1x1 blocked
    vector<vector<int>> t11 = {
        {1}
    };
    cout << "Test 11: " << obj.uniquePathsWithObstacles(t11) << endl; // 0


    // Test 12: Diagonal obstacles
    vector<vector<int>> t12 = {
        {0,0,0,0},
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,0}
    };
    cout << "Test 12: " << obj.uniquePathsWithObstacles(t12) << endl; // 4


    return 0;
}

// Time Complexity : O(m*n)
// Space Complexity : O(m*n)




*/


#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<long long> prevRow(n, 0);

   
        prevRow[n-1] = (grid[m-1][n-1] == 1) ? 0 : 1;

        for(int i = m - 1; i >= 0; i--) {

            vector<long long> currRow(n, 0);

            for(int j = n - 1; j >= 0; j--) {

                if(grid[i][j] == 1) {
                    currRow[j] = 0;
                }
                else if(i == m-1 && j == n-1) {
                    currRow[j] = prevRow[j]; // already handled
                }
                else {
                    long long right = (j+1 < n) ? currRow[j+1] : 0;
                    long long down  = prevRow[j];

                    currRow[j] = right + down;
                }
            }

            prevRow = currRow;
        }

        return prevRow[0];
    }
};

int main() {

    Solution obj;

    // Test 1: Basic (no obstacles)
    vector<vector<int>> t1 = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };
    cout << "Test 1: " << obj.uniquePathsWithObstacles(t1) << endl; // 6


    // Test 2: Start blocked
    vector<vector<int>> t2 = {
        {1,0},
        {0,0}
    };
    cout << "Test 2: " << obj.uniquePathsWithObstacles(t2) << endl; // 0


    // Test 3: End blocked
    vector<vector<int>> t3 = {
        {0,0},
        {0,1}
    };
    cout << "Test 3: " << obj.uniquePathsWithObstacles(t3) << endl; // 0


    // Test 4: Full blocked row
    vector<vector<int>> t4 = {
        {0,0,0},
        {1,1,1},
        {0,0,0}
    };
    cout << "Test 4: " << obj.uniquePathsWithObstacles(t4) << endl; // 0


    // Test 5: Single row
    vector<vector<int>> t5 = {
        {0,0,1,0,0}
    };
    cout << "Test 5: " << obj.uniquePathsWithObstacles(t5) << endl; // 0


    // Test 6: Single column
    vector<vector<int>> t6 = {
        {0},
        {0},
        {1},
        {0}
    };
    cout << "Test 6: " << obj.uniquePathsWithObstacles(t6) << endl; // 0


    // Test 7: Narrow path
    vector<vector<int>> t7 = {
        {0,1,0},
        {0,1,0},
        {0,0,0}
    };
    cout << "Test 7: " << obj.uniquePathsWithObstacles(t7) << endl; // 1


    // Test 8: Obstacle at turning
    vector<vector<int>> t8 = {
        {0,0,0},
        {0,1,1},
        {0,0,0}
    };
    cout << "Test 8: " << obj.uniquePathsWithObstacles(t8) << endl; // 1


    // Test 9: Almost full obstacles
    vector<vector<int>> t9 = {
        {0,1,1},
        {1,1,1},
        {1,1,0}
    };
    cout << "Test 9: " << obj.uniquePathsWithObstacles(t9) << endl; // 0


    // Test 10: 1x1 valid
    vector<vector<int>> t10 = {
        {0}
    };
    cout << "Test 10: " << obj.uniquePathsWithObstacles(t10) << endl; // 1


    // Test 11: 1x1 blocked
    vector<vector<int>> t11 = {
        {1}
    };
    cout << "Test 11: " << obj.uniquePathsWithObstacles(t11) << endl; // 0


    // Test 12: Diagonal obstacles
    vector<vector<int>> t12 = {
        {0,0,0,0},
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,0}
    };
    cout << "Test 12: " << obj.uniquePathsWithObstacles(t12) << endl; // 4


    return 0;
}

// Time Complexity : O(m*n)
// Space Complexity : O(m*n)


