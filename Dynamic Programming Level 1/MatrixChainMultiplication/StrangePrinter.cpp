/*
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int memo[101][101];

    int solve(string& s, int i, int j) {

        if(i == j) {
            return 1;
        }

        if( i > j) {
            return 0;
        }

        if(memo[i][j] != -1) {
            return memo[i][j];
        }

        int ans = 1 + solve(s, i + 1, j);

        for(int k = i + 1; k <= j; k ++) {

            if(s[i] == s[k]) {
                ans = min(ans, solve(s, i + 1, k - 1) + solve(s, k, j ));
            }
        }

        return memo[i][j] = ans;

    }

    int strangePrinter(string s) {
        
        int n = s.length();

        memset(memo, -1, sizeof(memo));

        return solve(s, 0, n - 1);
    }
};


int main() {
    Solution sol;

    vector<pair<string, int>> tests = {
        {"aaabbb", 2},
        {"aba",    2},
        {"a",      1},
        {"aa",     1},
        {"ab",     2},
        {"abcba",  3},
        {"aaabcaaa", 3},
    };

    int passed = 0;
    for (auto& test : tests) {
        
        string input = test.first;
        int expected = test.second;
        int result = sol.strangePrinter(input);
        bool ok = (result == expected);
        if (ok) passed++;

        cout << "Input: \"" << input << "\""
             << " | Output: " << result
             << " | Expected: " << expected
             << " | " << (ok ? "PASS" : "FAIL")
             << "\n";
    }

    cout << "\n" << passed << "/" << tests.size() << " tests passed.\n";
    return 0;
}
    Top Down Approach :
    Time Complexity : O(n^3)
    Space Complexity : O(n^2)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int memo[101][101];

    int solve(string& s, int i, int j) {

        if(i == j) {
            return 1;
        }

        if( i > j) {
            return 0;
        }

        if(memo[i][j] != -1) {
            return memo[i][j];
        }

        int ans = 1 + solve(s, i + 1, j);

        for(int k = i + 1; k <= j; k ++) {

            if(s[i] == s[k]) {
                ans = min(ans, solve(s, i + 1, k - 1) + solve(s, k, j ));
            }
        }

        return memo[i][j] = ans;

    }

    int strangePrinter(string s) {
        
        int n = s.length();

        vector<vector<int>>t(n + 1, vector<int>(n + 1 , 0));

        for(int i = n - 1; i >= 0; i --) {

            for(int j = i; j < n ; j ++) {

                int ans = 1 + t[i + 1][j];

                for(int k = i + 1; k <= j; k ++) {

                    if(s[i] == s[k]) {
                        ans = min(ans, t[i + 1][k - 1] + t[k][j]);
                    }
                }

                return memo[i][j] = ans;

            }
        }


    }
};


int main() {
    Solution sol;

    vector<pair<string, int>> tests = {
        {"aaabbb", 2},
        {"aba",    2},
        {"a",      1},
        {"aa",     1},
        {"ab",     2},
        {"abcba",  3},
        {"aaabcaaa", 3},
    };

    int passed = 0;
    for (auto& test : tests) {
        
        string input = test.first;
        int expected = test.second;
        int result = sol.strangePrinter(input);
        bool ok = (result == expected);
        if (ok) passed++;

        cout << "Input: \"" << input << "\""
             << " | Output: " << result
             << " | Expected: " << expected
             << " | " << (ok ? "PASS" : "FAIL")
             << "\n";
    }

    cout << "\n" << passed << "/" << tests.size() << " tests passed.\n";
    return 0;
}

// Bottom Up Approach :
// Time Complexity : O(n^3)
// Space Complexity : O(n^2)