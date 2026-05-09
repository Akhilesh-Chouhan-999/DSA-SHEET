/*

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

    bool dfs(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<bool>& recStack) {

      visited[u] = true;
      recStack[u] = true;

      for(int v : adj[u]) {
         
         if(recStack[v]) {
          return true;
         }
         else if(!visited[v] && dfs(adj, v, visited, recStack)){
          return true;
         }

      }
      
      recStack[u] = false;

      return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) { 

      vector<vector<int>> adj(V);

      for(vector<int>& edge : edges) {

        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
      }

      vector<bool> visited(V);
      vector<bool>recStack(V);

      for(int i = 0; i < V; i ++) {

        if(!visited[i] && dfs(adj, i, visited, recStack)) {
          return true;
        }
      }

      return false;
    }
};



// Main entry point with test cases
int main() {
    Solution sol;
    // Test Case 1: Graph with a cycle (0 -> 1 -> 2 -> 0)
    int V1 = 4;
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {2, 0}, {2, 3}};
    cout << "Test Case 1: " << (sol.isCyclic(V1, edges1) ? "true" : "false") << endl;
    // Expected: true

    // Test Case 2: Graph without a cycle
    int V2 = 4;
    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
    cout << "Test Case 2: " << (sol.isCyclic(V2, edges2) ? "true" : "false") << endl;
    // Expected: false

    // Test Case 3: Single node, no edge
    int V3 = 1;
    vector<vector<int>> edges3 = {};
    cout << "Test Case 3: " << (sol.isCyclic(V3, edges3) ? "true" : "false") << endl;
    // Expected: false

    // Test Case 4: Self-loop (cycle)
    int V4 = 2;
    vector<vector<int>> edges4 = {{0, 0}, {1, 0}};
    cout << "Test Case 4: " << (sol.isCyclic(V4, edges4) ? "true" : "false") << endl;
    // Expected: true

    return 0;
}

Time Complexity: O(V + E)
Space Complexity: O(V)

*/



#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

    bool isCyclic(int V, vector<vector<int>> &edges) { 

      vector<vector<int>> adj(V);
      vector<int>inDegree(V);

      for(vector<int>& edge : edges) {

        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
        inDegree[v] ++;
      }

      queue<int>que;

      for(int i = 0; i < V; i ++) {

        if(inDegree[i] == 0) {
          que.push(i);
        }
      }

      int cnt = 0;

      while(!que.empty()) {

        int u = que.front();
        que.pop();

        cnt ++;

        for(int v : adj[u]) {

          if(--inDegree[v] == 0) {
            que.push(v);
          } 

        }

      }

      return cnt != V;
  
    }
};



// Main entry point with test cases
int main() {
    Solution sol;
    // Test Case 1: Graph with a cycle (0 -> 1 -> 2 -> 0)
    int V1 = 4;
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {2, 0}, {2, 3}};
    cout << "Test Case 1: " << (sol.isCyclic(V1, edges1) ? "true" : "false") << endl;
    // Expected: true

    // Test Case 2: Graph without a cycle
    int V2 = 4;
    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
    cout << "Test Case 2: " << (sol.isCyclic(V2, edges2) ? "true" : "false") << endl;
    // Expected: false

    // Test Case 3: Single node, no edge
    int V3 = 1;
    vector<vector<int>> edges3 = {};
    cout << "Test Case 3: " << (sol.isCyclic(V3, edges3) ? "true" : "false") << endl;
    // Expected: false

    // Test Case 4: Self-loop (cycle)
    int V4 = 2;
    vector<vector<int>> edges4 = {{0, 0}, {1, 0}};
    cout << "Test Case 4: " << (sol.isCyclic(V4, edges4) ? "true" : "false") << endl;
    // Expected: true

    return 0;
}