#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        unordered_map<int, vector<int>> adj;
        vector<int>inDegree(n+1, 0);

        for(vector<int>& relation : relations) {

            int prevCourse = relation[0];
            int nextCourse = relation[1];

            adj[prevCourse].push_back(nextCourse);
            inDegree[nextCourse] ++;
        }

        queue<int>que;
        vector<int>dist(n + 1, 0);

        for(int i = 1; i <= n; i ++) {

            if(inDegree[i] == 0) {

                que.push(i);
                dist[i] = time[i - 1];
            }
        }

        while(!que.empty()) {

            int u = que.front();
            que.pop();


            for(int &v : adj[u]) {

                dist[v] = max(dist[v], dist[v] + time[v-1]);

                if(--inDegree[v] == 0) {
                    que.push(v);
                }
            }
        }

        int minTime = 0;

        for(int i = 1; i <= n; i ++) {
            minTime = max(minTime, dist[i]);
        }

        return minTime;

    }
};