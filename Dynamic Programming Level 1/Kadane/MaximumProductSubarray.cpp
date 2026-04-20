#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();

        int result = INT_MIN;

        int prefix = 1;
        int suffix = 1;

        for(int i = 0; i < n; i ++) {

            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;

            prefix *= nums[i];
            suffix *= nums[n - i - 1];

            result = max(result, max(prefix, suffix));
        }

        return result;
    }
};

int main() {

    Solution obj;

    vector<vector<int>> testCases = {
        {2, 3, -2, 4},              // Expected: 6
        {-2, 0, -1},                // Expected: 0
        {-3, -1, -1},               // Expected: 3
        {-3, 0, 1, -2},             // Expected: 1
        {7, -2, -4},                // Expected: 56
        {7, -2, 5, -4},             // Expected: 280
        {2, -5, -2, -4, 3},         // Expected: 24
        {2, -5, -2, -4, -6, 3},     // Expected: 1440
        {2, -5, -2, 8, -4, -6, 3},  // Expected: 5760
        {0, 10, 10, 10, -10, 10},   // Expected: 10000
        {-1},                       // Expected: -1
        {0, 0, 0},                  // Expected: 0
        {-2, -3, -4},               // Expected: 12
        {1, -2, 3, -4, 5, -6},      // Expected: 720
    };



    vector<int> expected = {
        6, 0, 3, 1, 56, 280, 24, 1440, 11520, 1000, -1, 0, 12, 360
    };

    for(int i = 0; i < testCases.size(); i++) {
        int ans = obj.maxProduct(testCases[i]);

        cout << "Test Case " << i + 1 << ": ";
        cout << "Output = " << ans 
             << ", Expected = " << expected[i];

        if(ans == expected[i]) cout << ", PASS ";
        else cout << ", FAIL ";

        cout << endl;
    }

    return 0;
}

/*
    Time Complexity  : O(n)
    Space Complexity : O(1)
*/