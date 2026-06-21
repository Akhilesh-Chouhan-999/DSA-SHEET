#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int cntLessOrEqualToX(int m, int n, int X) {

        int cnt = 0;

        for(int i = 1; i <= m; i ++) {

            cnt += min(X / i, n);
        }

        return cnt ;
    } 
    int findKthNumber(int m, int n, int k) {
        
        int low = 1;
        int high = m * n;
        int ans = -1;

        while(low <= high) {

            int mid = low + (high - low) / 2;


            if(cntLessOrEqualToX(m, n, mid) >= k) {

                ans = mid;
                high = mid - 1;
            }

            else {
                
                low = mid + 1;
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<vector<int>> tests = {
        // {m, n, k, expected}

        {3, 3, 5, 3},
        {2, 3, 6, 6},
        {3, 3, 1, 1},
        {3, 3, 9, 9},
        {5, 5, 12, 6},
        {5, 5, 13, 8},
        {1, 10, 7, 7},
        {10, 1, 7, 7},
        {4, 4, 8, 4},
        {6, 7, 20, 10}
    };

    for(auto &test : tests) {

        int m = test[0];
        int n = test[1];
        int k = test[2];
        int expected = test[3];

        int ans = obj.findKthNumber(m, n, k);

        cout << "m=" << m
             << ", n=" << n
             << ", k=" << k
             << " -> Answer = " << ans
             << " | Expected = " << expected
             << (ans == expected ? "| PASSED" : "FAIL")
             << '\n';
    }

    return 0;
}

/*
    Time Complexity : O(m * log(m * n))
    Space Complextiy : O(1)
*/