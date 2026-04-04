#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size() ; 

        vector<int>prefix(n , 1) ; 
        vector<int>suffix(n , 1) ; 

        prefix[0] = nums[0] ; 
        suffix[n-1] = nums[n-1]; 

        for(int i = 1 ; i < n ; i ++){

            prefix[i] = prefix[i-1]*nums[i] ; 
            suffix[n-i-1] = suffix[n-i]*nums[n-i-1] ; 
        }

        vector<int>result(n , 1) ; 
        result[0] = suffix[1] ; 
        result[n-1] = prefix[n-2] ; 

        for(int i = 1 ; i < n - 1 ; i ++){
            result[i] = prefix[i-1] * suffix[i+1] ; 
        }

        return result ; 
        
    }
};

int main() {

    // ✅ Test Case 1
    {
        vector<int> nums = {1, 2, 3, 4};
        Solution obj;
        vector<int> res = obj.productExceptSelf(nums);

        cout << "TC1: ";
        for(auto x : res) cout << x << " ";
        cout << "| Expected: 24 12 8 6" << endl;
    }

    // ✅ Test Case 2 (with zero)
    {
        vector<int> nums = {-1, 1, 0, -3, 3};
        Solution obj;
        vector<int> res = obj.productExceptSelf(nums);

        cout << "TC2: ";
        for(auto x : res) cout << x << " ";
        cout << "| Expected: 0 0 9 0 0" << endl;
    }

    // ✅ Test Case 3 (all positive)
    {
        vector<int> nums = {2, 3, 4, 5};
        Solution obj;
        vector<int> res = obj.productExceptSelf(nums);

        cout << "TC3: ";
        for(auto x : res) cout << x << " ";
        cout << "| Expected: 60 40 30 24" << endl;
    }

    // ✅ Test Case 4 (all negative)
    {
        vector<int> nums = {-1, -2, -3, -4};
        Solution obj;
        vector<int> res = obj.productExceptSelf(nums);

        cout << "TC4: ";
        for(auto x : res) cout << x << " ";
        cout << "| Expected: -24 -12 -8 -6" << endl;
    }

    // ✅ Test Case 5 (single zero)
    {
        vector<int> nums = {0, 2, 3, 4};
        Solution obj;
        vector<int> res = obj.productExceptSelf(nums);

        cout << "TC5: ";
        for(auto x : res) cout << x << " ";
        cout << "| Expected: 24 0 0 0" << endl;
    }

    return 0;
}