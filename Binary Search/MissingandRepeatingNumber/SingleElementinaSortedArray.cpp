#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int n = nums.size();

        int low = 0;
        int high = n - 1;

        while(low < high) {

            int mid = low + (high - low) / 2;

            if(mid % 2 == 0) {

                if(nums[mid] == nums[mid + 1]) {

                    low = mid + 2;
                }
                else {

                    high = mid;
                }
            }
            else {

                if(nums[mid] == nums[mid - 1]) {

                    low = mid + 1;
                }
                else {

                    high = mid - 1;
                }
            }
        }

        return nums[low];
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1,1,2,3,3,4,4,8,8};

    cout << obj.singleNonDuplicate(nums);

    return 0;
}



/*
    Time Complexity : O(log(n))
    Space Complexity : O(1)
*/