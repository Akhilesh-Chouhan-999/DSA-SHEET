#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:

    bool check(vector<int>&nums , int x){

        int n = nums.size() ; 

        int low = 0 ; 
        int high = n - 1;
        int lowerBound = -1  ; 

        while(low <= high){
            int mid = low + ( high - low) / 2 ; 

            if(nums[mid] >= x){
                lowerBound = mid  ; 
                high = mid - 1 ; 
            }
            else{
                low = mid + 1 ; 
            }
        }

        if(lowerBound == -1) return false ; 

        int cnt = n - lowerBound  ; 

        return cnt == x ; 
    }


    int specialArray(vector<int>& nums) {

        int n = nums.size() ; 

        sort(begin(nums) , end(nums)) ;

        for(int x = 1 ; x <= n ; x ++){

            if(check(nums , x )){
                return x ; 
            }

        }

        return -1 ; 
        
    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> nums1 = {3, 5};
    cout << obj.specialArray(nums1) << endl; // Expected: 2

    // Test Case 2
    vector<int> nums2 = {0, 0};
    cout << obj.specialArray(nums2) << endl; // Expected: -1

    // Test Case 3
    vector<int> nums3 = {0, 4, 3, 0, 4};
    cout << obj.specialArray(nums3) << endl; // Expected: 3

    // Additional Test Case 4
    vector<int> nums4 = {1, 2, 3, 4, 5};
    cout << obj.specialArray(nums4) << endl;

    return 0;
}


// Time Complexity  : O(n * log(n))
// Space Complexity : O(1)
