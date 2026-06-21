#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int V;
    bool bfs(vector<vector<int>>& graph, vector<int>& colors, int node, int clr) {


        queue<pair<int, int>> que;

        que.push({node, -1});
        colors[node] = clr;

        while(!que.empty()) {

            int u = que.front().first;
            int par = que.front().second;
            que.pop();

            for(int &v : graph[u]) {

                if(v == par) 
                continue;

                if(colors[v] == -1) {
                    que.push({v, u});
                    colors[v] = 1 - colors[u];
                }

                else if(colors[v] == colors[u]) {
                    return false;
                }
            }

        }

        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {

        this -> V = graph.size();

        vector<int>colors(V, -1);

        for(int i = 0; i < V; i ++) {
            if(colors[i] == -1) {

                if(!bfs(graph, colors, i, 0)) {
                    return false;
                }
            }
        }

        return true;

    }
};

int main() {
    Solution sol;

    // Test Case 1: Not Bipartite
    // Graph: [[1,2,3],[0,2],[0,1,3],[0,2]]
    vector<vector<int>> graph1 = {
        {1, 2, 3}, 
        {0, 2}, 
        {0, 1, 3}, 
        {0, 2}
    };
    cout << "Test Case 1: " << (sol.isBipartite(graph1) ? "true" : "false") << endl;
    // Expected Output: false

    // Test Case 2: Bipartite
    // Graph: [[1,3],[0,2],[1,3],[0,2]] (A simple cycle of 4)
    vector<vector<int>> graph2 = {
        {1, 3}, 
        {0, 2}, 
        {1, 3}, 
        {0, 2}
    };
    cout << "Test Case 2: " << (sol.isBipartite(graph2) ? "true" : "false") << endl;
    // Expected Output: true

    return 0;
}
