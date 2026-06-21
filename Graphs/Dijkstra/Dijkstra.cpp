#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    using p = pair<long long, int>;

    vector<int> shortestPath(int n, vector<vector<pair<int,int>>>& adj) {

        priority_queue<p, vector<p>, greater<p>> pq;

        vector<long long> dist(n + 1, LLONG_MAX);
        vector<int> parent(n + 1);

        for(int i = 1; i <= n; i++) {

            parent[i] = i;
        }

        pq.push({0, 1});
        dist[1] = 0;

        while(!pq.empty()) {

            long long d = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            if(d > dist[node]) 
            continue;

            for(auto &v : adj[node]) {

                int nei = v.first;
                int wt = v.second;

                if(dist[nei] > d + wt) {

                    dist[nei] = d + wt;
                    parent[nei] = node;

                    pq.push({dist[nei], nei});
                }
            }
        }

        if(dist[n] == LLONG_MAX) {
            return {-1};
        }

        vector<int> path;

        int node = n;

        while(node != 1) {

            path.push_back(node);
            node = parent[node];
        }

        path.push_back(1);

        reverse(path.begin(), path.end());

        return path;
    }
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n + 1);

    for(int i = 0; i < m; i++) {

        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    Solution obj;

    vector<int> ans = obj.shortestPath(n, adj);

    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
}