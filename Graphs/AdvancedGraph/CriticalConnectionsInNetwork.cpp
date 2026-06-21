#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int node, int parent, int& timer, vector<int>& discTime, vector<int>& lowDiscTime, vector<vector<int>>& adj, vector<vector<int>>& result) {

        discTime[node] = lowDiscTime[node] = timer++;

        for(int &nei : adj[node]) {

            if(nei == parent) {
                continue;
            }

            if(discTime[nei] == -1) {

                dfs(nei, node, timer, discTime, lowDiscTime, adj, result);

                lowDiscTime[node] = min(lowDiscTime[node], lowDiscTime[nei]);

                if(lowDiscTime[nei] > discTime[node]) {

                    result.push_back({node, nei});
                }
            }

            else {

                lowDiscTime[node] = min(lowDiscTime[node], discTime[nei]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        vector<vector<int>> adj(n);

        for(vector<int>& connection : connections) {

            int u = connection[0];
            int v = connection[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> discTime(n, -1);
        vector<int> lowDiscTime(n, -1);

        vector<vector<int>> result;

        int timer = 0;

        for(int i = 0; i < n; i++) {

            if(discTime[i] == -1) {

                dfs(i, -1, timer, discTime, lowDiscTime, adj, result);
            }
        }

        return result;
    }
};

int main() {

    int n = 4;

    vector<vector<int>> connections = {
        {0,1},
        {1,2},
        {2,0},
        {1,3}
    };

    Solution obj;

    vector<vector<int>> bridges = obj.criticalConnections(n, connections);

    for(auto &edge : bridges) {

        cout << edge[0] << " " << edge[1] << endl;
    }

    return 0;
}

/*
    Time Complexity : O(V + E)
    Space Complexity : O(V + E)
*/