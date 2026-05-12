/*
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int m;
    int n;
    const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool dfs(const vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y, int px, int py) {

        visited[x][y] = true;

        for(int i = 0; i < 4; i ++) {

            int dx = x + dir[i][0];
            int dy = y + dir[i][1];

            if((dx < 0 || dy < 0 || dx >= m || dy >= n) || (dx == px && dy == py) || (grid[dx][dy] != grid[x][y]))
            continue;


            if(!visited[dx][dy]) {

                if(dfs(grid, visited, dx, dy, x, y)) {
                    return true;
                }
            }
            else {

                return true;
            }

        }

        return false;
    }
    bool containsCycle(const vector<vector<char>>& grid) {
        
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>>visited(m, vector<bool>(n, false));

        for(int i = 0; i < m; i ++) {

            for(int j = 0; j < n; j ++) {

                if(!visited[i][j]) {

                    if(dfs(grid, visited, i, j, -1, -1))
                    return true;
                }
            }
        }

        return false;
    }
};
int main() {

    vector<vector<char>> grid1 = {
        {'a', 'a', 'a', 'a'},
        {'a', 'b', 'b', 'a'},
        {'a', 'b', 'b', 'a'},
        {'a', 'a', 'a', 'a'}
    };

    vector<vector<char>> grid2 = {
        {'a', 'b', 'c'},
        {'d', 'e', 'f'}
    };

    vector<vector<char>> grid3 = {
        {'a', 'b'},
        {'b', 'a'}
    };

    vector<vector<char>> grid4 = {
        {'c'}
    };

    vector<vector<char>> grid5 = {
        {'x', 'x', 'x', 'x'},
        {'x', 'y', 'y', 'x'},
        {'x', 'y', 'y', 'x'},
        {'x', 'x', 'x', 'x'}
    };

    vector<vector<char>> grid6 = {
        {'a', 'a', 'a'},
        {'a', 'b', 'b'},
        {'a', 'b', 'b'}
    };

    Solution sol;

    cout << sol.containsCycle(grid1) << endl; // 1
    cout << sol.containsCycle(grid2) << endl; // 0
    cout << sol.containsCycle(grid3) << endl; // 0
    cout << sol.containsCycle(grid4) << endl; // 0
    cout << sol.containsCycle(grid5) << endl; // 1

    return 0;
}


Time Complexity : O(m*n)
Space Complexity : O(m*n)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int m, n;
    const int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    bool bfs(vector<vector<char>>& grid,vector<vector<bool>>& visited, int sx, int sy) {

        queue<vector<int>>q;

        q.push({sx, sy, -1, -1});
        visited[sx][sy] = true;

        while(!q.empty()) {

            auto curr = q.front();
            q.pop();

            int x = curr[0];
            int y = curr[1];
            int px = curr[2];
            int py = curr[3];

            for(int i = 0; i < 4; i++) {

                int dx = x + dir[i][0];
                int dy = y + dir[i][1];

                if(dx < 0 || dy < 0 || dx >= m || dy >= n)
                continue;

                if(grid[dx][dy] != grid[x][y])
                continue;

                if(dx == px && dy == py)
                continue;

                if(visited[dx][dy]) {
                    return true;
                }

                visited[dx][dy] = true;
                q.push({dx, dy, x, y});
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {

        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                if(!visited[i][j]) {

                    if(bfs(grid, visited, i, j))
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {

    vector<vector<char>> grid = {
        {'a', 'a', 'a', 'a'},
        {'a', 'b', 'b', 'a'},
        {'a', 'b', 'b', 'a'},
        {'a', 'a', 'a', 'a'}
    };

    Solution sol;

    cout << sol.containsCycle(grid);

    return 0;
}