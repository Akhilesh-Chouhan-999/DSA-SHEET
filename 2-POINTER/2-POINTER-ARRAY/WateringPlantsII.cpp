#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumRefill(vector<int> &plants, int capacityA, int capacityB){
        
        int n = plants.size() ;

        int i      = 0 ; 
        int j      = n - 1 ;
        int result = 0 ;  
        int alice  = capacityA ; 
        int bob    = capacityB ; 

        while(i < j){

            if(alice >= plants[i]){
                alice -= plants[i] ; 
            } else{
                alice = capacityA ;
                alice -= plants[i] ; 
                result ++ ;
            }


            if(bob >= plants[j]){
                bob -= plants[j] ; 
            }else{
                bob = capacityB ; 
                bob -= plants[j] ; 
                result ++ ; 
            }

            i ++ ;
            j -- ; 

        }


        if( n % 2 == 1 && (alice < plants[i] && bob < plants[j]) )
        result ++ ; 


        return result ; 
      
    }
};


int main()
{
    Solution sol;

    // Test 1: Expected 1
    vector<int> plants1 = {2, 2, 3, 3};
    int res1 = sol.minimumRefill(plants1, 5, 5);
    cout << "Test 1 | plants=[2,2,3,3], capacityA=5, capacityB=5\n";
    cout << "  Expected: 1\n";
    cout << "  Output  : " << res1 << "\n\n";

    // Test 2: Expected 3
    vector<int> plants3 = {5};
    int res3 = sol.minimumRefill(plants3, 10, 8);
    cout << "Test 2 | plants=[5], capacityA=10, capacityB=8\n";
    cout << "  Expected: 0\n";
    cout << "  Output  : " << res3 << "\n";

    return 0;
}
// Time Complexity : O(n)
// Space Complexity : O(1)

