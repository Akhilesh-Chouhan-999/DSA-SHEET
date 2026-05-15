/*
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;
    const int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int sr, int sc) {

        visited[sr][sc] = true;

        for(int i = 0; i < 4; i ++) {

            int nr = sr + dir[i][0];
            int nc = sc + dir[i][1];

            if(nr < 0 || nc < 0 || nr >= m || nc >= n || visited[nr][nc] || grid[nr][nc] != '1') {
                continue;
            }

            dfs(grid, visited, nr, nc);
        }

        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        
        m = grid.size();
        n = grid[0].size();


        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int cntIslands = 0;

        for(int i = 0; i < m; i ++) {

            for(int j = 0; j < n; j ++) {

                if(!visited[i][j] && grid[i][j] == '1') {

                    dfs(grid, visited, i, j);
                    cntIslands ++;
                }
            }
        }
        

        return cntIslands;
    }
};


int main() {
    // Example Test Case 1
    vector<vector<char>> grid1 = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };

    // Example Test Case 2
    vector<vector<char>> grid2 = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    Solution sol;

    cout << "Test Case 1 - Number of Islands: " << sol.numIslands(grid1) << endl;
    cout << "Expected: 1" << endl << endl;

    cout << "Test Case 2 - Number of Islands: " << sol.numIslands(grid2) << endl;
    cout << "Expected: 3" << endl;

    return 0;
}
    DFS :
    Time Complexity : O(m * n)
    Space Complexity : O(m * n)
    
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int m, n;

    const int dir[4][2] = {
        {0, -1},
        {0, 1},
        {-1, 0},
        {1, 0}
    };

    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int sr, int sc) {

        queue<pair<int, int>> que;

        que.push({sr, sc});
        visited[sr][sc] = true;

        while(!que.empty()) {

            int r = que.front().first;
            int c = que.front().second;

            que.pop();

            for(int i = 0; i < 4; i++) {

                int nr = r + dir[i][0];
                int nc = c + dir[i][1];

                if(nr < 0 || nc < 0 || nr >= m || nc >= n ||
                   visited[nr][nc] || grid[nr][nc] != '1') {
                    continue;
                }

                que.push({nr, nc});
                visited[nr][nc] = true;
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int cntIslands = 0;

        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                if(!visited[i][j] && grid[i][j] == '1') {

                    bfs(grid, visited, i, j);
                    cntIslands++;
                }
            }
        }

        return cntIslands;
    }
};


int main() {
    // Example Test Case 1
    vector<vector<char>> grid1 = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };

    // Example Test Case 2
    vector<vector<char>> grid2 = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    Solution sol;

    cout << "Test Case 1 - Number of Islands: " << sol.numIslands(grid1) << endl;
    cout << "Expected: 1" << endl << endl;

    cout << "Test Case 2 - Number of Islands: " << sol.numIslands(grid2) << endl;
    cout << "Expected: 3" << endl;

    return 0;
}
/*
    BFS :
    Time Complexity : O(m * n)
    Space Complexity : O(m * n)
*/