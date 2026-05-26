#include<bits/stdc++.h>
using namespace std;

class DSU {
    public:

    int component ;
    vector<int> parent, rank;
    DSU(int V) {

        component = V;
        rank.resize(V + 1, 0);
        parent.resize(V + 1);

        for(int i = 1; i <= V; i ++) {

            parent[i] = i;
        }
    }

    int find(int x) {

        if(x == parent[x]) {

            return x;
        }

        return parent[x] = find(parent[x]);
    }

    bool Union(int x, int y) {

        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent) {

            return false;
        }

        if(rank[x_parent] < rank[y_parent]) {

            parent[x_parent] = y_parent;
        }

        else if(rank[y_parent] < rank[x_parent]) {

            parent[y_parent] = x_parent;
        }

        else {

            parent[y_parent] = x_parent;
            rank[y_parent] += 1;
        }

        component --;

        return true;

    }
};
class Solution {
public:

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {


        DSU alice(n);
        DSU bob(n);

        int removedEdges = 0;

        for(vector<int>& edge : edges) {

            int type = edge[0];
            int u = edge[1];
            int v = edge[2];

            if(type == 3) {

                bool AliceUsed = alice.Union(u, v);
                bool BobUsed = bob.Union(u, v);

                if(!AliceUsed && !BobUsed) {

                    removedEdges ++;
                }
            }
        }


        for(vector<int>& edge : edges) {

            int type = edge[0];
            int u = edge[1];
            int v = edge[2];

            if(type == 1) {

                bool AliceUsed = alice.Union(u, v);

                if(!AliceUsed) {

                    removedEdges ++;
                }
            }
        }


        for(vector<int>& edge : edges) {

            int type = edge[0];
            int u = edge[1];
            int v = edge[2];

            if(type == 2) {

                bool bobUsed = bob.Union(u, v);

                if(!bobUsed) {

                    removedEdges ++;
                }
            }
        }

        if(alice.component != 1 || bob.component != 1) {

            return -1;
        }

        return removedEdges;

    }
};


// Main Function
int main() {
    // Example Test Case 1
    int n1 = 4;
    vector<vector<int>> edges1 = {
        {3, 1, 2}, 
        {3, 2, 3}, 
        {1, 1, 3}, 
        {1, 2, 4}, 
        {1, 1, 2}, 
        {2, 3, 4}
    };

    Solution sol;
    int result1 = sol.maxNumEdgesToRemove(n1, edges1);
    cout << "Test Case 1 Output: " << result1 << endl; // Expected: 2



    // Example Test Case 3 (Impossible)
    int n3 = 4;
    vector<vector<int>> edges3 = {
        {3, 2, 3}, 
        {1, 1, 2}, 
        {2, 3, 4}
    };

    int result3 = sol.maxNumEdgesToRemove(n3, edges3);
    cout << "Test Case 3 Output: " << result3 << endl; // Expected: -1

    return 0;
}

/*
    Time Complexity : O(E × α(N))
    Space Complexity : O(V) 
*/