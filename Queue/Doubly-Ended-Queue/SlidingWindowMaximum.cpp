#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();

        vector<int> result;

        deque<int> dq;

        for(int i = 0; i < n; i ++) {

            while(!dq.empty() && dq.front() <= i - k) {

                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.front()] < nums[i]) {

                dq.pop_back();
            }

            dq.push_back(i);

            if(i + 1 >= k) {

                result.push_back(nums[dq.front()]);
            }

        }

        return result;

    }
};


int main() {
    // Test Case 1
    vector<int> nums1 = {1, 3, -1, -3, 5, 3, 6, 7};
    int k1 = 3;
    
    Solution sol;
    vector<int> result1 = sol.maxSlidingWindow(nums1, k1);
    
    cout << "Input: nums = [1,3,-1,-3,5,3,6,7], k = 3" << endl;
    cout << "Output: [";
    for (int i = 0; i < result1.size(); ++i) {
        cout << result1[i];
        if (i < result1.size() - 1) cout << ", ";
    }
    cout << "]" << endl << endl;

}