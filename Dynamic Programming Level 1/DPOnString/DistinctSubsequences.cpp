/*
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int m;
    int n;
    int memo[1001][1001];

    int solve(string &s, string &t, int i, int j){

        if(j == n)
        return 1;

        if(i == m)
        return 0 ; 

        if(memo[i][j] != -1)
        return memo[i][j];

        int cnt = 0 ; 

        if(s[i] == t[j]){
            cnt = solve(s, t, i + 1, j + 1) + solve(s, t, i + 1 , j);    
        }

        else{
            cnt += solve(s, t, i + 1, j);
        }

        return memo[i][j] = cnt ;

    }
    int numDistinct(string s, string t) {

        m = s.length();
        n = t.length();

        memset(memo, -1 , sizeof(memo));

        return solve(s, t, 0, 0);
    }
};

Top Down Approach :
Time Complexity : O(m*n)
Space Complexity : O(m*n)

*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

int numDistinct(string s, string t) {

    int m = s.length();
    int n = t.length();

    vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1, 0));
    for(int i = 0; i <= m; i++) {
        dp[i][n] = 1;
    }

    for(int i = m - 1; i >= 0; i--) {
        for(int j = n - 1; j >= 0; j--){

            if(s[i] == t[j]){
                dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
            }
            else{
                dp[i][j] = dp[i + 1][j];
            }
        }
    }

    return dp[0][0];
}
};

int main() {
    Solution sol;

    // Test Case 1
    string s1 = "rabbbit", t1 = "rabbit";
    int result1 = sol.numDistinct(s1, t1);
    cout << "Test 1: s=\"" << s1 << "\", t=\"" << t1 << "\" → " 
         << "Output: " << result1 << ", Expected: 3" << endl;

    // Test Case 2
    string s2 = "babgbag", t2 = "bag";
    int result2 = sol.numDistinct(s2, t2);
    cout << "Test 2: s=\"" << s2 << "\", t=\"" << t2 << "\" → " 
         << "Output: " << result2 << ", Expected: 5" << endl;

    // Test Case 3
    string s3 = "", t3 = "";
    int result3 = sol.numDistinct(s3, t3);
    cout << "Test 3: s=\"" << s3 << "\", t=\"" << t3 << "\" → " 
         << "Output: " << result3 << ", Expected: 1" << endl;

    // Test Case 4
    string s4 = "abc", t4 = "abc";
    int result4 = sol.numDistinct(s4, t4);
    cout << "Test 4: s=\"" << s4 << "\", t=\"" << t4 << "\" → " 
         << "Output: " << result4 << ", Expected: 1" << endl;

    // Test Case 5
    string s5 = "aaa", t5 = "aa";
    int result5 = sol.numDistinct(s5, t5);
    cout << "Test 5: s=\"" << s5 << "\", t=\"" << t5 << "\" → " 
         << "Output: " << result5 << ", Expected: 3" << endl;

    // Test Case 6
    string s6 = "abc", t6 = "d";
    int result6 = sol.numDistinct(s6, t6);
    cout << "Test 6: s=\"" << s6 << "\", t=\"" << t6 << "\" → " 
         << "Output: " << result6 << ", Expected: 0" << endl;

    return 0;
}