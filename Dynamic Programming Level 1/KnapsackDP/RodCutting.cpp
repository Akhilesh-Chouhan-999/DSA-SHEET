#include<bits/stdc++.h>
using namespace std ; 

class Solution {
  public:

    int memo[1001] ; 

    int solve(vector<int>& prices, int remLength){

        if(remLength <= 0){
            return 0 ; 
        }

        if(memo[remLength] != -1)
        return memo[remLength] ; 

        int maxProftit = INT_MIN ; 
        int profit     = INT_MIN ; 

        for(int i = 0 ; i < prices.size() ; i++){

            if(remLength >= i + 1){
                int cal = solve(prices, remLength - (i + 1));
                
                if(cal == INT_MIN){
                    profit = INT_MIN; 
                }
                else{
                    profit = prices[i] + cal ;
                }
            }

            maxProftit = max(maxProftit , profit) ; 
        }


        return memo[remLength] =  maxProftit ; 

    }


    int cutRod(vector<int> &price) {

        memset(memo , -1 , sizeof(memo)) ; 

        return solve(price , price.size()) ; 

    }
};


int main() {

    Solution obj;

    // Test Case 1
    vector<int> price1 = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << "Output: " << obj.cutRod(price1) << " | Expected: 22" << endl;

    // Test Case 2
    vector<int> price2 = {3, 5, 8, 9, 10, 17, 17, 20};
    cout << "Output: " << obj.cutRod(price2) << " | Expected: 24" << endl;

    // Test Case 3
    vector<int> price3 = {3};
    cout << "Output: " << obj.cutRod(price3) << " | Expected: 3" << endl;

    return 0;
}
 
// Top Down Approach :
// Time Complexity : O(n^2)
// Space Complexity : O(n^2)

