/*
#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:

    int memo[101][101];
    int solve(vector<int>& arr, int i, int j) {

        if(i == j) {
            return 0;
        }

        if(memo[i][j] != -1) {
            return memo[i][j];
        }

        int minCost = INT_MAX;

        for(int k = i; k < j; k ++) {

            int cost = arr[i - 1] * arr[k] * arr[j] +
                                    solve(arr, i, k) +
                                    solve(arr, k + 1, j);
        
            minCost = min(minCost, cost);
        }

        return memo[i][j] = minCost;

    }
    int matrixMultiplication(vector<int> &arr) {
        
        int n = arr.size();

        memset(memo, -1, sizeof(memo));

        return solve(arr, 1, n - 1);

    }
};


int main() {
    Solution obj;
    
    vector<vector<int>> testCases = {
        {2, 1, 3, 4},           // Test case 1
        {1, 2, 3, 4, 3},        // Test case 2
        {3, 4},                 // Test case 3
        {5, 10, 3, 12, 5},      // Test case 4
        {2, 3, 4, 5},           // Test case 5
        {10, 20, 30},           // Test case 6
        {1, 2, 3, 4, 5, 6},     // Test case 7
        {4, 5, 6, 7, 8},        // Test case 8
        {2, 2, 2, 2, 2},        // Test case 9
        {1, 100, 1, 100, 1}     // Test case 10
    };

    cout << "=== Matrix Chain Multiplication Test Suite ===\n\n";
    
    for(int i = 0; i < testCases.size(); i++) {
        cout << "Test case " << (i + 1) << ": ";
        cout << "arr[] = [";
        for(int j = 0; j < testCases[i].size(); j++) {
            cout << testCases[i] [j];
            if(j < testCases[i].size() - 1) cout << ", ";
        }
        cout << "] => ";
        
        int actual = obj.matrixMultiplication(testCases[i]);
        cout << "Output: " << actual << " PASS\n";
    }

    cout << "\n=== End of Tests ===\n";
    
    return 0;
}
    Time Complexity : O(n^3)
    Space Complexity : O(n^2)
*/



#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:

    int matrixMultiplication(vector<int> &arr) {
        
        int n = arr.size();

        vector<vector<int>>t(n, vector<int>(n , 0));

        for(int i = n - 1; i >= 1; i --) {

            for(int j = i + 1; j < n; j ++) {
                
                int minCost = INT_MAX;

                for(int k = i; k < j; k ++){


                    int cost = arr[i - 1] * arr[k] * arr[j] +
                                    t[i][k] +
                                    t[k + 1][j];
        
                    minCost = min(minCost, cost);
                }


                t[i][j] = minCost;
            }
        }

        return t[1][n-1];

    }
};


int main() {
    Solution obj;
    
    vector<vector<int>> testCases = {
        {2, 1, 3, 4},           // Test case 1
        {1, 2, 3, 4, 3},        // Test case 2
        {3, 4},                 // Test case 3
        {5, 10, 3, 12, 5},      // Test case 4
        {2, 3, 4, 5},           // Test case 5
        {10, 20, 30},           // Test case 6
        {1, 2, 3, 4, 5, 6},     // Test case 7
        {4, 5, 6, 7, 8},        // Test case 8
        {2, 2, 2, 2, 2},        // Test case 9
        {1, 100, 1, 100, 1}     // Test case 10
    };

    cout << "=== Matrix Chain Multiplication Test Suite ===\n\n";
    
    for(int i = 0; i < testCases.size(); i++) {
        cout << "Test case " << (i + 1) << ": ";
        cout << "arr[] = [";
        for(int j = 0; j < testCases[i].size(); j++) {
            cout << testCases[i] [j];
            if(j < testCases[i].size() - 1) cout << ", ";
        }
        cout << "] => ";
        
        int actual = obj.matrixMultiplication(testCases[i]);
        cout << "Output: " << actual << " PASS\n";
    }

    cout << "\n=== End of Tests ===\n";
    
    return 0;
}


