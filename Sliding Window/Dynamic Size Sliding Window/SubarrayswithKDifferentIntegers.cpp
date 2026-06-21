#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int cntsubarraysWithKDistinct(vector<int>& nums, int k) {

        int n = nums.size();

        unordered_map<int, int> freq;

        int i = 0;
        int j = 0;
        int cnt = 0;

        while(j < n) {

            freq[nums[j]]++;

            while(freq.size() > k) {

                if(--freq[nums[i]] == 0) {
                    freq.erase(nums[i]);
                }

                i++;
            }

            cnt += (j - i + 1);

            j++;
        }

        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return cntsubarraysWithKDistinct(nums, k) - cntsubarraysWithKDistinct(nums, k - 1);
    }
};

int main() {
    Solution obj;

    vector<int> nums1 = {1, 2, 1, 2, 3};
    int k1 = 2;
    cout << obj.subarraysWithKDistinct(nums1, k1) << endl; // Output: 7
    cout << "Expected : 7" << endl;

    vector<int> nums2 = {1, 2, 1, 3, 4};
    int k2 = 3;
    cout << obj.subarraysWithKDistinct(nums2, k2) << endl; // Output: 3
    cout << "Expected : 3" << endl;

    return 0;
}