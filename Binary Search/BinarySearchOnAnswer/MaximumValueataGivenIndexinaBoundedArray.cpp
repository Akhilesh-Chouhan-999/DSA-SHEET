#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;

    ll getSum(ll len, ll peak) {

        if(len <= peak) {

            ll first = peak - len + 1;
            ll last = peak;

           return (len * (first + last)) / 2;
        }

        ll remElement = len - peak;
        ll decPartSum = (peak * (peak + 1)) / 2;

        return remElement + decPartSum;
    }

    bool isPossible(int n, int index, int maxSum, ll x) {

        ll leftSum = getSum(index, x - 1);
        ll rightSum = getSum(n - index - 1, x - 1);
        
        return leftSum + x + rightSum <= (ll)maxSum;
    }

    int maxValue(int n, int index, int maxSum) {
        
        ll low = 0;
        ll high = maxSum;

        ll ans = 1;

        while(low <= high) {

            ll mid = low + (high - low) / 2;

            if(isPossible(n, index, maxSum, mid)) {

                ans = mid;
                low = mid + 1;
            }

            else {
                
                high = mid - 1;
            }
        }

        return (int)ans;
    }
};

int main() {

    Solution obj;

    cout << obj.maxValue(4, 2, 6) << endl;    // 2
    cout << obj.maxValue(6, 1, 10) << endl;   // 3

    return 0;
}

/* 
    Time Complexity : O(log(maxSum))
    Spae Complexity : O(1)
*/