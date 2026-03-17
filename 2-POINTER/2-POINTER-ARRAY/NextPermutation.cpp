#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
       
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

    // Test 1: Expected [1,3,2]
    vector<int> nums1 = {1, 2, 3};
    sol.nextPermutation(nums1);
    cout << "Test 1 | Input: [1,2,3]\n";
    cout << "  Expected: [1,3,2]\n";
    cout << "  Output  : ";
    print(nums1);
    cout << "\n\n";

    // Test 2: Expected [1,2,3]
    vector<int> nums2 = {3, 2, 1};
    sol.nextPermutation(nums2);
    cout << "Test 2 | Input: [3,2,1]\n";
    cout << "  Expected: [1,2,3]\n";
    cout << "  Output  : ";
    print(nums2);
    cout << "\n\n";

    // Test 3: Expected [1,5,1]
    vector<int> nums3 = {1, 1, 5};
    sol.nextPermutation(nums3);
    cout << "Test 3 | Input: [1,1,5]\n";
    cout << "  Expected: [1,5,1]\n";
    cout << "  Output  : ";
    print(nums3);
    cout << "\n";

    return 0;
}
