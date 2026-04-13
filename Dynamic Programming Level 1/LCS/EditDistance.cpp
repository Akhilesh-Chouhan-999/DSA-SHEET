/*
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int memo[501][501] ; 


    int solve(string& s1, string& s2, int i, int j) {

        if(j == s2.length()){
            return (s1.length() - i) ;
        }

        if(i == s1.length()){
            return (s2.length() - j) ;
        }

        if(memo[i][j] != -1)
        return memo[i][j];

        if(s1[i] == s2[j]){
            return memo[i][j] = solve(s1, s2, i + 1, j+1) ; 
        }
        else{

            int ins = solve(s1, s2, i + 1, j + 1) ;
            int del = solve(s1, s2, i, j + 1);
            int rep = solve(s1, s2, i + 1, j);

            return memo[i][j] = 1 + min(ins, min(del, rep)) ; 
        }
    }

    int minDistance(string word1, string word2) {

        memset(memo, -1, sizeof(memo));

        return solve(word1, word2, 0, 0);

    }
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution obj;

    // Test Case 1
    string word1 = "horse", word2 = "ros";
    cout << "Input: " << word1 << ", " << word2 << endl;
    cout << "Output: " << obj.minDistance(word1, word2) << endl;
    cout << "Expected: 3" << endl;
    cout << "-------------------" << endl;

    // Test Case 2
    word1 = "intention"; word2 = "execution";
    cout << "Input: " << word1 << ", " << word2 << endl;
    cout << "Output: " << obj.minDistance(word1, word2) << endl;
    cout << "Expected: 5" << endl;
    cout << "-------------------" << endl;

    // Test Case 3 (edge case)
    word1 = ""; word2 = "abc";
    cout << "Input: \"" << word1 << "\", " << word2 << endl;
    cout << "Output: " << obj.minDistance(word1, word2) << endl;
    cout << "Expected: 3" << endl;
    cout << "-------------------" << endl;

    // Test Case 4 (same strings)
    word1 = "abc"; word2 = "abc";
    cout << "Input: " << word1 << ", " << word2 << endl;
    cout << "Output: " << obj.minDistance(word1, word2) << endl;
    cout << "Expected: 0" << endl;
    cout << "-------------------" << endl;

    // Test Case 5 (one char)
    word1 = "a"; word2 = "b";
    cout << "Input: " << word1 << ", " << word2 << endl;
    cout << "Output: " << obj.minDistance(word1, word2) << endl;
    cout << "Expected: 1" << endl;

    return 0;
}

Top Down Approach : 
Time Complexity : O(m*n)
Space Complexity : O(m*n)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int minDistance(string word1, string word2) {

        int m = word1.size();
        int n = word2.size();

        vector<vector<int>>t(m+1, vector<int>(n+1, 0)) ; 

        for(int i = 0 ; i <= m ; i ++){
            t[i][n] = (m - i) ;
        }

        for(int j = 0 ; j <= n ; j ++){
            t[m][j] = (n - j);
        }

        for(int i = m - 1; i >= 0; i --){

            for(int j = n - 1 ; j >= 0; j --){

                if(word1[i] == word2[j]){
                     t[i][j] = t[i+1][j+1] ; 
                }
                else{

                    int ins = t[i + 1][ j + 1] ;
                    int del = t[i][ j + 1];
                    int rep = t[i+1][j];

                     t[i][j] = 1 + min(ins, min(del, rep)) ; 
                }
            }
        }

        return t[0][0] ;
    }
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution obj;

    // Test Case 1
    string word1 = "horse", word2 = "ros";
    cout << "Input: " << word1 << ", " << word2 << endl;
    cout << "Output: " << obj.minDistance(word1, word2) << endl;
    cout << "Expected: 3" << endl;
    cout << "-------------------" << endl;

    // Test Case 2
    word1 = "intention"; word2 = "execution";
    cout << "Input: " << word1 << ", " << word2 << endl;
    cout << "Output: " << obj.minDistance(word1, word2) << endl;
    cout << "Expected: 5" << endl;
    cout << "-------------------" << endl;

    // Test Case 3 (edge case)
    word1 = ""; word2 = "abc";
    cout << "Input: \"" << word1 << "\", " << word2 << endl;
    cout << "Output: " << obj.minDistance(word1, word2) << endl;
    cout << "Expected: 3" << endl;
    cout << "-------------------" << endl;

    // Test Case 4 (same strings)
    word1 = "abc"; word2 = "abc";
    cout << "Input: " << word1 << ", " << word2 << endl;
    cout << "Output: " << obj.minDistance(word1, word2) << endl;
    cout << "Expected: 0" << endl;
    cout << "-------------------" << endl;

    // Test Case 5 (one char)
    word1 = "a"; word2 = "b";
    cout << "Input: " << word1 << ", " << word2 << endl;
    cout << "Output: " << obj.minDistance(word1, word2) << endl;
    cout << "Expected: 1" << endl;

    return 0;
}

