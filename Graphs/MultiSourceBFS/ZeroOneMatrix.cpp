#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    using p = pair<int, int>;

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {-1, 1, 0, 0};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        queue<p> que;

        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                if(mat[i][j] == 0) {

                    dist[i][j] = 0;
                    que.push({i, j});
                }
            }
        }

        while(!que.empty()) {

            auto [cr, cc] = que.front();
            que.pop();

            for(int i = 0; i < 4; i++) {

                int nr = cr + dx[i];
                int nc = cc + dy[i];

                if(nr < 0 || nc < 0 || nr >= m || nc >= n) {
                    continue;
                }

                if(dist[nr][nc] > dist[cr][cc] + 1) {

                    dist[nr][nc] = dist[cr][cc] + 1;
                    que.push({nr, nc});
                }
            }
        }

        for(int i = 0; i < m; i ++) {

            for(int j = 0; j < n; j ++) {

                if(dist[i][j] == INT_MAX) {

                    dist[i][j]= 0;
                }
            }
        }

        return dist;
    }
};



// Main function to test the solution
int main() {
    // Example 1: A matrix with a 0 in the middle
    vector<vector<int>> mat1 = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    // Example 2: A matrix with 1s on the edge
    vector<vector<int>> mat2 = {
        {1, 0, 1},
        {1, 1, 1},
        {1, 1, 1}
    };

    Solution sol;

    // Test Case 1
    cout << "Test Case 1 Input:" << endl;
    for(const auto& row : mat1) {
        for(int val : row) cout << val << " ";
        cout << endl;
    }
    vector<vector<int>> result1 = sol.updateMatrix(mat1);
    cout << "Test Case 1 Output:" << endl;
    for(const auto& row : result1) {
        for(int val : row) cout << val << " ";
        cout << endl;
    }

    cout << "\n------------------\n" << endl;

    // Test Case 2
    cout << "Test Case 2 Input:" << endl;
    for(const auto& row : mat2) {
        for(int val : row) cout << val << " ";
        cout << endl;
    }
    vector<vector<int>> result2 = sol.updateMatrix(mat2);
    cout << "Test Case 2 Output:" << endl;
    for(const auto& row : result2) {
        for(int val : row) cout << val << " ";
        cout << endl;
    }

    return 0;
}