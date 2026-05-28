#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:

    int numOfSubarrays(vector<int>& arr, int k, int threshold) {

        int n = arr.size();

        int i = 0;
        int j = 0;

        int result = 0;
        int sum = 0;


        while(j < n) {

            sum += arr[j];

            

            if(j - i + 1 == k) {

                int avg = sum / k;

                if(avg >= threshold) {

                    result ++;
                }

                sum -= arr[i];

                i ++;
            }

            j ++;
        }


        return result;
    }
};




// Main function to run test cases
int main() {
    Solution sol;

    // Test Case 1 from your screenshot
    vector<int> arr1 = {2, 2, 2, 2, 5, 5, 5, 8};
    int k1 = 3;
    int threshold1 = 4;
    cout << "Test Case 1:" << endl;
    cout << "Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4" << endl;
    cout << "Output: " << sol.numOfSubarrays(arr1, k1, threshold1) << endl;
    cout << "Expected: 3" << endl << endl;

    // Test Case 2 from your screenshot
    vector<int> arr2 = {11, 13, 17, 23, 29, 31, 7, 5, 2, 3};
    int k2 = 3;
    int threshold2 = 5;
    cout << "Test Case 2:" << endl;
    cout << "Input: arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5" << endl;
    cout << "Output: " << sol.numOfSubarrays(arr2, k2, threshold2) << endl;
    cout << "Expected: 6" << endl;

    return 0;
}


/*
    Time Complexity : O(n)
    Space Complexity : O(1)
*/