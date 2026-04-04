#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {

        int n = obstacles.size() ; 


        vector<int>result ; 
        vector<int>LIS ;

        LIS.push_back(obstacles[0]) ; 
        result.push_back(1) ;

        for(int i = 1 ; i < n ; i ++ ){

            if(obstacles[i] >= LIS.back()){

                LIS.push_back(obstacles[i]) ; 

                result.push_back(LIS.size()) ; 

            }
            else{
                
                int idx = upper_bound(begin(LIS) , end(LIS) , obstacles[i]) - LIS.begin() ; 

                LIS[idx] = obstacles[i] ; 

                result.push_back(idx+1) ; 

            }
        }

        return result ; 
    }
};

int main() {
    Solution sol;

    // -------- Test Case 1 --------
    {
        vector<int> obstacles = {1,2,3,2};

        vector<int> result = sol.longestObstacleCourseAtEachPosition(obstacles);

        cout << "Test 1: ";
        for(int x : result) cout << x << " ";
        cout << endl;
    }

    // -------- Test Case 2 (duplicates) --------
    {
        vector<int> obstacles = {2,2,1};

        vector<int> result = sol.longestObstacleCourseAtEachPosition(obstacles);

        cout << "Test 2: ";
        for(int x : result) cout << x << " ";
        cout << endl;
    }

    // -------- Test Case 3 (random mix) --------
    {
        vector<int> obstacles = {3,1,5,6,4,2};

        vector<int> result = sol.longestObstacleCourseAtEachPosition(obstacles);

        cout << "Test 3: ";
        for(int x : result) cout << x << " ";
        cout << endl;
    }

    // -------- Test Case 4 (all increasing) --------
    {
        vector<int> obstacles = {1,2,3,4,5};

        vector<int> result = sol.longestObstacleCourseAtEachPosition(obstacles);

        cout << "Test 4: ";
        for(int x : result) cout << x << " ";
        cout << endl;
    }

    // -------- Test Case 5 (all same) --------
    {
        vector<int> obstacles = {5,5,5,5};

        vector<int> result = sol.longestObstacleCourseAtEachPosition(obstacles);

        cout << "Test 5: ";
        for(int x : result) cout << x << " ";
        cout << endl;
    }

    // -------- Test Case 6 (strictly decreasing) --------
    {
        vector<int> obstacles = {5,4,3,2,1};

        vector<int> result = sol.longestObstacleCourseAtEachPosition(obstacles);

        cout << "Test 6: ";
        for(int x : result) cout << x << " ";
        cout << endl;
    }

    return 0;
}

// Time Complexity : O(n*log(n))
// Space Complexity : O(n)