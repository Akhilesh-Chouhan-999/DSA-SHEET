#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;

    long long countGood(vector<int>& nums, int k) {
        
        int n = nums.size();

        ll result = 0;
        ll pair = 0;
        unordered_map<int, int> freq;

        int i = 0;
        int j = 0;

        while(j < n) {

            pair += freq[nums[j]];
            freq[nums[j]] ++;

            while(pair >= k) {

                result += (n - j);


                if(--freq[nums[i]] == 0) {

                    freq.erase(nums[i]);
                }

                pair = (pair - freq[nums[i]]);
                i ++;
            }

            j ++;
        }


        return result;
    }
};



int main() {
    Solution sol;

    // Test Case 1: From the snippet [1,1,1,1,1], k=10
    vector<int> nums1 = {1, 1, 1, 1, 1};
    int k1 = 10;
    cout << "Test Case 1:" << endl;
    cout << "Input: nums = [1,1,1,1,1], k = " << k1 << endl;
    cout << "Output: " << sol.countGood(nums1, k1) << endl;
    cout << "Expected: 1" << endl << endl;

    // Test Case 2: From the snippet [3,1,4,3,2,2,4], k=2
    vector<int> nums2 = {3, 1, 4, 3, 2, 2, 4};
    int k2 = 2;
    cout << "Test Case 2:" << endl;
    cout << "Input: nums = [3,1,4,3,2,2,4], k = " << k2 << endl;
    cout << "Output: " << sol.countGood(nums2, k2) << endl;
    cout << "Expected: 1" << endl << endl;

    // Test Case 3: Custom case where k=1
    vector<int> nums3 = {1, 2, 3};
    int k3 = 1;
    cout << "Test Case 3:" << endl;
    cout << "Input: nums = [1,2,3], k = " << k3 << endl;
    cout << "Output: " << sol.countGood(nums3, k3) << endl;
    cout << "Expected: 0 (No duplicates)" << endl;

    return 0;
}


/*
    Time Complexity : O(n)
    Space Complexity : O(n)
*/