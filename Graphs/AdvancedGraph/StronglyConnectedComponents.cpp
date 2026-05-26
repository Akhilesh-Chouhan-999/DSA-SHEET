/*

    SSC : A Strongly Connected Component (SCC) is a group of vertices where:

        For every pair of vertices u and v inside that group:

        there is a path from u → v
        and also a path from v → u

        So both vertices can reach each other.
*/


#include<bits/stdc++.h>
using namespace std;

class Kosaraju {
public:

    void dfsFill(int u, vector<bool>& vis, stack<int>& st, vector<vector<int>>& adj) {

        vis[u] = true;

        for(int &v : adj[u]) {

            if(!vis[v]) {

                dfsFill(v, vis, st, adj);
            }
        }

        st.push(u);
    }

    void dfsTraversal(int node, vector<bool>& vis, vector<vector<int>>& revAdj, vector<int>& component) {

        vis[node] = true;

        component.push_back(node);

        for(int &nei : revAdj[node]) {

            if(!vis[nei]) {

                dfsTraversal(nei, vis, revAdj, component);
            }
        }
    }

    vector<vector<int>> getSCC(vector<vector<int>>& adj) {

        int V = adj.size();

        stack<int> st;
        vector<bool> visited(V, false);

        for(int i = 0; i < V; i++) {

            if(!visited[i]) {

                dfsFill(i, visited, st, adj);
            }
        }

        vector<vector<int>> revAdj(V);

        for(int u = 0; u < V; u++) {

            for(int &v : adj[u]) {

                revAdj[v].push_back(u);
            }
        }

        visited = vector<bool>(V, false);

        vector<vector<int>> scc;

        while(!st.empty()) {

            int node = st.top();
            st.pop();

            if(!visited[node]) {

                vector<int> component;

                dfsTraversal(node, visited, revAdj, component);

                scc.push_back(component);
            }
        }

        return scc;
    }
};

int main() {

    vector<vector<vector<int>>> testCases = {

        {
            {2, 3}, // 0
            {0},    // 1
            {1},    // 2
            {4},    // 3
            {}      // 4
        },

        {
            {1},    // 0
            {2},    // 1
            {0, 3}, // 2
            {4},    // 3
            {}      // 4
        },

        {
            {1},    // 0
            {2},    // 1
            {3},    // 2
            {0},    // 3
            {5},    // 4
            {4}     // 5
        }
    };

    Kosaraju obj;

    for(int t = 0; t < testCases.size(); t++) {

        cout << "Test Case " << t + 1 << endl;

        vector<vector<int>> scc = obj.getSCC(testCases[t]);

        for(auto component : scc) {

            cout << "{ ";

            for(auto node : component) {

                cout << node << " ";
            }

            cout << "}" << endl;
        }

        cout << endl;
    }

    return 0;
}

/*
    Time Complexity : O(V + E) 
    Space Complexity : O(V + E)
*/