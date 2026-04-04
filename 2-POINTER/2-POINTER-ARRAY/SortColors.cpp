#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums){

        int n = nums.size() ; 

        int low = 0 ;
        int mid = 0 ; 
        int high = n - 1 ; 


        while(mid <= high){

            if(nums[mid] == 0){
                swap(nums[low] , nums[mid]) ;
                low ++ ; 
                mid ++ ; 
            }

            else if(nums[mid] == 1){
                mid += 1 ; 
            }
            else{
                swap(nums[mid] , nums[high]) ; 
                high -- ;
            }

        }


        return ; 
     
        
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

    // Test 1: Expected [0,0,1,1,2,2]
    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    sol.sortColors(nums1);
    cout << "Test 1 | Input: [2,0,2,1,1,0]\n";
    cout << "  Expected: [0,0,1,1,2,2]\n";
    cout << "  Output  : ";
    print(nums1);
    cout << "\n\n";

    // Test 2: Expected [0,1,2]
    vector<int> nums2 = {2, 0, 1};
    sol.sortColors(nums2);
    cout << "Test 2 | Input: [2,0,1]\n";
    cout << "  Expected: [0,1,2]\n";
    cout << "  Output  : ";
    print(nums2);
    cout << "\n\n";

    // Test 3: Expected [0]
    vector<int> nums3 = {0};
    sol.sortColors(nums3);
    cout << "Test 3 | Input: [0]\n";
    cout << "  Expected: [0]\n";
    cout << "  Output  : ";
    print(nums3);
    cout << "\n";

    return 0;
}

/// 00000 11111 / 0020202001010101 // 22222