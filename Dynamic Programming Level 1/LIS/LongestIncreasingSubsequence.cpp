/*
#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:


    // Longest Increasing Subsequence ending at i . 

    int solve(vector<int>& nums, int idx, vector<int>& memo) {

        if(idx == 0)
        return 1 ; 

        if(memo[idx] != -1)
        return memo[idx] ; 

        int maxLength = 1 ; 

        for(int j = idx - 1 ; j >= 0 ; j --){
            if(nums[j] < nums[idx]){
                maxLength = max(maxLength , 1 + solve(nums, j, memo));
            }
        }

        return memo[idx] = maxLength ; 
       
    }

    int lengthOfLIS(vector<int>& nums) {

        int result = 1 ; 

        vector<int>memo(nums.size() , -1) ; 

        for(int i = 1 ; i < nums.size() ; i ++ ){

            result = max(result, solve(nums, i, memo)) ; 

        }

        return result ; 

    }
};


int main() {

    Solution sol;

    // Test Case 1
    vector<int> nums1 = {10,9,2,5,3,7,101,18};
    cout << "Output 1: " << sol.lengthOfLIS(nums1) << endl;

    // Test Case 2
    vector<int> nums2 = {0,1,0,3,2,3};
    cout << "Output 2: " << sol.lengthOfLIS(nums2) << endl;

    // Test Case 3
    vector<int> nums3 = {7,7,7,7,7,7,7};
    cout << "Output 3: " << sol.lengthOfLIS(nums3) << endl;

    return 0;
}

    
Top Down Approach : 
Time Complexity : O(n^2)
Space Complexity : O(n)



#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size() ; 

        vector<int>t(n, 0) ;

        t[0] = 1 ; 
        
        for(int idx = 1 ; idx < n ; idx ++){

            int maxLength = 1 ; 

            for(int j = idx - 1 ; j >= 0 ; j --){

                if(nums[j] < nums[idx]){
                    maxLength = max(maxLength , 1 + t[j]);
                }

            }

            t[idx] = maxLength ; 

        }

        return *max_element(begin(t) , end(t)) ; 
    }
};


int main() {

    Solution sol;

    // Test Case 1
    vector<int> nums1 = {10,9,2,5,3,7,101,18};
    cout << "Output 1: " << sol.lengthOfLIS(nums1) << endl;

    // Test Case 2
    vector<int> nums2 = {0,1,0,3,2,3};
    cout << "Output 2: " << sol.lengthOfLIS(nums2) << endl;

    // Test Case 3
    vector<int> nums3 = {7,7,7,7,7,7,7};
    cout << "Output 3: " << sol.lengthOfLIS(nums3) << endl;

    return 0;
}
    Bottom Up Approach :
    Time Complexity : O(n^2)
    Space Complexity : O(n)
*/




#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size() ; 

        vector<int>tail ; 

        int maxLength = 1 ; 

        for(int num : nums){

            if(tail.empty()){
                tail.push_back(num);
            }
            else{
                
                auto it = lower_bound(begin(tail), end(tail), num) ; 
                
                if(it == end(tail)){
                    tail.push_back(num);
                }
                else{
                    *it = num;
                }
            }

            maxLength = max(maxLength, (int)tail.size()) ;
        }

        return maxLength ; 
        
    }
};


int main() {

    Solution sol;

    // Test Case 1
    vector<int> nums1 = {10,9,2,5,3,7,101,18};
    cout << "Output 1: " << sol.lengthOfLIS(nums1) << endl;

    // Test Case 2
    vector<int> nums2 = {0,1,0,3,2,3};
    cout << "Output 2: " << sol.lengthOfLIS(nums2) << endl;

    // Test Case 3
    vector<int> nums3 = {7,7,7,7,7,7,7};
    cout << "Output 3: " << sol.lengthOfLIS(nums3) << endl;

    return 0;
}

    

