#include <bits/stdc++.h>
using namespace std;

class Solution {
public : 


    int maxProfit(vector<int>& prices) {

        int n = prices.size() ; 

        int result = INT_MIN ; 

        int minSoFar = prices[0] ; 

        for(int i = 1 ; i < n ; i ++){

            if(prices[i] < minSoFar){
                minSoFar = prices[i] ; 
            }
            else{
                result = max(result , prices[i] - minSoFar) ; 
            }
        }

        return result == INT_MIN ? 0 : result ; 

    }
};



int main() {
    Solution obj;

    // Test Case 1 (Example)
    vector<int> prices1 = {7,1,5,3,6,4};
    cout << "Test Case 1 Output: "
         << obj.maxProfit(prices1) << endl;

    // Test Case 2 (No profit)
    vector<int> prices2 = {7,6,4,3,1};
    cout << "Test Case 2 Output: "
         << obj.maxProfit(prices2) << endl;

    // Test Case 3 (Single element)
    vector<int> prices3 = {5};
    cout << "Test Case 3 Output: "
         << obj.maxProfit(prices3) << endl;

    // Test Case 4 (All same values)
    vector<int> prices4 = {3,3,3,3,3};
    cout << "Test Case 4 Output: "
         << obj.maxProfit(prices4) << endl;

    // Test Case 5 (Strictly increasing)
    vector<int> prices5 = {1,2,3,4,5};
    cout << "Test Case 5 Output: "
         << obj.maxProfit(prices5) << endl;

    // Test Case 6 (Strictly decreasing)
    vector<int> prices6 = {9,8,7,6,5};
    cout << "Test Case 6 Output: "
         << obj.maxProfit(prices6) << endl;

    // Test Case 7 (Peak in middle)
    vector<int> prices7 = {5,2,6,1,4};
    cout << "Test Case 7 Output: "
         << obj.maxProfit(prices7) << endl;

    // Test Case 8 (Large fluctuation)
    vector<int> prices8 = {2,10,1,8,3,15};
    cout << "Test Case 8 Output: "
         << obj.maxProfit(prices8) << endl;

    // Test Case 9 (Buy at last possible)
    vector<int> prices9 = {8,7,6,5,10};
    cout << "Test Case 9 Output: "
         << obj.maxProfit(prices9) << endl;

    // Test Case 10 (Early max profit)
    vector<int> prices10 = {1,10,2,3,4};
    cout << "Test Case 10 Output: "
         << obj.maxProfit(prices10) << endl;

    return 0;
}

// Time Complexity : O(n)
// Space Complexity : O(1)

