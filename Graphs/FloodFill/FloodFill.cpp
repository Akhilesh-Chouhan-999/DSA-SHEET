#include<bits/stdc++.h>
using namespace std;

class Solution {
public:


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int m = image.size();
        int n = image[0].size();

        vector<vector<int>> grid(begin(image), end(image));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> que;
        

        que.push({sr, sc});
        visited[sr][sc] = true;

        while(!que.empty()) {

            int r = que.front().first;
            int c = que.front().second;

            grid[r][c] = color;

            que.pop();

            int dx[4] = { 0, 0, -1, 1};
            int dy[4] = {-1, 1,  0, 0};

            for(int i = 0; i < 4; i ++) {

                int nr = r + dx[i];
                int nc = c + dy[i];

                if(nr < 0 || nc < 0 || nr >= m || nc >= n || grid[nr][nc] != image[sr][sc] || visited[nr][nc]) {
                    continue;
                }

                que.push({nr, nc});
                visited[nr][nc] = true;

            }


        }

        return grid;

    }
};

void printMatrix(const vector<vector<int>>& matrix) {
    cout << "[";
    for (size_t i = 0; i < matrix.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i] [j];
            if (j < matrix[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < matrix.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}


int main() {
    Solution sol;

    // --- Test Case 1: The one failing in your screenshot ---
    // Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr=1, sc=1, color=2
    vector<vector<int>> image1 = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    cout << "Test Case 1 Input: " << endl;
    printMatrix(image1);
    vector<vector<int>> result1 = sol.floodFill(image1, 1, 1, 2);
    
    cout << "Test Case 1 Output: " << endl;
    printMatrix(result1);
    cout << "Expected: [[2,2,2],[2,2,0],[2,0,1]]" << endl << endl;

    // --- Test Case 2: All zeros ---
    // Input: image = [[0,0,0],[0,0,0]], sr=0, sc=0, color=0
    vector<vector<int>> image2 = {{0, 0, 0}, {0, 0, 0}};
    cout << "Test Case 2 Input: " << endl;
    printMatrix(image2);
    vector<vector<int>> result2 = sol.floodFill(image2, 0, 0, 0);
    
    cout << "Test Case 2 Output: " << endl;
    printMatrix(result2);
    cout << "Expected: [[0,0,0],[0,0,0]]" << endl << endl;

    return 0;
}

/*
    Time Complexity : O(m * n)
    space Complexity : O(m * n)
*/