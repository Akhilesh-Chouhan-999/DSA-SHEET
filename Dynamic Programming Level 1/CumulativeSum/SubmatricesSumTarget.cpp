#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
            
        int m = matrix.size();
        int n = matrix[0].size();

        int result = 0 ; 
        
        for(int top = 0; top < m; top ++) {

            vector<int>colSum(n, 0);

            for(int bottom = top; bottom < m ; bottom ++) {


                for(int col = 0; col < n; col ++){
                    colSum[col] += matrix[bottom][col];
                }

                unordered_map<int, int>mpp; 

                mpp[0] = 1;

                int prefix = 0;

                for(int i = 0 ; i < n ; i ++){

                    prefix += colSum[i];

                    if(mpp.count(prefix - target)){
                        result += mpp[prefix - target];
                    }

                    mpp[prefix] ++;
                }



            }
        }

        return result;
    }
};


int main() {
    Solution sol;

    vector<vector<int>> matrix1 = {
        {0, 1, 0},
        {1, 1, 1},
        {0, 1, 0}
    };
    int target1 = 0;
    cout << "Output 1: " << sol.numSubmatrixSumTarget(matrix1, target1) << endl;

    vector<vector<int>> matrix2 = {
        {1, -1},
        {-1, 1}
    };
    int target2 = 0;
    cout << "Output 2: " << sol.numSubmatrixSumTarget(matrix2, target2) << endl;

   
    vector<vector<int>> matrix3 = {
        {904}
    };
    int target3 = 0;
    cout << "Output 3: " << sol.numSubmatrixSumTarget(matrix3, target3) << endl;

    return 0;

}

// Time Complextity : O(m^2*n)
// Space Complexity : O(n)
