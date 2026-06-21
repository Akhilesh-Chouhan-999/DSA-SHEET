#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        
        
        int V = colors.size();
        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(V, 0);
        
        for(vector<int>& edge : edges) {
            
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            inDegree[v] ++;
        }


        queue<int>que;
        int cnt = 0;
        int answer = 1;
        vector<vector<int>>t(V, vector<int>(26, 0));

        for(int i = 0; i < V; i ++) {

            if(inDegree[i] == 0) {

                que.push(i);
                t[i][colors[i] - 'a'] = 1;
                cnt ++;
            }
        }


        while(!que.empty()) {

            int u = que.front();
            que.pop();

            answer = max(answer, t[u][colors[u] - 'a']);

            for(int &v : adj[u]) {

                for(int i = 0; i < 26; i ++) {

                    t[v][i] = max(t[v][i], t[u][i] + (colors[v] - 'a' == i));
                }

                if(--inDegree[v] == 0) {
                    que.push(v);
                    cnt ++;
                }
            }
        }

        return cnt == V ? answer : -1;


    }
};



// Main function for testing
int main() {
    Solution sol;

    // Test Case 1
    string colors1 = "abaca";
    vector<vector<int>> edges1 = {{0,1}, {0,2}, {2,3}, {3,4}};
    cout << "Test Case 1 Output: " << sol.largestPathValue(colors1, edges1) << endl;
    // Expected: 3

    // Test Case 2 (Cycle)
    string colors2 = "a";
    vector<vector<int>> edges2 = {{0,0}};
    cout << "Test Case 2 Output: " << sol.largestPathValue(colors2, edges2) << endl;
    // Expected: -1

    // Test Case 3 (Simple chain)
    string colors3 = "abc";
    vector<vector<int>> edges3 = {{0,1}, {1,2}};
    cout << "Test Case 3 Output: " << sol.largestPathValue(colors3, edges3) << endl;
    // Expected: 1 (each color appears once)

    return 0;
}