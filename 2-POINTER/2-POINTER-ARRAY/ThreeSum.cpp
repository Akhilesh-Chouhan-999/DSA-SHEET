#include <bits/stdc++.h>
using namespace std;

class Solution{

public:
    vector<vector<int>> threeSum(vector<int> &nums){

        int n = nums.size() ; 

        sort(begin(nums) , end(nums)) ; 

        vector<vector<int>> result ; 

        for(int idx =  0 ; idx < n ; idx ++ ){

            if( idx > 0  && nums[idx] == nums[idx-1])
            continue; 


            int i = idx + 1 ; 
            int j = n - 1 ; 

            while(i < j){

                int sum = nums[i] + nums[j] + nums[idx] ; 

                if(sum == 0){
                    result.push_back({nums[idx]  , nums[i] , nums[j]}) ; 
                    i ++ ; 
                    j -- ; 

                    while( i < j && nums[i] == nums[i-1]) i ++ ;
                    while( i < j && nums[j] == nums[j+1]) j -- ; 
                } else if(sum > 0){
                    j -- ; 
                }else{
                    i ++ ; 
                }


            }
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
            cout << "[";
            for (int j = 0; j < (int)v[i].size(); j++)
            {
                cout << v[i][j];
                if (j + 1 < (int)v[i].size())
                    cout << ",";
            }
            cout << "]";
            if (i + 1 < (int)v.size())
                cout << ",";
        }
        cout << "]";
    };

    // Test 1: Expected [[-1,-1,2],[-1,0,1]]
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    auto res1 = sol.threeSum(nums1);
    cout << "Test 1 | Input: [-1,0,1,2,-1,-4]\n";
    cout << "  Expected: [[-1,-1,2],[-1,0,1]]\n";
    cout << "  Output  : ";
    print(res1);
    cout << "\n\n";

    // Test 2: Expected []
    vector<int> nums2 = {0, 1, 1};
    auto res2 = sol.threeSum(nums2);
    cout << "Test 2 | Input: [0,1,1]\n";
    cout << "  Expected: []\n";
    cout << "  Output  : ";
    print(res2);
    cout << "\n\n";

    // Test 3: Expected [[0,0,0]]
    vector<int> nums3 = {0, 0, 0};
    auto res3 = sol.threeSum(nums3);
    cout << "Test 3 | Input: [0,0,0]\n";
    cout << "  Expected: [[0,0,0]]\n";
    cout << "  Output  : ";
    print(res3);
    cout << "\n";

    return 0;
}
