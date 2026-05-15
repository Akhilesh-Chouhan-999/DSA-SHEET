/*
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    const int dir[4][4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int m;
    int n;
    pair<int, int> bfs(vector<vector<int>>& land, vector<vector<bool>>& visited, int sr, int sc) {

        queue<pair<int, int>> que;
        que.push({sr, sc});
        visited[sr][sc] = true;

        pair<int, int> coord = {sr, sc};

        while(!que.empty()) {

            int r = que.front().first;
            int c = que.front().second;

            que.pop();


            for(int i = 0; i < 4; i++) {

                int nr = r + dir[i][0];
                int nc = c + dir[i][1];

                if(nr < 0 || nc < 0 || nr >= m|| nc >= n || visited[nr][nc] || land[nr][nc] == 0) {
                    continue;
                }

                que.push({nr, nc});
                visited[nr][nc] = true;

                if(nr + nc > coord.first + coord.second) {
                    coord = {nr, nc};
                }

            }


        } 

        return coord;

    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        

        m = land.size();
        n = land[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> result;

        for(int i = 0; i < m; i ++) {

            for(int j = 0; j < n; j ++) {


                if(!visited[i][j] && land[i][j] == 1) {

                    int sr = i;
                    int sc = j;

                    auto coord = bfs(land, visited, i, j);
                    int lr = coord.first;
                    int lc = coord.second;

                    result.push_back({sr, sc, lr, lc});
                }
            }
        }

        return result;
    }
};




// Main function to test the solution
int main() {
    Solution sol;

    // Test Case 1 from your screenshot (The one returning Wrong Answer)
    vector<vector<int>> land1 = {
        {1, 0, 0},
        {0, 1, 1},
        {0, 1, 1}
    };

    cout << "Test Case 1 Input:" << endl;
    for (const auto& row : land1) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }

    vector<vector<int>> result1 = sol.findFarmland(land1);

    cout << "\nTest Case 1 Output:" << endl;
    cout << "[";
    for (size_t i = 0; i < result1.size(); ++i) {
        cout << "[" << result1[i][0] << "," << result1[i][1] << "," << result1[i][2] << "," << result1[i][3] << "]";
        if (i != result1.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    cout << "\nExpected: [[0,0,0,0],[1,1,2,2]]" << endl;

    // Test Case 2
    vector<vector<int>> land2 = {
        {1, 1},
        {1, 1}
    };

    cout << "\nTest Case 2 Input:" << endl;
    vector<vector<int>> result2 = sol.findFarmland(land2);
    cout << "Output: [[" << result2[0][0] << "," << result2[0][1] << "," << result2[0][2] << "," << result2[0][3] << "]]" << endl;
    cout << "Expected: [[0,0,1,1]]" << endl;

    return 0;
}
    BFS 
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

    int dir[4][2] = {
        {0, -1},
        {0, 1},
        {-1, 0},
        {1, 0}
    };

    void dfs(vector<vector<int>>& land, vector<vector<bool>>& visited, int r, int c, pair<int, int>& coord) {

        visited[r][c] = true;

        if(r + c > coord.first + coord.second) {
            coord = {r, c};
        }

        for(int i = 0; i < 4; i++) {

            int nr = r + dir[i][0];
            int nc = c + dir[i][1];

            if(nr < 0 || nc < 0 || nr >= m || nc >= n || visited[nr][nc] || land[nr][nc] == 0) {
                continue;
            }

            dfs(land, visited, nr, nc, coord);
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {

        m = land.size();
        n = land[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        vector<vector<int>> result;

        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                if(!visited[i][j] && land[i][j] == 1) {

                    int sr = i;
                    int sc = j;

                    pair<int, int> coord = {i, j};

                    dfs(land, visited, i, j, coord);

                    int lr = coord.first;
                    int lc = coord.second;

                    result.push_back({sr, sc, lr, lc});
                }
            }
        }

        return result;
    }
};


// Main function to test the solution
int main() {
    Solution sol;

    // Test Case 1 from your screenshot (The one returning Wrong Answer)
    vector<vector<int>> land1 = {
        {1, 0, 0},
        {0, 1, 1},
        {0, 1, 1}
    };

    cout << "Test Case 1 Input:" << endl;
    for (const auto& row : land1) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }

    vector<vector<int>> result1 = sol.findFarmland(land1);

    cout << "\nTest Case 1 Output:" << endl;
    cout << "[";
    for (size_t i = 0; i < result1.size(); ++i) {
        cout << "[" << result1[i][0] << "," << result1[i][1] << "," << result1[i][2] << "," << result1[i][3] << "]";
        if (i != result1.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    cout << "\nExpected: [[0,0,0,0],[1,1,2,2]]" << endl;

    // Test Case 2
    vector<vector<int>> land2 = {
        {1, 1},
        {1, 1}
    };

    cout << "\nTest Case 2 Input:" << endl;
    vector<vector<int>> result2 = sol.findFarmland(land2);
    cout << "Output: [[" << result2[0][0] << "," << result2[0][1] << "," << result2[0][2] << "," << result2[0][3] << "]]" << endl;
    cout << "Expected: [[0,0,1,1]]" << endl;

    return 0;
}
/*
    DFS :
    Time Complexity : O(m * n)
    Space Complexity : O(m * n)
*/

