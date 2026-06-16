#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    using ll = long long;

    bool solve(vector<ll> diff, int r, int k, ll maxPower) {

        ll currPower = 0;

        for(int i = 0; i < diff.size(); i ++) {

            currPower += diff[i];

            if(maxPower > currPower) {

                ll need = maxPower - currPower;

                if(need > k) {

                    return false;
                }

                currPower += need;
                k -= need;

                if(i + 2 * r + 1 < diff.size()) {

                    diff[i + 2 * r + 1] -= need;
                }
            }
        }


        return true;
    }
    long long maxPower(vector<int>& stations, int r, int k) {

        ll n = stations.size();

        vector<ll> diff(n, 0);

        for(int i = 0; i < n; i ++) {

            diff[max(0, i - r )] += stations[i];

            if(i + r + 1 < n) {

                diff[i + r + 1] -= stations[i];
            }
        }

        ll low = 0;
        ll high = accumulate(begin(stations), end(stations), 0ll) + k;

        ll ans = -1;
        while(low <= high) {

            ll mid = low + (high - low) / 2;

            if(solve(diff, r, k, mid)) {

                ans = mid;
                low = mid + 1;
            }

            else {

                high = mid - 1;
            }
        
        }

        return ans;
    }
};



// Main function wrapper to run the solution
int main() {
    Solution sol;
    
    // Example 1
    vector<int> stations1 = {1, 2, 4, 5, 0};
    int r1 = 1;
    int k1 = 2;
    cout << "Example 1 Output: " << sol.maxPower(stations1, r1, k1) << endl;
    // Expected: 5
    
    // Example 2
    vector<int> stations2 = {4, 4, 4, 4};
    int r2 = 0;
    int k2 = 3;
    cout << "Example 2 Output: " << sol.maxPower(stations2, r2, k2) << endl;
    // Expected: 4

    return 0;
}


/*
    Time Complexity : O(n * log(sum(stations)+k)
    Space Complexity : O(n)
*/