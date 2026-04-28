/*

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(unordered_map<int, vector<int>>& adj, vector<bool>& visited, int u) {

        if(visited[u]) {
            return;
        }

        visited[u] = true;

        for(int v : adj[u]) {

            if(!visited[v]) {
                dfs(adj, visited, v);
            }
            
        }

        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int V = isConnected.size();

        unordered_map<int, vector<int>>adj(V);

        for(int u = 0; u < V; u ++) {

            for(int v = 0; v < V; v ++) {

                if(isConnected[u][v] == 1 && u != v) {
                    adj[u].push_back(v);
                }

            }
        }

        vector<bool>visited(V, false);

        int cntProvince = 0;

        for(int i = 0; i < V; i ++) {

            if(!visited[i]) {
                dfs(adj, visited, i);
                cntProvince ++;
            } 

        }

        return cntProvince;
    }
};


int main() {
    Solution sol;

    // Test Case 1: From the problem description
    vector<vector<int>> isConnected1 = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    
    // Test Case 2: From the problem description
    vector<vector<int>> isConnected2 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    cout << "Test Case 1 Output: " << sol.findCircleNum(isConnected1) << " (Expected: 2)" << endl;
    cout << "Test Case 2 Output: " << sol.findCircleNum(isConnected2) << " (Expected: 3)" << endl;

    return 0;
}

    DFS : 
    Time Complexity  : O(V ^ 2)
    Space Complexity : O(V ^ 2)


*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void bfs(vector<vector<int>>& adj, vector<bool>& visited, int u) {

        int V = adj.size();

        queue<int>que;

        que.push(u);

        while(!que.empty()) {

            int node = que.front();
            que.pop();

            visited[node] = true;

            for(int i = 0; i < V; i++) {

                if(adj[node][i] == 1 && !visited[i]) {
                    que.push(i);
                }

            }

        }

        return;

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int V = isConnected.size();

        vector<bool>visited(V, false);
        queue<int>que;

        int cntProvince = 0;

        for(int i = 0; i < V; i ++) {

            if(!visited[i]) {
                bfs(isConnected, visited, i);
                cntProvince ++;
            } 

        }

        return cntProvince;
    }
};


int main() {
    Solution sol;

    // Test Case 1: From the problem description
    vector<vector<int>> isConnected1 = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    
    // Test Case 2: From the problem description
    vector<vector<int>> isConnected2 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    cout << "Test Case 1 Output: " << sol.findCircleNum(isConnected1) << " (Expected: 2)" << endl;
    cout << "Test Case 2 Output: " << sol.findCircleNum(isConnected2) << " (Expected: 3)" << endl;

    return 0;
}

/*
    BFS :
    Time Complexity : O(V ^ 2)
    Space Complexity : O(V)

    where V is Vertices
*/