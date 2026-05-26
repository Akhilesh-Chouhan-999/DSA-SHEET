#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    using p = pair<int, int>;

    int spanningTree(int V, vector<vector<int>> adj[]) {

        priority_queue<p, vector<p>, greater<p>> pq;

        vector<bool> visited(V, false);

        int sum = 0;

        pq.push({0, 0});

        while(!pq.empty()) {

            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(visited[node]) {
                continue;
            }

            visited[node] = true;

            sum += wt;

            for(auto &temp : adj[node]) {

                int nei = temp[0];
                int neiWeight = temp[1];

                if(!visited[nei]) {

                    pq.push({neiWeight, nei});
                }
            }
        }

        return sum;

    }
};

int main() {

    int V = 5;

    vector<vector<int>> adj[V];

    auto addEdge = [&](int u, int v, int wt) {

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    };

    addEdge(0, 1, 2);
    addEdge(0, 3, 6);
    addEdge(1, 2, 3);
    addEdge(1, 3, 8);
    addEdge(1, 4, 5);
    addEdge(2, 4, 7);

    Solution obj;

    cout << obj.spanningTree(V, adj);

    return 0;
}

/*
    Time Complexity : O(E * log(E))
    Space Complexity : O(E) + O(V)
*/