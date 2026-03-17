#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        
    }
};

int main()
{
    Solution sol;

    // Test 1: Expected 2
    vector<int> nums1 = {-1, 2, 1, -4};
    int res1 = sol.threeSumClosest(nums1, 1);
    cout << "Test 1 | Input: [-1,2,1,-4], target=1\n";
    cout << "  Expected: 2\n";
    cout << "  Output  : " << res1 << "\n\n";

    // Test 2: Expected 0
    vector<int> nums2 = {0, 0, 0};
    int res2 = sol.threeSumClosest(nums2, 1);
    cout << "Test 2 | Input: [0,0,0], target=1\n";
    cout << "  Expected: 0\n";
    cout << "  Output  : " << res2 << "\n\n";

    // Test 3: Expected 3
    vector<int> nums3 = {1, 1, 1, 0};
    int res3 = sol.threeSumClosest(nums3, 100);
    cout << "Test 3 | Input: [1,1,1,0], target=100\n";
    cout << "  Expected: 3\n";
    cout << "  Output  : " << res3 << "\n";

    return 0;
}
