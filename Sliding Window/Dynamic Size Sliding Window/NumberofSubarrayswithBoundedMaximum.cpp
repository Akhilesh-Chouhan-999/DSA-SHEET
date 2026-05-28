#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {

        int n = nums.size();

        int i = 0;
        int j = 0;

        int result = 0;
        int prevCnt = 0;

        while(j < n) {

            int curr = nums[j];

            if(left <= curr && curr <= right) {

                prevCnt = j - i + 1;
                result += prevCnt;
            }

            else if(curr < left) {

                result += prevCnt;
            }

            else {

                i = j + 1;
                prevCnt = 0;
            }

            j ++;
        }

        return result;
    }
};




int main() {
    Solution sol;

    // Test Case 1: nums = [2,1,4,3], left = 2, right = 3
    // Expected subarrays: , [2,1],  → Total: 3
    vector<int> nums1 = {2, 1, 4, 3};
    int left1 = 2, right1 = 3;
    cout << "Test Case 1: " << endl;
    cout << "Input: nums = [2,1,4,3], left = 2, right = 3" << endl;
    cout << "Output: " << sol.numSubarrayBoundedMax(nums1, left1, right1) << endl;
    cout << "Expected: 3" << endl << endl;

    // Test Case 2: nums = [2,9,2,5,6], left = 2, right = 8
    // Expected subarrays: , [2,9] (invalid), , [2,5], [2,5,6] (invalid), , [5,6] (invalid),  (invalid)
    // Valid: , , [2,5],  → Total: 7
    vector<int> nums2 = {2, 9, 2, 5, 6};
    int left2 = 2, right2 = 8;
    cout << "Test Case 2: " << endl;
    cout << "Input: nums = [2,9,2,5,6], left = 2, right = 8" << endl;
    cout << "Output: " << sol.numSubarrayBoundedMax(nums2, left2, right2) << endl;
    cout << "Expected: 7" << endl;

    return 0;
}