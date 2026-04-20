/*
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int memo[501];
    int solve(vector<int>& arr, int idx, int k) {

        if(idx == arr.size()) {
            return 0;
        } 

        if(memo[idx] != -1)
        return memo[idx];

        int ans = 0;
        int maxElement = 0;
    
        for(int l = 1; l <= k && idx + l <= arr.size(); l++) {

            maxElement = max(maxElement, arr[idx + l - 1]);

            ans = max(ans,
                        maxElement * l + solve(arr, idx + l, k));
        }

        return memo[idx] = ans;
    
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        memset(memo, -1, sizeof(memo));

        return solve(arr, 0, k);
    }
};


int main() {
    Solution sol;

    // Test Case 1
    vector<int> arr1 = {1, 15, 7, 9, 2, 5, 10};
    int k1 = 3;
    cout << "Test 1: " << sol.maxSumAfterPartitioning(arr1, k1) << endl;
    // Expected: 84

    // Test Case 2
    vector<int> arr2 = {1, 4, 1, 5, 7, 3, 6, 1, 9, 9, 3};
    int k2 = 4;
    cout << "Test 2: " << sol.maxSumAfterPartitioning(arr2, k2) << endl;
    // Expected: 83

    // Test Case 3
    vector<int> arr3 = {1};
    int k3 = 1;
    cout << "Test 3: " << sol.maxSumAfterPartitioning(arr3, k3) << endl;
    // Expected: 1

    return 0;
}
    Top Down Approach :
    Time Complexity : O(n*l)
    Space Complexity : O(n)
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int n = arr.size();
        vector<int> dp(n + 1, 0);   

        for (int i = n - 1; i >= 0; i--) {

            int maxElement = 0;
            int ans = 0;

            for (int l = 1; l <= k && i + l <= n; l++) {

                maxElement = max(maxElement, arr[i + l - 1]);

                ans = max(ans,
                          maxElement * l + dp[i + l]);
            }

            dp[i] = ans;
        }

        return dp[0];
    }
};


int main() {
    Solution sol;

    // Test Case 1
    vector<int> arr1 = {1, 15, 7, 9, 2, 5, 10};
    int k1 = 3;
    cout << "Test 1: " << sol.maxSumAfterPartitioning(arr1, k1) << endl;
    // Expected: 84

    // Test Case 2
    vector<int> arr2 = {1, 4, 1, 5, 7, 3, 6, 1, 9, 9, 3};
    int k2 = 4;
    cout << "Test 2: " << sol.maxSumAfterPartitioning(arr2, k2) << endl;
    // Expected: 83

    // Test Case 3
    vector<int> arr3 = {1};
    int k3 = 1;
    cout << "Test 3: " << sol.maxSumAfterPartitioning(arr3, k3) << endl;
    // Expected: 1

    return 0;
}
    // Bottom Up Approach :
    // Time Complexity : O(n*l)
    // Space Complexity : O(n)