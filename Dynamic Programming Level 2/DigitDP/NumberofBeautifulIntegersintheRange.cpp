#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int memo[11][2][11][11][21][2];
    int solve(string& num, int k, int idx, bool tight, int cntEven, int cntOdd, int rem, bool leadingZeros) {

        if(idx == num.size()) {
            return !leadingZeros && cntEven == cntOdd && rem % k == 0;
        }


        if(!tight && memo[idx][tight][cntEven][cntOdd][rem][leadingZeros] != -1) {
            return memo[idx][tight][cntEven][cntOdd][rem][leadingZeros] ;
        }

        int upperBound = tight ? num[idx] - '0' : 9;

        int cnt = 0;

        for(int i = 0; i <= upperBound; i ++) {

            bool newTight = tight && i == upperBound;

            if(leadingZeros && i == 0) {
                cnt += solve(num, k, idx + 1, newTight, 0, 0, 0, true);
            }
            else{
                int currRem = (rem * 10 + i) % k ;
                int currCntEven = i % 2 == 0 ? cntEven + 1 : cntEven;
                int currCntOdd  = i % 2 == 1 ? cntOdd + 1 : cntOdd;
                cnt += solve(num, k, idx + 1, newTight, currCntEven, currCntOdd, currRem, false);
            }
        }

        if(!tight){
            memo[idx][tight][cntEven][cntOdd][rem][leadingZeros] = cnt;
        }

        return  cnt;
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {

        string num1 = to_string(high);
        memset(memo, -1, sizeof(memo));
        int highAns = solve(num1, k, 0, true, 0, 0, 0, true);
        
        string num2 = to_string(low - 1);
        memset(memo, -1, sizeof(memo));
        int lowAns = solve(num2, k, 0, true, 0, 0, 0, true);

        return highAns - lowAns;
    }
};


int main() {
    Solution sol;

    // Test case 1: low=10, high=20, k=3
    int result1 = sol.numberOfBeautifulIntegers(10, 20, 3);
    cout << "Test 1: low=10, high=20, k=3 => " << result1 << " (Expected: 2)\n";

    // Test case 2: low=1, high=10, k=1
    int result2 = sol.numberOfBeautifulIntegers(1, 10, 1);
    cout << "Test 2: low=1, high=10, k=1 => " << result2 << " (Expected: 1)\n";

    // Test case 3: low=5, high=5, k=2
    int result3 = sol.numberOfBeautifulIntegers(5, 5, 2);
    cout << "Test 3: low=5, high=5, k=2 => " << result3 << " (Expected: 0)\n";

    return 0;
}