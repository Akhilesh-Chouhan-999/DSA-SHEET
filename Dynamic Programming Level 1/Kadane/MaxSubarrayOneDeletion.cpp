#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        
        int n = arr.size();

        vector<int>left(n, 0), right(n, 0);

        left[0] = arr[0];
        for(int i = 1; i < n; i ++) {
            left[i] = max(arr[i], left[i-1] + arr[i]);
        }

        right[n-1] = arr[n-1];
        for(int i = n - 2; i >= 0; i --) {
            right[i] = max(arr[i], right[i+1] + arr[i]);
        }


        int result = left[0];

        for(int i = 1; i < n; i ++) {
            result= max(result, left[i]);
        }

        for(int i = 1;  i < n - 1; i ++) {
            result = max(result, left[i - 1] + right[i + 1]);
        }

        return result;

    }
};



int main() {
    Solution sol;

    // Test case 1: Expected output = 4 (drop -2 from [1,-2,0,3])
    vector<int> arr1 = {1, -2, 0, 3};
    cout << "Test 1: " << sol.maximumSum(arr1) << " (expected 4)" << endl;

    // Test case 2: Expected output = 3 (just pick )
    vector<int> arr2 = {1, -2, -2, 3};
    cout << "Test 2: " << sol.maximumSum(arr2) << " (expected 3)" << endl;

    // Test case 3: Expected output = -1 (all negatives, must keep at least one)
    vector<int> arr3 = {-1, -1, -1, -1};
    cout << "Test 3: " << sol.maximumSum(arr3) << " (expected -1)" << endl;

    return 0;
}