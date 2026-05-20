#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {-1, 1, 0, 0};
    int m;
    int n;

    void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int sr, int sc) {

        queue<pair<int, int>> que;

        que.push({sr, sc});
        visited[sr][sc] = true;

        while(!que.empty()) {

            int cr = que.front().first;
            int cc = que.front().second;

            que.pop();


            for(int i = 0; i < 4; i ++) {

                int nr = cr + dx[i];
                int nc = cc + dy[i];


                if(nr < 0 || nc < 0 || nr >= m || nc >= n) {
                    continue;
                }

                if(visited[nr][nc]) {
                    continue;
                }

                if(grid[nr][nc] == 1) {
                    continue;
                }

                que.push({nr , nc});
                visited[nr][nc] = true;
            }
        }

        return;
    }
    
    int closedIsland(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> que;

        /*
            0 --> island
            1 --> water
        */
        for(int i = 0; i < m; i ++) {

            if(grid[i][0] == 0) {

                que.push({i, 0});
                visited[i][0] = true;
            }

            if(grid[i][n - 1] == 0) {

                que.push({i, n - 1});
                visited[i][n - 1] = true;
            }
        }

        for(int i = 0; i < n; i ++) {

            if(grid[0][i] == 0) {

                que.push({0, i});
                visited[0][i] = true;
            }

            if(grid[m - 1][i] == 0) {

                que.push({m - 1, i});
                visited[m - 1][i] = true;
            }
        }


        while(!que.empty()) {

            int size = que.size();

            for(int i = 0; i < size; i ++) {

                int cr = que.front().first;
                int cc = que.front().second;

                que.pop();

                for(int i = 0; i < 4; i ++) {

                    int nr = cr + dx[i];
                    int nc = cc + dy[i];

                    if(nr < 0 || nc < 0 || nr >= m || nc >= n) {
                        continue;
                    }

                    if(visited[nr][nc]) {
                        continue;
                    }

                    if(grid[nr][nc] == 1) {
                        continue;
                    }

                    que.push({nr, nc});
                    visited[nr][nc] = true;
                }

        
            }
        }

        int result = 0;

        for(int i = 0; i < m; i ++) {

            for(int j = 0; j < n; j ++) {

                if(!visited[i][j] && grid[i][j] == 0) {

                    bfs(grid, visited, i, j);
                    result ++;
                }
            }
        }


        return result;

    }
};



int main() {
    Solution sol;

    // Test Case 1 from your screenshot
    vector<vector<int>> grid1 = {
        {1,1,1,1,1,1,1,0},
        {1,0,0,0,0,1,1,0},
        {1,0,1,0,1,1,1,0},
        {1,0,0,0,0,1,0,1},
        {1,1,1,1,1,1,1,0}
    };

    cout << "Test Case 1 Output: " << sol.closedIsland(grid1) << endl;
    // Expected: 2 (Your screenshot showed 11, which was incorrect; the correct answer for this grid is 2)

    // Test Case 2
    vector<vector<int>> grid2 = {
        {0,0,1,0,0},
        {0,1,0,1,0},
        {0,1,1,1,0}
    };

    cout << "Test Case 2 Output: " << sol.closedIsland(grid2) << endl;
    // Expected: 1

    // Test Case 3
    vector<vector<int>> grid3 = {
        {1,1,1,1,1,1,1},
        {1,0,0,0,0,0,1},
        {1,0,1,1,1,0,1},
        {1,0,1,0,1,0,1},
        {1,0,1,1,1,0,1},
        {1,0,0,0,0,0,1},
        {1,1,1,1,1,1,1}
    };

    cout << "Test Case 3 Output: " << sol.closedIsland(grid3) << endl;
    // Expected: 2

    return 0;
}


/*
    Multi-Source BFS :
    Time Complexity : O(m * n)
    Space Complexity : O(m * n)

*/