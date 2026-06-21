#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> nseAndpse(vector<int>& heights) {

        int n = heights.size();

        vector<int> nse(n, n);
        stack<int> st;

        st.push(n - 1);

        for(int i = n - 2; i >= 0; i --) {

            int curr = heights[i];

            while(!st.empty() && curr <= heights[st.top()]) {

                st.pop();
            }

            if(!st.empty()) {

                nse[i] = st.top();
            }

            st.push(i);
        }

        vector<int> pse(n, -1);
        st = stack<int>();

        st.push(0);

        for(int i = 1; i < n; i ++) {

            int curr = heights[i];

            while(!st.empty() && curr <= heights[st.top()]) {

                st.pop();
            }

            if(!st.empty()) {

                pse[i] = st.top();
            }

            st.push(i);
        }

        return {nse, pse};
    }


    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();

        auto temp = nseAndpse(heights);
        vector<int> nse = temp[0];
        vector<int> pse = temp[1];

        int maxRect = INT_MIN;

        for(int i = 0; i < n; i ++) {
            
            int width = nse[i] - pse[i] - 1;
            int currRect = heights[i] * width;

            maxRect = max(maxRect, currRect);
        }

        return maxRect;
    }
};


int main() {
    Solution sol;

    // Test Case 1: The example from the page
    vector<int> heights1 = {2, 1, 5, 6, 2, 3};
    cout << "Test Case 1: " << endl;
    cout << "Input: [2, 1, 5, 6, 2, 3]" << endl;
    cout << "Output: " << sol.largestRectangleArea(heights1) << endl;
    cout << "Expected: 10" << endl << endl;

    // Test Case 2: The second example from the page
    vector<int> heights2 = {2, 4};
    cout << "Test Case 2: " << endl;
    cout << "Input: [2, 4]" << endl;
    cout << "Output: " << sol.largestRectangleArea(heights2) << endl;
    cout << "Expected: 4" << endl << endl;

    // Test Case 3: Single bar
    vector<int> heights3 = {5};
    cout << "Test Case 3: " << endl;
    cout << "Input: " << endl;
    cout << "Output: " << sol.largestRectangleArea(heights3) << endl;
    cout << "Expected: 5" << endl << endl;

    // Test Case 4: All increasing heights
    vector<int> heights4 = {1, 2, 3, 4, 5};
    cout << "Test Case 4: " << endl;
    cout << "Input: [1, 2, 3, 4, 5]" << endl;
    cout << "Output: " << sol.largestRectangleArea(heights4) << endl;
    cout << "Expected: 9" << endl << "(3 * 3 = 9, bars 3,4,5 with height 3)" << endl << endl;

    // Test Case 5: All decreasing heights
    vector<int> heights5 = {5, 4, 3, 2, 1};
    cout << "Test Case 5: " << endl;
    cout << "Input: [5, 4, 3, 2, 1]" << endl;
    cout << "Output: " << sol.largestRectangleArea(heights5) << endl;
    cout << "Expected: 9" << endl << "(3 * 3 = 9, bars 3,4,5 with height 3)" << endl << endl;

    // Test Case 6: All same heights
    vector<int> heights6 = {2, 2, 2, 2};
    cout << "Test Case 6: " << endl;
    cout << "Input: [2, 2, 2, 2]" << endl;
    cout << "Output: " << sol.largestRectangleArea(heights6) << endl;
    cout << "Expected: 8" << endl << endl;

    // Test Case 7: Large gap with small bar in middle
    vector<int> heights7 = {1, 1, 1, 1, 1};
    cout << "Test Case 7: " << endl;
    cout << "Input: [1, 1, 1, 1, 1]" << endl;
    cout << "Output: " << sol.largestRectangleArea(heights7) << endl;
    cout << "Expected: 5" << endl << endl;

    return 0;
}