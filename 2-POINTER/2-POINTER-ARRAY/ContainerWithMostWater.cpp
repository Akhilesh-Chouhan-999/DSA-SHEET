#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
     
    }
};

int main()
{
    Solution sol;

    // Test 1: Expected 49
    vector<int> h1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int res1 = sol.maxArea(h1);
    cout << "Test 1 | Input: [1,8,6,2,5,4,8,3,7]\n";
    cout << "  Expected: 49\n";
    cout << "  Output  : " << res1 << "\n\n";

    // Test 2: Expected 1
    vector<int> h2 = {1, 1};
    int res2 = sol.maxArea(h2);
    cout << "Test 2 | Input: [1,1]\n";
    cout << "  Expected: 1\n";
    cout << "  Output  : " << res2 << "\n\n";

    // Test 3: Expected 36
    vector<int> h3 = {4, 3, 2, 1, 4};
    int res3 = sol.maxArea(h3);
    cout << "Test 3 | Input: [4,3,2,1,4]\n";
    cout << "  Expected: 16\n";
    cout << "  Output  : " << res3 << "\n";

    return 0;
}
