#include<bits/stdc++.h>
#define p pair<int, int>
#define INF 1e9

using namespace std;

class Solution {
public:

    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        
        vector<vector<int>> adj(n + 1);

        for(auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        priority_queue<p, vector<p>, greater<p>> pq;

        vector<int> minD1(n + 1, INF);
        vector<int> minD2(n + 1, INF);

        pq.push({0, 1});
        minD1[1] = 0;

        while(!pq.empty()) {

            int currTime = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            if(node == n && currTime > minD1[node]) {
               
                return currTime;
            }

            int div = currTime / change;

            if(div % 2 == 1) {
                
                currTime = (div + 1) * change;
            }

            for(auto nei : adj[node]) {

                int newTime = currTime + time;

                if(newTime < minD1[nei]) {

                    minD2[nei] = minD1[nei];
                    minD1[nei] = newTime;

                    pq.push({newTime, nei});
                }

                else if(newTime > minD1[nei] && newTime < minD2[nei]) {

                    minD2[nei] = newTime;

                    pq.push({newTime, nei});
                }
            }
        }

        return -1;
    }
};



int main() {
    Solution sol;

    // Test Case 1
    int n1 = 5;
    vector<vector<int>> edges1 = {{1,2},{1,3},{1,4},{3,4},{4,5}};
    int time1 = 3;
    int change1 = 5;
    
    cout << "Test Case 1:" << endl;
    cout << "Input: n = " << n1 << ", time = " << time1 << ", change = " << change1 << endl;
    cout << "Output: " << sol.secondMinimum(n1, edges1, time1, change1) << endl;
    cout << "Expected: 13" << endl << endl;

    // Test Case 2
    int n2 = 2;
    vector<vector<int>> edges2 = {{1,2}};
    int time2 = 3;
    int change2 = 2;

    cout << "Test Case 2:" << endl;
    cout << "Input: n = " << n2 << ", time = " << time2 << ", change = " << change2 << endl;
    cout << "Output: " << sol.secondMinimum(n2, edges2, time2, change2) << endl;
    cout << "Expected: 11" << endl;

    return 0;
}