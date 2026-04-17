#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    unordered_map<int, vector<string>>memo;

    vector<string> solve(string &s, unordered_set<string>&dict, int i) {

        
        if(i >= s.length()) {
            return {""};
        }
        
        
        if(memo.count(i)) {
            return memo[i];
        }
        
        vector<string> sentence;

        for(int l = 1; l + i <= s.length(); l ++){

            string word = s.substr(i, l);

            if(dict.count(word)) {

                vector<string> suffix = solve(s, dict, i + l);

                for(string &suff : suffix) {

                    string temp = word;

                    if(suff != "") {
                        temp = temp + " " + suff;
                    }

                    sentence.push_back(temp);
                }
            }
        }

        return memo[i] = sentence;

    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        this->n = s.length();

        unordered_set<string>dict(wordDict.begin(), wordDict.end());

        return solve(s, dict, 0); 
        
    }
};

int main() {
    Solution sol;

    // Test Case 1
    string s1 = "catsanddog";
    vector<string> wordDict1 = {"cat", "cats", "and", "sand", "dog"};
    vector<string> result1 = sol.wordBreak(s1, wordDict1);

    cout << "Test Case 1: \"" << s1 << "\"" << endl;
    cout << "Dictionary: [";
    for (int i = 0; i < wordDict1.size(); ++i) {
        cout << "\"" << wordDict1[i] << "\"";
        if (i < wordDict1.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    cout << "Output: [";
    for (int i = 0; i < result1.size(); ++i) {
        cout << "\"" << result1[i] << "\"";
        if (i < result1.size() - 1) cout << ", ";
    }
    cout << "]" << endl << endl;

    // Test Case 2
    string s2 = "pineapplepenapple";
    vector<string> wordDict2 = {"apple", "pen", "applepen", "pine", "pineapple"};
    vector<string> result2 = sol.wordBreak(s2, wordDict2);

    cout << "Test Case 2: \"" << s2 << "\"" << endl;
    cout << "Dictionary: [";
    for (int i = 0; i < wordDict2.size(); ++i) {
        cout << "\"" << wordDict2[i] << "\"";
        if (i < wordDict2.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    cout << "Output: [";
    for (int i = 0; i < result2.size(); ++i) {
        cout << "\"" << result2[i] << "\"";
        if (i < result2.size() - 1) cout << ", ";
    }
    cout << "]" << endl << endl;

    // Test Case 3
    string s3 = "catsandog";
    vector<string> wordDict3 = {"cats", "dog", "sand", "and", "cat"};
    vector<string> result3 = sol.wordBreak(s3, wordDict3);

    cout << "Test Case 3: \"" << s3 << "\"" << endl;
    cout << "Dictionary: [";
    for (int i = 0; i < wordDict3.size(); ++i) {
        cout << "\"" << wordDict3[i] << "\"";
        if (i < wordDict3.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    cout << "Output: [";
    for (int i = 0; i < result3.size(); ++i) {
        cout << "\"" << result3[i] << "\"";
        if (i < result3.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}