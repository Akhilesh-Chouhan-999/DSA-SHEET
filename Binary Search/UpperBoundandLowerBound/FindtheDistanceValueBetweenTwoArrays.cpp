#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {

        int n = arr1.size()  ; 
        int m = arr2.size()  ; 

        sort(begin(arr2) , end(arr2)) ; 

        int result = n ; 

        for( int x : arr1){

            int low = 0 ; 
            int high = m - 1 ; 
            bool found = false ; 

            while(low <= high){

                int mid = low + ( high - low ) / 2 ; 
                int y = arr2[mid] ; 

                if( x - d <= y && y <= x + d) {
                    found = true ; 
                    break; 
                }

                else if( x - d > y ){
                    low = mid + 1 ; 
                }

                else{
                    high = mid - 1 ; 
                }


            }

            if(found)
            result -- ; 
        }

        return result ; 
        
    }
};


int main() {
    Solution sol;

    vector<int> arr1_1 = {4, 5, 8};
    vector<int> arr2_1 = {10, 9, 1, 8};
    int d1 = 2;
    cout << sol.findTheDistanceValue(arr1_1, arr2_1, d1) << endl;

    vector<int> arr1_2 = {1, 4, 2, 3};
    vector<int> arr2_2 = {-4, -3, 6, 10, 20, 30};
    int d2 = 3;
    cout << sol.findTheDistanceValue(arr1_2, arr2_2, d2) << endl;

    vector<int> arr1_3 = {2, 1, 100, 3};
    vector<int> arr2_3 = {-5, -2, 10, -3, 7};
    int d3 = 6;
    cout << sol.findTheDistanceValue(arr1_3, arr2_3, d3) << endl;

    return 0;
}