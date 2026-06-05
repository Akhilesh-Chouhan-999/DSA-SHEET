#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    const int MOD = 1e9 + 7;
    vector<vector<int>> nseAndpse(vector<int>& arr) {

        int n = arr.size();

        vector<int> nse(n, n);     
        vector<int> pse(n, -1);    

        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && arr[st.top()] >= arr[i]) {

                st.pop();
            }

            if(!st.empty()) {
                nse[i] = st.top();
            }

            st.push(i);
        }

        st = stack<int>();

        for(int i = 0; i < n; i++) {

            while(!st.empty() && arr[st.top()] > arr[i]) {

                st.pop();
            }

            if(!st.empty()) {

                pse[i] = st.top();
            }

            st.push(i);
        }

        return {nse, pse};
    }

    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();

        auto temp = nseAndpse(arr);

        vector<int> nse = temp[0];
        vector<int> pse = temp[1];

        int result = 0;

        for(int i = 0; i < n; i ++) {

            int left = nse[i];
            int right = pse[i];

            result = (result + (left * right % MOD) * arr[i]) % MOD;
        }

        return result;
        
    }
};

int main() {
    Solution sol;

    // Test Case 1 from your screenshot
    vector<int> arr1 = {3, 1, 2, 4};
    cout << "Input: [3, 1, 2, 4]" << endl;
    cout << "Output: " << sol.sumSubarrayMins(arr1) << endl;
    cout << "Expected: 17" << endl << endl;

    // Test Case 2 from your screenshot
    vector<int> arr2 = {11, 81, 94, 43, 3};
    cout << "Input: [11, 81, 94, 43, 3]" << endl;
    cout << "Output: " << sol.sumSubarrayMins(arr2) << endl;
    cout << "Expected: 444" << endl;

    return 0;
}
