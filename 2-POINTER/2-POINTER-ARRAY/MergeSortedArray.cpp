#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n){

        int i = m - 1 ; 
        int j = n - 1 ; 
        int k = m + n - 1 ;


        while( i >= 0 && j >= 0 ) {

            if(nums1[i] <= nums2[j]){
                nums1[k] = nums2[j] ;
                k -- ; 
                j -- ; 
            }else{
                nums1[k] = nums1[i] ;
                k -- ; 
                i -- ; 
            }
        }

        for(int idx = i ; idx >= 0 ; idx -- ){
            nums1[k--] = nums1[idx] ; 
        }

        for(int idx = j ; idx >= 0 ; idx --){
            nums1[k--] = nums2[idx] ; 
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

    // Test 1: Expected [1,2,2,3,5,6]
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    sol.merge(nums1, 3, nums2, 3);
    cout << "Test 1 | nums1=[1,2,3,0,0,0], m=3, nums2=[2,5,6], n=3\n";
    cout << "  Expected: [1,2,2,3,5,6]\n";
    cout << "  Output  : ";
    print(nums1);
    cout << "\n\n";

    // Test 2: Expected [1]
    vector<int> nums3 = {1};
    vector<int> nums4 = {};
    sol.merge(nums3, 1, nums4, 0);
    cout << "Test 2 | nums1=[1], m=1, nums2=[], n=0\n";
    cout << "  Expected: [1]\n";
    cout << "  Output  : ";
    print(nums3);
    cout << "\n\n";

    // Test 3: Expected [1]
    vector<int> nums5 = {0};
    vector<int> nums6 = {1};
    sol.merge(nums5, 0, nums6, 1);
    cout << "Test 3 | nums1=[0], m=0, nums2=[1], n=1\n";
    cout << "  Expected: [1]\n";
    cout << "  Output  : ";
    print(nums5);
    cout << "\n";

    return 0;
}

// Time Complexity : O(m+n)
// Space Complexity : O(1)