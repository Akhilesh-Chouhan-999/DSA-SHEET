#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums){

        int n = nums.size() ; 


        int i = 0 ; 

        for(int j = i + 1 ; j < n ; j ++ ){

            if(nums[i] != nums[j]){
                i ++ ; 
                swap(nums[i] , nums[j]) ; 
            }

        }
        

        return i + 1  ; 
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

    // Test 1: Expected k=2, nums=[1,2,...]
    vector<int> nums1 = {1, 1, 2};
    int k1 = sol.removeDuplicates(nums1);
    cout << "Test 1 | Input: [1,1,2]\n";
    cout << "  Expected: k=2, nums=[1,2]\n";
    cout << "  Output  : k=" << k1 << ", nums=";
    print(nums1, k1);
    cout << "\n\n";

    // Test 2: Expected k=5, nums=[0,1,2,3,4]
    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k2 = sol.removeDuplicates(nums2);
    cout << "Test 2 | Input: [0,0,1,1,1,2,2,3,3,4]\n";
    cout << "  Expected: k=5, nums=[0,1,2,3,4]\n";
    cout << "  Output  : k=" << k2 << ", nums=";
    print(nums2, k2);
    cout << "\n";

    return 0;
}
