#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int> &nums, int target){

        int n = nums.size() ; 

        unordered_map<int , int>mpp ; 

        for(int i = 0 ; i < n ; i ++ ){
            mpp[nums[i]] = i ; 
        }


        for(int i = 0 ; i < n ; i ++ ){

            if(mpp.find(target - nums[i]) != mpp.end() && i != mpp[target - nums[i]])
            return { i , mpp[target-nums[i]]}  ; 
            
        }

        return { -1 , -1} ; 
       
    }
};

int main()
{
    Solution sol;

    auto print = [](const vector<int> &v)
    {
        cout << "[";
        for (int i = 0; i < (int)v.size(); i++)
        {
            cout << v[i];
            if (i + 1 < (int)v.size())
                cout << ",";
        }
        cout << "]";
    };

    // Test 1: Expected [0,1]
    vector<int> nums1 = {2, 7, 11, 15};
    auto res1 = sol.twoSum(nums1, 9);
    cout << "Test 1 | Input: [2,7,11,15], target=9\n";
    cout << "  Expected: [0,1]\n";
    cout << "  Output  : ";
    print(res1);
    cout << "\n\n";

    // Test 2: Expected [1,2]
    vector<int> nums2 = {3, 2, 4};
    auto res2 = sol.twoSum(nums2, 6);
    cout << "Test 2 | Input: [3,2,4], target=6\n";
    cout << "  Expected: [1,2]\n";
    cout << "  Output  : ";
    print(res2);
    cout << "\n\n";

    // Test 3: Expected [0,1]
    vector<int> nums3 = {3, 3};
    auto res3 = sol.twoSum(nums3, 6);
    cout << "Test 3 | Input: [3,3], target=6\n";
    cout << "  Expected: [0,1]\n";
    cout << "  Output  : ";
    print(res3);
    cout << "\n";

    return 0;
}
