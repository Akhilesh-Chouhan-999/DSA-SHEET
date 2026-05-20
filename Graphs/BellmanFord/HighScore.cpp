#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll INF = LLONG_MAX;

struct Edge {

    int u;
    int v;
    int w;
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    vector<ll> dist(n + 1, INF);

    for(int i = 0; i < m; i++) {

        int a, b, x;
        cin >> a >> b >> x;

        edges.push_back({a, b, -x});
    }

    
    dist[1] = 0;

    for(int count = 1; count <= n - 1; count++) {

        for(auto edge : edges) {

            int u = edge.u;
            int v = edge.v;
            int w = edge.w;

            if(dist[u] != INF && dist[u] + w < dist[v]) {

                dist[v] = dist[u] + w;
            }
        }
    }

    vector<int> affected(n + 1, false);

    for(int count = 1; count <= n; count++) {

        for(auto edge : edges) {

            int u = edge.u;
            int v = edge.v;
            int w = edge.w;

            if(dist[u] != INF && dist[u] + w < dist[v]) {

                dist[v] = dist[u] + w;
                affected[v] = true;
            }

            if(affected[u]) {

                affected[v] = true;
            }
        }
    }

    if(affected[n]) {

        cout << -1 << endl;
    }
    else {

        cout << -dist[n] << endl;
    }

    return 0;
}