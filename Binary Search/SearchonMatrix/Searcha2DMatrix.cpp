#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        int low = 0;
        int high = m * n - 1;

        
        while(low <= high) {
            
            int mid = low + (high - low) / 2;

            int row = mid / n;
            int col = mid % n;

            if(matrix[row][col] == target) {

                return true;
            }

            else if(matrix[row][col] < target) {


                low = mid + 1;
            }

            else {

                high = mid - 1;
            }

        }

        return false;
    }
};



int main() {
    Solution sol;
    
    // Test Case 1
    vector<vector<int>> matrix1 = {{1,3,5,7}, {10,11,16,20}, {23,30,34,60}};
    int target1 = 3;
    cout << "Test Case 1 (Target: " << target1 << ") -> " 
         << (sol.searchMatrix(matrix1, target1) ? "true" : "false") << endl;
    cout << "Expected: true" << endl;

    // Test Case 2
    vector<vector<int>> matrix2 = {{1,3,5,7}, {10,11,16,20}, {23,30,34,60}};
    int target2 = 13;
    cout << "Test Case 2 (Target: " << target2 << ") -> " 
         << (sol.searchMatrix(matrix2, target2) ? "true" : "false") << endl;
    cout << "Expected: False" << endl;

    return 0;
}

/*
    Time Complexity : O(log(m * n))
    Space Complexity : O(1)
*/