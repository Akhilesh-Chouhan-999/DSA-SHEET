#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n = cardPoints.size();

        int i = 0;
        int j = 0;

        int winSize = n - k;
        int minSum = INT_MAX;
        int currSum = 0;

        while(j < n) {

            currSum += cardPoints[j];

            if(j - i + 1 == winSize) {

                minSum = min(minSum, currSum);

                currSum -= cardPoints[i];

                i ++;
            }

            j ++;

        }

        int sum = std::accumulate(cardPoints.begin(), cardPoints.end(), 0); 

        if(minSum == INT_MAX) {

            minSum = 0;
        }


        return sum - minSum;
    }
};




int main() {
    Solution sol;
    vector<vector<int>> testCases = {
        {1,2,3,4,5,6,1},
        {2,2,2},
        {9,7,7,9,7,7,9}
    };
    vector<int> kValues = {3, 2, 7};

    for (int i = 0; i < testCases.size(); ++i) {
        cout << "Test Case " << i+1 << ": ";
        cout << sol.maxScore(testCases[i], kValues[i]) << endl;
    }

    return 0;
}