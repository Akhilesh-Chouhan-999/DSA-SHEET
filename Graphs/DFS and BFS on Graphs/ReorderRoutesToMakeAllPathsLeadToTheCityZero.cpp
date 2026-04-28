/*
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void solve(unordered_map<int, vector<pair<int,int>>>& adj, int u, vector<bool>& visited, int& cnt) {

        if(visited[u]) {
            return;
        }

        visited[u] = true;

        for(pair<int, int>p : adj[u]) {

            int v = p.first;
            int w = p.second;

            if(!visited[v]) {
                cnt += w;
                solve(adj, v, visited, cnt);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
 
        unordered_map<int, vector<pair<int,int>>> adj(n);

        for(vector<int>connection : connections) {

            int u = connection[0];
            int v = connection[1];

            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }

        vector<bool>visited(n, false);

        int cnt = 0;

        solve(adj, 0, visited , cnt);

        return cnt;

    }
};

int main() {
    Solution sol;

    // Test case 1
    int n1 = 6;
    vector<vector<int>> connections1 = {{0,1},{1,3},{2,3},{4,0},{4,5}};
    cout << "Test Case 1 Output: " << sol.minReorder(n1, connections1) << endl;

    // Test case 2
    int n2 = 5;
    vector<vector<int>> connections2 = {{1,0},{1,2},{3,2},{3,4}};
    cout << "Test Case 2 Output: " << sol.minReorder(n2, connections2) << endl;

    // Test case 3
    int n3 = 3;
    vector<vector<int>> connections3 = {{1,0},{2,0}};
    cout << "Test Case 3 Output: " << sol.minReorder(n3, connections3) << endl;

    return 0;
}

    DFS :
    Time Complexity : O(V + E)
    Space Complexity : O(V + E)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
 
        unordered_map<int, vector<pair<int, int>>> adj(n);

        for(vector<int>connection : connections) {

            int u = connection[0];
            int v = connection[1];

            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }

        vector<bool>visited(n, false);

        int cnt = 0;

        queue<pair<int, int>>que;

        que.push({0,0});

        while(!que.empty()) {

            int u = que.front().first;
            int w = que.front().second;
            que.pop();

            visited[u] = true;

            cnt += w;

            for(pair<int, int>& p : adj[u]) {

                int v = p.first;
                int w = p.second;

                if(!visited[v]) {
                    que.push({v, w});
                }
            }
        }

        return cnt;
    }
};
int main() {
    Solution sol;

    // Test case 1
    int n1 = 6;
    vector<vector<int>> connections1 = {{0,1},{1,3},{2,3},{4,0},{4,5}};
    cout << "Test Case 1 Output: " << sol.minReorder(n1, connections1) << endl;

    // Test case 2
    int n2 = 5;
    vector<vector<int>> connections2 = {{1,0},{1,2},{3,2},{3,4}};
    cout << "Test Case 2 Output: " << sol.minReorder(n2, connections2) << endl;

    // Test case 3
    int n3 = 3;
    vector<vector<int>> connections3 = {{1,0},{2,0}};
    cout << "Test Case 3 Output: " << sol.minReorder(n3, connections3) << endl;

    return 0;
}
/*
    BFS :
    Time Complexity  : O(V + E) => O(V)
    Space Complexity : O(V + E) => O(V)
    where E = V - 1
*/
