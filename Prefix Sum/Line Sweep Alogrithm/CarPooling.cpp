#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        vector<vector<int>>events ; 

        for(vector<int>&trip : trips){

            int passengers = trip[0] ; 
            int from = trip[1] ;
            int to = trip[2] ; 


            events.push_back({from , +1 , passengers}); 
            events.push_back({to   , -1 , passengers});
            
        }


        sort(begin(events) , end(events)) ; 

        int prevPass = 0 ; 

        for(vector<int>&e : events){

            int pos  = e[0] ;
            int type = e[1] ;
            int currPass = e[2] ; 

            if(type == 1){

                if(prevPass + currPass > capacity)
                return false ; 

                 prevPass += currPass ; 

            }
            else{
                prevPass -= currPass ; 
            }

        }
       

        return true; 

    }
};

int main() {
    Solution sol;

    vector<vector<int>> trips1 = {{2,1,5}, {3,3,7}};
    int capacity1 = 4;
    cout << (sol.carPooling(trips1, capacity1) ? "true" : "false");
    cout << "  // Expected: false" << endl;

    vector<vector<int>> trips2 = {{2,1,5}, {3,3,7}};
    int capacity2 = 5;
    cout << (sol.carPooling(trips2, capacity2) ? "true" : "false");
    cout << "  // Expected: true" << endl;

    return 0;
}