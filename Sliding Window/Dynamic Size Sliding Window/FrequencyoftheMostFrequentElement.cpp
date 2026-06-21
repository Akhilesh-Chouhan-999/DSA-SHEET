#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        int n = nums.size();

        if(n == 0) {

            return 0;
        }

        sort(begin(nums), end(nums));

        int i = 0;
        int j = 0;
        int result = 1;

        int currSum = 0;

        while(j < n) {

            currSum += nums[j];

            while(i <= j && currSum + k < nums[j] * (j - i + 1)) {

                currSum -= nums[i];
                i ++;
            }

            result = max(result, j - i + 1);

            j ++;
        }

        return result;
    }
};



int main() {
    Solution sol;

    // Test Case 1: nums = [1,2,4], k = 5
    // Expected: 3
    {
        vector<int> nums = {1, 2, 4};
        int k = 5;
        cout << "Test 1 Input: [1, 2, 4], k = 5" << endl;
        cout << "Expected: 3, Got: " << sol.maxFrequency(nums, k) << endl << endl;
    }

    // Test Case 2: nums = [1,4,8,13], k = 5
    // Expected: 2
    {
        vector<int> nums = {1, 4, 8, 13};
        int k = 5;
        cout << "Test 2 Input: [1, 4, 8, 13], k = 5" << endl;
        cout << "Expected: 2, Got: " << sol.maxFrequency(nums, k) << endl << endl;
    }

    // Test Case 3: nums = [3,9,6], k = 2
    // Expected: 2 (Note: Input in screenshot is unsorted, algorithm sorts it to [3,6,9])
    // With k=2, we can make [3, 6] -> [6, 6] (cost 3 > 2, no). 
    // Actually, let's trace: sorted [3, 6, 9]. 
    // Window [3, 6]: target 6. Need (6-3)=3. k=2. Fail. Max len 1? 
    // Wait, screenshot says Expected 2 for [3,9,6] k=2.
    // Let's re-read screenshot output. 
    // Output column says: 1, 2, 3. Expected column says: 1, 2, 3.
    // Ah, the screenshot input/output mapping:
    // Case 1: [1,2,4] k=5 -> 3
    // Case 2: [1,4,8,13] k=5 -> 2
    // Case 3: [3,9,6] k=2 -> 2? 
    // Let's check logic: [3, 6, 9] sorted.
    // Window [3, 6]: cost to make 6 is 3. k=2. Invalid.
    // Window [6, 9]: cost to make 9 is 3. k=2. Invalid.
    // Maybe the screenshot expected output for the 3rd case is actually 1?
    // Looking at the screenshot text: 
    // Output: 1, 2, 3 (This looks like the row numbers 1, 2, 3)
    // Then the actual values:
    // Input: [3,9,6] k=2 -> Expected: 2? 
    // Let's trust the algorithm. If k=2, [3,6] needs 3. [6,9] needs 3.
    // Perhaps the screenshot shows Expected: 2 for a different input or I am misreading the alignment.
    // However, the code I will run is exactly the one submitted and accepted.
    
    // Let's run the code on the 3rd case:
    {
        vector<int> nums = {3, 9, 6};
        int k = 2;
        cout << "Test 3 Input: [3, 9, 6], k = 2" << endl;
        cout << "Expected (from screenshot): 2, Got: " << sol.maxFrequency(nums, k) << endl;
    }

    return 0;
}


/*
    Time Complexity : O(n*log(n))
    Space Complexity : O(1)
*/

