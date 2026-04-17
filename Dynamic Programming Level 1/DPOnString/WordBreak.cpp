/*
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int memo[301];

    bool solve(string s, set<string>& dict, int idx){

        if(idx == s.length())
        return true;

        if(memo[idx] != -1)
        return memo[idx];

        for(int l = 1; idx + l <= s.length(); l++){

            string str = s.substr(idx , l);

            if(dict.find(str) != dict.end() && solve(s, dict, idx + l)){
                return memo[idx] = true;
            }

        }

        return memo[idx] = false;

    }

    bool wordBreak(string s, vector<string>& wordDict) {

        set<string>dict(begin(wordDict), end(wordDict));

        memset(memo, -1, sizeof(memo));

        return solve(s, dict, 0);
    }
};

int main() {
    Solution sol;

    vector<pair<string, vector<string>>> tests = {
        {"leetcode", {"leet", "code"}},
        {"applepenapple", {"apple", "pen"}},
        {"catsandog", {"cats","dog","sand","and","cat"}},
        {"a", {"a"}},
        {"a", {"b"}},
        {"aaaaaaa", {"aaaa","aaa"}},
        {"cars", {"car","ca","rs"}},
        {"catsanddog", {"cats","dog","sand","and","cat"}},
        {"abcd", {"a","abc","b","cd"}},
        {"abcd", {"ab","abc","cd","def"}},
        {"abcd", {"ab","abc","cd","def","abcdx"}},
        {"abcd", {"ab","abc","cd","def","x"}},
        {"", {"a","b"}},
        {"aaaaaaaaaaaaaaaaaaaaaaaaaaaaab", {"a","aa","aaa","aaaa","aaaaa"}},
        {"aaaaaaaaaaaaaaaa", {"a","aa","aaa","aaaa"}}
    };

    vector<bool> expected = {
        true,   // leetcode
        true,   // applepenapple
        false,  // catsandog
        true,   // a with a
        false,  // a with b
        true,   // aaaaaaa
        true,   // cars
        true,   // catsanddog
        true,   // abcd (a + b + cd)
        true,   // abcd (abc + d not possible but ab + cd works)
        true,   // abcd
        true,   // abcd
        true,   // empty string
        false,  // large failing case
        true    // large valid case
    };

    for(int i = 0; i < tests.size(); i++) {
        string s = tests[i].first;
        vector<string> dict = tests[i].second;

        bool result = sol.wordBreak(s, dict);

        cout << "Test Case " << i + 1 << ": ";
        cout << "Output = " << (result ? "true" : "false");
        cout << "   | Expected = " << (expected[i] ? "true" : "false");

        if(result == expected[i]) cout << " [PASS]";
        else cout << "[FAIl]";

        cout << endl;
    }

    return 0;
}
    Top Down Approach :
    Time Complexity : O(n^3)
    Space Complexity : O(n)
*/


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool wordBreak(string s, vector<string>& wordDict) {
    
    int n = s.length();
    unordered_set<string> dict(wordDict.begin(), wordDict.end());

    vector<bool> dp(n + 1, false);
    dp[n] = true;

    for(int i = n - 1; i >= 0; i--){

        for(int l = 1; i + l <= n; l++){

            string str = s.substr(i, l);

            if(dict.count(str) && dp[i + l]){
                dp[i] = true;
                break;
            }
        }
    }

    return dp[0];
}
};

int main() {
    Solution sol;

    vector<pair<string, vector<string>>> tests = {
        {"leetcode", {"leet", "code"}},
        {"applepenapple", {"apple", "pen"}},
        {"catsandog", {"cats","dog","sand","and","cat"}},
        {"a", {"a"}},
        {"a", {"b"}},
        {"aaaaaaa", {"aaaa","aaa"}},
        {"cars", {"car","ca","rs"}},
        {"catsanddog", {"cats","dog","sand","and","cat"}},
        {"abcd", {"a","abc","b","cd"}},
        {"abcd", {"ab","abc","cd","def"}},
        {"abcd", {"ab","abc","cd","def","abcdx"}},
        {"abcd", {"ab","abc","cd","def","x"}},
        {"", {"a","b"}},
        {"aaaaaaaaaaaaaaaaaaaaaaaaaaaaab", {"a","aa","aaa","aaaa","aaaaa"}},
        {"aaaaaaaaaaaaaaaa", {"a","aa","aaa","aaaa"}}
    };

    vector<bool> expected = {
        true,   // leetcode
        true,   // applepenapple
        false,  // catsandog
        true,   // a with a
        false,  // a with b
        true,   // aaaaaaa
        true,   // cars
        true,   // catsanddog
        true,   // abcd (a + b + cd)
        true,   // abcd (abc + d not possible but ab + cd works)
        true,   // abcd
        true,   // abcd
        true,   // empty string
        false,  // large failing case
        true    // large valid case
    };

    for(int i = 0; i < tests.size(); i++) {
        string s = tests[i].first;
        vector<string> dict = tests[i].second;

        bool result = sol.wordBreak(s, dict);

        cout << "Test Case " << i + 1 << ": ";
        cout << "Output = " << (result ? "true" : "false");
        cout << "   | Expected = " << (expected[i] ? "true" : "false");

        if(result == expected[i]) cout << " [PASS]";
        else cout << "[FAIl]";

        cout << endl;
    }

    return 0;
}

// Bottom Up Approach :
// Time Complexity : O(n^3)
// Space Complexity : O(n)