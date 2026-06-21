/*
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

    bool dfs(unordered_map<int, vector<int>>& adj, vector<bool>& visited, int u, int parent) {

        visited[u] = true;

        for(int& v : adj[u]) {

            if(parent == v) {
                continue;
            }

            else if(visited[v]) {
                return true;
            }

            else{
                if(dfs(adj, visited, v, u)) {
                    return true;
                }
            }
        }

        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
      
        unordered_map<int, vector<int>>adj;

        for(vector<int>edge : edges) {

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>visited(V, false);

        for(int i = 0; i < V; i ++) {

            if(!visited[i] && dfs(adj, visited, i, -1 )){
                return true;
            }

        }

        return false;
    }
};

void runTest(int V, vector<vector<int>> edges, bool expected, int id) {
    Solution sol;
    bool result = sol.isCycle(V, edges);
    cout << "Test " << id << ": " << (result == expected ? "PASS" : "FAIL") 
         << " | Expected: " << (expected ? "true" : "false") 
         << " | Got: " << (result ? "true" : "false") << endl;
}


int main() {
    // Test 1: Graph with a cycle (Triangle 0-1-2)
    // V=4, Edges: [0,1], [0,2], [1,2], [2,3]
    runTest(4, {{0, 1}, {0, 2}, {1, 2}, {2, 3}}, true, 1);

    // Test 2: No cycle (Line 0-1-2-3)
    // V=4, Edges: [0,1], [1,2], [2,3]
    runTest(4, {{0, 1}, {1, 2}, {2, 3}}, false, 2);

    // Test 3: Disconnected components (Cycle in one, line in other)
    // Component 1: 0-1-2-0 (Cycle), Component 2: 3-4 (No cycle)
    // V=5, Edges: [0,1], [1,2], [2,0], [3,4]
    runTest(5, {{0, 1}, {1, 2}, {2, 0}, {3, 4}}, true, 3);

    // Test 4: Single isolated node (No cycle)
    // V=1, Edges: []
    runTest(1, {}, false, 4);

    // Test 5: Two nodes with one edge (No cycle)
    // V=2, Edges: [0,1]
    runTest(2, {{0, 1}}, false, 5);

    // Test 6: Two nodes with two edges (Cycle 0-1-0, though simple graphs usually don't have multi-edges, this tests logic)
    // Note: In standard simple graphs, multi-edges are rare, but if edges=[0,1] and [0,1] exist, it forms a cycle.
    // Assuming input doesn't have duplicate edges as per standard problem constraints.
    // Let's test a square: 0-1-2-3-0
    // V=4, Edges: [0,1], [1,2], [2,3], [3,0]
    runTest(4, {{0, 1}, {1, 2}, {2, 3}, {3, 0}}, true, 6);

    return 0;
}



    Key Point:
    In an undirected graph, during DFS:

    If we encounter a visited node:
    - If it is the parent → ignore
    - Else → cycle exists
*/



#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

    bool bfs(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited) {

        queue<pair<int,int>>que;

        que.push({u, -1});

        visited[u] = true;

        while(!que.empty()) {

            int node = que.front().first;
            int parent = que.front().second;
            que.pop();

            for(int &v : adj[node]) {

                if(parent == v) 
                continue;

                else if(visited[v]) 
                return true;

                else {
                    visited[v] = true;
                    que.push({v, node});
                }
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
      
        unordered_map<int, vector<int>>adj;

        for(vector<int>edge : edges) {

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>visited(V, false);

        for(int i = 0; i < V; i ++) {

            if(!visited[i] && bfs(adj, i, visited)){
                return true;
            }

        }

        return false;
    }
};

void runTest(int V, vector<vector<int>> edges, bool expected, int id) {
    Solution sol;
    bool result = sol.isCycle(V, edges);
    cout << "Test " << id << ": " << (result == expected ? "PASS" : "FAIL") 
         << " | Expected: " << (expected ? "true" : "false") 
         << " | Got: " << (result ? "true" : "false") << endl;
}


int main() {
    // Test 1: Graph with a cycle (Triangle 0-1-2)
    // V=4, Edges: [0,1], [0,2], [1,2], [2,3]
    runTest(4, {{0, 1}, {0, 2}, {1, 2}, {2, 3}}, true, 1);

    // Test 2: No cycle (Line 0-1-2-3)
    // V=4, Edges: [0,1], [1,2], [2,3]
    runTest(4, {{0, 1}, {1, 2}, {2, 3}}, false, 2);

    // Test 3: Disconnected components (Cycle in one, line in other)
    // Component 1: 0-1-2-0 (Cycle), Component 2: 3-4 (No cycle)
    // V=5, Edges: [0,1], [1,2], [2,0], [3,4]
    runTest(5, {{0, 1}, {1, 2}, {2, 0}, {3, 4}}, true, 3);

    // Test 4: Single isolated node (No cycle)
    // V=1, Edges: []
    runTest(1, {}, false, 4);

    // Test 5: Two nodes with one edge (No cycle)
    // V=2, Edges: [0,1]
    runTest(2, {{0, 1}}, false, 5);

    // Test 6: Two nodes with two edges (Cycle 0-1-0, though simple graphs usually don't have multi-edges, this tests logic)
    // Note: In standard simple graphs, multi-edges are rare, but if edges=[0,1] and [0,1] exist, it forms a cycle.
    // Assuming input doesn't have duplicate edges as per standard problem constraints.
    // Let's test a square: 0-1-2-3-0
    // V=4, Edges: [0,1], [1,2], [2,3], [3,0]
    runTest(4, {{0, 1}, {1, 2}, {2, 3}, {3, 0}}, true, 6);

    return 0;
}

/*
    Time Complexity : O(V + E)
    Space Complexity : O(V + E)
*/
