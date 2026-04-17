#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {

        int m = matrix.size();
        int n = matrix[0].size();

        int result = INT_MIN;

        for(int top = 0; top < m; top ++) {

            vector<int>currCols(n, 0);

            for(int bottom = top; bottom < m; bottom ++){


                for(int col = 0; col < n; col ++) {
                    currCols[col] += matrix[bottom][col];
                }

                set<int>st;

                st.insert(0);

                int currSum = 0;

                for(int curr : currCols) {

                    currSum += curr;

                    auto it = st.lower_bound(currSum - k);

                    if(it != st.end()) {

                        int prevSum = *it;
                        result = max(result, currSum - prevSum);
                    }
                    st.insert(currSum);
                }

            }

        }

        return result;
    }
};


int main() {
    Solution sol;

    // Test Case 1
    vector<vector<int>> matrix1 = {
        {1, 0, 1},
        {0, -2, 3}
    };
    int k1 = 2;
    cout << "Output 1: " << sol.maxSumSubmatrix(matrix1, k1) << endl;

    // Test Case 2
    vector<vector<int>> matrix2 = {
        {2, 2, -1}
    };
    int k2 = 3;
    cout << "Output 2: " << sol.maxSumSubmatrix(matrix2, k2) << endl;

    // Custom Test Case 3 (edge case: negatives)
    vector<vector<int>> matrix3 = {
        {-1, -2},
        {-3, -4}
    };
    int k3 = -2;
    cout << "Output 3: " << sol.maxSumSubmatrix(matrix3, k3) << endl;

    // Custom Test Case 4 (mixed values)
    vector<vector<int>> matrix4 = {
        {5, -2, 3}
    };
    int k4 = 4;
    cout << "Output 4: " << sol.maxSumSubmatrix(matrix4, k4) << endl;

    return 0;
}