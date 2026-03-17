#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> findKDistantIndices(vector<int> &nums, int key, int k){

        int n = nums.size() ; 

        vector<int>storeKey ; 

        for(int i = 0 ; i < n ; i ++ ){
            if(nums[i] == key){
                storeKey.push_back(i) ; 
            }
        }

        vector<int>result ;
        int lastFilled = INT_MIN;
        

        for(int j : storeKey){

            int start = max( 0     , j - k ) ;
            int end =   min( n - 1 , j + k ) ;

            for(int idx = max(start , lastFilled + 1) ; idx <= end ; idx ++){
                result.push_back(idx) ; 
            }

            lastFilled = end  ; 
        }

        return result ; 

      
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

    // Test 1: Expected [1,2,3,4,5,6]
    vector<int> nums1 = {3, 4, 9, 1, 3, 9, 5};
    auto res1 = sol.findKDistantIndices(nums1, 9, 1);
    cout << "Test 1 | Input: [3,4,9,1,3,9,5], key=9, k=1\n";
    cout << "  Expected: [1,2,3,4,5,6]\n";
    cout << "  Output  : ";
    print(res1);
    cout << "\n\n";

    // Test 2: Expected [0,1,2,3,4]
    vector<int> nums2 = {2, 2, 2, 2, 2};
    auto res2 = sol.findKDistantIndices(nums2, 2, 2);
    cout << "Test 2 | Input: [2,2,2,2,2], key=2, k=2\n";
    cout << "  Expected: [0,1,2,3,4]\n";
    cout << "  Output  : ";
    print(res2);
    cout << "\n\n";

    // Test 3: Expected [0]
    vector<int> nums3 = {1, 2, 3};
    auto res3 = sol.findKDistantIndices(nums3, 1, 0);
    cout << "Test 3 | Input: [1,2,3], key=1, k=0\n";
    cout << "  Expected: [0]\n";
    cout << "  Output  : ";
    print(res3);
    cout << "\n";

    return 0;
}

// Time Complexity : O(n)
// Space Complexity : O(n)

