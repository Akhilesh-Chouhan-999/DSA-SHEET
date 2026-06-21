#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    typedef pair<int, int> p;

    int numEnclaves(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<p> que;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

       
        for(int i = 0; i < m; i++) {

            if(grid[i][0] == 1) {
                que.push({i, 0});
                visited[i][0] = true;
            }

            if(grid[i][n - 1] == 1) {
                que.push({i, n - 1});
                visited[i][n - 1] = true;
            }
        }

        for(int i = 0; i < n; i++) {

            if(grid[0][i] == 1) {
                que.push({0, i});
                visited[0][i] = true;
            }

            if(grid[m - 1][i] == 1) {
                que.push({m - 1, i});
                visited[m - 1][i] = true;
            }
        }

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while(!que.empty()) {

            int cr = que.front().first;
            int cc = que.front().second;

            que.pop();

            for(int i = 0; i < 4; i++) {

                int nr = cr + dx[i];
                int nc = cc + dy[i];

                if(nr < 0 || nc < 0 || nr >= m || nc >= n) {
                    continue;
                }

                if(visited[nr][nc]) {
                    continue;
                }

                if(grid[nr][nc] == 0) {
                    continue;
                }

                visited[nr][nc] = true;
                que.push({nr, nc});
            }
        }

        int cnt = 0;

        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1 && !visited[i][j]) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};



int main() {
    Solution sol;

    // Test Case 1: From your screenshot
    vector<vector<int>> grid1 = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    cout << "Test Case 1 Output: " << sol.numEnclaves(grid1) << endl;
 
    
    // Test Case 2: Another example
    vector<vector<int>> grid2 = {
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0}
    };
    cout << "Test Case 2 Output: " << sol.numEnclaves(grid2) << endl;
  

    return 0;
}

/*

    Multi-Source BFS :
    Time Complexity : O(m * n)
    Space Complexity : O(m * n)

*/