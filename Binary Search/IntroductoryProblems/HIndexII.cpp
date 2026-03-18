#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int hIndex(vector<int>& citations) {

        int n = citations.size() ;


        int low = 1 ; 
        int high = n  ; 
        int result = 0 ; 

        while(low <= high){

            int mid = low + ( high - low) / 2 ; 

            if(citations[n-mid] >= mid){
                result = mid ; 
                low = mid + 1 ; 
            }
            else{
                high = mid - 1 ; 
            }
        }

        return result ; 
    }
};
int main() {
    Solution obj;

    // Test Case 1
    vector<int> citations1 = {0, 1, 3, 5, 6};
    cout << "H-Index: " << obj.hIndex(citations1) << endl;  // Expected: 3

    // Test Case 2
    vector<int> citations2 = {1, 2, 100};
    cout << "H-Index: " << obj.hIndex(citations2) << endl;  // Expected: 2

    // Test Case 3
    vector<int> citations3 = {0, 0, 0};
    cout << "H-Index: " << obj.hIndex(citations3) << endl;  // Expected: 0

    // Test Case 4
    vector<int> citations4 = {10, 20, 30, 40};
    cout << "H-Index: " << obj.hIndex(citations4) << endl;  // Expected: 4

    // Test Case 5
    vector<int> citations5 = {0, 1, 2, 3, 4, 5};
    cout << "H-Index: " << obj.hIndex(citations5) << endl;  // Expected: 3

    return 0;
}

// Time Complexity : O(log(n))
// Space Complexity : O(1)

