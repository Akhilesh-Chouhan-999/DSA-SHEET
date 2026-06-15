#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool canEatBanana(vector<int>& piles, int h, int K) {

        int cntHrs = 0;

        for(int &pile : piles) {

            cntHrs += (pile + K - 1) / K;

            if(cntHrs > h) {

                return false;
            }
        }

        return cntHrs <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = *max_element(begin(piles), end(piles));

        int ans;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(canEatBanana(piles, h, mid)) {

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
    Solution solution;

    // Test Case 1 from your screenshot
    vector<int> piles1 = {3, 6, 7, 11};
    int h1 = 8;
    cout << "Test Case 1:" << endl;
    cout << "Piles: [3, 6, 7, 11], Hours: " << h1 << endl;
    cout << "Output: " << solution.minEatingSpeed(piles1, h1) << endl;
    cout << "Expected: 4" << endl << endl;

    // Test Case 2 from your screenshot
    vector<int> piles2 = {30, 11, 23, 4, 20};
    int h2 = 5;
    cout << "Test Case 2:" << endl;
    cout << "Piles: [30, 11, 23, 4, 20], Hours: " << h2 << endl;
    cout << "Output: " << solution.minEatingSpeed(piles2, h2) << endl;
    cout << "Expected: 30" << endl << endl;

    // Test Case 3 from your screenshot
    int h3 = 6;
    cout << "Test Case 3:" << endl;
    cout << "Piles: [30, 11, 23, 4, 20], Hours: " << h3 << endl;
    cout << "Output: " << solution.minEatingSpeed(piles2, h3) << endl;
    cout << "Expected: 23" << endl;

    return 0;
}