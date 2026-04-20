/*
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int n;
    int memo[301][301];
    int solve(vector<int>& nums, int i, int j) {

        if(i > j) {
            return 0;
        }

        if(memo[i][j] != -1) {
            return memo[i][j];
        }

        int maxCoins = INT_MIN;

        for(int k = i ; k <= j ; k ++) {

            int coins = nums[i-1] * nums[k] * nums[j+1] 
                                  + solve(nums, i, k - 1)
                                  + solve(nums, k + 1, j);

            maxCoins = max(maxCoins, coins);
        }

        return memo[i][j] = maxCoins;
        
    }
    int maxCoins(vector<int>& nums) {

        memset(memo, -1 , sizeof(memo));
        
        nums.insert(begin(nums), 1);

        nums.push_back(1);

        n = nums.size();

        return solve(nums, 1, n-2);

    }
};



int main() {
    // Test cases: {input, expected output}
    Solution sol;

    vector<pair<vector<int>, int>> testCases = {
        {{3, 1, 5, 8}, 167},
        {{1, 5},        10},
        {{5},           5},
        {{0},           0},
    };

    int passed = 0;

    for (int i = 0; i < testCases.size(); i++) {
        vector<int> nums = testCases[i].first;  // copy so we don't mutate original
        int expected     = testCases[i].second;
        int result       = sol.maxCoins(nums);

        bool ok = (result == expected);
        if (ok) passed++;

        cout << "Test " << i + 1 << ": "
             << (ok ? "PASSED" : "FAILED")
             << " | Output: " << result
             << " | Expected: " << expected
             << "\n";
    }

    cout << "\n" << passed << "/" << testCases.size() << " tests passed.\n";

    return 0;
}

    Top Down Approach -
    Time Complexity : O(n^3)
    Space Complexity : O(n^2)
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int maxCoins(vector<int>& nums) {

        nums.insert(begin(nums), 1);

        nums.push_back(1);

        int n = nums.size();

        vector<vector<int>>dp(n, vector<int>(n, 0));

        for(int i = n-2; i >= 1; i--) {
            for(int j = i; j <= n-2; j++) {

                int maxCoins = 0;

                for(int k = i; k <= j; k++) {


                    int coins = nums[i-1] * nums[k] * nums[j+1]
                                + dp[i][k-1] + dp[k+1][j];

                    maxCoins = max(maxCoins, coins);
                }

                dp[i][j] = maxCoins;
            }
        }
        return dp[1][n-2];
    }
};



int main() {
    // Test cases: {input, expected output}
    Solution sol;

    vector<pair<vector<int>, int>> testCases = {
        {{3, 1, 5, 8}, 167},
        {{1, 5},        10},
        {{5},           5},
        {{0},           0},
    };

    int passed = 0;

    for (int i = 0; i < testCases.size(); i++) {
        vector<int> nums = testCases[i].first;  // copy so we don't mutate original
        int expected     = testCases[i].second;
        int result       = sol.maxCoins(nums);

        bool ok = (result == expected);
        if (ok) passed++;

        cout << "Test " << i + 1 << ": "
             << (ok ? "PASSED" : "FAILED")
             << " | Output: " << result
             << " | Expected: " << expected
             << "\n";
    }

    cout << "\n" << passed << "/" << testCases.size() << " tests passed.\n";

    return 0;
}
