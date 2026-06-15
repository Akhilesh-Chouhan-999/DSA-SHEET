#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();

        int low = 0;
        int high = n - 1; 

        int ans = INT_MAX;

        for(int i = 0; i < n; i ++) {

            int mid = low + (high - low) / 2;

            if(nums[low] == nums[mid] && nums[mid] == nums[high]) {

                ans = min(ans, nums[low]);
                low ++;
                high --;
            }

            else if(nums[low] <= nums[mid]) {

                ans = min(ans, nums[low]);
                low = mid + 1;
            }

            else {

                ans = min(ans, nums[mid]);
                high = mid - 1;
            }

        }
        
        return ans;
    }
};


int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {3, 4, 5, 1, 2};
    cout << "Input: [3, 4, 5, 1, 2]" << endl;
    cout << "Output: " << sol.findMin(nums1) << endl;
    cout << "Expected: 1" << endl << endl;

    // Test Case 2
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    cout << "Input: [4, 5, 6, 7, 0, 1, 2]" << endl;
    cout << "Output: " << sol.findMin(nums2) << endl;
    cout << "Expected: 0" << endl << endl;

    // Test Case 3
    vector<int> nums3 = {11, 13, 15, 17};
    cout << "Input: [11, 13, 15, 17]" << endl;
    cout << "Output: " << sol.findMin(nums3) << endl;
    cout << "Expected: 11" << endl;

    return 0;
}

/*
    Time Complexity : O(n)
    Space Complexity : O(1)
*/