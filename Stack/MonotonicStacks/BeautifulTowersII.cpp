#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<long long>> nseAndpse(vector<int>& arr) {

        long long n = arr.size();

        vector<long long> nse(n, n);     
        vector<long long> pse(n, -1);    

        stack<long long> st;

        for(long long i = n - 1; i >= 0; i--) {

            while(!st.empty() && arr[st.top()] >= arr[i]) {

                st.pop();
            }

            if(!st.empty()) {
                nse[i] = st.top();
            }

            st.push(i);
        }

        st = stack<long long>();

        for(long long i = 0; i < n; i++) {

            while(!st.empty() && arr[st.top()] > arr[i]) {

                st.pop();
            }

            if(!st.empty()) {

                pse[i] = st.top();
            }

            st.push(i);
        }

        return {nse, pse};
    };


    long long maximumSumOfHeights(vector<int>& maxHeights) {
        
        int n = maxHeights.size();

        auto temp = nseAndpse(maxHeights);

        vector<long long> nse = temp[0];
        vector<long long> pse = temp[1];


        vector<long long> left(n);
        vector<long long> right(n);

        for(int i = 0; i < n; i ++) {

            if(pse[i] == -1) {

                left[i] = 1LL * (i + 1) * maxHeights[i];
            }

            else{

                left[i] = left[pse[i]] + 1LL *(i - pse[i]) * maxHeights[i];
            }
        }

        for(int i = n - 1; i >= 0; i --) {

            if(nse[i] == -1) {

                right[i] = 1LL * (n - i) * maxHeights[i];
            }

            else {

                right[i] = right[nse[i]] + 1LL * (nse[i] - i) * maxHeights[i];
            }
        }

        long long result = 0;

        for(int i = 0; i < n; i ++) {

            result = max(result, left[i] + right[i] - maxHeights[i]);
        }

        return result;
    }
};


int main() {
    Solution sol;

    // Test Case 1 from your screenshot
    vector<int> maxHeights1 = {5, 3, 4, 1, 1};
    cout << "Test Case 1: [5, 3, 4, 1, 1]" << endl;
    cout << "Result: " << sol.maximumSumOfHeights(maxHeights1) << endl;
    cout << "Expected: 13 (5+3+4+1+1 = 14? No, logic is mountain shape. Max sum is 13)" << endl;
    cout << "------------------------" << endl;

    // Test Case 2: Simple increasing
    vector<int> maxHeights2 = {1, 2, 3, 4, 5};
    cout << "Test Case 2: [1, 2, 3, 4, 5]" << endl;
    cout << "Result: " << sol.maximumSumOfHeights(maxHeights2) << endl;
    cout << "------------------------" << endl;

    // Test Case 3: All same
    vector<int> maxHeights3 = {2, 2, 2, 2};
    cout << "Test Case 3: [2, 2, 2, 2]" << endl;
    cout << "Result: " << sol.maximumSumOfHeights(maxHeights3) << endl;
    cout << "------------------------" << endl;

    return 0;
}