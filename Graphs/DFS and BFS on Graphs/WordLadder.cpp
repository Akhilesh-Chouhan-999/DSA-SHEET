#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        queue<pair<string, int>>que;
        unordered_set<string>st(begin(wordList), end(wordList));
        unordered_set<string>visited;

        que.push({beginWord, 1});
        visited.insert(beginWord);

        while(!que.empty()) {

            string currStr = que.front().first;
            int currLevel = que.front().second;
            que.pop();

            if(currStr == endWord) {
                return currLevel;
            }

            for(int i = 0; i < currStr.length(); i ++) {

                string temp = currStr;

                for(int j = 0; j < 26; j ++) {

                    temp[i] = 'a' + j;

                    if(st.find(temp) != st.end() && visited.find(temp) == visited.end()) {

                        que.push({temp, currLevel + 1});
                        visited.insert(temp);
                        
                    }
                    
                }
            }
        }

        return 0;

    }
};


int main() {
    Solution sol;

    // Test Case 1: From the problem description
    {
        string beginWord = "hit";
        string endWord = "cog";
        vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
        
        cout << "Test Case 1:" << endl;
        cout << "Input: beginWord = \"" << beginWord << "\", endWord = \"" << endWord << "\", wordList = [";
        for (int i = 0; i < wordList.size(); ++i) {
            cout << "\"" << wordList[i] << "\"";
            if (i < wordList.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
        
        int result = sol.ladderLength(beginWord, endWord, wordList);
        cout << "Output: " << result << endl;
        cout << "Expected: 5" << endl << endl;
    }

    // Test Case 2: endWord not in list
    {
        string beginWord = "hit";
        string endWord = "cog";
        vector<string> wordList = {"hot", "dot", "dog", "lot", "log"};
        
        cout << "Test Case 2:" << endl;
        cout << "Input: beginWord = \"" << beginWord << "\", endWord = \"" << endWord << "\", wordList = [";
        for (int i = 0; i < wordList.size(); ++i) {
            cout << "\"" << wordList[i] << "\"";
            if (i < wordList.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
        
        int result = sol.ladderLength(beginWord, endWord, wordList);
        cout << "Output: " << result << endl;
        cout << "Expected: 0" << endl << endl;
    }

    // Test Case 3: Simple transformation
    {
        string beginWord = "cat";
        string endWord = "dog";
        vector<string> wordList = {"cat", "cot", "cog", "dog"};
        
        cout << "Test Case 3:" << endl;
        cout << "Input: beginWord = \"" << beginWord << "\", endWord = \"" << endWord << "\", wordList = [";
        for (int i = 0; i < wordList.size(); ++i) {
            cout << "\"" << wordList[i] << "\"";
            if (i < wordList.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
        
        int result = sol.ladderLength(beginWord, endWord, wordList);
        cout << "Output: " << result << endl;
        // Path: cat -> cot -> cog -> dog (4 words)
        cout << "Expected: 4" << endl;
    }

    return 0;
}

/*
    Time Complexity : O(N * L * 26)
    Space Complexity : O(N)
        N = number of words in wordList
        L = length of each word
*/