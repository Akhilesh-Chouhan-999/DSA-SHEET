#include<bits/stdc++.h>
using namespace std;

class Solution {

    public:
    void solve(int n, vector<vector<int>>& adj) {

        queue<int>que; 
        vector<int>parent(n+1);
        vector<bool>visited(n+1, false);

        parent[1] = -1;
        visited[1] = true;
        que.push(1);

        while(!que.empty()) {

            int u = que.front();
            que.pop();
            
            for(int v : adj[u]) {
                
                if(!visited[v]) {
                    que.push(v);
                    visited[v] = true;
                    parent[v] = u;
                }
            }
        }

        if(!visited[n]) {
            cout << "IMPOSSIBLE\n" << endl;
            return;
        }

        vector<int>path;

        int curr = n;

        while(curr != -1) {
            
            path.push_back(curr);
            curr = parent[curr];

        }

        reverse(begin(path), end(path));

        /*
            Minimum Path Size :
        */

        cout << path.size() << "\n" ;
        for(int x : path) {
            cout << x << " ";
        } 

        cout << "\n";

    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    Solution obj;
    obj.solve(n, adj);

    return 0;
}