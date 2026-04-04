#include<bits/stdc++.h>
using namespace std ; 

class NumArray {
public:

    vector<int>prefix ; 
    NumArray(vector<int>& nums) {

        int n = nums.size() ; 
        prefix.resize(n , 0) ; 

        prefix[0] = nums[0] ; 

        for(int i = 1 ; i < n ; i ++){
            prefix[i] = prefix[i-1] + nums[i] ; 
        }
    }
    
    int sumRange(int left, int right) {
        return ( prefix[right] -  ( left > 0 ? prefix[left-1] : 0)) ; 
    }
};


int main() {

    // ✅ Test Case 1 (Given Example)
    {
        vector<int> nums = {-2, 0, 3, -5, 2, -1};
        NumArray* obj = new NumArray(nums);

        cout << "TC1:" << endl;
        cout << obj->sumRange(0, 2) << " | Expected = 1" << endl;
        cout << obj->sumRange(2, 5) << " | Expected = -1" << endl;
        cout << obj->sumRange(0, 5) << " | Expected = -3" << endl;
        cout << endl;
    }

    // ✅ Test Case 2 (Single Element)
    {
        vector<int> nums = {5};
        NumArray* obj = new NumArray(nums);

        cout << "TC2:" << endl;
        cout << obj->sumRange(0, 0) << " | Expected = 5" << endl;
        cout << endl;
    }

    // ✅ Test Case 3 (All Positive)
    {
        vector<int> nums = {1, 2, 3, 4, 5};
        NumArray* obj = new NumArray(nums);

        cout << "TC3:" << endl;
        cout << obj->sumRange(0, 4) << " | Expected = 15" << endl;
        cout << obj->sumRange(1, 3) << " | Expected = 9" << endl;
        cout << endl;
    }

    // ✅ Test Case 4 (All Negative)
    {
        vector<int> nums = {-1, -2, -3, -4};
        NumArray* obj = new NumArray(nums);

        cout << "TC4:" << endl;
        cout << obj->sumRange(0, 3) << " | Expected = -10" << endl;
        cout << obj->sumRange(1, 2) << " | Expected = -5" << endl;
        cout << endl;
    }

    // ✅ Test Case 5 (Mixed Values)
    {
        vector<int> nums = {10, -3, 5, -2, 7, -8, 4};
        NumArray* obj = new NumArray(nums);

        cout << "TC5:" << endl;
        cout << obj->sumRange(0, 6) << " | Expected = 13" << endl;
        cout << obj->sumRange(2, 4) << " | Expected = 10" << endl;
        cout << obj->sumRange(3, 5) << " | Expected = -3" << endl;
        cout << endl;
    }

    // ✅ Test Case 6 (Zeros)
    {
        vector<int> nums = {0, 0, 0, 0};
        NumArray* obj = new NumArray(nums);

        cout << "TC6:" << endl;
        cout << obj->sumRange(0, 3) << " | Expected = 0" << endl;
        cout << obj->sumRange(1, 2) << " | Expected = 0" << endl;
        cout << endl;
    }

    return 0;
}

// Time Complexity : O( n + q)
// Space Complexity : O( n )