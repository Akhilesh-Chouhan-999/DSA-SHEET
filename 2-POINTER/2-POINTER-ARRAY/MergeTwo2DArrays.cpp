#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2){
        
        int n1 = nums1.size() ;
        int n2 = nums2.size() ;

        int i = 0 ; 
        int j = 0 ; 

        vector<vector<int>>result ; 

        while( i < n1 && j < n2 ){

            int id1 = nums1[i][0] ;
            int val1 = nums1[i][1] ; 

            int id2 = nums2[j][0] ;
            int val2 = nums2[j][1] ;

            if(id1 == id2){
                result.push_back({id1 , val1 + val2});
                i++;
                j++;
            }else if(id1 < id2){
                result.push_back({id1 , val1});
                i++;
            }else{
                result.push_back({id2, val2}) ; 
                j++ ; 
            }
        }
        
       for( ; i < n1 ; i ++){
        result.push_back({nums1[i][0] , nums1[i][1]}) ;
       }

       for( ; j < n2 ; j ++){
        result.push_back({nums2[j][0] , nums2[j][1]}) ;
       }
        
        return result ; 
    }
};

int main()
{
    Solution sol;

    auto print = [](const vector<vector<int>> &v)
    {
        cout << "[";
        for (int i = 0; i < (int)v.size(); i++)
        {
            cout << "[" << v[i][0] << "," << v[i][1] << "]";
            if (i + 1 < (int)v.size())
                cout << ",";
        }
        cout << "]";
    };

    // Test 1: Expected [[1,6],[2,4],[3,5],[4,6]]
    vector<vector<int>> n1 = {{1, 2}, {2, 3}, {4, 5}};
    vector<vector<int>> n2 = {{1, 4}, {3, 2}, {4, 1}};
    auto res1 = sol.mergeArrays(n1, n2);
    cout << "Test 1 | nums1=[[1,2],[2,3],[4,5]], nums2=[[1,4],[3,2],[4,1]]\n";
    cout << "  Expected: [[1,6],[2,3],[3,2],[4,6]]\n";
    cout << "  Output  : ";
    print(res1);
    cout << "\n\n";

    // Test 2: Expected [[1,3],[2,4],[3,6],[4,3],[5,5]]
    vector<vector<int>> n3 = {{2, 4}, {3, 6}, {5, 5}};
    vector<vector<int>> n4 = {{1, 3}, {4, 3}};
    auto res2 = sol.mergeArrays(n3, n4);
    cout << "Test 2 | nums1=[[2,4],[3,6],[5,5]], nums2=[[1,3],[4,3]]\n";
    cout << "  Expected: [[1,3],[2,4],[3,6],[4,3],[5,5]]\n";
    cout << "  Output  : ";
    print(res2);
    cout << "\n";

    return 0;
}


// Time Complexity : O(n1 + n2)
// Space Complexity : O(1) 
