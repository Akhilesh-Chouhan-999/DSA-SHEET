#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int memo[30][2][2];

    int solve(string &num, int idx, int tight, int prev) {

        if(idx == num.size()) {
            return 1; 
        }

        if(memo[idx][tight][prev] != -1) {
            return memo[idx][tight][prev];
        }

        int upperBound = tight ? num[idx] - '0' : 1;

        int cnt = 0;

        for(int digit = 0; digit <= upperBound; digit ++) {

            if(prev == 1 && digit == 1)
            continue;

            bool newTight = tight && (digit == upperBound);

            cnt += solve(num, idx + 1, newTight, digit);
        }

        return memo[idx][tight][prev] = cnt;
       
    }
    int findIntegers(int n) {
        
        string num = bitset<32>(n).to_string();

        string binaryNum = num.substr(num.find('1'));
        
        memset(memo, -1, sizeof(memo));

        return solve(num, 0, true, 0);

    }
};
