#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length();

        int i = 0;
        int j = 0;

        unordered_set<char> vis;

        int result = 0;

        while(j < n) {

            char ch = s[j];

            while(vis.find(ch) != vis.end()) {

                vis.erase(s[i]);
                i++;
            }

            vis.insert(ch);

            result = max(result, j - i + 1);

            j++;
        }

        return result;
    }
};

int main() {

    Solution obj;

    string s = "abcabcbb";

    cout << obj.lengthOfLongestSubstring(s);

    return 0;
}

/*
    Time Complexity : O(n)
    Space Complexity : O(k) where k = 26
*/