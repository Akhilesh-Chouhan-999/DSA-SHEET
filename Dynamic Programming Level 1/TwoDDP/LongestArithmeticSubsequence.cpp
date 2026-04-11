/*

#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:

    int memo[1001][1003] ; 
    int offset = 500;

    int solve(vector<int>&nums , int idx , int diff){

        if(idx < 0 )
        return 0 ; 

        if(memo[idx][diff+offset] != -1)
        return memo[idx][diff+offset] ; 

        int len = 0; 

        for(int k = idx - 1 ; k >= 0  ; k --){

            if(nums[idx] - nums[k] == diff){
                len = max(len , 1 + solve(nums , k , diff)) ; 
            }
        }

        return memo[idx][diff+offset] = len ; 
    }
    int longestArithSeqLength(vector<int>& nums) {

        int n = nums.size() ; 

        if( n <= 2)
        return n ; 

        memset(memo , -1 , sizeof(memo)) ; 

        int result = 0 ; 
        

        for(int i = 0 ; i < n ; i ++ ){

            for(int j = i + 1 ; j < n ; j ++){

                int diff = nums[j] - nums[i] ; 

                result = max(result , 2 +  solve(nums ,  i , diff))  ; 
            }
        }

        return result ; 
        
    }
};


int main() {
    Solution obj;

    vector<int> test1 = {3, 6, 9, 12};
    vector<int> test2 = {9, 4, 7, 2, 10};
    vector<int> test3 = {20, 1, 15, 3, 10, 5, 8};

    cout << "Test 1 Output: " << obj.longestArithSeqLength(test1)
         << " | Expected: 4" << endl;

    cout << "Test 2 Output: " << obj.longestArithSeqLength(test2)
         << " | Expected: 3" << endl;

    cout << "Test 3 Output: " << obj.longestArithSeqLength(test3)
         << " | Expected: 4" << endl;

    return 0;
}

Top Down Approach :
Time Complexity : O(n^3)
Space Complexity : O(n*D)
*/

#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:

  
    int offset = 500;

    int longestArithSeqLength(vector<int>& nums) {

        int n = nums.size() ; 

        vector<vector<int>>t(n+1 , vector<int>(1001 , 1))  ;

        int result = 0 ; 

        for(int i = 1 ; i < n ; i ++){

            for(int j = 0 ; j < i ; j ++ ){

                int diff = nums[i] - nums[j]  + offset ; 
                t[i][diff] = t[j][diff] > 0 ? t[j][diff] + 1 : 2 ; 
                result = max(result , t[i][diff]) ; 

            }
        }

        return result ; 
    
    }
};


int main() {
    Solution obj;

    vector<int> test1 = {3, 6, 9, 12};
    vector<int> test2 = {9, 4, 7, 2, 10};
    vector<int> test3 = {20, 1, 15, 3, 10, 5, 8};

    cout << "Test 1 Output: " << obj.longestArithSeqLength(test1)
         << " | Expected: 4" << endl;

    cout << "Test 2 Output: " << obj.longestArithSeqLength(test2)
         << " | Expected: 3" << endl;

    cout << "Test 3 Output: " << obj.longestArithSeqLength(test3)
         << " | Expected: 4" << endl;

    return 0;
}

// Botton Up Approach :
// Time Complexity : O(n^2)
// Space Complexity : O(n*diff)