/*
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<bool>>& visited, int sr, int sc) {

        if(sr < 0 || sc < 0 || sr >= m || sc >= n ) {
            return true;
        } 

        if(grid2[sr][sc] == 0 || visited[sr][sc]) {
            return true;
        }

        visited[sr][sc] = true;

        bool isSubIsland = true;

        if(grid1[sr][sc] == 0) {
            isSubIsland = false;
        }

        bool up = dfs(grid1, grid2, visited, sr - 1, sc);
        bool down = dfs(grid1, grid2, visited, sr + 1, sc);
        bool left = dfs(grid1, grid2, visited, sr, sc - 1 );
        bool right = dfs(grid1, grid2, visited, sr, sc + 1);

        return isSubIsland && up && down && left && right;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        m = grid1.size();
        n = grid1[0].size();

        int cnt = 0;
        vector<vector<bool>> visited(m, vector<bool> (n, false));

        for(int i = 0; i < m; i ++) {

            for(int j = 0; j < n; j ++) {

                if(!visited[i][j] && grid2[i][j] == 1) {

                    if(dfs(grid1, grid2, visited, i, j)) {
                        cnt ++;
                    }
                }
            }
        }

        return cnt;
    }
};


// Helper function to print a 2D vector (optional, for debugging)
void printGrid(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution solution;

    // Test Case 1 (From your submission)
    vector<vector<int>> grid1_1 = {
        {1,1,1,0,0},
        {0,1,1,1,1},
        {0,0,0,0,0},
        {1,0,0,0,0},
        {1,1,0,1,1}
    };
    vector<vector<int>> grid2_1 = {
        {1,1,1,0,0},
        {0,0,1,1,1},
        {0,1,0,0,0},
        {1,0,1,1,0},
        {0,1,0,1,0}
    };

    cout << "Test Case 1:" << endl;
    cout << "Expected Output: 3" << endl;
    cout << "Actual Output: " << solution.countSubIslands(grid1_1, grid2_1) << endl << endl;

    // Test Case 2 (From your submission)
    vector<vector<int>> grid1_2 = {
        {1,0,1,0,1},
        {1,1,1,1,1},
        {0,0,0,0,0},
        {1,1,1,1,1},
        {1,0,1,0,1}
    };
    vector<vector<int>> grid2_2 = {
        {0,0,0,0,0},
        {1,1,1,1,1},
        {0,1,0,1,0},
        {0,1,0,1,0},
        {1,0,0,0,1}
    };

    cout << "Test Case 2:" << endl;
    cout << "Expected Output: 2" << endl;
    cout << "Actual Output: " << solution.countSubIslands(grid1_2, grid2_2) << endl;

    return 0;
}


    DFS : 
    Time Complexity : O(m * n)
    Space Complexity : O(m * n)
*/
#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int m, n;
    int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    bool bfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<bool>>& visited, int sr, int sc) {

        queue<pair<int,int>> q;
        q.push({sr, sc});

        visited[sr][sc] = true;

        bool isSubIsland = true;

        while(!q.empty()) {

            auto frontNode = q.front();
            q.pop();

            int r = frontNode.first;
            int c = frontNode.second;

            if(grid1[r][c] == 0) {
                isSubIsland = false;
            }

            for(int i = 0; i < 4; i++) {

                int nr = r + dir[i][0];
                int nc = c + dir[i][1];

                if(nr >= 0 && nc >= 0 && nr < m && nc < n && !visited[nr][nc] && grid2[nr][nc] == 1) {

                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }

        return isSubIsland;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        m = grid1.size();
        n = grid1[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int cnt = 0;

        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                if(!visited[i][j] && grid2[i][j] == 1) {

                    if(bfs(grid1, grid2, visited, i, j)) {
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};



void printGrid(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution solution;

    // Test Case 1 (From your submission)
    vector<vector<int>> grid1_1 = {
        {1,1,1,0,0},
        {0,1,1,1,1},
        {0,0,0,0,0},
        {1,0,0,0,0},
        {1,1,0,1,1}
    };
    vector<vector<int>> grid2_1 = {
        {1,1,1,0,0},
        {0,0,1,1,1},
        {0,1,0,0,0},
        {1,0,1,1,0},
        {0,1,0,1,0}
    };

    cout << "Test Case 1:" << endl;
    cout << "Expected Output: 3" << endl;
    cout << "Actual Output: " << solution.countSubIslands(grid1_1, grid2_1) << endl << endl;

    // Test Case 2 (From your submission)
    vector<vector<int>> grid1_2 = {
        {1,0,1,0,1},
        {1,1,1,1,1},
        {0,0,0,0,0},
        {1,1,1,1,1},
        {1,0,1,0,1}
    };
    vector<vector<int>> grid2_2 = {
        {0,0,0,0,0},
        {1,1,1,1,1},
        {0,1,0,1,0},
        {0,1,0,1,0},
        {1,0,0,0,1}
    };

    cout << "Test Case 2:" << endl;
    cout << "Expected Output: 2" << endl;
    cout << "Actual Output: " << solution.countSubIslands(grid1_2, grid2_2) << endl;

    return 0;
}

