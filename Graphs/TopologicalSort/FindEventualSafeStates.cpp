#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int V = graph.size();

        unordered_map<int, vector<int>> adj;
        vector<int> outDegree(V, 0);

        for(int u = 0; u < V; u ++) {

            for(int v : graph[u]) {
                
                outDegree[u] ++;
                adj[v].push_back(u);
            }
        }


        queue<int> que;
        vector<int> result;

        for(int i = 0; i < V; i ++) {

            if(outDegree[i] == 0) {
                que.push(i);
            }
        }

        while(!que.empty()) {

            int u = que.front();
            result.push_back(u);
            que.pop();

            for(int &v : adj[u]) {

                if(--outDegree[v] == 0) {
                    que.push(v);
                }
            }
        }

        sort(begin(result), end(result));


        return result;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    // Input: graph = [[1,2],[2,3],,,,[],[]]
    // Expected Output: [2,4,5,6]
    vector<vector<int>> graph1 = {{1,2}, {2,3}, {5}, {0}, {5}, {}, {}};
    vector<int> result1 = sol.eventualSafeNodes(graph1);
    
    cout << "Test Case 1 Output: [";
    for (int i = 0; i < result1.size(); i++) {
        cout << result1[i] << (i == result1.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;

    // Test Case 2
    // Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
    // Expected Output: 
    vector<vector<int>> graph2 = {{1,2,3,4}, {1,2}, {3,4}, {0,4}, {}};
    vector<int> result2 = sol.eventualSafeNodes(graph2);
    
    cout << "Test Case 2 Output: [";
    for (int i = 0; i < result2.size(); i++) {
        cout << result2[i] << (i == result2.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;

    return 0;
}