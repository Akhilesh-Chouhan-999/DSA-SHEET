/*
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(unordered_map<int,vector<int>>& adj, vector<bool>& visited, int u) {

        if(visited[u])
        return ;

        visited[u] = true;

        for(int v : adj[u]) {

            if(!visited[v]){
                dfs(adj, visited, v);
            }

        }

        return ;
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int V = rooms.size();

        unordered_map<int,vector<int>>adj(V);

        for(int i = 0; i < V; i ++) {
            for(int key : rooms[i]) {
                adj[i].push_back(key);
            }
        }

        vector<bool>visited(V, false);

        dfs(adj, visited, 0);

        for(bool visit : visited) {
            if(!visit) {
                return false;
            }
        }

        return true;
    }
};


int main() {
    Solution sol;

    // Test Case 1
    vector<vector<int>> rooms1 = {{1}, {2}, {3}, {}};
    cout << "Test Case 1 Output: " << (sol.canVisitAllRooms(rooms1) ? "true" : "false") << endl;

    // Test Case 2
    vector<vector<int>> rooms2 = {{1,3}, {3,0,1}, {2}, {0}};
    cout << "Test Case 2 Output: " << (sol.canVisitAllRooms(rooms2) ? "true" : "false") << endl;

    // Custom Test Case 3
    vector<vector<int>> rooms3 = {{1,2}, {2}, {3}, {}};
    cout << "Test Case 3 Output: " << (sol.canVisitAllRooms(rooms3) ? "true" : "false") << endl;

    return 0;
}


    DFS :
    Time Complexity : O(V + E)
    Space Complexity : O(V + E)
    where V : Vertices and E : Edges.
*/



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int V = rooms.size();

        vector<bool>visited(V, false);

        queue<int>que;

        que.push(0);

        while (!que.empty()) {

            int u = que.front();
            que.pop();

            visited[u] = true;

            for(int v : rooms[u]) {

                if(!visited[v]) {
                    que.push(v);
                }

            }
        }
        

       for(bool visit : visited) {

            if(!visit) {
                return false;
            }
       }

       return true;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<vector<int>> rooms1 = {{1}, {2}, {3}, {}};
    cout << "Test Case 1 Output: " << (sol.canVisitAllRooms(rooms1) ? "true" : "false") << endl;

    // Test Case 2
    vector<vector<int>> rooms2 = {{1,3}, {3,0,1}, {2}, {0}};
    cout << "Test Case 2 Output: " << (sol.canVisitAllRooms(rooms2) ? "true" : "false") << endl;

    // Custom Test Case 3
    vector<vector<int>> rooms3 = {{1,2}, {2}, {3}, {}};
    cout << "Test Case 3 Output: " << (sol.canVisitAllRooms(rooms3) ? "true" : "false") << endl;

    return 0;
}


/*
    BFS :
    Time Complexity : O(V + E)
    Space Complexity : O(V)
    where V : Vertices and E : Edges.

*/