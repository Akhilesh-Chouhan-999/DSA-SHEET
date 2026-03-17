#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val){

        int n = nums.size() ; 

        int i = 0 ;
        int j = n - 1 ; 

        while( i <= j ){

            if(nums[j] == val){
                j -- ; 
            } else if(nums[i] == val){
                swap(nums[i] , nums[j]) ; 
                i ++ ; 
                j -- ; 
            }else{
                i ++ ; 
            }
        }

        return i ;
    
    }
};

int main()
{
    Solution sol;

    auto print = [](const vector<int> &v, int k)
    {
        cout << "[";
        for (int i = 0; i < k; i++)
        {
            cout << v[i];
            if (i + 1 < k)
                cout << ",";
        }
        cout << "]";
    };

    // Test 1: Expected k=2, nums=[2,2,...]
    vector<int> nums1 = {3, 2, 2, 3};
    int k1 = sol.removeElement(nums1, 3);
    cout << "Test 1 | Input: [3,2,2,3], val=3\n";
    cout << "  Expected: k=2, nums=[2,2]\n";
    cout << "  Output  : k=" << k1 << ", nums=";
    print(nums1, k1);
    cout << "\n\n";

    // Test 2: Expected k=5, nums=[0,1,4,0,3,...]
    vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    int k2 = sol.removeElement(nums2, 2);
    cout << "Test 2 | Input: [0,1,2,2,3,0,4,2], val=2\n";
    cout << "  Expected: k=5, nums=[0,1,3,0,4]\n";
    cout << "  Output  : k=" << k2 << ", nums=";
    print(nums2, k2);
    cout << "\n";

    return 0;
}

// Time Complexity : O(n)
// Space Complexity : O(1)