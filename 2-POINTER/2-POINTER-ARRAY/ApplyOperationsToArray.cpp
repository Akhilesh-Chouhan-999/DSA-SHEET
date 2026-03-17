#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> applyOperations(vector<int> &nums){

        int n = nums.size() ; 
        int pos = 0 ; 

        for(int i = 0 ; i < n - 1 ; i ++ ){

            if(i < n - 1 && nums[i] == nums[i+1]){
                nums[i] = 2 * nums[i] ; 
                nums[i+1] = 0 ; 
            }

   
            if(nums[i] != 0){
                swap(nums[i] , nums[pos])  ; 
                pos ++ ; 
            }
        }
        

        return nums ;
    }
};

int main()
{
    Solution sol;

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

    // Test 1: Expected [1,4,2,0,0,0]
    vector<int> nums1 = {1, 2, 2, 1, 1, 0};
    auto res1 = sol.applyOperations(nums1);
    cout << "Test 1 | Input: [1,2,2,1,1,0]\n";
    cout << "  Expected: [1,4,2,0,0,0]\n";
    cout << "  Output  : ";
    print(res1);
    cout << "\n\n";

    // Test 2: Expected [1,0]
    vector<int> nums2 = {0, 1};
    auto res2 = sol.applyOperations(nums2);
    cout << "Test 2 | Input: [0,1]\n";
    cout << "  Expected: [1,0]\n";
    cout << "  Output  : ";
    print(res2);
    cout << "\n\n";

    // Test 3: Expected [4,8,0,0]
    vector<int> nums3 = {2, 2, 4, 4};
    auto res3 = sol.applyOperations(nums3);
    cout << "Test 3 | Input: [2,2,4,4]\n";
    cout << "  Expected: [4,8,0,0]\n";
    cout << "  Output  : ";
    print(res3);
    cout << "\n";

    return 0;
}

// Time Complexity : O(n)
// Space Complexity : O(1)


