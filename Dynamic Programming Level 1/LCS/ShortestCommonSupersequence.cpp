#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {

        int m = s1.size();
        int n = s2.size();

        vector<vector<int>>t(m + 1, vector<int>(n + 1, 0));

        for(int i = m - 1; i >= 0 ; i --) {
            for(int j = n - 1; j >= 0; j--) {

                if(s1[i] == s2[j]) {
                    t[i][j] = 1 + t[i + 1][j + 1];
                }
                else {
                    t[i][j] = max(t[i + 1][j] , t[i][j + 1]);
                }

            }
        }


        string result = "" ; 
        int i = 0;
        int j = 0;

        while(i < m && j < n) {

            if(s1[i] == s2[j]) {
                result += s1[i];
                i ++;
                j ++;
            }
            else if(t[i][j+1] > t[i+1][j]) {
                result += s2[j];
                j ++;
            }
            else {
                result += s1[i];
                i ++;
            }
        }

        while(i < m) {
            result += s1[i];
            i ++;
        }

        while(j < n) {
            result += s2[j];
            j ++;
        }

        return result ;
    
    }
};

int main() {
    Solution sol;

    // Basic test
    cout << sol.shortestCommonSupersequence("abac", "cab") 
         << " -> Expected: cabac" << endl;

    // Same strings
    cout << sol.shortestCommonSupersequence("abc", "abc") 
         << " -> Expected: abc" << endl;

    // No common characters
    cout << sol.shortestCommonSupersequence("abc", "def") 
         << " -> Expected: abcdef" << endl;

    // One empty string
    cout << sol.shortestCommonSupersequence("", "abc") 
         << " -> Expected: abc" << endl;

    cout << sol.shortestCommonSupersequence("abc", "") 
         << " -> Expected: abc" << endl;

    // Partial overlap
    cout << sol.shortestCommonSupersequence("geek", "eke") 
         << " -> Expected: geeke" << endl;

    // Another tricky case
    cout << sol.shortestCommonSupersequence("AGGTAB", "GXTXAYB") 
         << " -> Expected: AGGXTXAYB" << endl;

    return 0;
}

// Bottom Up Approach : 
// Time Complexity : O(n^2)
// Space Complexity : O(n^2)