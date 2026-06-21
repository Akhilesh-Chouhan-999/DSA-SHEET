#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    using p = pair<long long, int>;
    using ll = long long;

    int dijkstra(int n, unordered_map<int, vector<pair<int, int>>>& adj) {


        const int MOD = 1e9 + 7;

        priority_queue<p, vector<p>, greater<p>> pq;
        vector<int> ways(n, 0);
        vector<ll>dist(n, LLONG_MAX);

        ways[0] = 1;
        dist[0] = 0;
        pq.push({0, 0});

        while(!pq.empty()) {
            
            
            ll d = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            for(auto it : adj[node]) {

                int nei = it.first;
                int wt = it.second;

                if(dist[nei] > d + wt) {

                    dist[nei] = d + wt;
                    ways[nei] = ways[node];
                    pq.push({d + wt, nei});
                }

                else if(dist[nei] == d + wt) {

                    ways[nei] = (ways[nei] + ways[node]) % MOD;
                }

            }
        }

        return ways[n - 1];
    }
    int countPaths(int n, vector<vector<int>>& roads) {

        unordered_map<int, vector<pair<int, int>>> adj;

        for(vector<int>& road : roads) {

            int u = road[0];
            int v = road[1];
            int w = road[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        return dijkstra(n, adj);

    }
};


void runTest(int n, vector<vector<int>> roads, int expected, int testNum) {

    Solution sol;
    int result = sol.countPaths(n, roads);

    cout << "Test Case #" << testNum << ":\n";

    cout << "Input:\n";
    cout << "n = " << n << "\n";

    cout << "roads = [";

    for(int i = 0; i < roads.size(); i++) {

        cout << "[" 
             << roads[i][0] << ", "
             << roads[i][1] << ", "
             << roads[i][2] << "]";

        if(i != roads.size() - 1)
            cout << ", ";
    }

    cout << "]\n";

    cout << "Expected = " << expected << "\n";
    cout << "Output   = " << result << "\n";

    if(result == expected)
        cout << "PASS\n";
    else
        cout << "FAIL\n";

    cout << "\n";
}

int main() {
    // Test Case 1: Original problem from submission
    // 7 nodes, complex graph with multiple shortest paths
    {
        int n = 7;
        vector<vector<int>> roads = {
            {0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, 
            {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, 
            {0, 4, 5}, {4, 6, 2}
        };
        runTest(n, roads, 4, 1);
    }

    // Test Case 2: Simple single path
    // Only one way to go from 0 to 1
    {
        int n = 2;
        vector<vector<int>> roads = {
            {1, 0, 10}
        };
        runTest(n, roads, 1, 2);
    }

    // Test Case 3: Multiple paths with same shortest distance
    // 0 -> 1 (cost 1), 0 -> 2 (cost 1), 1 -> 3 (cost 1), 2 -> 3 (cost 1)
    // Shortest dist to 3 is 2. Paths: 0-1-3 and 0-2-3. Total ways = 2.
    {
        int n = 4;
        vector<vector<int>> roads = {
            {0, 1, 1},
            {0, 2, 1},
            {1, 3, 1},
            {2, 3, 1}
        };
        runTest(n, roads, 2, 3);
    }

    // Test Case 4: Linear graph (Straight line)
    // 0 -> 1 -> 2 -> 3. Only 1 path exists.
    {
        int n = 4;
        vector<vector<int>> roads = {
            {0, 1, 5},
            {1, 2, 5},
            {2, 3, 5}
        };
        runTest(n, roads, 1, 4);
    }

    return 0;
}