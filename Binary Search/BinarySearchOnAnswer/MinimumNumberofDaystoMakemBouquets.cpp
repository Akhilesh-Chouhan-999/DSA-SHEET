#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isPossible(vector<int>& bloomDay, int m, int k, int mid) {

        int n = bloomDay.size();
        int bqCnt = 0;
        int consDayCnt = 0;

        for(int i = 0; i < n; i++) {

            if(bloomDay[i] > mid) {

                consDayCnt = 0;
            }
            else {

                consDayCnt++;

                if(consDayCnt == k) {

                    consDayCnt = 0;
                    bqCnt++;
                }
            }

            if(bqCnt >= m) {

                return true;
            }
        }

        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        int n = bloomDay.size();

        if((long long)m * k > n) {

            return -1;
        }

        int low = *min_element(begin(bloomDay), end(bloomDay));
        int high = *max_element(begin(bloomDay), end(bloomDay));

        int ans = -1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(isPossible(bloomDay, m, k, mid)) {

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

    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3;
    int k = 1;

    cout << obj.minDays(bloomDay, m, k) << endl;

    return 0;
}

/*
    Time Complexity : O(n * log(maxDay - minDay))
    Space Complexity : O(1)
*/