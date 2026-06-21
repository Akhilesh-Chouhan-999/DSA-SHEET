#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
public:

    vector<int> parent;
    vector<int> rank;

    DisjointSet(int V) {

        parent.resize(V);
        rank.resize(V, 0);

        for(int i = 0; i < V; i ++) {

            parent[i] = i;
        }
    }

    int find(int x) {

        if(x == parent[x]) {

            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {

        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent) {

            return ;
        }

        if(rank[x_parent] < rank[y_parent]) {

            parent[x_parent] = y_parent;
        }

        else if(rank[y_parent] < rank[x_parent]) {

            parent[y_parent] = x_parent;
        }

        else {
            
            parent[y_parent] = x_parent;
            rank[x_parent] += 1;
        }


        return;
    }
};

class Solution {
public:

    int spanningTree(int V, vector<vector<int>> adj[]) {

        vector<vector<int>> edges;

        // u -> {{v1, w1}, {v2, w2}, ...... ,{vn, wn}}

        for(int u = 0; u < V; u ++) {

            for(vector<int>& temp : adj[u]) {

                int v = temp[0];
                int wt = temp[1];


                if(u < v) {
                    
                    edges.push_back({u, v, wt});
                }
            }
        }

        auto lambda = [&](const vector<int>& a, const vector<int>& b) {

            if(a[2] < b[2]) {

                return true;
            }

            return false;
        };

        sort(begin(edges), end(edges), lambda);

        DisjointSet dsu(V);

        int mstWeight = 0;

        for(vector<int>& edge : edges) {

            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            int u_parent = dsu.find(u);
            int v_parent = dsu.find(v);

            if(u_parent != v_parent) {

                dsu.Union(u, v);
                mstWeight += wt;
            }
        }
        
        return mstWeight;
    }
};

int main() {

    int V = 5;

    vector<vector<int>> adj[V];

    // u -- v , wt

    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    Solution obj;

    cout << obj.spanningTree(V, adj);

    return 0;
}


/*
    Time Complexity : O(E*log(E)) + O(E*⋅α(V)) +  O(V + E)
    Space Complexity : O(V) + (E)
*/