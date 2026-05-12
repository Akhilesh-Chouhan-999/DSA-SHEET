#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int V;
    int bfs(unordered_map<int,vector<int>>& adj, int node) {

        queue<pair<int, int>>que;
        vector<bool>visited(V, false);
        vector<int>dist(V, 0);

        int shortestCycle = INT_MAX;

        que.push({node, -1});
        visited[node] = true;
        dist[node] = 0;

        while(!que.empty()) {

            int u = que.front().first;
            int par = que.front().second;
            que.pop();

            for(int& v : adj[u]) {

                if(v == par) {
                    continue;
                }

                else if(!visited[v]) {
                    que.push({v, u});
                    dist[v] = 1 + dist[u];
                    visited[v] = true;
                }

                else{
                    shortestCycle = min(shortestCycle, 1 + dist[u] + dist[v]);
                }

            }

        }

        return shortestCycle == INT_MAX ? -1 : shortestCycle;
    }

    int findShortestCycle(int n, vector<vector<int>>& edges) {

        this -> V = n;
        unordered_map<int, vector<int>> adj;

        for(const vector<int>& edge : edges) {

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int result = INT_MAX;

        for(int i = 0; i < n; i ++) {

            int cycleLength = bfs(adj, i);

            if(cycleLength != -1) {
                result = min(result, cycleLength);
            }
        }

        return result == INT_MAX ? -1 : result;
        
    }
};


// Main function with hardcoded test cases
int main() {
    Solution sol;

    // Test Case 1
    // Input: n = 7, edges = [[0,1],[1,2],[2,0],[3,4],[4,5],[5,6],[6,3]]
    // Expected Output: 3
    {
        int n1 = 7;
        vector<vector<int>> edges1 = {{0,1}, {1,2}, {2,0}, {3,4}, {4,5}, {5,6}, {6,3}};
        int result1 = sol.findShortestCycle(n1, edges1);
        cout << "Test Case 1:" << endl;
        cout << "Input: n = " << n1 << ", edges = [[0,1],[1,2],[2,0],[3,4],[4,5],[5,6],[6,3]]" << endl;
        cout << "Output: " << result1 << endl;
        cout << "Expected: 3" << endl;
        cout << (result1 == 3 ? "PASS" : "FAIL") << endl << endl;
    }

    // Test Case 2
    // Input: n = 4, edges = [[0,1],[0,2]]
    // Expected Output: -1
    {
        int n2 = 4;
        vector<vector<int>> edges2 = {{0,1}, {0,2}};
        int result2 = sol.findShortestCycle(n2, edges2);
        cout << "Test Case 2:" << endl;
        cout << "Input: n = " << n2 << ", edges = [[0,1],[0,2]]" << endl;
        cout << "Output: " << result2 << endl;
        cout << "Expected: -1" << endl;
        cout << (result2 == -1 ? "PASS" : "FAIL") << endl << endl;
    }

    // Test Case 3 (Custom: Triangle + Square)
    // Input: n = 5, edges = [[0,1],[1,2],[2,0],[2,3],[3,4],[4,2]]
    // Cycle 1: 0-1-2 (len 3)
    // Cycle 2: 2-3-4-2 (len 3)
    // Expected Output: 3
    {
        int n3 = 5;
        vector<vector<int>> edges3 = {{0,1}, {1,2}, {2,0}, {2,3}, {3,4}, {4,2}};
        int result3 = sol.findShortestCycle(n3, edges3);
        cout << "Test Case 3:" << endl;
        cout << "Input: n = " << n3 << ", edges = [[0,1],[1,2],[2,0],[2,3],[3,4],[4,2]]" << endl;
        cout << "Output: " << result3 << endl;
        cout << "Expected: 3" << endl;
        cout << (result3 == 3 ? "PASS" : "FAIL") << endl << endl;
    }

    // Test Case 4 (Custom: No cycle, Line graph)
    // Input: n = 3, edges = [[0,1],[1,2]]
    // Expected Output: -1
    {
        int n4 = 3;
        vector<vector<int>> edges4 = {{0,1}, {1,2}};
        int result4 = sol.findShortestCycle(n4, edges4);
        cout << "Test Case 4:" << endl;
        cout << "Input: n = " << n4 << ", edges = [[0,1],[1,2]]" << endl;
        cout << "Output: " << result4 << endl;
        cout << "Expected: -1" << endl;
        cout << (result4 == -1 ? "PASS" : "FAIL") << endl;
    }

    return 0;
}

/*
    Time Complexity : O(V * (V + E))
    Space Complexity : O(V + E)

*/