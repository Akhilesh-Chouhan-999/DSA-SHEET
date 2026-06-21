#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        queue<pair<int,int>> que;

        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 2) {

                    que.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        int dx[] = {0, 0, 1, -1};
        int dy[] = {-1, 1, 0, 0};

        while(!que.empty()) {

            int cr = que.front().first;
            int cc = que.front().second;

            que.pop();

            for(int i = 0; i < 4; i++) {

                int nr = cr + dx[i];
                int nc = cc + dy[i];

                if(nr < 0 || nc < 0 || nr >= m || nc >= n)
                    continue;

                if(grid[nr][nc] == 0)
                    continue;

                if(dist[nr][nc] <= dist[cr][cc] + 1)
                    continue;

                dist[nr][nc] = dist[cr][cc] + 1;

                que.push({nr, nc});
            }
        }

        int result = 0;

        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1 && dist[i][j] == INT_MAX)
                    return -1;

                if(dist[i][j] != INT_MAX)
                    result = max(result, dist[i][j]);
            }
        }

        return result;
    }
};


int main() {
    Solution sol;

    // Test case 1: All oranges rot in 4 minutes
    vector<vector<int>> grid1 = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };
    cout << "Test 1: " << sol.orangesRotting(grid1) << endl; // Expected: 4

    // Test case 2: Impossible to rot all oranges
    vector<vector<int>> grid2 = {
        {2,1,1},
        {0,1,1},
        {1,0,0}
    };
    cout << "Test 2: " << sol.orangesRotting(grid2) << endl; // Expected: -1

    // Test case 3: No fresh oranges
    vector<vector<int>> grid3 = {
        {2,2,2},
        {2,2,2}
    };
    cout << "Test 3: " << sol.orangesRotting(grid3) << endl; // Expected: 0

    return 0;
}