#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        
        int n = nums.size();

        int start = 0;
        int end = n - 1;
        int ans;

        while(start <= end) {

            int mid = start + (end - start) / 2;

            if(mid + 1 < n && nums[mid] < nums[mid + 1]) {

                start = mid + 1;
            }

            else {

                ans = mid;
                end = mid - 1;
            }
        }

        return ans;
    }
};

/*
    Time Complexity : O(log(n))
    Space Complexity : O(1)
*/