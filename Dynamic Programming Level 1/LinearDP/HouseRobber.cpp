/*
#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:

    int memo[101] ;
    int solve(vector<int>&nums , int idx){

        if(idx >= nums.size()){
            return 0 ; 
        }


        if(memo[idx] != -1)
        return memo[idx] ; 


        int maxAmount = 0 ; 

        int take = nums[idx] + solve(nums , idx + 2) ; 
        int skip = solve(nums , idx + 1) ; 

       return memo[idx] = maxAmount = max(maxAmount , max(take , skip)) ; 

    }

    int rob(vector<int>& nums) {

        memset(memo , -1 , sizeof(memo))  ; 
        return solve(nums , 0) ; 

    }
};


int main() {
    Solution obj;

    // Test Case 1 (Example)
    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Test Case 1 Output: "
         << obj.rob(nums1) << endl;

    // Test Case 2 (Example)
    vector<int> nums2 = {2, 7, 9, 3, 1};
    cout << "Test Case 2 Output: "
         << obj.rob(nums2) << endl;

    // Test Case 3 (Single house)
    vector<int> nums3 = {5};
    cout << "Test Case 3 Output: "
         << obj.rob(nums3) << endl;

    // Test Case 4 (All zero)
    vector<int> nums4 = {0, 0, 0, 0};
    cout << "Test Case 4 Output: "
         << obj.rob(nums4) << endl;

    // Test Case 5 (Alternating high-low)
    vector<int> nums5 = {10, 1, 10, 1, 10};
    cout << "Test Case 5 Output: "
         << obj.rob(nums5) << endl;

    // Test Case 6 (Strictly increasing)
    vector<int> nums6 = {1, 2, 3, 4, 5};
    cout << "Test Case 6 Output: "
         << obj.rob(nums6) << endl;

    // Test Case 7 (Strictly decreasing)
    vector<int> nums7 = {9, 8, 7, 6, 5};
    cout << "Test Case 7 Output: "
         << obj.rob(nums7) << endl;

    // Test Case 8 (Mixed values)
    vector<int> nums8 = {4, 1, 2, 7, 5, 3, 1};
    cout << "Test Case 8 Output: "
         << obj.rob(nums8) << endl;

    // Test Case 9 (Edge case - two houses)
    vector<int> nums9 = {2, 3};
    cout << "Test Case 9 Output: "
         << obj.rob(nums9) << endl;

    // Test Case 10 (Large values)
    vector<int> nums10 = {100, 400, 100, 400, 100};
    cout << "Test Case 10 Output: "
         << obj.rob(nums10) << endl;

    return 0;
}
Top Down Approach :
Time complexity : O(n)
Space Complexity : O(n)




#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:

   

    int rob(vector<int>& nums) {

        int n = nums.size()  ;

        vector<int>dp(n+2 , 0) ; 

        for(int idx = n - 1 ; idx >= 0 ; idx --){

             int take = nums[idx] + dp[idx + 2] ; 
             int skip = dp[idx+1] ;
             
             dp[idx] = max(take ,skip) ; 
        }

        return dp[0] ; 

    }
};


int main() {
    Solution obj;

    // Test Case 1 (Example)
    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Test Case 1 Output: "
         << obj.rob(nums1) << endl;

    // Test Case 2 (Example)
    vector<int> nums2 = {2, 7, 9, 3, 1};
    cout << "Test Case 2 Output: "
         << obj.rob(nums2) << endl;

    // Test Case 3 (Single house)
    vector<int> nums3 = {5};
    cout << "Test Case 3 Output: "
         << obj.rob(nums3) << endl;

    // Test Case 4 (All zero)
    vector<int> nums4 = {0, 0, 0, 0};
    cout << "Test Case 4 Output: "
         << obj.rob(nums4) << endl;

    // Test Case 5 (Alternating high-low)
    vector<int> nums5 = {10, 1, 10, 1, 10};
    cout << "Test Case 5 Output: "
         << obj.rob(nums5) << endl;

    // Test Case 6 (Strictly increasing)
    vector<int> nums6 = {1, 2, 3, 4, 5};
    cout << "Test Case 6 Output: "
         << obj.rob(nums6) << endl;

    // Test Case 7 (Strictly decreasing)
    vector<int> nums7 = {9, 8, 7, 6, 5};
    cout << "Test Case 7 Output: "
         << obj.rob(nums7) << endl;

    // Test Case 8 (Mixed values)
    vector<int> nums8 = {4, 1, 2, 7, 5, 3, 1};
    cout << "Test Case 8 Output: "
         << obj.rob(nums8) << endl;

    // Test Case 9 (Edge case - two houses)
    vector<int> nums9 = {2, 3};
    cout << "Test Case 9 Output: "
         << obj.rob(nums9) << endl;

    // Test Case 10 (Large values)
    vector<int> nums10 = {100, 400, 100, 400, 100};
    cout << "Test Case 10 Output: "
         << obj.rob(nums10) << endl;

    return 0;
}


*/



#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:

   

    int rob(vector<int>& nums) {

        int n = nums.size()  ;

        int next1 = 0 ; 
        int next2 = 0 ; 

        for(int idx = n - 1 ; idx >= 0 ; idx --){

             int take = nums[idx] + next2 ; 
             int skip = next1 ;

             int curr = max(next1 , next2) ; 
             
             next2 = next1;
             next1 = curr ;  
        }

        return next1 ; 

    }
};


int main() {
    Solution obj;

    // Test Case 1 (Example)
    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Test Case 1 Output: "
         << obj.rob(nums1) << endl;

    // Test Case 2 (Example)
    vector<int> nums2 = {2, 7, 9, 3, 1};
    cout << "Test Case 2 Output: "
         << obj.rob(nums2) << endl;

    // Test Case 3 (Single house)
    vector<int> nums3 = {5};
    cout << "Test Case 3 Output: "
         << obj.rob(nums3) << endl;

    // Test Case 4 (All zero)
    vector<int> nums4 = {0, 0, 0, 0};
    cout << "Test Case 4 Output: "
         << obj.rob(nums4) << endl;

    // Test Case 5 (Alternating high-low)
    vector<int> nums5 = {10, 1, 10, 1, 10};
    cout << "Test Case 5 Output: "
         << obj.rob(nums5) << endl;

    // Test Case 6 (Strictly increasing)
    vector<int> nums6 = {1, 2, 3, 4, 5};
    cout << "Test Case 6 Output: "
         << obj.rob(nums6) << endl;

    // Test Case 7 (Strictly decreasing)
    vector<int> nums7 = {9, 8, 7, 6, 5};
    cout << "Test Case 7 Output: "
         << obj.rob(nums7) << endl;

    // Test Case 8 (Mixed values)
    vector<int> nums8 = {4, 1, 2, 7, 5, 3, 1};
    cout << "Test Case 8 Output: "
         << obj.rob(nums8) << endl;

    // Test Case 9 (Edge case - two houses)
    vector<int> nums9 = {2, 3};
    cout << "Test Case 9 Output: "
         << obj.rob(nums9) << endl;

    // Test Case 10 (Large values)
    vector<int> nums10 = {100, 400, 100, 400, 100};
    cout << "Test Case 10 Output: "
         << obj.rob(nums10) << endl;

    return 0;
}

// Time Complexity : O(n)
// Space Complexity : O(1)