#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int node, int parent, int& timer, vector<int>& discTime, vector<int>& lowDiscTime, vector<vector<int>>& adj, vector<bool>& isArticulationPoint) {

        discTime[node] = lowDiscTime[node] = timer++;

        int children = 0;

        for(int &nei : adj[node]) {

            if(parent == nei) {
                continue;
            }

            if(discTime[nei] == -1) {

                children ++;

                dfs(nei, node, timer, discTime, lowDiscTime, adj, isArticulationPoint);

                lowDiscTime[node] = min(lowDiscTime[node], lowDiscTime[nei]);

                if(parent != -1 && lowDiscTime[nei] >= discTime[node]) {

                    isArticulationPoint[node] = true;
                }
            }

            else if(nei != parent) {

                lowDiscTime[node] = min(lowDiscTime[node], discTime[nei]);
            }
        }

        if(children > 1 && parent == -1) {

            isArticulationPoint[node] = true;
        }
    }
    vector<int> articulationPoints(int V, vector<vector<int>>& adj) {

        vector<int> discTime(V, -1);
        vector<int> lowDiscTime(V, -1);
        vector<bool> isArticulationPoint(V, false);
        int timer = 0;

        for(int u = 0; u < V; u ++) {

            if(discTime[u] == -1) {

                dfs(u, -1, timer, discTime, lowDiscTime, adj, isArticulationPoint);
            }
        }

        vector<int> result;

        for(int i = 0; i < V; i ++) {

            if(isArticulationPoint[i]) {

                result.push_back(i);
            }
        }

        return result;

    }
};

int main() {

    Solution obj;

    // ================= TEST CASE 1 =================
    // Graph:
    // 0 - 1 - 3 - 4
    //  \ /
    //   2
    //
    // AP = 1, 3

    {
        int V = 5;

        vector<vector<int>> adj(V);

        auto addEdge = [&](int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        };

        addEdge(0, 1);
        addEdge(1, 2);
        addEdge(2, 0);
        addEdge(1, 3);
        addEdge(3, 4);

        vector<int> ans = obj.articulationPoints(V, adj);

        cout << "Test Case 1: ";
        for (auto x : ans) cout << x << " ";
        cout << endl;
    }

    // ================= TEST CASE 2 =================
    // Linear Graph
    // 0 - 1 - 2 - 3 - 4
    //
    // AP = 1 2 3

    {
        int V = 5;

        vector<vector<int>> adj(V);

        auto addEdge = [&](int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        };

        addEdge(0, 1);
        addEdge(1, 2);
        addEdge(2, 3);
        addEdge(3, 4);

        vector<int> ans = obj.articulationPoints(V, adj);

        cout << "Test Case 2: ";
        for (auto x : ans) cout << x << " ";
        cout << endl;
    }

    // ================= TEST CASE 3 =================
    // Complete Cycle
    // 0 - 1
    // |   |
    // 3 - 2
    //
    // No articulation point

    {
        int V = 4;

        vector<vector<int>> adj(V);

        auto addEdge = [&](int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        };

        addEdge(0, 1);
        addEdge(1, 2);
        addEdge(2, 3);
        addEdge(3, 0);

        vector<int> ans = obj.articulationPoints(V, adj);

        cout << "Test Case 3: ";
        for (auto x : ans) cout << x << " ";
        cout << endl;
    }

    // ================= TEST CASE 4 =================
    // More Complex Graph
    //
    //       0
    //      / \
    //     1---2
    //      \
    //       3
    //      / \
    //     4---5
    //
    // AP = 1, 3

    {
        int V = 6;

        vector<vector<int>> adj(V);

        auto addEdge = [&](int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        };

        addEdge(0, 1);
        addEdge(1, 2);
        addEdge(2, 0);

        addEdge(1, 3);

        addEdge(3, 4);
        addEdge(4, 5);
        addEdge(5, 3);

        vector<int> ans = obj.articulationPoints(V, adj);

        cout << "Test Case 4: ";
        for (auto x : ans) cout << x << " ";
        cout << endl;
    }

    return 0;
}

/*

    Time Complexity : O(V + E)
    Space Complexity : O(V)
*/