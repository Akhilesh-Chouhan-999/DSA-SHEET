#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();

        int low = 0;
        int high = n - 1;


        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(nums[mid] == target) {

                return mid;
            }

            else if(nums[low] <= nums[mid]) {

                if(nums[low] <= target && target < nums[mid]) {

                    high = mid - 1;
                }
                else {

                    low = mid + 1;
                }
            }

            else{

                if(nums[mid] < target && target <= nums[high]) {

                    low = mid + 1;
                }

                else {

                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};


int main() {
    Solution sol;
    vector<int> nums;
    int target;

    // Example 1
    nums = {4, 5, 6, 7, 0, 1, 2};
    target = 0;
    cout << "Input: nums = [4,5,6,7,0,1,2], target = 0" << endl;
    cout << "Output: " << sol.search(nums, target) << endl; // Expected: 4
    cout << endl;

    // Example 2
    nums = {4, 5, 6, 7, 0, 1, 2};
    target = 3;
    cout << "Input: nums = [4,5,6,7,0,1,2], target = 3" << endl;
    cout << "Output: " << sol.search(nums, target) << endl; // Expected: -1
    cout << endl;

    // Example 3
    nums = {1};
    target = 0;
    cout << "Input: nums = , target = 0" << endl;
    cout << "Output: " << sol.search(nums, target) << endl; // Expected: -1

    return 0;
}

/*
    Time Complexity : O(log(n))
    Space Complexity : O(1)
*/