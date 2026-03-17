#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &nums){

        int n = nums.size() ; 

        int i = 0 ; 
        int j = 1 ; 

        while(i < n && j < n){


            bool conflict1 = nums[i] % 2 == 1 ; 
            bool conflict2 = nums[j] % 2 == 0 ; 

            if(conflict1 && conflict2){
                swap(nums[i] , nums[j]) ; 
                i += 2 ; 
                j += 2 ; 
            } else if(!conflict1 && !conflict2){
                i += 2 ; 
                j += 2 ; 
            } else if(!conflict1){
                i += 2 ; 
            }
            else{
                j += 2 ; 
            }

        }

        return nums ; 

     
    }
};

int main()
{
    Solution sol;

    auto isValid = [](const vector<int> &v)
    {
        for (int i = 0; i < (int)v.size(); i++)
            if (v[i] % 2 != i % 2)
                return false;
        return true;
    };

    auto print = [](const vector<int> &v)
    {
        cout << "[";
        for (int i = 0; i < (int)v.size(); i++)
        {
            cout << v[i];
            if (i + 1 < (int)v.size())
                cout << ",";
        }
        cout << "]";
    };

    // Test 1: Expected: even indices have even nums, odd indices have odd nums
    vector<int> nums1 = {4, 2, 5, 7};
    auto res1 = sol.sortArrayByParityII(nums1);
    cout << "Test 1 | Input: [4,2,5,7]\n";
    cout << "  Expected: e.g. [4,5,2,7]\n";
    cout << "  Output  : ";
    print(res1);
    cout << " | Valid: " << (isValid(res1) ? "Yes" : "No") << "\n\n";

    // Test 2
    vector<int> nums2 = {2, 3};
    auto res2 = sol.sortArrayByParityII(nums2);
    cout << "Test 2 | Input: [2,3]\n";
    cout << "  Expected: [2,3]\n";
    cout << "  Output  : ";
    print(res2);
    cout << " | Valid: " << (isValid(res2) ? "Yes" : "No") << "\n\n";

    // Test 3
    vector<int> nums3 = {3, 1, 4, 2};
    auto res3 = sol.sortArrayByParityII(nums3);
    cout << "Test 3 | Input: [3,1,4,2]\n";
    cout << "  Expected: e.g. [4,1,2,3] or [4,3,2,1]\n";
    cout << "  Output  : ";
    print(res3);
    cout << " | Valid: " << (isValid(res3) ? "Yes" : "No") << "\n";

    return 0;
}

// Time Complexity : O(n)
// Space Complexity : O(1)