#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums){

        int n = nums.size() ; 

        vector<int>result(n) ; 

        int i = 0 , j = 1 ; 

        for(int idx = 0 ; idx < n ; idx ++ ){

            if(nums[idx] > 0){
                result[i] = nums[idx] ;
                i += 2 ;  
            } else if(nums[idx] < 0){
                result[j] = nums[idx] ; 
                j += 2 ; 
            }

        }

        return result ;
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

    // Test 1: Expected [3,-2,1,-5,2,-4]
    vector<int> nums1 = {3, 1, -2, -5, 2, -4};
    auto res1 = sol.rearrangeArray(nums1);
    cout << "Test 1 | Input: [3,1,-2,-5,2,-4]\n";
    cout << "  Expected: [3,-2,1,-5,2,-4]\n";
    cout << "  Output  : ";
    print(res1);
    cout << "\n\n";

    // Test 2: Expected [-1,1]
    vector<int> nums2 = {-1, 1};
    auto res2 = sol.rearrangeArray(nums2);
    cout << "Test 2 | Input: [-1,1]\n";
    cout << "  Expected: [1,-1]\n";
    cout << "  Output  : ";
    print(res2);
    cout << "\n\n";

    return 0;
}
