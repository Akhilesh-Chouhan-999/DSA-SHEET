#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int n = nums.size();

        if(k <= 1) {

            return 0;
        }

        int i = 0;
        int j = 0;

        int product = 1;
        int cnt = 0;

        while(j < n) {

            product *= nums[j];

            while(i < n && product >= k) {

                product = (product / nums[i]);
                i ++;
            }

            cnt += (j - i + 1);

            j ++;
            
        }

        return cnt;
    }
};



int main() {
    Solution sol;
    
    // Test Case 1: [10,5,2,6], k = 100
    vector<int> nums1 = {10, 5, 2, 6};
    int k1 = 100;
    cout << "Test 1 Output: " << sol.numSubarrayProductLessThanK(nums1, k1) << " (Expected: 8)" << endl;

    // Test Case 2: [1,2,3], k = 0
    vector<int> nums2 = {1, 2, 3};
    int k2 = 0;
    cout << "Test 2 Output: " << sol.numSubarrayProductLessThanK(nums2, k2) << " (Expected: 0)" << endl;

    return 0;
}