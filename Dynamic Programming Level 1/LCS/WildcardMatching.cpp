/*

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int m;
    int n;
    int memo[2001][2001];
    
    bool solve(string& s, string &p, int i, int j) {

        if(i == m && j == n)
        return true;

        if(j == n)
        return false;

        
        if(i == m){

            for(int idx = j; idx < n; idx ++){
                if(p[idx] != '*')
                return false;
            }

            return true;
        }

        if(s[i] != p[j] && p[j] != '?' && p[j] != '*')
        return false;

        if(memo[i][j] != -1)
        return memo[i][j];


        bool option1 = false, option2 = false; 

        if(s[i] == p[j] || p[j] == '?'){
          option1 = solve(s, p, i + 1, j + 1);
        }
        else if(p[j] == '*'){
            option2 = solve(s, p, i + 1, j) || solve(s, p, i, j + 1);
        }

        return memo[i][j] = option1 || option2;
    }


    bool isMatch(string s, string p) {

        m = s.length();
        n = p.length();

        memset(memo, -1 , sizeof(memo));

        return solve(s, p, 0, 0);
    }
};

int main() {
    Solution sol;

    // Basic cases
    cout << sol.isMatch("aa", "a") << " -> Expected: 0" << endl;
    cout << sol.isMatch("aa", "*") << " -> Expected: 1" << endl;
    cout << sol.isMatch("cb", "?a") << " -> Expected: 0" << endl;

    // Exact match
    cout << sol.isMatch("abc", "abc") << " -> Expected: 1" << endl;

    // '?' cases
    cout << sol.isMatch("abc", "a?c") << " -> Expected: 1" << endl;
    cout << sol.isMatch("abc", "??c") << " -> Expected: 1" << endl;
    cout << sol.isMatch("abc", "??d") << " -> Expected: 0" << endl;

    // '*' cases
    cout << sol.isMatch("abc", "*") << " -> Expected: 1" << endl;
    cout << sol.isMatch("abc", "a*") << " -> Expected: 1" << endl;
    cout << sol.isMatch("abc", "*c") << " -> Expected: 1" << endl;
    cout << sol.isMatch("abc", "a*c") << " -> Expected: 1" << endl;
    cout << sol.isMatch("abc", "a*d") << " -> Expected: 0" << endl;

    // Mix of '?' and '*'
    cout << sol.isMatch("abcd", "a*?d") << " -> Expected: 1" << endl;
    cout << sol.isMatch("abcd", "a*?c") << " -> Expected: 0" << endl;
    cout << sol.isMatch("abcd", "?*?c") << " -> Expected: 0" << endl;

    // Edge cases
    cout << sol.isMatch("", "") << " -> Expected: 1" << endl;
    cout << sol.isMatch("", "*") << " -> Expected: 1" << endl;
    cout << sol.isMatch("", "?") << " -> Expected: 0" << endl;
    cout << sol.isMatch("a", "") << " -> Expected: 0" << endl;

    // Consecutive '*'
    cout << sol.isMatch("abcde", "a**b**c*de") << " -> Expected: 1" << endl;

    // Tricky / interview-level
    cout << sol.isMatch("mississippi", "m*si*pi") << " -> Expected: 1" << endl;
    cout << sol.isMatch("adceb", "*a*b") << " -> Expected: 1" << endl;
    cout << sol.isMatch("acdcb", "a*c?b") << " -> Expected: 0" << endl;

    return 0;
}
    Top Down Approach :
    Time Complexity : O(m*n + n*n)
    Space Complexity : O(m*n)    
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

bool isMatch(string s, string p) {

        int m = s.length();
        int n = p.length();

        vector<vector<int>>t(m + 1, vector<int>(n + 1, false)) ; 

        t[m][n] = true;


        for(int j = n - 1 ; j >= 0 ; j --){

            if(p[j] == '*'){
                t[m][j] = t[m][j+1];
            }else{
                t[m][j] = false;
            }

        }

        for(int i = m - 1; i >= 0; i --){
            for(int j = n - 1;  j >= 0; j --){

              
                if(s[i] == p[j] || p[j] == '?'){
                    t[i][j] = t[i + 1][j + 1];
                }
                else if(p[j] == '*'){
                    t[i][j] = t[i + 1][j] || t[i][j + 1];
                }
                else{
                    t[i][j] = false;
                }

            }
        }

    return t[0][0] ;
       
    }
};

int main() {
    Solution sol;

    // Basic cases
    cout << sol.isMatch("aa", "a") << " -> Expected: 0" << endl;
    cout << sol.isMatch("aa", "*") << " -> Expected: 1" << endl;
    cout << sol.isMatch("cb", "?a") << " -> Expected: 0" << endl;

    // Exact match
    cout << sol.isMatch("abc", "abc") << " -> Expected: 1" << endl;

    // '?' cases
    cout << sol.isMatch("abc", "a?c") << " -> Expected: 1" << endl;
    cout << sol.isMatch("abc", "??c") << " -> Expected: 1" << endl;
    cout << sol.isMatch("abc", "??d") << " -> Expected: 0" << endl;

    // '*' cases
    cout << sol.isMatch("abc", "*") << " -> Expected: 1" << endl;
    cout << sol.isMatch("abc", "a*") << " -> Expected: 1" << endl;
    cout << sol.isMatch("abc", "*c") << " -> Expected: 1" << endl;
    cout << sol.isMatch("abc", "a*c") << " -> Expected: 1" << endl;
    cout << sol.isMatch("abc", "a*d") << " -> Expected: 0" << endl;

    // Mix of '?' and '*'
    cout << sol.isMatch("abcd", "a*?d") << " -> Expected: 1" << endl;
    cout << sol.isMatch("abcd", "a*?c") << " -> Expected: 0" << endl;
    cout << sol.isMatch("abcd", "?*?c") << " -> Expected: 0" << endl;

    // Edge cases
    cout << sol.isMatch("", "") << " -> Expected: 1" << endl;
    cout << sol.isMatch("", "*") << " -> Expected: 1" << endl;
    cout << sol.isMatch("", "?") << " -> Expected: 0" << endl;
    cout << sol.isMatch("a", "") << " -> Expected: 0" << endl;

    // Consecutive '*'
    cout << sol.isMatch("abcde", "a**b**c*de") << " -> Expected: 1" << endl;

    // Tricky / interview-level
    cout << sol.isMatch("mississippi", "m*si*pi") << " -> Expected: 1" << endl;
    cout << sol.isMatch("adceb", "*a*b") << " -> Expected: 1" << endl;
    cout << sol.isMatch("acdcb", "a*c?b") << " -> Expected: 0" << endl;

    return 0;
}

// Bottom Up Approach :
// Time Complexity : O(m*n)
// Space Complexity : O(m*n)

