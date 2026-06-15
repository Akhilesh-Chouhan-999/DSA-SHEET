#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        
        int low = 1;
        int high = x;

        int ans = -1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(mid * mid == x) {

                return mid;
            }

            else if(mid * mid > x) {

                high = mid - 1;
            }

            else {
                
                ans = mid;
                low = mid + 1;
            }
        }

        return ans == -1 ? 0 : ans;
    }
};

int main() {
    Solution sol;
    
    // Test cases matching the logic from your submission
    vector<int> inputs = {0, 1, 4, 8, 9, 15, 16, 2147395600};

    cout << "Testing mySqrt function:" << endl;
    cout << "------------------------" << endl;

    for (int x : inputs) {
        int result = sol.mySqrt(x);
        cout << "mySqrt(" << x << ") = " << result << endl;
    }

    return 0;
}