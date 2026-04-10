/*
#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:

    int memo[21][2001] ;
    int offset  ;
    int solve(vector<int>& nums, int idx, int target){

        if(target + offset < 0 || target + offset >= 2001)
        return 0 ; 

        if(idx == 0){
           return (target - nums[idx] == 0) + (target + nums[idx] == 0) ;
        }

        if(memo[idx][target + offset] != -1)
        return memo[idx][target + offset] ; 

        int opt1 =  solve(nums,  idx - 1, target - nums[idx]) ; 
        int opt2 =  solve(nums , idx - 1, target + nums[idx]) ; 


        return memo[idx][target + offset] = opt1 + opt2 ; 
    }


    int findTargetSumWays(vector<int>& nums, int target) {
        
        memset(memo , -1 , sizeof(memo)) ; 

        int sum = accumulate(begin(nums) , end(nums) , 0) ; 

        offset = sum ; 
        
        return solve(nums , nums.size() - 1 , target) ; 
    }
};


int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1,1,1,1,1};
    int target1 = 3;
    int result1 = sol.findTargetSumWays(nums1, target1);
    cout << "Test Case 1 Output: " << result1 << endl;
    cout << "Expected Output: 5" << endl << endl;

    // Test Case 2
    vector<int> nums2 = {1};
    int target2 = 1;
    int result2 = sol.findTargetSumWays(nums2, target2);
    cout << "Test Case 2 Output: " << result2 << endl;
    cout << "Expected Output: 1" << endl << endl;

    // Additional Test Case 3
    vector<int> nums3 = {1,2,3};
    int target3 = 2;
    int result3 = sol.findTargetSumWays(nums3, target3);
    cout << "Test Case 3 Output: " << result3 << endl;
    cout << "Expected Output: 1" << endl << endl;

    return 0;
}
    Top Down Approach : 
    Time Complexity : O(N*target)
    Space Complexity : O(N*target)


#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:

    vector<vector<int>>memo ; 

    int solve(vector<int>& nums, int idx, int target){

        if(idx < 0){
            return target == 0 ;
        }

        if(memo[idx][target] != -1)
        return memo[idx][target];

        int skip = solve(nums, idx-1, target) ;
        int take = 0 ; 

        if(nums[idx] <= target){
            take += solve(nums, idx-1, target-nums[idx]) ;
        }

        return memo[idx][target] = take + skip ; 

    }


    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum = accumulate(begin(nums), end(nums), 0) ;

        if((sum + target) % 2 == 1 || (sum + target) < 0)
        return 0 ; 

        int newTarget = (sum + target) / 2;

        memo.resize(nums.size(), vector<int>(newTarget + 1, -1));

        return solve(nums, nums.size()-1, (sum+target)/2);
     
    }
};


int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1,1,1,1,1};
    int target1 = 3;
    int result1 = sol.findTargetSumWays(nums1, target1);
    cout << "Test Case 1 Output: " << result1 << endl;
    cout << "Expected Output: 5" << endl << endl;

    // Test Case 2
    vector<int> nums2 = {1};
    int target2 = 1;
    int result2 = sol.findTargetSumWays(nums2, target2);
    cout << "Test Case 2 Output: " << result2 << endl;
    cout << "Expected Output: 1" << endl << endl;

    // Additional Test Case 3
    vector<int> nums3 = {1,2,3};
    int target3 = 2;
    int result3 = sol.findTargetSumWays(nums3, target3);
    cout << "Test Case 3 Output: " << result3 << endl;
    cout << "Expected Output: 1" << endl << endl;

    return 0;
}

//    Top Down  : 
//    Time Complexity: O(n * S)
//    Space Complexity: O(n * S)

*/





#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:

    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum = accumulate(begin(nums), end(nums), 0) ;

        if((sum + target) % 2 == 1 || (sum + target) < 0)
        return 0 ; 

        int newTarget = (sum + target) / 2;

        vector<vector<int>>t(nums.size(), vector<int>(newTarget+1, 0));

        t[0][0] = 1 ;
        if(nums[0] <= newTarget)
            t[0][nums[0]] += 1;


        for(int idx = 1 ; idx < nums.size() ; idx ++){

            for(int tar = 0 ; tar <= newTarget ; tar ++){

                int skip = t[idx-1][tar] ;
                int take = 0 ; 

                if(nums[idx] <= tar){
                    take += t[idx-1][tar-nums[idx]] ;
                }

                t[idx][tar] = skip + take ; 
            }
        }

        return t[nums.size()-1][newTarget];
     
    }
};


int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1,1,1,1,1};
    int target1 = 3;
    int result1 = sol.findTargetSumWays(nums1, target1);
    cout << "Test Case 1 Output: " << result1 << endl;
    cout << "Expected Output: 5" << endl << endl;

    // Test Case 2
    vector<int> nums2 = {1};
    int target2 = 1;
    int result2 = sol.findTargetSumWays(nums2, target2);
    cout << "Test Case 2 Output: " << result2 << endl;
    cout << "Expected Output: 1" << endl << endl;

    // Additional Test Case 3
    vector<int> nums3 = {1,2,3};
    int target3 = 2;
    int result3 = sol.findTargetSumWays(nums3, target3);
    cout << "Test Case 3 Output: " << result3 << endl;
    cout << "Expected Output: 1" << endl << endl;

    return 0;
}
