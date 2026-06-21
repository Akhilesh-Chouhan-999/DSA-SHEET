#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        
        int m = mat.size();
        int n = mat[0].size();

        int low = INT_MAX;
        int high = INT_MIN;

        for(int i = 0; i < m; i ++) {

          low = min(low, mat[i][0]);
          high = max(high, mat[i][n - 1]);
        }

        int required = ( m * n + 1) / 2;

        int ans = -1;
        while(low <= high) {

          int mid = low + (high - low) / 2;

          int cnt = 0;

          for(int i = 0; i < m; i ++) {

            cnt += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
          }

          if(cnt < required) {
            
            low = mid + 1;
          }
          else {

            ans = mid;
            high = mid - 1;
          }

        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<vector<int>> mat1 = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };

    cout << obj.median(mat1) << endl; // 5

    vector<vector<int>> mat2 = {
        {2, 4, 9},
        {3, 6, 7},
        {4, 7, 10}
    };

    cout << obj.median(mat2) << endl; // 6

    vector<vector<int>> mat3 = {
        {3},
        {4},
        {8}
    };

    cout << obj.median(mat3) << endl; // 4

    return 0;
}

/*
  Time Complexity : O(log(ValueRange)×m×logn)
  Space Complexity : O(1)
*/