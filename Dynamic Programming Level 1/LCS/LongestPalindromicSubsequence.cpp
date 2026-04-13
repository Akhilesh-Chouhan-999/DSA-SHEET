/*
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int memo[1001][1001];

    int solve(string& s, int i, int j) {

        if(i == j )
        return 1;

        if(i > j)
        return 0 ; 

        if(memo[i][j] != -1)
        return memo[i][j] ; 

        if(s[i] == s[j]){
            return memo[i][j] = 2 + solve(s , i + 1 , j - 1) ; 
        } 

        else{
            return memo[i][j] = max(solve(s , i + 1 , j ) ,  solve(s , i , j - 1)) ; 
        }

    }
    int longestPalindromeSubseq(string s) {
    
        if(s.length() == 1)
        return 1 ; 

        memset(memo, -1, sizeof(memo)) ; 

        return solve(s , 0 , s.length() - 1) ; 

    }
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution obj;

    // Test Case 1
    string s = "bbbab";
    cout << "Input: " << s << endl;
    cout << "Output: " << obj.longestPalindromeSubseq(s) << endl;
    cout << "Expected: 4" << endl;
    cout << "-------------------" << endl;

    // Test Case 2
    s = "cbbd";
    cout << "Input: " << s << endl;
    cout << "Output: " << obj.longestPalindromeSubseq(s) << endl;
    cout << "Expected: 2" << endl;
    cout << "-------------------" << endl;

    // Test Case 3
    s = "agbdba";
    cout << "Input: " << s << endl;
    cout << "Output: " << obj.longestPalindromeSubseq(s) << endl;
    cout << "Expected: 5" << endl; // "abdba"
    cout << "-------------------" << endl;

    // Test Case 4
    s = "a";
    cout << "Input: " << s << endl;
    cout << "Output: " << obj.longestPalindromeSubseq(s) << endl;
    cout << "Expected: 1" << endl;
    cout << "-------------------" << endl;

    // Test Case 5
    s = "character";
    cout << "Input: " << s << endl;
    cout << "Output: " << obj.longestPalindromeSubseq(s) << endl;
    cout << "Expected: 5" << endl; // "carac"

    return 0;
}
    Top Down Approach :
    Time complexity : O(n^2)
    Space Complexity : O(n^2)

*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

  int longestPalindromeSubseq(string s) {

    int n = s.length();

    vector<vector<int>> t(n, vector<int>(n, 0));

    for(int i = n - 1; i >= 0; i--) {

        t[i][i] = 1; 

        for(int j = i + 1; j < n; j++) {

            if(s[i] == s[j]) {
                t[i][j] = 2 + t[i + 1][j - 1];
            } 
            else {
                t[i][j] = max(t[i + 1][j], t[i][j - 1]);
            }
        }
    }

    return t[0][n - 1];
    }
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution obj;

    // Test Case 1
    string s = "bbbab";
    cout << "Input: " << s << endl;
    cout << "Output: " << obj.longestPalindromeSubseq(s) << endl;
    cout << "Expected: 4" << endl;
    cout << "-------------------" << endl;

    // Test Case 2
    s = "cbbd";
    cout << "Input: " << s << endl;
    cout << "Output: " << obj.longestPalindromeSubseq(s) << endl;
    cout << "Expected: 2" << endl;
    cout << "-------------------" << endl;

    // Test Case 3
    s = "agbdba";
    cout << "Input: " << s << endl;
    cout << "Output: " << obj.longestPalindromeSubseq(s) << endl;
    cout << "Expected: 5" << endl; // "abdba"
    cout << "-------------------" << endl;

    // Test Case 4
    s = "a";
    cout << "Input: " << s << endl;
    cout << "Output: " << obj.longestPalindromeSubseq(s) << endl;
    cout << "Expected: 1" << endl;
    cout << "-------------------" << endl;

    // Test Case 5
    s = "character";
    cout << "Input: " << s << endl;
    cout << "Output: " << obj.longestPalindromeSubseq(s) << endl;
    cout << "Expected: 5" << endl; // "carac"

    return 0;
}