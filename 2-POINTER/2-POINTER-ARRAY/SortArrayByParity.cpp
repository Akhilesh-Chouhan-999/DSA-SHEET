#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums){
    
        int n = nums.size() ; 

        vector<int>result ; 

        int i = 0 ;
        int j = n - 1 ; 

        while( i < j ){

            if(nums[j]%2 == 0){

                if(nums[i]%2==0){
                    i ++ ; 
                }else{
                    swap(nums[i] , nums[j]) ; 
                    i ++ ; 
                    j -- ; 
                }
            }else{
                j -- ;
            }
        }

        return nums; 
    }
};

int main()
{
    Solution sol;

    auto isValid = [](const vector<int> &v)
    {
        int i = 0;
        while (i < (int)v.size() && v[i] % 2 == 0)
            i++;
        while (i < (int)v.size() && v[i] % 2 != 0)
            i++;
        return i == (int)v.size();
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

    // Test 1: Expected: even numbers first, then odd
    vector<int> nums1 = {3, 1, 2, 4};
    auto res1 = sol.sortArrayByParity(nums1);
    cout << "Test 1 | Input: [3,1,2,4]\n";
    cout << "  Expected: (evens first) e.g. [2,4,3,1]\n";
    cout << "  Output  : ";
    print(res1);
    cout << " | Valid: " << (isValid(res1) ? "Yes" : "No") << "\n\n";

    // Test 2
    vector<int> nums2 = {0};
    auto res2 = sol.sortArrayByParity(nums2);
    cout << "Test 2 | Input: [0]\n";
    cout << "  Expected: [0]\n";
    cout << "  Output  : ";
    print(res2);
    cout << " | Valid: " << (isValid(res2) ? "Yes" : "No") << "\n\n";

    // Test 3
    vector<int> nums3 = {1, 3, 5, 2, 4, 6};
    auto res3 = sol.sortArrayByParity(nums3);
    cout << "Test 3 | Input: [1,3,5,2,4,6]\n";
    cout << "  Expected: (evens first) e.g. [6,4,2,1,3,5]\n";
    cout << "  Output  : ";
    print(res3);
    cout << " | Valid: " << (isValid(res3) ? "Yes" : "No") << "\n";

    return 0;
}

// Time complexity : O(n)
// Space Complexity : O(1)