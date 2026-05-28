#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isVowel(char ch) {

        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {

            return true;
        }

        return false;
    }

    int maxVowels(string s, int k) {
        
        int n = s.length() ;

        int i = 0;
        int j = 0;
        unordered_map<char, int> freq;

        int result = INT_MIN;

        while(j < n) {

            if(isVowel(s[j])) {

                freq[s[j]] ++;
            }


            if(j - i + 1 == k) {

                int currFreqVowel = 0;

                for(auto [first, second] : freq) {

                    currFreqVowel += second;
                }

                result = max(result, currFreqVowel);

                if(isVowel(s[i])) {

                    if( -- freq[s[i]] == 0) {

                        freq.erase(s[i]);
                    }
                }

                i ++;
            }

            j ++;

        }

        return result;
    }
};


int main() {
    string s;
    int k;

    // Example 1: Input: s = "abciiidef", k = 3
    // You can modify these lines to test other cases
    s = "abciiidef";
    k = 3;

    // If you want to read from standard input instead, uncomment the lines below:
    // cin >> s >> k;

    Solution sol;
    int result = sol.maxVowels(s, k);

    cout << "Input: s = \"" << s << "\", k = " << k << endl;
    cout << "Output: " << result << endl;

    return 0;
}
/*
    Time Complexity : O(n)
    Space Complexity : O(1)
*/