#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        
    }
};

int main()
{
    Solution sol;

    auto print = [](const vector<vector<int>> &v)
    {
        cout << "[";
        for (int i = 0; i < (int)v.size(); i++)
        {
            cout << "[";
            for (int j = 0; j < (int)v[i].size(); j++)
            {
                cout << v[i][j];
                if (j + 1 < (int)v[i].size())
                    cout << ",";
            }
            cout << "]";
            if (i + 1 < (int)v.size())
                cout << ",";
        }
        cout << "]";
    };

    // Test 1: Expected [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
    vector<int> nums1 = {1, 0, -1, 0, -2, 2};
    auto res1 = sol.fourSum(nums1, 0);
    cout << "Test 1 | Input: [1,0,-1,0,-2,2], target=0\n";
    cout << "  Expected: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]\n";
    cout << "  Output  : ";
    print(res1);
    cout << "\n\n";

    // Test 2: Expected [[2,2,2,2]]
    vector<int> nums2 = {2, 2, 2, 2, 2};
    auto res2 = sol.fourSum(nums2, 8);
    cout << "Test 2 | Input: [2,2,2,2,2], target=8\n";
    cout << "  Expected: [[2,2,2,2]]\n";
    cout << "  Output  : ";
    print(res2);
    cout << "\n\n";

    // Test 3: Expected []
    vector<int> nums3 = {0, 0, 0, 0};
    auto res3 = sol.fourSum(nums3, 1);
    cout << "Test 3 | Input: [0,0,0,0], target=1\n";
    cout << "  Expected: []\n";
    cout << "  Output  : ";
    print(res3);
    cout << "\n";

    return 0;
}
