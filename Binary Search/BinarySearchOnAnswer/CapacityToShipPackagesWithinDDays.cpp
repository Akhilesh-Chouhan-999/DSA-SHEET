#include<bits/stdc++.h>
using namespace std;

class Solution {
public: 
    bool canShipped(vector<int>& weights, int days, int maxCap) {

        int cntDays = 1;
        int currWeight = 0;

        for(int &w : weights) {
    
            if(currWeight + w > maxCap) {

                cntDays ++;
                currWeight = 0;
            }

            currWeight += w;

            if(cntDays > days || w > maxCap) {

                return false;
            }

        }

        return cntDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int n = weights.size();

        int low = *max_element(begin(weights), end(weights));
        int high = accumulate(begin(weights), end(weights), 0);

        int ans;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(canShipped(weights, days, mid)) {

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

    vector<int> weights1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days1 = 5;
    cout << "Test 1: " << obj.shipWithinDays(weights1, days1)
         << " (Expected: 15)" << endl;

    vector<int> weights2 = {3, 2, 2, 4, 1, 4};
    int days2 = 3;
    cout << "Test 2: " << obj.shipWithinDays(weights2, days2)
         << " (Expected: 6)" << endl;

    vector<int> weights3 = {1, 2, 3, 1, 1};
    int days3 = 4;
    cout << "Test 3: " << obj.shipWithinDays(weights3, days3)
         << " (Expected: 3)" << endl;

    vector<int> weights4 = {10};
    int days4 = 1;
    cout << "Test 4: " << obj.shipWithinDays(weights4, days4)
         << " (Expected: 10)" << endl;

    vector<int> weights5 = {5, 5, 5, 5};
    int days5 = 2;
    cout << "Test 5: " << obj.shipWithinDays(weights5, days5)
         << " (Expected: 10)" << endl;

    vector<int> weights6 = {7, 2, 5, 10, 8};
    int days6 = 2;
    cout << "Test 6: " << obj.shipWithinDays(weights6, days6)
         << " (Expected: 18)" << endl;

    return 0;
}
/*
    Time Complexity : O(n × log(sum(weights) - max(weights) + 1))
    Space Complexity : O(1)
*/
