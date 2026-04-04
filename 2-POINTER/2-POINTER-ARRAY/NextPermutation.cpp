#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums){

        int n = nums.size() ; 

        int pivot = -1 ; 

        for(int i = n - 2 ; i >= 0 ; i --){

            if(nums[i] < nums[i+1]){
                pivot = i ; 
                break; 
            }
        } 

        if(pivot == -1){
            sort(begin(nums) , end(nums)) ; 
            return ; 
        }

        int closestElement = INT_MAX ; 
        int index = -1 ; 

        for(int j = n - 1 ; j > pivot ; j -- ){

            int curr = nums[j] ; 

            if(curr > nums[pivot] ){

                if(curr < closestElement){
                    closestElement = curr ; 
                    index = j ; 
                }

            }
        }

        swap(nums[pivot] , nums[index]) ; 

        sort(nums.begin() + pivot + 1 , nums.end())  ; 

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

    // Test 1: Expected [1,3,2]
    vector<int> nums1 = {1, 2, 3};
    sol.nextPermutation(nums1);
    cout << "Test 1 | Input: [1,2,3]\n";
    cout << "  Expected: [1,3,2]\n";
    cout << "  Output  : ";
    print(nums1);
    cout << "\n\n";

    // Test 2: Expected [1,2,3]
    vector<int> nums2 = {3, 2, 1};
    sol.nextPermutation(nums2);
    cout << "Test 2 | Input: [3,2,1]\n";
    cout << "  Expected: [1,2,3]\n";
    cout << "  Output  : ";
    print(nums2);
    cout << "\n\n";

    // Test 3: Expected [1,5,1]
    vector<int> nums3 = {1, 1, 5};
    sol.nextPermutation(nums3);
    cout << "Test 3 | Input: [1,1,5]\n";
    cout << "  Expected: [1,5,1]\n";
    cout << "  Output  : ";
    print(nums3);
    cout << "\n";

    return 0;
}
