/*

#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:

    int upperBound(vector<int>& nums, int target){

        int n    = nums.size() ; 
        int low  = 0 ; 
        int high = n - 1 ;
        int ans  = -1 ; 

        while(low <= high){

            int mid = low + (high - low) / 2 ; 

            if(nums[mid] == target){
                ans = mid ; 
                low = mid + 1 ;
            }else if(nums[mid] < target){
                low = mid + 1 ; 
            }
            else{
                high = mid - 1 ; 
            }
        }

        return ans; 

    }

    int lowerBound(vector<int>& nums, int target){

        int n = nums.size() ; 
        int low = 0 ; 
        int high = n - 1 ;
        int ans = -1 ; 

        while(low <= high){

            int mid = low + (high - low) / 2 ; 

            if(nums[mid] == target){
                ans = mid ; 
                high = mid - 1 ;
            }else if(nums[mid] < target){
                low = mid + 1 ; 
            }
            else{
                high = mid - 1 ; 
            }
        }

        return ans; 

    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int start = lowerBound(nums , target) ; 
        int end   = upperBound(nums , target) ; 

        return {start , end} ;
    }
};


int main() {
    Solution obj;

    vector<int> nums1 = {5,7,7,8,8,10};
    int target1 = 8;   // Expected: [3,4]

    vector<int> nums2 = {5,7,7,8,8,10};
    int target2 = 6;   // Expected: [-1,-1]

    vector<int> nums3 = {};
    int target3 = 0;   // Expected: [-1,-1]

    vector<int> nums4 = {2,2,2,2};
    int target4 = 2;   // Expected: [0,3]

    vector<int> nums5 = {1};
    int target5 = 1;   // Expected: [0,0]

    vector<int> ans1 = obj.searchRange(nums1, target1);
    vector<int> ans2 = obj.searchRange(nums2, target2);
    vector<int> ans3 = obj.searchRange(nums3, target3);
    vector<int> ans4 = obj.searchRange(nums4, target4);
    vector<int> ans5 = obj.searchRange(nums5, target5);

    cout << "Test 1 Output: [" << ans1[0] << ", " << ans1[1] << "]  Expected: [3,4]" << endl;
    cout << "Test 2 Output: [" << ans2[0] << ", " << ans2[1] << "]  Expected: [-1,-1]" << endl;
    cout << "Test 3 Output: [" << ans3[0] << ", " << ans3[1] << "]  Expected: [-1,-1]" << endl;
    cout << "Test 4 Output: [" << ans4[0] << ", " << ans4[1] << "]  Expected: [0,3]" << endl;
    cout << "Test 5 Output: [" << ans5[0] << ", " << ans5[1] << "]  Expected: [0,0]" << endl;

    return 0;
}
 Time Complexity : O(log(n))    
*/


#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:

    vector<int> searchRange(vector<int>& nums, int target) {
        
        int start = lower_bound(begin(nums) , end(nums) , target)  - begin(nums);

        if(nums.size() == start || nums[start] != target)
        return { -1 , -1} ; 

       int end = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;

        return { start , end};
    }
};


int main() {
    Solution obj;

    vector<int> nums1 = {5,7,7,8,8,10};
    int target1 = 8;   // Expected: [3,4]

    vector<int> nums2 = {5,7,7,8,8,10};
    int target2 = 6;   // Expected: [-1,-1]

    vector<int> nums3 = {};
    int target3 = 0;   // Expected: [-1,-1]

    vector<int> nums4 = {2,2,2,2};
    int target4 = 2;   // Expected: [0,3]

    vector<int> nums5 = {1};
    int target5 = 1;   // Expected: [0,0]

    vector<int> ans1 = obj.searchRange(nums1, target1);
    vector<int> ans2 = obj.searchRange(nums2, target2);
    vector<int> ans3 = obj.searchRange(nums3, target3);
    vector<int> ans4 = obj.searchRange(nums4, target4);
    vector<int> ans5 = obj.searchRange(nums5, target5);

    cout << "Test 1 Output: [" << ans1[0] << ", " << ans1[1] << "]  Expected: [3,4]" << endl;
    cout << "Test 2 Output: [" << ans2[0] << ", " << ans2[1] << "]  Expected: [-1,-1]" << endl;
    cout << "Test 3 Output: [" << ans3[0] << ", " << ans3[1] << "]  Expected: [-1,-1]" << endl;
    cout << "Test 4 Output: [" << ans4[0] << ", " << ans4[1] << "]  Expected: [0,3]" << endl;
    cout << "Test 5 Output: [" << ans5[0] << ", " << ans5[1] << "]  Expected: [0,0]" << endl;

    return 0;
}