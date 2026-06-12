#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int n = nums.size();
        
        int low = 0;
        int high = n - 1;
        int ans = -1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(mid + 1 < n && nums[mid] < nums[mid + 1]) {

                low = mid + 1;
            }
            else {

                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main() {
    // Test Case 1: From your screenshot
    vector<int> nums1 = {1, 2, 3, 1};
    
    // Test Case 2: From your screenshot
    vector<int> nums2 = {1, 2, 1, 3, 5, 6, 4};

    Solution sol;

    cout << "Test Case 1: ";
    for (int num : nums1) cout << num << " ";
    cout << "\nPeak Index: " << sol.findPeakElement(nums1) << " (Expected: 2)\n\n";

    cout << "Test Case 2: ";
    for (int num : nums2) cout << num << " ";
    cout << "\nPeak Index: " << sol.findPeakElement(nums2) << " (Expected: 2 or 5)\n";

    return 0;
}
