/*
#include<bits/stdc++.h>
using namespace std ; 
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n = nums.size() ; 

        sort(begin(nums), end(nums)) ; 

        vector<int>dp(n , 1) ;
        vector<int>parent(n , -1) ; 

        int LIS = 0 ; 
        int LisIdx = 0 ; 

        for(int i = 0 ; i < n ; i ++){

            for(int j = 0 ; j < i ; j ++){

                if(nums[i] % nums[j] == 0){
                    
                    if(dp[j]+1 > dp[i]){
                        dp[i] = dp[j] + 1 ; 
                        parent[i] = j ;
                    }
                    
                }
            }

            if(dp[i] > LIS){
                LIS = dp[i] ; 
                LisIdx = i ; 
            }
        }

        vector<int>result ; 

        int idx = LisIdx ; 

        while(idx != -1){
            result.push_back(nums[idx]) ; 
            idx = parent[idx] ; 
        }

        reverse(begin(result), end(result)) ; 

        return result ; 


    }
};

int main() {

    Solution obj;

    // Test Case 1
    vector<int> nums1 = {1, 2, 3};
    vector<int> ans1 = obj.largestDivisibleSubset(nums1);

    cout << "Output 1: ";
    for(auto x : ans1) cout << x << " ";
    cout << endl;

    // Test Case 2
    vector<int> nums2 = {1, 2, 4, 8};
    vector<int> ans2 = obj.largestDivisibleSubset(nums2);

    cout << "Output 2: ";
    for(auto x : ans2) cout << x << " ";
    cout << endl;

    // Test Case 3 (important tricky one)
    vector<int> nums3 = {5, 9, 18, 54, 108, 540, 90, 180, 360, 720};
    vector<int> ans3 = obj.largestDivisibleSubset(nums3);

    cout << "Output 3: ";
    for(auto x : ans3) cout << x << " ";
    cout << endl;

    return 0;
}
    Bottom Up Approach : 
    Time Complexity : O(n^2)
    Space Complexity : O(n)

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> dp;
    vector<int> parent;

    int solve(vector<int>& nums, int i){

        if(dp[i] != -1)
            return dp[i];

        int length = 1;

        for(int j = 0; j < i; j++){

            if(nums[i] % nums[j] == 0){

                int currLength = 1 + solve(nums, j);

                if(currLength > length){
                    length = currLength;
                    parent[i] = j;
                }
                
            }
        }

        return dp[i] = length;
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n = nums.size();

        sort(begin(nums), end(nums));

        dp.assign(n, -1);
        parent.assign(n, -1);

        int LIS    = 1;
        int LisIdx = 0;

        for(int i = 0; i < n; i++){

            int length = solve(nums, i);

            if(length > LIS){
                LIS = length;
                LisIdx = i;
            }
        }

        vector<int> result;

        int idx = LisIdx;

        while(idx != -1){
            result.push_back(nums[idx]);
            idx = parent[idx];
        }

        reverse(begin(result), end(result));

        return result;
    }
};

int main() {

    Solution obj;

    // Test Case 1
    vector<int> nums1 = {1, 2, 3};
    vector<int> ans1 = obj.largestDivisibleSubset(nums1);

    cout << "Output 1: ";
    for(auto x : ans1) cout << x << " ";
    cout << endl;

    // Test Case 2
    vector<int> nums2 = {1, 2, 4, 8};
    vector<int> ans2 = obj.largestDivisibleSubset(nums2);

    cout << "Output 2: ";
    for(auto x : ans2) cout << x << " ";
    cout << endl;

    // Test Case 3 (important tricky one)
    vector<int> nums3 = {5, 9, 18, 54, 108, 540, 90, 180, 360, 720};
    vector<int> ans3 = obj.largestDivisibleSubset(nums3);

    cout << "Output 3: ";
    for(auto x : ans3) cout << x << " ";
    cout << endl;

    return 0;
}

    // Top Down Approach :
    // Time Complexity : O(n*n)
    // Space Complexity : O(n)


