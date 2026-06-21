#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool canSplit(vector<int>&nums, int k, int maxSum) {

        int cntSubArr = 1;

        int currSum = 0;

        for(int i = 0; i < nums.size(); i ++) {

            currSum += nums[i];

            if(currSum > maxSum) {

                cntSubArr ++;
                currSum = nums[i];
            }

            if(cntSubArr > k) {

                return false;
            }
            
        }

        return cntSubArr <= k;
    }

    int splitArray(vector<int>& nums, int k) {

        int n = nums.size();

       int low = *max_element(begin(nums), end(nums));
       int high = accumulate(begin(nums), end(nums), 0);
       int ans;

       while(low <= high) {

            int mid = low + (high - low) / 2;

            if(canSplit(nums, k, mid)) {

                ans = mid;
                high = mid - 1;
            }

            else {

                low = mid + 1;
            }
        }

        return ans;
    }
};



// Helper function to parse a string like "[1,2,3]" into a vector<int>
vector<int> parseArray(string s) {
    vector<int> result;
    // Remove brackets
    if (s.front() == '[') s.erase(0, 1);
    if (s.back() == ']') s.pop_back();

    stringstream ss(s);
    string item;
    while (getline(ss, item, ',')) {
        result.push_back(stoi(item));
    }
    return result;
}

int main() {
    Solution sol;

    // Test Case 1 from your "Wrong Answer" section
    // Input: nums = [1,2,3,4,5], k = 2
    // Expected: 9 (Your code output 6)
    {
        string numsStr = "[1,2,3,4,5]";
        int k = 2;
        vector<int> nums = parseArray(numsStr);
        int result = sol.splitArray(nums, k);
        cout << "Test Case 1:" << endl;
        cout << "Input: nums = [1,2,3,4,5], k = 2" << endl;
        cout << "Output: " << result << endl;
        cout << "Expected: 9" << endl;
        cout << "Status: " << (result == 9 ? "PASS" : "FAIL") << endl << endl;
    }

    // Test Case 2 from your "Wrong Answer" section
    // Input: nums = [7,2,5,10,8], k = 2
    // Expected: 18
    {
        string numsStr = "[7,2,5,10,8]";
        int k = 2;
        vector<int> nums = parseArray(numsStr);
        int result = sol.splitArray(nums, k);
        cout << "Test Case 2:" << endl;
        cout << "Input: nums = [7,2,5,10,8], k = 2" << endl;
        cout << "Output: " << result << endl;
        cout << "Expected: 18" << endl;
        cout << "Status: " << (result == 18 ? "PASS" : "FAIL") << endl << endl;
    }

    return 0;
}