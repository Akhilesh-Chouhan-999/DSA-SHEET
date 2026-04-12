/*
#include<bits/stdc++.h>
using namespace std ; 

class Solution {
  public:
 
    unordered_map<int, vector<int>> memo;

    vector<int> solve(vector<int>& arr, int idx) {


        if(memo.count(idx)){
            return memo[idx] ; 
        }

        vector<int>LIS ; 
        LIS.push_back(arr[idx]) ; 


        for(int prev = idx - 1 ; prev >= 0 ; prev --) {

            if(arr[prev] < arr[idx]){

                vector<int>candidate = solve(arr, prev) ;
                candidate.push_back(arr[idx]) ;


                if(candidate.size() >= LIS.size()){
                    LIS = candidate ; 
                }
            }

        }

        return memo[idx] = LIS ; 
    }


    
    vector<int> getLIS(vector<int>& arr) {

        int n = arr.size()  ;

        vector<int>result ; 

        for(int i = 0 ; i < n ; i ++){

            vector<int>candidate = solve(arr, i) ; 

            if(candidate.size() > result.size()){
                result = candidate ; 
            }
        }
        
        return result ;
    }
};

int main() {

    Solution obj;

    // Test Case 1
    vector<int> arr1 = {10, 20, 3, 40};
    vector<int> res1 = obj.getLIS(arr1);

    cout << "LIS 1: ";
    for(int x : res1) cout << x << " ";
    cout << endl;

    // Test Case 2
    vector<int> arr2 = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    vector<int> res2 = obj.getLIS(arr2);

    cout << "LIS 2: ";
    for(int x : res2) cout << x << " ";
    cout << endl;

    // Test Case 3 (edge case)
    vector<int> arr3 = {5, 4, 3, 2, 1};
    vector<int> res3 = obj.getLIS(arr3);

    cout << "LIS 3: ";
    for(int x : res3) cout << x << " ";
    cout << endl;

    // Test Case 4 (duplicates)
    vector<int> arr4 = {2, 2, 2, 2};
    vector<int> res4 = obj.getLIS(arr4);

    cout << "LIS 4: ";
    for(int x : res4) cout << x << " ";
    cout << endl;

    return 0;
}
    Time Complexity : O(n^3)
    Space Complexity : O(n^2)

#include<bits/stdc++.h>
using namespace std ; 

class Solution {
  public:

    vector<int> getLIS(vector<int>& arr) {

        int n = arr.size() ;

        vector<int>dp(n,1) ;
        vector<int>parent(n,-1) ; 
         
        int LIS = 1 ; 
        int liSIdx = 0 ; 
        for(int i = 0 ; i < n ; i ++) {

            for(int j = 0 ; j < i ; j ++) {

                if(arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }

            if(LIS < dp[i]){
                LIS = dp[i] ; 
                liSIdx = i ; 
            }
        }

        vector<int>result ; 

        int curr = liSIdx;

        while(curr != -1) {
            result.push_back(arr[curr]);
            curr = parent[curr];
        }

        reverse(result.begin(), result.end());

        return result ; 
    }
};

int main() {

    Solution obj;

    // Test Case 1
    vector<int> arr1 = {10, 20, 3, 40};
    vector<int> res1 = obj.getLIS(arr1);

    cout << "LIS 1: ";
    for(int x : res1) cout << x << " ";
    cout << endl;

    // Test Case 2
    vector<int> arr2 = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    vector<int> res2 = obj.getLIS(arr2);

    cout << "LIS 2: ";
    for(int x : res2) cout << x << " ";
    cout << endl;

    // Test Case 3 (edge case)
    vector<int> arr3 = {5, 4, 3, 2, 1};
    vector<int> res3 = obj.getLIS(arr3);

    cout << "LIS 3: ";
    for(int x : res3) cout << x << " ";
    cout << endl;

    // Test Case 4 (duplicates)
    vector<int> arr4 = {2, 2, 2, 2};
    vector<int> res4 = obj.getLIS(arr4);

    cout << "LIS 4: ";
    for(int x : res4) cout << x << " ";
    cout << endl;

    return 0;
}
 Time Complexity : O(n^2)
 Space Complexity : O(n)
*/

#include<bits/stdc++.h>
using namespace std ; 

class Solution {
  public:

    vector<int>parent ;
    vector<int>dp ; 

    int solve(vector<int>& arr, int i) {


        if(dp[i] != -1)
        return dp[i] ; 

        int maxLength = 1 ; 

        for(int j = 0 ; j < i ; j ++ ){

            
            if(arr[j] < arr[i] ) {
                
                int length = solve(arr , j) ; 

                if(maxLength < length + 1){
                    maxLength = length + 1  ;
                    parent[i] = j ; 
                }
            }

        }
        

        return dp[i] =  maxLength ; 

     }
    vector<int> getLIS(vector<int>& arr) {

        
        int n = arr.size();

        dp.assign(n , -1) ; 
        parent.assign(n,-1) ; 

        int LIS = 1;
        int lisIdx = 0;

        for(int i = 0; i < n; i++) {

            int len = solve(arr, i);

            if(len > LIS) {
                LIS = len;
                lisIdx = i;
            }
        }

        vector<int> result;
        int curr = lisIdx;

        while(curr != -1) {
            result.push_back(arr[curr]);
            curr = parent[curr];
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
