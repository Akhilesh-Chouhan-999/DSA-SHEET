#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int n = nums.size();

        int i = 0;
        int j = 0;
        int maxLength = INT_MIN;

        int target = accumulate(begin(nums), end(nums), 0) - x;
        int currSum = 0;

        while(j < n) {

            currSum += nums[j];

            while(i <= j && currSum > target) {

                currSum -= nums[i];

                i ++;
            }

            if(currSum == target) {

                maxLength = max(maxLength, j - i + 1);
            }
            
            j ++;
        }

        if(maxLength == INT_MIN) {

            return -1;
        }

        return n - maxLength;
    }
};


// Helper function to print a vector
void printVector(const vector<int>& nums) {
    cout << "[";
    for (size_t k = 0; k < nums.size(); ++k) {
        cout << nums[k];
        if (k < nums.size() - 1) cout << ", ";
    }
    cout << "]";
}


int main() {
    Solution sol;

    // Test Case 1: From the error log in the page
    {
        vector<int> nums = {5, 6, 7, 8, 9};
        int x = 4;
        cout << "Input: nums = ";
        printVector(nums);
        cout << ", x = " << x << endl;
        cout << "Output: " << sol.minOperations(nums, x) << endl;
        cout << "Expected: -1 (since 4 cannot be formed by removing prefix/suffix)" << endl << endl;
    }

    // Test Case 2: A valid case
    {
        vector<int> nums = {1, 1, 4, 2, 3};
        int x = 5;
        cout << "Input: nums = ";
        printVector(nums);
        cout << ", x = " << x << endl;
        cout << "Output: " << sol.minOperations(nums, x) << endl;
        cout << "Expected: 2 (remove 1,1 from left or 2,3 from right)" << endl << endl;
    }

    // Test Case 3: Another valid case
    {
        vector<int> nums = {5, 6, 7, 8, 9};
        int x = 4; 
        // Note: The original error log used this input but expected -1.
        // Let's try a case where it works: x = 15 (remove 6+9 or 5+6+4? no 4)
        // Let's try x = 5 (remove 5) -> operations = 1
        nums = {5, 6, 7, 8, 9};
        x = 5;
        cout << "Input: nums = ";
        printVector(nums);
        cout << ", x = " << x << endl;
        cout << "Output: " << sol.minOperations(nums, x) << endl;
        cout << "Expected: 1 (remove 5)" << endl << endl;
    }

    return 0;
}