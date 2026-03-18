#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:

    int upperBound(vector<int>&prefix , int target){

        int n = prefix.size() ;

        int low = 0  ; 
        int high = n - 1 ; 
        int ub =  -1 ; 

        while(low <= high){

            int mid = low + (high - low) / 2 ; 

            if(prefix[mid] <= target){
                ub = mid ; 
                low = mid + 1 ; 
            }
            else{
                high = mid - 1 ; 
            }
        }

        if(ub == -1)
        return 0 ; 

        return ub + 1; 

    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    
        int n = nums.size();

        sort(begin(nums) , end(nums)) ;

        vector<int>prefix(n) ; 
        prefix[0] = nums[0] ; 

        for(int i = 1 ; i < n ; i ++ ){
            prefix[i] = nums[i] + prefix[i-1] ; 
        }

        vector<int>answer ; 

        for(int query : queries){
            answer.push_back(upperBound(prefix , query)) ; 
        }

        return answer ; 
    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> nums1 = {4, 5, 2, 1};
    vector<int> queries1 = {3, 10, 21};
    vector<int> ans1 = obj.answerQueries(nums1, queries1);
    for (int x : ans1) cout << x << " ";
    cout << endl; // Expected: 2 3 4

    // Test Case 2
    vector<int> nums2 = {2, 3, 4, 5};
    vector<int> queries2 = {1};
    vector<int> ans2 = obj.answerQueries(nums2, queries2);
    for (int x : ans2) cout << x << " ";
    cout << endl; // Expected: 0

    // Additional Test Case 3
    vector<int> nums3 = {1, 2, 3, 4};
    vector<int> queries3 = {5, 6, 7};
    vector<int> ans3 = obj.answerQueries(nums3, queries3);
    for (int x : ans3) cout << x << " ";
    cout << endl;

    return 0;
}

// Time complexity :  O(m * log(n))
// Space Complexity : O(n)