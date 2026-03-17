#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot){

        int n = nums.size() ; 

        int lessThanPivot = 0 ; 
        int equalToPivot = 0 ;

        for(int num : nums){
            if(num == pivot){
                equalToPivot ++ ; 
            } else if(num < pivot){
                lessThanPivot ++ ; 
            }
        }


        int i = 0 ; 
        int j = lessThanPivot ; 
        int k = lessThanPivot + equalToPivot ; 

        vector<int>result(n) ; 

        for(int num : nums){

            if(num == pivot){
                result[j] = num ; 
                j ++ ;  
            } else if(num < pivot){
                result[i] = num ; 
                i ++ ; 
            } else{
                result[k] = num ; 
                k ++ ; 
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

    // Test 1: Expected [9,12,10,3,1,3,2,4,5] (less:9,5,3? wait let me redo)
    // nums=[9,12,2,10,3,1,3,5,4], pivot=3 => less:[2,1], equal:[3,3], greater:[9,12,10,5,4]
    vector<int> nums1 = {9, 12, 2, 10, 3, 1, 3, 5, 4};
    auto res1 = sol.pivotArray(nums1, 3);
    cout << "Test 1 | Input: [9,12,2,10,3,1,3,5,4], pivot=3\n";
    cout << "  Expected: [2,1,3,3,9,12,10,5,4]\n";
    cout << "  Output  : ";
    print(res1);
    cout << "\n\n";

    // Test 2: Expected [-3,2,4,3,3,5]
    vector<int> nums2 = {-3, 2, 4, 3, 5, 3};
    auto res2 = sol.pivotArray(nums2, 3);
    cout << "Test 2 | Input: [-3,2,4,3,5,3], pivot=3\n";
    cout << "  Expected: [-3,2,3,3,4,5]\n";
    cout << "  Output  : ";
    print(res2);
    cout << "\n\n";

    // Test 3: Expected [1,3]
    vector<int> nums3 = {3, 1};
    auto res3 = sol.pivotArray(nums3, 2);
    cout << "Test 3 | Input: [3,1], pivot=2\n";
    cout << "  Expected: [1,3]\n";
    cout << "  Output  : ";
    print(res3);
    cout << "\n";

    return 0;
}
