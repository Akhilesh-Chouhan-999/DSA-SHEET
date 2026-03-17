#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int nextGreaterElement(int n)
    {
        
    }
};

int main()
{
    Solution sol;

    // Test 1: Expected 21
    int res1 = sol.nextGreaterElement(12);
    cout << "Test 1 | Input: 12\n";
    cout << "  Expected: 21\n";
    cout << "  Output  : " << res1 << "\n\n";

    // Test 2: Expected -1
    int res2 = sol.nextGreaterElement(21);
    cout << "Test 2 | Input: 21\n";
    cout << "  Expected: -1\n";
    cout << "  Output  : " << res2 << "\n\n";

    // Test 3: Expected 132
    int res3 = sol.nextGreaterElement(123);
    cout << "Test 3 | Input: 123\n";
    cout << "  Expected: 132\n";
    cout << "  Output  : " << res3 << "\n";

    return 0;
}
