#include<iostream>
using namespace std ; 

class Solution {
public:
    int arrangeCoins(int n) {

        int low = 1 ;
        int high = n ; 


        while(low <= high){

            int mid = low + ( high - low) / 2 ; 

            int coins = mid * ( mid + 1 ) / 2 ; 

            if(coins == n)
            return mid ; 

            else if(coins > n){
                high = mid - 1 ; 
            }

            else{
                low = mid + 1 ; 
            }
            
        }

        return high ;
        
    }
};


int main() {
    Solution obj;

    // Test Case 1
    int n1 = 5;
    cout << obj.arrangeCoins(n1) << endl; // Expected: 2

    // Test Case 2
    int n2 = 8;
    cout << obj.arrangeCoins(n2) << endl; // Expected: 3

    // Additional Test Case 3
    int n3 = 1;
    cout << obj.arrangeCoins(n3) << endl; // Expected: 1

    // Additional Test Case 4
    int n4 = 10;
    cout << obj.arrangeCoins(n4) << endl; // Expected: 4

    return 0;
}