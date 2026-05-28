#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        
        int n = s.length();

        int i = 0; 
        int j = 0;

        unordered_map<char, int> freq;
        unordered_map<string, int> mp;

        int cnt = 0;

        while(j < n) {

            freq[s[j]]++;

            if(j - i + 1 > minSize) {

                if(--freq[s[i]] == 0) {

                    freq.erase(s[i]);
                }

                i ++;
            }

            if(j - i + 1 == minSize) {

                if(freq.size() <= maxLetters) {

                    string temp = s.substr(i, j - i + 1);

                    mp[temp] ++;

                    cnt = max(cnt, mp[temp]);
                }
            }

            j ++;

        }  


        return cnt;
    }
};
int main() {

    Solution sol;

    {
        string s = "aaaa";
        int maxLetters = 1;
        int minSize = 2;
        int maxSize = 3;

        cout << sol.maxFreq(s, maxLetters, minSize, maxSize) << endl;
        // Expected: 3
    }

    {
        string s = "aabcabcab";
        int maxLetters = 2;
        int minSize = 2;
        int maxSize = 3;

        cout << sol.maxFreq(s, maxLetters, minSize, maxSize) << endl;
        // Expected: 3
    }

    {
        string s = "abcaab";
        int maxLetters = 2;
        int minSize = 2;
        int maxSize = 3;

        cout << sol.maxFreq(s, maxLetters, minSize, maxSize) << endl;
        // Expected: 2
    }

    {
        string s = "abababab";
        int maxLetters = 2;
        int minSize = 2;
        int maxSize = 4;

        cout << sol.maxFreq(s, maxLetters, minSize, maxSize) << endl;
        // Expected: 4
    }

    {
        string s = "abcabcabc";
        int maxLetters = 3;
        int minSize = 2;
        int maxSize = 4;

        cout << sol.maxFreq(s, maxLetters, minSize, maxSize) << endl;
        // Expected: 3
    }

    {
        string s = "zzzzzz";
        int maxLetters = 1;
        int minSize = 2;
        int maxSize = 5;

        cout << sol.maxFreq(s, maxLetters, minSize, maxSize) << endl;
        // Expected: 5
    }

    {
        string s = "abcdef";
        int maxLetters = 2;
        int minSize = 2;
        int maxSize = 3;

        cout << sol.maxFreq(s, maxLetters, minSize, maxSize) << endl;
        // Expected: 1
    }

    {
        string s = "aaabbb";
        int maxLetters = 1;
        int minSize = 2;
        int maxSize = 3;

        cout << sol.maxFreq(s, maxLetters, minSize, maxSize) << endl;
        // Expected: 2
    }

    {
        string s = "abcdeabcde";
        int maxLetters = 5;
        int minSize = 5;
        int maxSize = 5;

        cout << sol.maxFreq(s, maxLetters, minSize, maxSize) << endl;
        // Expected: 2
    }

    {
        string s = "ababcbabab";
        int maxLetters = 2;
        int minSize = 3;
        int maxSize = 4;

        cout << sol.maxFreq(s, maxLetters, minSize, maxSize) << endl;
        // Expected: 2
    }

    return 0;
}

/*
    Time Complexity : O(n * minSize)
    Space Complexity :  O(n * minSize)
*/