/*
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m;
    int n;
    int memo[301][301];
    int solve(vector<vector<char>>& matrix, int i, int j) {

        if(i >= m || j >= n) {
            return 0;
        }

        if(memo[i][j] != -1)
        return memo[i][j];


        int side = 0;

        int right    = solve(matrix, i, j + 1);
        int bottom   = solve(matrix, i + 1, j);
        int diagonal = solve(matrix, i + 1, j + 1);

        if(matrix[i][j] == '1'){
            side = max(side, 1 + min({right, bottom, diagonal}));
        }

        return memo[i][j] = side;
    }
    int maximalSquare(vector<vector<char>>& matrix) {


        this -> m = matrix.size();
        this -> n = matrix[0].size();

        memset(memo, -1, sizeof(memo));
        
        int area = INT_MIN;

        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++){
                int side = solve(matrix, i, j);
                area = max(area, side*side);
            }
        }

        return area;

    }
};
int main() {

    Solution obj;

    // -------- Test Case 1 --------
    vector<vector<char>> t1 = {
        {'0','0','0'},
        {'0','0','0'},
        {'0','0','0'}
    };
    cout << "Test 1 Output: " << obj.maximalSquare(t1) << " | Expected: 0\n";

    // -------- Test Case 2 --------
    vector<vector<char>> t2 = {
        {'1','1','1'},
        {'1','1','1'},
        {'1','1','1'}
    };
    cout << "Test 2 Output: " << obj.maximalSquare(t2) << " | Expected: 9\n";

    // -------- Test Case 3 --------
    vector<vector<char>> t3 = {
        {'1','1','1','1','1'}
    };
    cout << "Test 3 Output: " << obj.maximalSquare(t3) << " | Expected: 1\n";

    // -------- Test Case 4 --------
    vector<vector<char>> t4 = {
        {'1'},
        {'1'},
        {'1'},
        {'1'}
    };
    cout << "Test 4 Output: " << obj.maximalSquare(t4) << " | Expected: 1\n";

    // -------- Test Case 5 --------
    vector<vector<char>> t5 = {
        {'1','0','0'},
        {'0','1','0'},
        {'0','0','1'}
    };
    cout << "Test 5 Output: " << obj.maximalSquare(t5) << " | Expected: 1\n";

    // -------- Test Case 6 (VERY IMPORTANT) --------
    vector<vector<char>> t6 = {
        {'1','1','1'},
        {'1','0','1'},
        {'1','1','1'}
    };
    cout << "Test 6 Output: " << obj.maximalSquare(t6) << " | Expected: 1\n";

    // -------- Test Case 7 --------
    vector<vector<char>> t7 = {
        {'1','1','1','1'},
        {'1','1','1','1'}
    };
    cout << "Test 7 Output: " << obj.maximalSquare(t7) << " | Expected: 4\n";

    // -------- Test Case 8 --------
    vector<vector<char>> t8 = {
        {'1','0','1','1'},
        {'1','1','1','1'},
        {'0','1','1','1'}
    };
    cout << "Test 8 Output: " << obj.maximalSquare(t8) << " | Expected: 4\n";

    // -------- Test Case 9 --------
    vector<vector<char>> t9 = {
        {'1','1','0'},
        {'1','1','0'},
        {'1','1','1'}
    };
    cout << "Test 9 Output: " << obj.maximalSquare(t9) << " | Expected: 4\n";

    // -------- Test Case 10 --------
    vector<vector<char>> t10 = {
        {'0','1','1','1','0'},
        {'1','1','1','1','1'},
        {'1','1','1','1','1'},
        {'0','1','1','1','0'}
    };
    cout << "Test 10 Output: " << obj.maximalSquare(t10) << " | Expected: 9\n";

    return 0;
}

    Time Complexity : O(m*n)
    Space Complexity : O(m*n)
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int maximalSquare(vector<vector<char>>& matrix) {


        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>>t(m + 1, vector<int>(n + 1, 0));

        for(int i = m - 1; i >= 0 ; i --){
            for(int j = n - 1; j >= 0; j --){

                int side = 0;

                int right    = t[i][j + 1];
                int bottom   = t[i + 1][j];
                int diagonal = t[i + 1][j + 1];

                if(matrix[i][j] == '1'){
                    side = max(side, 1 + min({right, bottom, diagonal}));
                }

                t[i][j] = side;

            }
        }

        
        int area = INT_MIN;

        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++){
                int side = t[i][j];
                area = max(area, side*side);
            }
        }

        return area;
    }
};
int main() {

    Solution obj;

    // -------- Test Case 1 --------
    vector<vector<char>> t1 = {
        {'0','0','0'},
        {'0','0','0'},
        {'0','0','0'}
    };
    cout << "Test 1 Output: " << obj.maximalSquare(t1) << " | Expected: 0\n";

    // -------- Test Case 2 --------
    vector<vector<char>> t2 = {
        {'1','1','1'},
        {'1','1','1'},
        {'1','1','1'}
    };
    cout << "Test 2 Output: " << obj.maximalSquare(t2) << " | Expected: 9\n";

    // -------- Test Case 3 --------
    vector<vector<char>> t3 = {
        {'1','1','1','1','1'}
    };
    cout << "Test 3 Output: " << obj.maximalSquare(t3) << " | Expected: 1\n";

    // -------- Test Case 4 --------
    vector<vector<char>> t4 = {
        {'1'},
        {'1'},
        {'1'},
        {'1'}
    };
    cout << "Test 4 Output: " << obj.maximalSquare(t4) << " | Expected: 1\n";

    // -------- Test Case 5 --------
    vector<vector<char>> t5 = {
        {'1','0','0'},
        {'0','1','0'},
        {'0','0','1'}
    };
    cout << "Test 5 Output: " << obj.maximalSquare(t5) << " | Expected: 1\n";

    // -------- Test Case 6 (VERY IMPORTANT) --------
    vector<vector<char>> t6 = {
        {'1','1','1'},
        {'1','0','1'},
        {'1','1','1'}
    };
    cout << "Test 6 Output: " << obj.maximalSquare(t6) << " | Expected: 1\n";

    // -------- Test Case 7 --------
    vector<vector<char>> t7 = {
        {'1','1','1','1'},
        {'1','1','1','1'}
    };
    cout << "Test 7 Output: " << obj.maximalSquare(t7) << " | Expected: 4\n";

    // -------- Test Case 8 --------
    vector<vector<char>> t8 = {
        {'1','0','1','1'},
        {'1','1','1','1'},
        {'0','1','1','1'}
    };
    cout << "Test 8 Output: " << obj.maximalSquare(t8) << " | Expected: 4\n";

    // -------- Test Case 9 --------
    vector<vector<char>> t9 = {
        {'1','1','0'},
        {'1','1','0'},
        {'1','1','1'}
    };
    cout << "Test 9 Output: " << obj.maximalSquare(t9) << " | Expected: 4\n";

    // -------- Test Case 10 --------
    vector<vector<char>> t10 = {
        {'0','1','1','1','0'},
        {'1','1','1','1','1'},
        {'1','1','1','1','1'},
        {'0','1','1','1','0'}
    };
    cout << "Test 10 Output: " << obj.maximalSquare(t10) << " | Expected: 9\n";

    return 0;
}