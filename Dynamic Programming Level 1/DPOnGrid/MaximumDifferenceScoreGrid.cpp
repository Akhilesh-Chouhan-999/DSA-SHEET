/*
#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:

    int m ; 
    int n ; 
    int memo[1001][1001] ;

    int solve(vector<vector<int>>& grid, int i, int j){

        if( i >= m || j >= n ){
            return 0 ; 
        }

        if(memo[i][j] != -1)
        return memo[i][j] ; 

        int bottom = max(grid[i][j] , solve(grid , i + 1 , j)) ; 
        int right = max(grid[i][j] , solve(grid , i , j + 1) ) ; 

        return memo[i][j] = max(bottom , right) ; 

    }
    int maxScore(vector<vector<int>>& grid) {

        this-> m = grid.size() ; 
        this-> n = grid[0].size() ;

        memset(memo , -1 , sizeof(memo)) ; 

        int result = INT_MIN ;

        for(int i = 0 ; i < m ; i ++ ){
            for(int j = 0 ; j < n ; j ++){

                int cal =  max(solve(grid , i + 1 , j) , solve(grid , i , j + 1))  ; 
                result = max(result , cal == 0 ? INT_MIN : -grid[i][j] + cal) ; 
            }
        }
        

        return result ; 
    }
};


int main() {

    Solution obj;

    // Test Case 1: Normal grid
    vector<vector<int>> grid1 = {
        {9, 5, 7, 3},
        {8, 9, 6, 1},
        {6, 7, 14, 3},
        {2, 5, 3, 1}
    };
    cout << "Test 1 Output: " << obj.maxScore(grid1) << endl;

    // Test Case 2: Increasing values (best path obvious)
    vector<vector<int>> grid2 = {
        {1, 2},
        {3, 4}
    };
    cout << "Test 2 Output: " << obj.maxScore(grid2) << endl;

    // Test Case 3: All same values (edge case)
    vector<vector<int>> grid3 = {
        {5, 5},
        {5, 5}
    };
    cout << "Test 3 Output: " << obj.maxScore(grid3) << endl;

    return 0;
}
    Top Down Approach : 
    Time Complexity : O(m * n)
    Space Complexity : O(m * n)

*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int maxScore(vector<vector<int>>& grid) {

        int m = grid.size(); 
        int n = grid[0].size();

        vector<int> prevRow(n+1, INT_MIN);

        int result = INT_MIN;

        for(int i = m-1; i >= 0; i--){

            vector<int> currRow(n+1, INT_MIN);

            for(int j = n-1; j >= 0; j--){

                int bottom = (prevRow[j] == INT_MIN) ? grid[i][j] : max(grid[i][j], prevRow[j]);
                int right  = (currRow[j+1] == INT_MIN) ? grid[i][j] : max(grid[i][j], currRow[j+1]);

                currRow[j] = max(bottom, right);

                if(prevRow[j] != INT_MIN)
                    result = max(result, prevRow[j] - grid[i][j]);

                if(currRow[j+1] != INT_MIN)
                    result = max(result, currRow[j+1] - grid[i][j]);
            }

            prevRow = currRow; 
        }

        return result;
    }
};





int main() {

    Solution obj;

    // Test Case 1: Normal grid
    vector<vector<int>> grid1 = {
        {9, 5, 7, 3},
        {8, 9, 6, 1},
        {6, 7, 14, 3},
        {2, 5, 3, 1}
    };
    cout << "Test 1 Output: " << obj.maxScore(grid1) << endl;

    // Test Case 2: Increasing values (best path obvious)
    vector<vector<int>> grid2 = {
        {1, 2},
        {3, 4}
    };
    cout << "Test 2 Output: " << obj.maxScore(grid2) << endl;

    // Test Case 3: All same values (edge case)
    vector<vector<int>> grid3 = {
        {5, 5},
        {5, 5}
    };
    cout << "Test 3 Output: " << obj.maxScore(grid3) << endl;

    return 0;
}


// Optimization : 
// Space Complexity : O(n)

