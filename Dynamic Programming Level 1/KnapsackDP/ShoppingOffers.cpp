#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:

    bool baseCase(vector<int>& needs){

        bool flag = true ;

        for(int &x : needs){
            if(x != 0)
            return false ; 
        }

        return true ; 
    }
    int calculateMincost(vector<int>& price, vector<vector<int>>& specials, vector<int>& needs, map<vector<int>,int>memo){

        if(baseCase(needs)){
            return 0;
        }

        if(memo.count(needs))
        return memo[needs] ;

        int minCost = calculateCost(price, needs);

        for(vector<int>& special : specials){

            vector<int>newNeeds ;

            if(isSpecialApplicable(special, needs)){

                int cost = special[special.size()-1] ;   

                for(int i = 0 ; i < needs.size() ; i ++){
                    newNeeds.push_back(needs[i]-special[i]) ; 
                }

                minCost = min(minCost, cost + calculateMincost(price, specials, newNeeds, memo));
            }

        }

        return memo[needs] = minCost ; 
    }


    int calculateCost(vector<int>&price, vector<int>&needs){

        int cost = 0 ; 

        for(int i = 0 ; i < price.size() ; i ++){
            cost += price[i]*needs[i] ; 
        }

        return cost ; 
    }

    bool isSpecialApplicable(vector<int>&special, vector<int>&needs){

        for(int i = 0 ; i < needs.size() ; i ++){

            if(special[i] > needs[i])
            return false ; 
        }


        return true ; 
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {

        map<vector<int>, int> memo;
        
        return calculateMincost(price, special, needs, memo);
    }
};

int main() {

    Solution obj;

    // Test Case 1
    vector<int> price1 = {2, 5};
    vector<vector<int>> special1 = {{3, 0, 5}, {1, 2, 10}};
    vector<int> needs1 = {3, 2};

    cout << obj.shoppingOffers(price1, special1, needs1) << endl; // Expected: 14


    // Test Case 2
    vector<int> price2 = {2, 3, 4};
    vector<vector<int>> special2 = {{1,1,0,4}, {2,2,1,9}};
    vector<int> needs2 = {1,2,1};

    cout << obj.shoppingOffers(price2, special2, needs2) << endl; // Expected: 11


    return 0;
}


// Time Complexity : O((maxNeed)^k × S × k)
// Space Complexity : O((maxNeed+1)^k × k)