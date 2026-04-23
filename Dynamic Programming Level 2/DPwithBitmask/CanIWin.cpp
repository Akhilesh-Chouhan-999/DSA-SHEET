#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    unordered_map<int,int>memo;

    bool solve(int maxChoosableInteger, int desiredTotal, int mask) {

        if(desiredTotal <= 0) {
            return false;
        }

        if(memo.count(mask)) {
            return memo[mask];
        }

        for(int i = 1; i <= maxChoosableInteger; i ++) {

            if((mask & (1 << (i - 1))) == 0) {

                if(!solve(maxChoosableInteger, desiredTotal - i,  mask | (1 << i - 1)))
                return memo[mask] = true;

            }
        }
     
        return memo[mask] = false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {

        memo.clear();
        
        if(desiredTotal == 0) return true;

        if((maxChoosableInteger * (maxChoosableInteger + 1) / 2) < desiredTotal)
        return false;

        return solve(maxChoosableInteger, desiredTotal, 0);
    }
};

int main() {
    Solution sol;

    // Test Case 1
    cout << "Test 1: " << sol.canIWin(10, 11) << endl;
    cout << "Expected: 0 (false)\n\n";

    // Test Case 2
    cout << "Test 2: " << sol.canIWin(10, 0) << endl;
    cout << "Expected: 1 (true)\n\n";

    // Test Case 3
    cout << "Test 3: " << sol.canIWin(10, 1) << endl;
    cout << "Expected: 1 (true)\n\n";

    // Additional Test Case 4
    cout << "Test 4: " << sol.canIWin(5, 6) << endl;
    cout << "Expected: 0 (false)\n\n";

    // Additional Test Case 5
    cout << "Test 5: " << sol.canIWin(5, 5) << endl;
    cout << "Expected: 1 (true)\n\n";

    // Additional Test Case 6
    cout << "Test 6: " << sol.canIWin(20, 210) << endl;
    cout << "Expected: 0 (false)\n\n";

    return 0;
}