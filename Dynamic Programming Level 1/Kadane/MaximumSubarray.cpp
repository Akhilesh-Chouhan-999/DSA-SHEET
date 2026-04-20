#include<bits/stdc++.h>
using namespace std;

class Solution {
public:  
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();

        int maxEndingSoFar = nums[0];
        int result = nums[0];

        for(int i = 1; i < n; i ++) {

            maxEndingSoFar = max(nums[i], maxEndingSoFar + nums[i]);

            result = max(result, maxEndingSoFar);
        }

        return result;
    }
};


int main() {
    Solution sol;

    // Test Case 1: Mixed positive and negative numbers
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Test 1: " << sol.maxSubArray(nums1) << endl; // Expected: 6

    // Test Case 2: All negative numbers
    vector<int> nums2 = {-3, -1, -2, -4};
    cout << "Test 2: " << sol.maxSubArray(nums2) << endl; // Expected: -1

    // Test Case 3: All positive numbers
    vector<int> nums3 = {1, 2, 3, 4, 5};
    cout << "Test 3: " << sol.maxSubArray(nums3) << endl; // Expected: 15

    // Test Case 4: Single element
    vector<int> nums4 = {7};
    cout << "Test 4: " << sol.maxSubArray(nums4) << endl; // Expected: 7

    // Test Case 5: Single negative element
    vector<int> nums5 = {-7};
    cout << "Test 5: " << sol.maxSubArray(nums5) << endl; // Expected: -7

    return 0;
}


// Time Complexity : O(n)
// Space Complexity : O(n)