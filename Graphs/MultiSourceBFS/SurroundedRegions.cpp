#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        queue<pair<int, int>> que;

        for(int i = 0; i < n; i ++) {

            if(board[0][i] == 'O') {

                que.push({0, i});
                visited[0][i] = true;
            }

            if(board[m - 1][i] == 'O') {

                que.push({m - 1, i});
                visited[m - 1][i] = true;
            }
        } 


        for(int i = 0; i < m; i ++) {

            if(board[i][0] == 'O') {

                que.push({i, 0});
                visited[i][0] = true;
            }

            if(board[i][n - 1] == 'O') {

                que.push({i, n - 1});
                visited[i][n - 1] = true;
            }
        }

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {-1, 1, 0, 0};

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

                    if(board[nr][nc] == 'X') {
                        continue;
                    }

                    que.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }
        
        int cnt = 0;

        for(int i = 0; i < m; i ++) {


            for(int j = 0; j < n; j ++) {

                if(!visited[i][j] && board[i][j] == 'O') {

                    board[i][j] = 'X';
                }
            }
        }

        return;
    }
};


// Helper function to print the board
void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    // Test Case 1: Standard example
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    cout << "Original Board:" << endl;
    printBoard(board);

    Solution sol;
    sol.solve(board);

    cout << "After solving:" << endl;
    printBoard(board);

    // Test Case 2: All 'O's connected to border
    vector<vector<char>> board2 = {
        {'O', 'O', 'O'},
        {'O', 'O', 'O'},
        {'O', 'O', 'O'}
    };

    cout << "Original Board 2:" << endl;
    printBoard(board2);

    sol.solve(board2);

    cout << "After solving (should remain all 'O'):" << endl;
    printBoard(board2);

    return 0;
}