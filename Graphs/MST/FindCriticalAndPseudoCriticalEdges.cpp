#include<bits/stdc++.h>
using namespace std;

class DSU {

public:

    vector<int> parent, rank;

    DSU(int V) {

        parent.resize(V);
        rank.resize(V, 0);

        for(int i = 0; i < V; i++) {

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

            return;
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
    }
};

class Solution {
public:

    int N;

    int kruskal(vector<vector<int>>& edges, int skipEdge, int addEdge) {

        DSU dsu(N);

        int weight = 0;
        int edgesUsed = 0;

        if(addEdge != -1) {

            int u = edges[addEdge][0];
            int v = edges[addEdge][1];
            int wt = edges[addEdge][2];

            dsu.Union(u, v);

            weight += wt;
            edgesUsed++;
        }

        for(int i = 0; i < edges.size(); i++) {

            if(i == skipEdge) {

                continue;
            }

            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            if(dsu.find(u) != dsu.find(v)) {

                dsu.Union(u, v);

                weight += wt;
                edgesUsed++;
            }
        }

        if(edgesUsed != N - 1) {

            return INT_MAX;
        }

        return weight;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {

        N = n;

     
        for(int i = 0; i < edges.size(); i++) {

            edges[i].push_back(i);
        }

        sort(edges.begin(), edges.end(),
                                        [&](const vector<int>& a, const vector<int>& b) {

                                            return a[2] < b[2];
                                        }
        );

        int mstWeight = kruskal(edges, -1, -1);

        vector<int> critical;
        vector<int> pseudoCritical;

        for(int i = 0; i < edges.size(); i++) {

            int idx = edges[i][3];

            if(kruskal(edges, i, -1) > mstWeight) {

                critical.push_back(idx);
            }

            else if(kruskal(edges, -1, i) == mstWeight) {

                pseudoCritical.push_back(idx);
            }
        }

        return {critical, pseudoCritical};
    }
};

int main() {
    // Example Test Case
    // Graph: 4 nodes, edges: [0,1,1], [1,2,1], [2,3,1], [0,3,1]
    // All edges have weight 1. Any 3 edges form an MST.
    // Critical edges: None (removing any one still allows an MST of weight 3)
    // Pseudo-Critical: All edges (including any one in MST still yields weight 3)
    
    int n = 4;
    vector<vector<int>> edges = {
        {0, 1, 1},
        {1, 2, 1},
        {2, 3, 1},
        {0, 3, 1}
    };

    Solution sol;
    vector<vector<int>> result = sol.findCriticalAndPseudoCriticalEdges(n, edges);

    cout << "Critical Edges indices: ";
    for (int idx : result[0]) {
        cout << idx << " ";
    }
    cout << endl;

    cout << "Pseudo-Critical Edges indices: ";
    for (int idx : result[1]) {
        cout << idx << " ";
    }
    cout << endl;

    // Another Test Case
    // Graph: 5 nodes, edges forming a simple tree plus one extra edge
    // n = 5
    // edges = [[0,1,1], [1,2,1], [2,3,1], [3,4,1], [0,4,2]]
    // The edge [0,4,2] is not critical or pseudo-critical likely, or depends on structure.
    // Let's try a case with a critical edge.
    // n = 4, edges = [[0,1,1], [1,2,1], [2,3,1], [0,2,2]]
    // MST weight = 3 (0-1, 1-2, 2-3). Edge [0,2,2] is not in MST.
    // If we remove [0,1,1], we must use [0,2,2] -> weight 1+1+2 = 4 > 3. So [0,1,1] is critical.
    
    int n2 = 4;
    vector<vector<int>> edges2 = {
        {0, 1, 1},
        {1, 2, 1},
        {2, 3, 1},
        {0, 2, 2}
    };

    // Note: The original code modifies the 'edges' vector by pushing back the original index.
    // In a real main, we should pass a copy if we want to reuse the original data or if the function signature doesn't take const reference (it does in the snippet: vector<vector<int>>& edges, but it modifies it).
    // The snippet does: edges[i].push_back(i); which modifies the passed vector.
    
    vector<vector<int>> result2 = sol.findCriticalAndPseudoCriticalEdges(n2, edges2);

    cout << "\nTest Case 2:" << endl;
    cout << "Critical Edges indices: ";
    for (int idx : result2[0]) {
        cout << idx << " ";
    }
    cout << endl;

    cout << "Pseudo-Critical Edges indices: ";
    for (int idx : result2[1]) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}
/*
    Time Complexity : O(E * log(E)) + O(E * E * α(V))
    Space Complexity : O(V)
*/