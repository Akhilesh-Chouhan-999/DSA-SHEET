#include<bits/stdc++.h>
using namespace std;

using p = pair<long long, int>;

vector<long long> dijkstra(int n, vector<vector<pair<int,int>>> adj) {

    priority_queue<p, vector<p>, greater<p>> pq;

    pq.push({0, 1}); // dist -- node

    vector<long long>dist(n + 1, LLONG_MAX);

    dist[1] = 0;

    while(!pq.empty()) {

        long long d = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        if(d > dist[node]) 
        continue;


        for(auto &it : adj[node]) {

            int adjNode = it.first;
            int wt = it.second;

            if(dist[adjNode] > d + wt) {

                dist[adjNode] = d + wt;
                pq.push({d + wt, adjNode});
            }
        }
    }

    return dist;

}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n + 1);

    for(int i = 0; i < m; i++) {

        int u, v, wt;
        cin >> u >> v >> wt;

        adj[u].push_back({v, wt});
    }



    vector<long long> ans = dijkstra(n, adj);

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}


/*
    Dijkstra Algorithm :
    Time Complexity : O( V * E * log(v))
    Space Complexity : O(V + E)
*/