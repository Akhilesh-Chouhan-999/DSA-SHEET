/*
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int memo[101][101];
    int calMinCharForPalindrome(string& s, int i, int j) {

        int cnt = 0;

        while(i < j) {

            if(s[i] != s[j])
            cnt ++;

            i ++;
            j --;
        }

        return cnt;
    }


    int solve(string& s, int idx, int k) {

        if(memo[idx][k] != -1)
        return memo[idx][k];
        
        if(k == 1){
            return calMinCharForPalindrome(s, idx, s.length() - 1);
        }

        int minOpern = INT_MAX;

        for(int j = idx; j <= s.length() - k; j ++) {

            int opern = calMinCharForPalindrome(s, idx, j) + solve(s, j + 1, k - 1);

            minOpern = min(minOpern, opern);
        }

        return memo[idx][k] = minOpern;
    }

    int palindromePartition(string s, int k) {
        
        memset(memo, -1, sizeof(memo));

        return solve(s, 0, k);
    }
};

int main() {
    Solution sol;

    // Test cases matching the LeetCode problem
    vector<pair<string, int>> testCases = {
        {"abc",      2},
        {"aabbc",    3},
        {"leetcode", 8}
    };

    vector<int> expected = {1, 0, 0};

    for (int i = 0; i < (int)testCases.size(); i++) {
        string s = testCases[i].first;
        int k    = testCases[i].second;

        int result = sol.palindromePartition(s, k);

        cout << "s = \"" << s << "\", k = " << k
             << " => Output: " << result
             << " | Expected: " << expected[i]
             << (result == expected[i] ? " PASS" : " FAIL")
             << "\n";
    }

    return 0;
}

Top Down Approach :
Time Complexity : O(n^3)
Space Complexity : O(n*k)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int calMinCharForPalindrome(string& s, int i, int j) {
      
        int cnt = 0;

        while(i < j) {
            if(s[i] != s[j]) 
            cnt++;

            i++;
            j--;
        }

        return cnt;
    }

    int palindromePartition(string s, int K) {

        int n = s.length();

       
        vector<vector<int>> dp(n, vector<int>(K + 1, INT_MAX));

        for(int i = 0; i < n; i++) {
            dp[i][1] = calMinCharForPalindrome(s, i, n - 1);
        }

    
        for(int k = 2; k <= K; k++) {

            for(int idx = n - 1; idx >= 0; idx--) {

                int minOpern = INT_MAX;

                for(int j = idx; j <= n - k; j++) {

                    int opern = calMinCharForPalindrome(s, idx, j)
                                                    + dp[j + 1][k - 1];

                    minOpern = min(minOpern, opern);
                }

                dp[idx][k] = minOpern;
            }
        }

        return dp[0][K];
    }
};

int main() {
    Solution sol;

    // Test cases matching the LeetCode problem
    vector<pair<string, int>> testCases = {
        {"abc",      2},
        {"aabbc",    3},
        {"leetcode", 8}
    };

    vector<int> expected = {1, 0, 0};

    for (int i = 0; i < (int)testCases.size(); i++) {
        string s = testCases[i].first;
        int k    = testCases[i].second;

        int result = sol.palindromePartition(s, k);

        cout << "s = \"" << s << "\", k = " << k
             << " => Output: " << result
             << " | Expected: " << expected[i]
             << (result == expected[i] ? " PASS" : " FAIL")
             << "\n";
    }

    return 0;
}