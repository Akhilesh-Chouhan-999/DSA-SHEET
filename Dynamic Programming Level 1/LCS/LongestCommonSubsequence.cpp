/*

#include<bits/stdc++.h>
using namespace std  ; 

class Solution {
public:
    int m;
    int n;
    int memo[1001][1001]; 

    int solve(string& s1, string &s2, int i, int j) {

        if( i == m || j == n)
        return 0 ; 
        

        if(memo[i][j] != -1)
        return memo[i][j];

        if(s1[i] == s2[j]) {
            return memo[i][j] = 1 + solve(s1, s2, i + 1, j + 1);
        }
        else {
            return memo[i][j] = max(solve(s1, s2, i + 1, j) , solve(s1, s2, i, j + 1));
        }
        
    }

    int longestCommonSubsequence(string text1, string text2) {
        
        this -> m = text1.size(); 
        this -> n = text2.size();
        
        memset(memo, -1, sizeof(memo));
        
        return solve(text1, text2, 0, 0); 

    }
};

int main() {

    Solution obj;

    // Test Case 1
    string text1 = "abcde", text2 = "ace";
    cout << "Output 1: " << obj.longestCommonSubsequence(text1, text2) << endl;
    cout << "Expected: 3" << endl << endl;

    // Test Case 2
    string text3 = "abc", text4 = "abc";
    cout << "Output 2: " << obj.longestCommonSubsequence(text3, text4) << endl;
    cout << "Expected: 3" << endl << endl;

    // Test Case 3
    string text5 = "abc", text6 = "def";
    cout << "Output 3: " << obj.longestCommonSubsequence(text5, text6) << endl;
    cout << "Expected: 0" << endl;

    return 0;
}

Top Down Approach :
Time Complexity  : O(m*n)
Space Complexity : O(m*n)
*/

#include<bits/stdc++.h>
using namespace std  ; 

class Solution {
public:
    
    int longestCommonSubsequence(string s1, string s2) {
        
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

        return t[0][0] ; 
    }
};

int main() {

    Solution obj;

    // Test Case 1
    string text1 = "abcde", text2 = "ace";
    cout << "Output 1: " << obj.longestCommonSubsequence(text1, text2) << endl;
    cout << "Expected: 3" << endl << endl;

    // Test Case 2
    string text3 = "abc", text4 = "abc";
    cout << "Output 2: " << obj.longestCommonSubsequence(text3, text4) << endl;
    cout << "Expected: 3" << endl << endl;

    // Test Case 3
    string text5 = "abc", text6 = "def";
    cout << "Output 3: " << obj.longestCommonSubsequence(text5, text6) << endl;
    cout << "Expected: 0" << endl;

    return 0;
}

// Time Complexity : O(m*n)
// Space Complexity : O(m*n)

