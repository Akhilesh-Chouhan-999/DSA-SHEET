#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:

    void rotate(vector<int> &nums, int k){

        int n = nums.size() ;

        k = k % n ; 

        reverse(nums.begin() + n - k , nums.end()) ;
        reverse(nums.begin() , nums.end()) ; 
        reverse(nums.begin() + k , nums.end()) ;

        return ; 
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

    // Test 1: Expected [5,6,7,1,2,3,4]
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    sol.rotate(nums1, 3);
    cout << "Test 1 | Input: [1,2,3,4,5,6,7], k=3\n";
    cout << "  Expected: [5,6,7,1,2,3,4]\n";
    cout << "  Output  : ";
    print(nums1);
    cout << "\n\n";

    // Test 2: Expected [3,-99,-100,-1]
    vector<int> nums2 = {-1, -100, 3, 99};
    sol.rotate(nums2, 2);
    cout << "Test 2 | Input: [-1,-100,3,99], k=2\n";
    cout << "  Expected: [3,99,-1,-100]\n";
    cout << "  Output  : ";
    print(nums2);
    cout << "\n\n";

    // Test 3: k > n, Expected [2,1]
    vector<int> nums3 = {1, 2};
    sol.rotate(nums3, 3);
    cout << "Test 3 | Input: [1,2], k=3\n";
    cout << "  Expected: [2,1]\n";
    cout << "  Output  : ";
    print(nums3);
    cout << "\n";

    return 0;
}


// Time Complexity : O(n) 
// space Complexity : O(1)