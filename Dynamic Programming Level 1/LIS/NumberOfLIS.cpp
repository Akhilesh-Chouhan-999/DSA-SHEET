#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    unordered_map<int, pair<int,int>>memo ; 

    pair<int,int> solve(vector<int>& nums, int idx) {

        if(memo.count(idx))
        return memo[idx] ; 

        int maxLength = 1; 
        int freq = 1; 

        for(int prev = idx - 1; prev >= 0; prev--) {

            if(nums[prev] < nums[idx]) {

                auto [len, f] = solve(nums, prev);

                if(len + 1 > maxLength){
                    maxLength = len + 1; 
                    freq = f; 
                }
                else if(len + 1 == maxLength){
                    freq += f; 
                }
            }
        }

        return memo[idx] =  {maxLength , freq}; 
        
    }

    int findNumberOfLIS(vector<int>& nums) {

        int n = nums.size();

        int freq = 0;
        int maxLen = 1;

        for(int i = 0; i < n; i++) {

            auto [len, f] = solve(nums, i);

            if(len > maxLen) {
                maxLen = len;
                freq = f;
            }
            else if(len == maxLen) {
                freq += f;
            }
        }

        return freq;
    }
};


int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1, 3, 5, 4, 7};
    cout << "Test 1 Output: " << sol.findNumberOfLIS(nums1) << endl;
    // Expected: 2

    // Test Case 2
    vector<int> nums2 = {2, 2, 2, 2, 2};
    cout << "Test 2 Output: " << sol.findNumberOfLIS(nums2) << endl;
    // Expected: 5

    // Test Case 3 (increasing)
    vector<int> nums3 = {1, 2, 3, 4};
    cout << "Test 3 Output: " << sol.findNumberOfLIS(nums3) << endl;
    // Expected: 1

    // Test Case 4 (decreasing)
    vector<int> nums4 = {5, 4, 3, 2, 1};
    cout << "Test 4 Output: " << sol.findNumberOfLIS(nums4) << endl;
    // Expected: 5

    // Test Case 5 (mixed tricky)
    vector<int> nums5 = {1, 2, 4, 3, 5, 4, 7, 2};
    cout << "Test 5 Output: " << sol.findNumberOfLIS(nums5) << endl;
    // Expected: 3

    // Test Case 6 (single element)
    vector<int> nums6 = {10};
    cout << "Test 6 Output: " << sol.findNumberOfLIS(nums6) << endl;
    // Expected: 1

    return 0;
}