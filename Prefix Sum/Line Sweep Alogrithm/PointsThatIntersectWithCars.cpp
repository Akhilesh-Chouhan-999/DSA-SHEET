/*
#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {

        int n = nums.size() ; 

        sort(begin(nums) , end(nums)) ;
        
        vector<vector<int>>event ;

        for(vector<int>&num : nums){
            int start = num[0] ; 
            int end = num[1] ; 

            if(event.empty())
            event.push_back({start , end}) ; 


            else{

                if(event.back()[1] >= start){
                    event.back()[1] = max(event.back()[1] , end) ; 
                }

                else{
                    event.push_back({start , end}) ; 
                }

            }
        }


        int result = 0 ; 

        for(vector<int>&e : event){

            result += (e[1] - e[0]) ; 
        }

        return result ; 
    }
};

*/


#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {

        int n = nums.size() ; 

        vector<vector<int>>events ; 

        for(vector<int>&num : nums){

            int start = num[0] ; 
            int end = num[1] ; 

            events.push_back({start , +1}) ; 
            events.push_back({end + 1 , -1}) ; 
        }

        sort(begin(events) , end(events)) ; 

        int result = 0 ; 
        int active = 0 ; 
        int prev = 0 ; 

        for(vector<int>event : events){

            int curr = event[0] ; 
            int type = event[1] ; 

            if(active > 0){
                result += (curr - prev ) ;
            }
           
            active += type ; 
            prev = curr ; 
        }

        return result ; 
    }
};


int main() {
    Solution obj;

    vector<vector<int>> nums1 = {{3,6},{1,5},{4,7}};
    cout << obj.numberOfPoints(nums1) << endl;  // Expected: 7

    vector<vector<int>> nums2 = {{1,3},{5,8}};
    cout << obj.numberOfPoints(nums2) << endl;  // Expected: 7

    return 0;
}

// Time Complexity : O(n*log(n))
// Space Complexity : O(2*n)