#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:
    vector<int> diStringMatch(string s) {
        
        int n = s.length() ;

        int i = 0  , j = n  ; 

        vector<int>result ; 

        for(char ch : s){

            if(ch == 'I'){
                result.push_back(i) ; 
                i ++ ; 
            }
            else{
                result.push_back(j) ; 
                j -- ; 
            }
        }

        result.push_back(i) ;

        return result ; 
    }
};

void print(vector<int>&perm){

    cout << " [ " ;

    for(int x : perm)
    cout << x << " " ;

    cout << "] " ;
    cout << endl; 

    return ; 
}

int main(){

    Solution obj ; 

    {
        vector<int>result = obj.diStringMatch("IDID") ; 
        print(result) ;
    }

    {
         vector<int>result = obj.diStringMatch("III") ; 
        print(result) ;
    }

    {
         vector<int>result = obj.diStringMatch("DDI") ; 
        print(result) ;
    }


    return 0 ; 
}

// Time complexity : O(n)
// Space Complexity : O(n)
