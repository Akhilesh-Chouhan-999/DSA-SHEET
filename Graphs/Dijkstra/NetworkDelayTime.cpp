#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    using p = pair<int, int>;

    vector<int> dijkstra(int n, unordered_map<int, vector<pair<int, int>>>& adj, int k) {

        priority_queue<p , vector<p>, greater<p>> pq;
        const int INF = 1e9;
        vector<int> dist(n + 1, INF);

        pq.push({0, k});
        dist[k] = 0;

        while(!pq.empty()) {

            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (d > dist[node])
            continue;

            for(auto &it : adj[node]) {

                int nei = it.first;
                int wt = it.second;

                if(dist[nei] > d + wt) {

                    dist[nei] = d + wt;
                    pq.push({dist[nei], nei});
                }
            }
        }

        return dist;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        unordered_map<int, vector<pair<int, int>>> adj;

        for(vector<int>& time : times) {

            int u = time[0];
            int v = time[1];
            int w = time[2];

            adj[u].push_back({v, w});
        }

        vector<int> dist = dijkstra(n, adj, k);

        int ans = 0;

        for (int i = 1; i <= n; ++ i) {

            if (dist[i] == 1e9) 
            return -1;

            ans = max(ans, dist[i]);
        }

        return ans;

    }
};

int main() {
    // Example 1
    vector<vector<int>> times1 = {{2,1,1},{2,3,1},{3,4,1}};
    int n1 = 4;
    int k1 = 2;
    
    Solution sol;
    cout << "Example 1 Output: " << sol.networkDelayTime(times1, n1, k1) << endl; // Expected: 2

    // Example 2
    vector<vector<int>> times2 = {{1,2,1}};
    int n2 = 2;
    int k2 = 1;
    cout << "Example 2 Output: " << sol.networkDelayTime(times2, n2, k2) << endl; // Expected: 1

    // Example 3
    vector<vector<int>> times3 = {{1,2,1}};
    int n3 = 2;
    int k3 = 2;
    cout << "Example 3 Output: " << sol.networkDelayTime(times3, n3, k3) << endl; // Expected: -1

    return 0;
}