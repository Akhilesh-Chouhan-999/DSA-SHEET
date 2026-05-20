/*

include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    using p = pair<int, int>;
    using q = pair<int, pair<int, int>>;    
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};
    int m;
    int n;
    const int INF = 1e9;

    int dijkstra(map<p, vector<pair<int, p>>>& adj) {

        priority_queue<q, vector<q>, greater<q>> pq;
        vector<vector<int>> dist(m, vector<int>(n, INF));

        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        while(!pq.empty()) {

            auto top = pq.top();

            int d = top.first;
            auto [cr , cc] = top.second;
            pq.pop();

            if(d > dist[cr][cc]) 
            continue;

            for(auto &it : adj[{cr, cc}]) {

                int wt = it.first;
                auto [neiR, neiC] = it.second;

                if(dist[neiR][neiC] > d + wt) {

                    dist[neiR][neiC] = d + wt;
                    pq.push({d + wt, {neiR, neiC}});
                }
            }
        }


        return dist[m - 1][n -1];

    }
    int minCost(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        map<p, vector<pair<int, p>>> adj;

        for(int i = 0; i < m; i ++) {

            for(int j = 0; j < n; j ++) {

                vector<int> dir(4, 1);
                dir[grid[i][j] - 1] = 0;

                for(int k = 0; k < 4; k ++) {

                    int nr = i + dx[k];
                    int nc = j + dy[k];

                    if(nr < 0 || nc < 0 || nr >= m || nc >= n) {
                        continue;
                    }

                    adj[{i, j}].push_back({dir[k] , {nr, nc}});

                }
            }
        }
        
        return dijkstra(adj);
    }
};


int main() {
    Solution sol;

    // Test Case 1 from your screenshot
    vector<vector<int>> grid1 = {
        {1, 1, 3},
        {3, 2, 2},
        {1, 1, 4}
    };
    
    cout << "Test Case 1 Result: " << sol.minCost(grid1) << endl;
    // Expected: 0 (The path follows the arrows: 1->1->3(down)->2(right)->2(down)->4)
    // Note: Your screenshot showed "Wrong Answer" with output 1000000000 for this, 
    // which implies the logic might be slightly off for specific edge cases or indexing, 
    // but this main function correctly executes the provided logic.

    // Test Case 2
    vector<vector<int>> grid2 = {
        {1, 1, 1, 1},
        {2, 2, 2, 2},
        {1, 1, 1, 1},
        {2, 2, 2, 2}
    };

    cout << "Test Case 2 Result: " << sol.minCost(grid2) << endl;

    // Test Case 3
    vector<vector<int>> grid3 = {
        {1, 2},
        {4, 3}
    };

    cout << "Test Case 3 Result: " << sol.minCost(grid3) << endl;

    return 0;
}

    Let:

    m = number of rows
    n = number of cols

    Total nodes:

    V = m * n

    Each cell has at most 4 edges.

    So:

    E ≈ 4 * m * n

    which is:

    E = O(m * n)
    Dijkstra Complexity

    Dijkstra using priority queue:

    O((V + E) log V)

    Substitute values:

    O((mn + mn) log(mn))

    So final TC:

    O(m * n * log(m * n))



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    using p = pair<int, pair<int,int>>;

    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};

    int minCost(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        priority_queue<p, vector<p>, greater<p>> pq;

        vector<vector<int>> dist(m, vector<int>(n, 1e9));

        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        while(!pq.empty()) {

            auto top = pq.top();
            pq.pop();

            int d = top.first;
            auto [r, c] = top.second;

            if(d > dist[r][c])
                continue;

            for(int k = 0; k < 4; k++) {

                int nr = r + dx[k];
                int nc = c + dy[k];

                if(nr < 0 || nc < 0 || nr >= m || nc >= n)
                    continue;

                int wt = (k == grid[r][c] - 1) ? 0 : 1;

                if(dist[nr][nc] > d + wt) {

                    dist[nr][nc] = d + wt;

                    pq.push({dist[nr][nc], {nr, nc}});
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};



int main() {
    Solution sol;

    // Test Case 1 from your screenshot
    vector<vector<int>> grid1 = {
        {1, 1, 3},
        {3, 2, 2},
        {1, 1, 4}
    };
    
    cout << "Test Case 1 Result: " << sol.minCost(grid1) << endl;
    // Expected: 0 (The path follows the arrows: 1->1->3(down)->2(right)->2(down)->4)
    // Note: Your screenshot showed "Wrong Answer" with output 1000000000 for this, 
    // which implies the logic might be slightly off for specific edge cases or indexing, 
    // but this main function correctly executes the provided logic.

    // Test Case 2
    vector<vector<int>> grid2 = {
        {1, 1, 1, 1},
        {2, 2, 2, 2},
        {1, 1, 1, 1},
        {2, 2, 2, 2}
    };

    cout << "Test Case 2 Result: " << sol.minCost(grid2) << endl;

    // Test Case 3
    vector<vector<int>> grid3 = {
        {1, 2},
        {4, 3}
    };

    cout << "Test Case 3 Result: " << sol.minCost(grid3) << endl;

    return 0;
}


*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    using p = pair<int,int>;
    const int INF = 1e9;
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};

    int minCost(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        deque<p> dq;

        vector<vector<int>> dist(m, vector<int>(n, INF));

        dq.push_front({0,0});
        dist[0][0] = 0;

        while(!dq.empty()) {

            auto [r, c] = dq.front();
            dq.pop_front();

            for(int k = 0; k < 4; k++) {

                int nr = r + dx[k];
                int nc = c + dy[k];

                if(nr < 0 || nc < 0 || nr >= m || nc >= n)
                    continue;

                int wt = (k == grid[r][c] - 1) ? 0 : 1;

                if(dist[nr][nc] > dist[r][c] + wt) {

                    dist[nr][nc] = dist[r][c] + wt;

                    if(wt == 0) {
                        dq.push_front({nr, nc});
                    }
                    else {
                        dq.push_back({nr, nc});
                    }
                }
            }
        }

        return dist[m-1][n-1];
    }
};





int main() {
    Solution sol;

    // Test Case 1 from your screenshot
    vector<vector<int>> grid1 = {
        {1, 1, 3},
        {3, 2, 2},
        {1, 1, 4}
    };
    
    cout << "Test Case 1 Result: " << sol.minCost(grid1) << endl;
    // Expected: 0 (The path follows the arrows: 1->1->3(down)->2(right)->2(down)->4)
    // Note: Your screenshot showed "Wrong Answer" with output 1000000000 for this, 
    // which implies the logic might be slightly off for specific edge cases or indexing, 
    // but this main function correctly executes the provided logic.

    // Test Case 2
    vector<vector<int>> grid2 = {
        {1, 1, 1, 1},
        {2, 2, 2, 2},
        {1, 1, 1, 1},
        {2, 2, 2, 2}
    };

    cout << "Test Case 2 Result: " << sol.minCost(grid2) << endl;

    // Test Case 3
    vector<vector<int>> grid3 = {
        {1, 2},
        {4, 3}
    };

    cout << "Test Case 3 Result: " << sol.minCost(grid3) << endl;

    return 0;
}

/*
    Muilti-Source BFS :
    Time Complexity : O(m * n)
    Space Complexity : O(m * n)
*/