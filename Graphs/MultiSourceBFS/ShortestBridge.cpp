#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int m, n;
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int sr, int sc) {

        visited[sr][sc] = true;

        for(int i = 0; i < 4; i ++) {

            int nr = sr + dx[i]; 
            int nc = sc + dy[i];

            if(nr < 0 || nc < 0 || nr >=m || nc >= n || visited[nr][nc] || grid[nr][nc] != 1)  {
                continue;
            }

            dfs(grid, visited, nr , nc);
        }

        return;
    }

    int shortestBridge(vector<vector<int>>& grid) {

        m = grid.size(); 
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0; i < m; i ++) {

            bool check = false;

            for(int j = 0; j < n; j ++) {

                if(grid[i][j] == 1) {
                    dfs(grid, visited, i, j);
                    check = true;
                    break;
                }
            }

            if(check) {
                break;
            }
        }


        queue<pair<int, int>> que;

        for(int i = 0; i < m; i ++) {

            for(int j = 0; j < n; j ++) {

                if(visited[i][j]) {

                    que.push({i, j});
                }
            }
        }

        int cnt = 0;

        while(!que.empty()) {

            int size = que.size();

            for(int i = 0; i < size; i++) {

                int cr = que.front().first;
                int cc = que.front().second;
                que.pop();

                for(int k = 0; k < 4; k++) {

                    int nr = cr + dx[k];
                    int nc = cc + dy[k];

                    if(nr < 0 || nc < 0 || nr >= m || nc >= n || visited[nr][nc]) {
                        continue;
                    }

                  
                    if(grid[nr][nc] == 1) {
                        return cnt;
                    }

                    visited[nr][nc] = true;
                    que.push({nr, nc});
                }
            }

            cnt++;
        }


        return -1;
    }
};

// Main function to run test cases
int main() {
    Solution sol;

    // Test Case 1
    vector<vector<int>> grid1 = {{0,1,0},{0,0,0},{0,0,1}};
    cout << "Test Case 1 Output: " << sol.shortestBridge(grid1) << endl; 
    // Expected: 2

    // Test Case 2
    vector<vector<int>> grid2 = {{0,1},{1,0}};
    cout << "Test Case 2 Output: " << sol.shortestBridge(grid2) << endl; 
    // Expected: 1

    // Test Case 3
    vector<vector<int>> grid3 = {{1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,1,1}};
    cout << "Test Case 3 Output: " << sol.shortestBridge(grid3) << endl; 
    // Expected: 1

    return 0;
}

/*
    MulitSource BFS :
    Time Complexity : O(m * n)
    Space Complexity : O(m * n)
*/