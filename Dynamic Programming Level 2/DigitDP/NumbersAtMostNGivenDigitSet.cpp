#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int memo[10][2][2];
    int solve(string& num, int idx, bool tight, bool leadingZeros, int mask) {

        if(idx == num.size()) {
            return leadingZeros ? 0 : 1;
        }

        if(memo[idx][tight][leadingZeros] != -1) {
            return memo[idx][tight][leadingZeros];
        }

        int upperBound = tight ? num[idx] - '0' : 9;

        int cnt = 0;

        for(int i = 0; i <= upperBound; i ++) {

            bool newLeadingZeros = leadingZeros && i == 0;
            
            if(newLeadingZeros){
                cnt += solve(num, idx + 1, false, true, mask);
            }
            else{

                if(!(mask & (1 << i))) {
                    continue;
                }
                bool newTight = tight && (num[idx] - '0' == i);

                cnt += solve(num, idx + 1, newTight, false, mask);
            }
        }

        return memo[idx][tight][leadingZeros] = cnt;
    }
 
    int atMostNGivenDigitSet(vector<string>& digits, int n) {

        int mask = 0;

        for(string &digit : digits) {

            int dig = stoi(digit);

            mask = mask | (1 << dig);
        }

        memset(memo, -1, sizeof(memo));

        string num = to_string(n);

        return solve(num, 0, true, true, mask);

    }
};

int main() {

    Solution sol;

    // Test Case 1: digits = ["1","3","5","7"], n = 100  → Expected: 20
    vector<string> digits1 = {"1", "3", "5", "7"};
    cout << "Test 1: " << sol.atMostNGivenDigitSet(digits1, 100)
         << " (expected 20)" << endl;

    // Test Case 2: digits = ["1","4","9"], n = 1000000000  → Expected: 29523
    vector<string> digits2 = {"1", "4", "9"};
    cout << "Test 2: " << sol.atMostNGivenDigitSet(digits2, 1000000000)
         << " (expected 29523)" << endl;

    // Test Case 3: digits = ["7"], n = 8  → Expected: 1
    vector<string> digits3 = {"7"};
    cout << "Test 3: " << sol.atMostNGivenDigitSet(digits3, 8)
         << " (expected 1)" << endl;

    return 0;
}