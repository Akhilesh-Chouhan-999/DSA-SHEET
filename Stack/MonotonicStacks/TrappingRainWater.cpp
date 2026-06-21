#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        stack<int> st;
        int result = 0;

        for(int i = 0; i < n; i ++) {

            while(!st.empty() && height[st.top()] < height[i]) {

                int bottom = height[st.top()];
                st.pop();

                if(st.empty()) {

                    break;
                }

                int left = height[st.top()];
                int right = height[i];
                int width = i - st.top() - 1;

                int currArea = (min(left, right) - bottom) * width;

                result += currArea;
            }

            st.push(i);
        }


        return result;
    }
};

int main() {
    Solution sol;

    // Test Case 1 from the page
    vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Test Case 1:" << endl;
    cout << "Input: [0,1,0,2,1,0,1,3,2,1,2,1]" << endl;
    cout << "Output: " << sol.trap(height1) << endl;
    cout << "Expected: 6" << endl << endl;

    // Test Case 2 from the page
    vector<int> height2 = {4, 2, 0, 3, 2, 5};
    cout << "Test Case 2:" << endl;
    cout << "Input: [4,2,0,3,2,5]" << endl;
    cout << "Output: " << sol.trap(height2) << endl;
    cout << "Expected: 9" << endl;

    return 0;
}