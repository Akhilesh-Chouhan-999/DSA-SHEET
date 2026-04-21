#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int memo[11][2][11];

    int solve(string& num, int idx, bool tight, int cnt) {

        if(idx == num.size()) {
            return cnt;
        }

        if(memo[idx][tight][cnt] != -1) {
            return memo[idx][tight][cnt];
        }

        int upperBound = tight ? num[idx] - '0' : 9;

        int ans = 0;

        for(int i = 0; i <= upperBound; i ++) {

            int currCnt = cnt + (i == 1);

            bool newTight = tight && (i == num[idx] - '0');

            ans += solve(num, idx + 1, newTight, currCnt);

        }

        return memo[idx][tight][cnt] = ans;
    }
 
    int countDigitOne(int n) {

        memset(memo, -1, sizeof(memo));

        string num1 = to_string(n);
        return solve(num1, 0, true, 0);
    
    }
};


int main() {
    Solution sol;
    
    // Test cases with expected results
    vector<pair<int, int>> testCases = {
        {1, 1},
        {2, 1},
        {13, 6},
        {0, 0},
        {100, 21}
    };
    
    int passed = 0;
    int failed = 0;
    
    for(auto& test : testCases) {
        int input = test.first;
        int expected = test.second;
        int result = sol.countDigitOne(input);
        
        if(result == expected) {
            cout << " PASSED: countDigitOne(" << input << ") = " << result << endl;
            passed++;
        } else {
            cout << " FAILED: countDigitOne(" << input << ") = " << result 
                 << " (Expected: " << expected << ")" << endl;
            failed++;
        }
    }
    
    cout << "\n" << passed << "/" << testCases.size() << " tests passed" << endl;
    
    return 0;
}

// Time Complexity : O(digits * 2 * digits * 10)
// Space Complexity : O(digits * 2 * digits)