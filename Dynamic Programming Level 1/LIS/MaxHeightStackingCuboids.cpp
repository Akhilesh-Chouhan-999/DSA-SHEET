/*
#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:

    int maxHeight(vector<vector<int>>& cuboids) {
        
        int n = cuboids.size() ;


        for(vector<int>&cuboid : cuboids) {
            sort(begin(cuboid) , end(cuboid)) ; 
        }

        sort(begin(cuboids) , end(cuboids)) ; 

        vector<int>dp(n) ; 

        for(int i = 0 ; i < n ; i ++){
            dp[i] = cuboids[i][2] ; 
        }

        int maxHeight = INT_MIN ; 

        for(int i = 0 ; i < n ; i ++){

            vector<int>currDimesion = cuboids[i] ;

            for(int j = 0 ; j < i ; j ++){

                vector<int>prevDimension = cuboids[j] ;

                if(prevDimension[0] <= currDimesion[0] && 
                   prevDimension[1] <= currDimesion[1] &&
                   prevDimension[2] <= currDimesion[2]) {

                        dp[i] = max(dp[i] , dp[j] + currDimesion[2]) ; 
                        
                }
            }

            maxHeight = max(maxHeight , dp[i]) ; 
        }

        return maxHeight ;
    }
};

int main() {

    Solution obj;

    // Test Case 1
    vector<vector<int>> cuboids1 = {{50,45,20},{95,37,53},{45,23,12}};
    cout << "Output 1: " << obj.maxHeight(cuboids1) << endl;
    cout << "Expected: 190" << endl << endl;

    // Test Case 2
    vector<vector<int>> cuboids2 = {{38,25,45},{76,35,3}};
    cout << "Output 2: " << obj.maxHeight(cuboids2) << endl;
    cout << "Expected: 76" << endl << endl;

    // Test Case 3
    vector<vector<int>> cuboids3 = {{7,11,17},{7,17,11},{11,7,17},{11,17,7},{17,7,11},{17,11,7}};
    cout << "Output 3: " << obj.maxHeight(cuboids3) << endl;
    cout << "Expected: 102" << endl;

    return 0;
}


Bottom Up Approach :
Time Complexity : O(n^2)
Space Complexity : O(n)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solve(int i, vector<vector<int>>& cuboids, vector<int>& dp){

        if(dp[i] != -1)
            return dp[i];

        int height = cuboids[i][2];

        for(int j = 0; j < i; j++){

            if(cuboids[j][0] <= cuboids[i][0] &&
               cuboids[j][1] <= cuboids[i][1] &&
               cuboids[j][2] <= cuboids[i][2]){

                height = max(height, cuboids[i][2] + solve(j, cuboids, dp));
            }
        }

        return dp[i] = height;
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        
        int n = cuboids.size();

        for(auto &c : cuboids)
            sort(begin(c), end(c));

        sort(begin(cuboids), end(cuboids));

        vector<int> dp(n, -1);

        int ans = 0;

        for(int i = 0; i < n; i++){
            ans = max(ans, solve(i, cuboids, dp));
        }

        return ans;
    }
};



int main() {

    Solution obj;

    // Test Case 1
    vector<vector<int>> cuboids1 = {{50,45,20},{95,37,53},{45,23,12}};
    cout << "Output 1: " << obj.maxHeight(cuboids1) << endl;
    cout << "Expected: 190" << endl << endl;

    // Test Case 2
    vector<vector<int>> cuboids2 = {{38,25,45},{76,35,3}};
    cout << "Output 2: " << obj.maxHeight(cuboids2) << endl;
    cout << "Expected: 76" << endl << endl;

    // Test Case 3
    vector<vector<int>> cuboids3 = {{7,11,17},{7,17,11},{11,7,17},{11,17,7},{17,7,11},{17,11,7}};
    cout << "Output 3: " << obj.maxHeight(cuboids3) << endl;
    cout << "Expected: 102" << endl;

    return 0;
}


