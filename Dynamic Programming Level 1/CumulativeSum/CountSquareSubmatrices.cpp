#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>>t(m + 1, vector<int>(n + 1, 0));

        for(int i = m - 1; i >= 0 ; i --){
            for(int j = n - 1; j >= 0; j --){

                int side = 0;

                int right    = t[i][j + 1];
                int bottom   = t[i + 1][j];
                int diagonal = t[i + 1][j + 1];

                if(matrix[i][j] == 1){
                    side = max(side, 1 + min({right, bottom, diagonal}));
                }

                t[i][j] = side;

            }
        }

        int cnt = 0 ; 

        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++){
              cnt += t[i][j];
            }
        }

        return cnt; 
    }
};

int main() {

    Solution obj;

    // -------- Test Case 1 --------
    vector<vector<int>> t1 = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };
    cout << "Test 1 Output: " << obj.countSquares(t1) << " | Expected: 0\n";

    // -------- Test Case 2 --------
    vector<vector<int>> t2 = {
        {1,1,1},
        {1,1,1},
        {1,1,1}
    };
    cout << "Test 2 Output: " << obj.countSquares(t2) << " | Expected: 14\n";

    // -------- Test Case 3 --------
    vector<vector<int>> t3 = {
        {1,1,1,1,1}
    };
    cout << "Test 3 Output: " << obj.countSquares(t3) << " | Expected: 5\n";

    // -------- Test Case 4 --------
    vector<vector<int>> t4 = {
        {1},
        {1},
        {1},
        {1}
    };
    cout << "Test 4 Output: " << obj.countSquares(t4) << " | Expected: 4\n";

    // -------- Test Case 5 --------
    vector<vector<int>> t5 = {
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };
    cout << "Test 5 Output: " << obj.countSquares(t5) << " | Expected: 3\n";

    // -------- Test Case 6 --------
    vector<vector<int>> t6 = {
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };
    cout << "Test 6 Output: " << obj.countSquares(t6) << " | Expected: 8\n";

    // -------- Test Case 7 --------
    vector<vector<int>> t7 = {
        {1,1,1,1},
        {1,1,1,1}
    };
    cout << "Test 7 Output: " << obj.countSquares(t7) << " | Expected: 11\n";

    // -------- Test Case 8 --------
    vector<vector<int>> t8 = {
        {1,0,1,1},
        {1,1,1,1},
        {0,1,1,1}
    };
    cout << "Test 8 Output: " << obj.countSquares(t8) << " | Expected: 10\n";

    // -------- Test Case 9 --------
    vector<vector<int>> t9 = {
        {1,1,0},
        {1,1,0},
        {1,1,1}
    };
    cout << "Test 9 Output: " << obj.countSquares(t9) << " | Expected: 9\n";

    // -------- Test Case 10 --------
    vector<vector<int>> t10 = {
        {0,1,1,1,0},
        {1,1,1,1,1},
        {1,1,1,1,1},
        {0,1,1,1,0}
    };
    cout << "Test 10 Output: " << obj.countSquares(t10) << " | Expected: 20\n";

    return 0;
}

// Time Complexity : O(n*m)
// Space Complexity : O(n*m)