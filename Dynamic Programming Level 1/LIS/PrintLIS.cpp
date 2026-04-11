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

int main(){

}