/*
#include<bits/stdc++.h>
using namespace std; 
class Solution {
  public:

    int m;
    int n;   
    int memo[1001][1001]; 
    set<string>answer ; 

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

        memset(memo, -1, sizeof(memo));
        
        return solve(text1, text2, 0, 0); 

    }

    void genLCS(string &s1, string &s2, int i, int j, string res, int len) {


        if(len == 0) {
            answer.insert(res);
            return;
        }

        if(i >= m || j >= n) 
        return;

        if(s1[i] == s2[j]){
            res.push_back(s1[i]);
            genLCS(s1, s2, i + 1, j + 1, res, len - 1); 
        }
        else{
            genLCS(s1, s2, i+1, j, res, len);
            genLCS(s1, s2, i, j+1, res, len);
        }

        return ; 
    }

    vector<string> allLCS(string &s1, string &s2) {

        this -> m = s1.size(); 
        this -> n = s2.size();
        
        int lenOfLCS = longestCommonSubsequence(s1, s2);

        genLCS(s1, s2, 0, 0, "", lenOfLCS) ;

        vector<string>result(begin(answer), end(answer));

        return result ; 
        
    }
};
int main() {

    Solution obj;

    // Test Case 1
    string s1 = "abcabcaa";
    string s2 = "acbacba";

    vector<string> res = obj.allLCS(s1, s2);

    cout << "All LCS:\n";
    for(auto &str : res) {
        cout << str << endl;
    }

    cout << "-------------------\n";

    // Test Case 2
    s1 = "abc";
    s2 = "ac";

    res = obj.allLCS(s1, s2);

    cout << "All LCS:\n";
    for(auto &str : res) {
        cout << str << endl;
    }

    cout << "-------------------\n";

    // Test Case 3
    s1 = "AGGTAB";
    s2 = "GXTXAYB";

    res = obj.allLCS(s1, s2);

    cout << "All LCS:\n";
    for(auto &str : res) {
        cout << str << endl;
    }

    return 0;
}

Brute Force :
    Time Complexity  : O(2^(m+n))
    Space Complexity : O(m*n)
*/

#include<bits/stdc++.h>
using namespace std; 
class Solution {
  public:

    int m;
    int n;   
    int memo[1001][1001]; 
    set<string>answer ; 

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

        memset(memo, -1, sizeof(memo));
        
        return solve(text1, text2, 0, 0); 

    }

    void genLCS(string &s1, string &s2, int i, int j, string res, int len) {


        if(len == 0) {
            answer.insert(res);
            return;
        }

        if(i >= m || j >= n) 
        return;

        if(s1[i] == s2[j]){
            res.push_back(s1[i]);
            genLCS(s1, s2, i + 1, j + 1, res, len - 1); 
        }
        else{
            genLCS(s1, s2, i+1, j, res, len);
            genLCS(s1, s2, i, j+1, res, len);
        }

        return ; 
    }

    vector<string> allLCS(string &s1, string &s2) {

        this -> m = s1.size(); 
        this -> n = s2.size();
        
        int lenOfLCS = longestCommonSubsequence(s1, s2);

        genLCS(s1, s2, 0, 0, "", lenOfLCS) ;

        vector<string>result(begin(answer), end(answer));

        return result ; 
        
    }
};
int main() {

    Solution obj;

    // Test Case 1
    string s1 = "abcabcaa";
    string s2 = "acbacba";

    vector<string> res = obj.allLCS(s1, s2);

    cout << "All LCS:\n";
    for(auto &str : res) {
        cout << str << endl;
    }

    cout << "-------------------\n";

    // Test Case 2
    s1 = "abc";
    s2 = "ac";

    res = obj.allLCS(s1, s2);

    cout << "All LCS:\n";
    for(auto &str : res) {
        cout << str << endl;
    }

    cout << "-------------------\n";

    // Test Case 3
    s1 = "AGGTAB";
    s2 = "GXTXAYB";

    res = obj.allLCS(s1, s2);

    cout << "All LCS:\n";
    for(auto &str : res) {
        cout << str << endl;
    }

    return 0;
}