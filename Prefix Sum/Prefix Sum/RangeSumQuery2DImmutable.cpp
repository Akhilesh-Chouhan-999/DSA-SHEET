#include <bits/stdc++.h>
using namespace std;

class NumMatrix {
public:

    vector<vector<int>>prefix ; 

    NumMatrix(vector<vector<int>>& matrix) {
       
        int m = matrix.size() ; 
        int n = matrix[0].size() ; 

        prefix.resize(m+1 , vector<int>(n+1 , 0)) ; 

        
        for(int i = 1 ; i <= m ; i ++){
            
            for(int j = 1 ; j <= n ; j ++){
                
                prefix[i][j] = prefix[i][j-1] + matrix[i-1][j-1] ;
                
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int result = 0 ; 

 
        for(int idx = row1 ; idx <= row2 ; idx ++){
            result += (prefix[idx+1][col2+1] - prefix[idx+1][col1]) ; 
        }

        return result ; 
    }
};

int main() {
    vector<vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };

    NumMatrix obj(matrix);

    cout << obj.sumRegion(2, 1, 4, 3) << " Expected: 8" << endl;
    cout << obj.sumRegion(1, 1, 2, 2) << " Expected: 11" << endl;
    cout << obj.sumRegion(1, 2, 2, 4) << " Expected: 12" << endl;

    return 0;
}