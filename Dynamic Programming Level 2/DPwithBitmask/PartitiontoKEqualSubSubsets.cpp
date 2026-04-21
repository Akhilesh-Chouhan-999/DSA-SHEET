/*
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<int>memo;
    bool solve(vector<int>& nums, int currSum, int mask, int k, int target) {

        if(k == 0) {
            return true;
        }

        if(currSum == target) {
            return solve(nums, 0, mask, k - 1, target);
        }


        for(int i = 0; i < n; i ++) {
            
            if(mask & (1 << i)) {
                continue;
            }

            if(currSum + nums[i] > target)
            continue;

            int newMask = mask | (1 << i);

            if(solve(nums, currSum + nums[i], newMask, k, target))
            return true;

        }

        return false;

    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        this -> n = nums.size();

        int sum = accumulate(begin(nums), end(nums), 0);

        if(sum % k != 0) return false;

        int target = sum / k;

        return solve(nums, 0, 0, k, target);

    }
};

int main() {
    Solution sol;

    // { input nums, k, expected output }
    vector<pair<pair<vector<int>, int>, bool>> testCases = {
        { { {4, 3, 2, 3, 5, 2, 1}, 4 }, true  },  // Example 1
        { { {1, 2, 3, 4},          3 }, false },  // Example 2
        { { {2, 2, 2, 2, 3, 4, 5}, 4 }, false },  // Not divisible evenly
        { { {1, 1, 1, 1, 1, 1},    3 }, true  },  // All ones, k=3
        { { {10,1,10,9,6,1,9,5,9,10,7,8,5,2,10,8}, 11 }, true }, // Stress case
    };

    int passed = 0;
    for (int i = 0; i < (int)testCases.size(); i++) {
        auto& input             = testCases[i].first;
        auto& expected          = testCases[i].second;
        auto& nums              = input.first;
        auto& k                 = input.second;

        vector<int> numsCopy = nums; // solve modifies via sort
        bool result = sol.canPartitionKSubsets(numsCopy, k);

        bool ok = (result == expected);
        passed += ok;

        cout << "Test " << i + 1 << ": "
             << (ok ? "PASSED" : "FAILED")
             << " | Output: " << (result   ? "true" : "false")
             << " | Expected: " << (expected ? "true" : "false")
             << "\n";
    }

    cout << "\n" << passed << "/" << testCases.size() << " tests passed.\n";
    return 0;
}

*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int n = nums.size();

        int sum = accumulate(begin(nums), end(nums), 0);

        if(sum % k != 0) return false;

        int target = sum / k;


        

        

    }
};

int main() {
    Solution sol;

    // { input nums, k, expected output }
    vector<pair<pair<vector<int>, int>, bool>> testCases = {
        { { {4, 3, 2, 3, 5, 2, 1}, 4 }, true  },  // Example 1
        { { {1, 2, 3, 4},          3 }, false },  // Example 2
        { { {2, 2, 2, 2, 3, 4, 5}, 4 }, false },  // Not divisible evenly
        { { {1, 1, 1, 1, 1, 1},    3 }, true  },  // All ones, k=3
        { { {10,1,10,9,6,1,9,5,9,10,7,8,5,2,10,8}, 11 }, true }, // Stress case
    };

    int passed = 0;
    for (int i = 0; i < (int)testCases.size(); i++) {
        auto& input             = testCases[i].first;
        auto& expected          = testCases[i].second;
        auto& nums              = input.first;
        auto& k                 = input.second;

        vector<int> numsCopy = nums; // solve modifies via sort
        bool result = sol.canPartitionKSubsets(numsCopy, k);

        bool ok = (result == expected);
        passed += ok;

        cout << "Test " << i + 1 << ": "
             << (ok ? "PASSED" : "FAILED")
             << " | Output: " << (result   ? "true" : "false")
             << " | Expected: " << (expected ? "true" : "false")
             << "\n";
    }

    cout << "\n" << passed << "/" << testCases.size() << " tests passed.\n";
    return 0;
}