#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isValid(vector<int>& price, int k, int x) {

        int n = price.size();
        int cntCandies = 1;
        int lastCandy = price[0];

        for(int i = 1; i < n; i ++) {

            if(price[i] - lastCandy >= x) {

                cntCandies ++;
                lastCandy = price[i];
            }

            if(cntCandies >= k) {

                return true;
            }
        }

        return false;
    }

    int maximumTastiness(vector<int>& price, int k) {

        int n = price.size();

        sort(begin(price), end(price));

        int low = 1;
        int high = price.back() - price.front();

        int ans = 0;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(isValid(price, k, mid)) {

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

int main() {

    Solution obj;

    vector<int> price2 = {1, 3, 1};
    int k2 = 2;
    cout << obj.maximumTastiness(price2, k2) << endl; // 2

    vector<int> price3 = {7, 7, 7, 7};
    int k3 = 2;
    cout << obj.maximumTastiness(price3, k3) << endl; // 0

    vector<int> price4 = {1, 2, 3, 4, 5};
    int k4 = 3;
    cout << obj.maximumTastiness(price4, k4) << endl; // 2

    return 0;
}


/*
    Sorting:      O(n log n)
    Validity:     O(n)
    Binary Search: O(log(maxPrice - minPrice))

    Total:
    Time Compexity : O(n log n + n log(maxPrice - minPrice))
    Space Complexity : O(1)
*/