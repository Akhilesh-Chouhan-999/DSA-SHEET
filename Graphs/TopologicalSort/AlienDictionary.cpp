#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

    bool buildAdjList(unordered_map<int, vector<int>>& adj, vector<int>& inDegree, string curr, string prev) {
        
        
        if(curr.length() < prev.length()) {
            
            if(prev.substr(0, curr.length()) == curr)
            return false;
            
        }
        int length = min(curr.length(), prev.length());

        for(int i = 0; i < length ; i ++) {

            if(prev[i] != curr[i]) {

                adj[prev[i] - 'a'].push_back(curr[i] - 'a');
                inDegree[curr[i]- 'a'] ++;

                break;
            }
        }
        
        return true;


    }
    string findOrder(vector<string> &words) {

        int n = words.size();

        unordered_map<int, vector<int>> adj;
 
        string prev = words[0];
        vector<int> inDegree(26, 0);
        vector<bool> present(26, false);

        for(string word : words) {

            for(char ch : word) {

                present[ch - 'a']  = true;
            }
        }

        for(int i = 1; i < n; i ++) {

            string curr = words[i];

            if(!buildAdjList(adj, inDegree, curr, prev))
            return "";

            prev = curr;
        }

        queue<int>que;

        for(int i = 0; i < 26; i ++) {

            if(inDegree[i] == 0 && present[i]) {
                
                que.push(i);
            }
        }

        string result = "";
        while(!que.empty()) {

            int u = que.front();
            que.pop();

            result += (u + 'a');

            for(int &v : adj[u]) {

                if(--inDegree[v] == 0) {

                    que.push(v);
                }
            }
        }

        for(int i = 0; i < 26; i ++) {

            if(inDegree[i] != 0) {
                return "";
            }
        }
        
        return result;

    }
};


int main() {
    Solution obj;

    // Test Case 1
    {
        cout << "Test Case 1:" << endl;
        vector<string> words1 = {"baa", "abcd", "abca", "cab", "cad"};
        string result = obj.findOrder(words1);
        
        if (result.empty()) {
            cout << "Output: \"\" (Invalid)" << endl;
        } else {
            cout << "Output: \"" << result << "\"" << endl;
            // Explanation verification: 
            // Expected valid order like "bdac" or similar.
            // Note: The problem allows ANY valid order. 
            // Your description says 'b'->'d'->'a'->'c' is valid.
            // Let's see what the topological sort produces.
        }
        cout << "-------------------------" << endl;
    }

    // Test Case 2
    {
        cout << "Test Case 2:" << endl;
        vector<string> words2 = {"caa", "aaa", "aab"};
        string result = obj.findOrder(words2);
        
        if (result.empty()) {
            cout << "Output: \"\" (Invalid)" << endl;
        } else {
            cout << "Output: \"" << result << "\"" << endl;
            // Expected: "cab" (or similar valid order)
        }
        cout << "-------------------------" << endl;
    }

    // Test Case 3
    {
        cout << "Test Case 3:" << endl;
        vector<string> words3 = {"ab", "cd", "ef", "ad"};
        string result = obj.findOrder(words3);
        
        if (result.empty()) {
            cout << "Output: \"\" (Invalid - Cycle detected)" << endl;
        } else {
            cout << "Output: \"" << result << "\"" << endl;
        }
        cout << "-------------------------" << endl;
    }

    return 0;
}