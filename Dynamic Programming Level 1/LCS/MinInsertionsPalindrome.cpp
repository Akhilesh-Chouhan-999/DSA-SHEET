/*
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int memo[501][501] ; 

    int solve(string& s, int i, int j) {

        if( i == j || i > j)
        return 0 ; 

        if(memo[i][j] != -1){
            return memo[i][j] ;
        }

        if(s[i] == s[j]){
            return memo[i][j] = solve(s, i + 1, j - 1);
        }
        else{
            return memo[i][j] = 1 + min(solve(s, i + 1, j) , solve(s, i, j - 1));
        }

    }

    int minInsertions(string s) {
        
        int n = s.length(); 

        memset(memo, -1 ,sizeof(memo)) ;

        return solve(s, 0, n-1) ; 
    }
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution obj;

    // Test Case 1
    string s = "abca";
    cout << "Input: " << s << endl;
    cout << "Output: " << obj.minInsertions(s) << endl;
    cout << "Expected: 1" << endl;
    cout << "-------------------" << endl;

    // Test Case 2
    s = "abc";
    cout << "Input: " << s << endl;
    cout << "Output: " << obj.minInsertions(s) << endl;
    cout << "Expected: 2" << endl;
    cout << "-------------------" << endl;

    // Test Case 3
    s = "race";
    cout << "Input: " << s << endl;
    cout << "Output: " << obj.minInsertions(s) << endl;
    cout << "Expected: 3" << endl;
    cout << "-------------------" << endl;

    // Test Case 4 (already palindrome)
    s = "madam";
    cout << "Input: " << s << endl;
    cout << "Output: " << obj.minInsertions(s) << endl;
    cout << "Expected: 0" << endl;
    cout << "-------------------" << endl;

    // Test Case 5 (edge case)
    s = "";
    cout << "Input: \"" << s << "\"" << endl;
    cout << "Output: " << obj.minInsertions(s) << endl;
    cout << "Expected: 0" << endl;

    return 0;
}

    Top Down Approach :
    Time Complexity : O(n*n)
    Space Complexity : O(n*n)
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int memo[501][501] ; 

    int solve(string& s, int i, int j) {

        if( i == j || i > j)
        return 0 ; 

        if(memo[i][j] != -1){
            return memo[i][j] ;
        }

        if(s[i] == s[j]){
            return memo[i][j] = solve(s, i + 1, j - 1);
        }
        else{
            return memo[i][j] = 1 + min(solve(s, i + 1, j) , solve(s, i, j - 1));
        }

    }

    int minInsertions(string s) {

        int n = s.length() ; 

        vector<vector<int>>t(n + 1, vector<int>(n + 1, 0));

        for(int i = n - 1; i >= 0; i --){
            for(int j = i + 1; j < n; j ++){

                if(s[i] == s[j]){
                    t[i][j] = t[i + 1][j - 1];
                }
                else{
                    t[i][j] = 1 + min(t[i + 1][j] , t[i][j - 1]);
                }
            }
        }

        return t[0][n-1];

    }
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution obj;

    // Test Case 1
    string s = "abca";
    cout << "Input: " << s << endl;
    cout << "Output: " << obj.minInsertions(s) << endl;
    cout << "Expected: 1" << endl;
    cout << "-------------------" << endl;

    // Test Case 2
    s = "abc";
    cout << "Input: " << s << endl;
    cout << "Output: " << obj.minInsertions(s) << endl;
    cout << "Expected: 2" << endl;
    cout << "-------------------" << endl;

    // Test Case 3
    s = "race";
    cout << "Input: " << s << endl;
    cout << "Output: " << obj.minInsertions(s) << endl;
    cout << "Expected: 3" << endl;
    cout << "-------------------" << endl;

    // Test Case 4 (already palindrome)
    s = "madam";
    cout << "Input: " << s << endl;
    cout << "Output: " << obj.minInsertions(s) << endl;
    cout << "Expected: 0" << endl;
    cout << "-------------------" << endl;

    // Test Case 5 (edge case)
    s = "";
    cout << "Input: \"" << s << "\"" << endl;
    cout << "Output: " << obj.minInsertions(s) << endl;
    cout << "Expected: 0" << endl;

    return 0;
}

//     Top Down Approach :
//     Time Complexity : O(n*n)
//     Space Complexity : O(n*n)
//     dp[i][j] = minimum operations required to make the substring s[i…j] a palindrome