/*
#include<bits/stdc++.h>
using namespace std ; 


class Solution {
public:

    vector<vector<int>>memo ; 

    int solve(vector<int>&nums , int idx , int sum) {

        if(sum == 0)
        return true ;

        if(sum < 0 || idx >= nums.size())
        return false ; 

        if(memo[idx][sum] != -1)
        return memo[idx][sum] ; 

        // Pick the element 
        bool take = solve(nums , idx + 1 , sum - nums[idx]) ; 

        // Skip the element 
        bool skip = solve(nums ,  idx + 1 , sum )  ; 

        return memo[idx][sum] = take || skip ; 

    }
    bool canPartition(vector<int>& nums) {

        int n = nums.size() ; 

        int sum = 0  ; 

        for(int num : nums)
        sum += num ; 

        memo.resize(n + 1 , vector<int>(sum + 1 , -1)) ; 

        if(sum % 2 == 1) return false  ; 

        return solve(nums , 0 , sum / 2 ) ; 
        
    }
};


int main() {
    Solution obj;

    // Test Case 1 (Example)
    vector<int> nums1 = {1, 5, 11, 5};
    cout << "Test Case 1 Output: "
         << obj.canPartition(nums1) << endl;

    // Test Case 2 (Example)
    vector<int> nums2 = {1, 2, 3, 5};
    cout << "Test Case 2 Output: "
         << obj.canPartition(nums2) << endl;

    // Test Case 3 (Single element)
    vector<int> nums3 = {2};
    cout << "Test Case 3 Output: "
         << obj.canPartition(nums3) << endl;

    // Test Case 4 (All equal)
    vector<int> nums4 = {2, 2, 2, 2};
    cout << "Test Case 4 Output: "
         << obj.canPartition(nums4) << endl;

    // Test Case 5 (Large values)
    vector<int> nums5 = {100, 100};
    cout << "Test Case 5 Output: "
         << obj.canPartition(nums5) << endl;

    // Test Case 6 (Odd total sum)
    vector<int> nums6 = {1, 2, 3};
    cout << "Test Case 6 Output: "
         << obj.canPartition(nums6) << endl;

    // Test Case 7 (Edge case)
    vector<int> nums7 = {1, 1};
    cout << "Test Case 7 Output: "
         << obj.canPartition(nums7) << endl;

    return 0;
}

 Top Down Approach : 
 Time Complexity : O(n*sum)
 Space Complexity : O(n*sum)

*/

#include<bits/stdc++.h>
using namespace std ; 


class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int n = nums.size() ; 

        int sum = 0  ; 

        for(int num : nums)
        sum += num ; 
        
        if(sum % 2 == 1) 
        return false  ; 
        
        int target = sum / 2;
        
        vector<vector<int>>t(n + 1 , vector<int>(target + 1 , 0)) ; 


       for(int i = 0; i <= n; i++) {
            t[i][0] = 1;
        }

        for(int idx = n-1; idx >= 0; idx--) {

            for(int s = 0; s <= target; s++) {

                bool take = (s - nums[idx] >= 0) ? t[idx+1][s - nums[idx]] : 0;
                bool skip = t[idx+1][s];

                t[idx][s] = take || skip;
            }
        }

        return t[0][target] ; 
            
        
    }
};


int main() {
    Solution obj;

    // Test Case 1 (Example)
    vector<int> nums1 = {1, 5, 11, 5};
    cout << "Test Case 1 Output: "
         << obj.canPartition(nums1) << endl;

    // Test Case 2 (Example)
    vector<int> nums2 = {1, 2, 3, 5};
    cout << "Test Case 2 Output: "
         << obj.canPartition(nums2) << endl;

    // Test Case 3 (Single element)
    vector<int> nums3 = {2};
    cout << "Test Case 3 Output: "
         << obj.canPartition(nums3) << endl;

    // Test Case 4 (All equal)
    vector<int> nums4 = {2, 2, 2, 2};
    cout << "Test Case 4 Output: "
         << obj.canPartition(nums4) << endl;

    // Test Case 5 (Large values)
    vector<int> nums5 = {100, 100};
    cout << "Test Case 5 Output: "
         << obj.canPartition(nums5) << endl;

    // Test Case 6 (Odd total sum)
    vector<int> nums6 = {1, 2, 3};
    cout << "Test Case 6 Output: "
         << obj.canPartition(nums6) << endl;

    // Test Case 7 (Edge case)
    vector<int> nums7 = {1, 1};
    cout << "Test Case 7 Output: "
         << obj.canPartition(nums7) << endl;

    return 0;
}