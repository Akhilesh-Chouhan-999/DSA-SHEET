#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        int n = asteroids.size();

        stack<int> st;

        for(int i = 0; i < n; i ++) {

            int curr = asteroids[i];

            if(curr > 0) {

                st.push(curr);
            }

            else {

                bool alive = true;

                while(!st.empty() && st.top() > 0) {

                    int top = st.top();

                    if(top == abs(curr)) {

                        st.pop();
                        alive = false;
                        break;
                    }

                    else if(top > abs(curr)) {

                        alive = false;
                        break;
                    }

                    else {

                        st.pop();
                    }
                }

                if(alive) {

                    st.push(curr);
                }

            }
        }

        vector<int> result;

        while(!st.empty()) {
            
            result.push_back(st.top());
            st.pop();
        }


        reverse(begin(result), end(result));

        return result;
        
    }
};



int main() {
    Solution sol;

    // Test Case 1: [5,10,-5] -> Expected: [5,10]
    vector<int> input1 = {5, 10, -5};
    vector<int> output1 = sol.asteroidCollision(input1);
    cout << "Input: [5, 10, -5]" << endl;
    cout << "Output: [";
    for (size_t i = 0; i < output1.size(); ++i) {
        cout << output1[i] << (i == output1.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl << endl;

    // Test Case 2: [8,-8] -> Expected: []
    vector<int> input2 = {8, -8};
    vector<int> output2 = sol.asteroidCollision(input2);
    cout << "Input: [8, -8]" << endl;
    cout << "Output: [";
    for (size_t i = 0; i < output2.size(); ++i) {
        cout << output2[i] << (i == output2.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl << endl;

    // Test Case 3: [10,2,-5] -> Expected: 
    vector<int> input3 = {10, 2, -5};
    vector<int> output3 = sol.asteroidCollision(input3);
    cout << "Input: [10, 2, -5]" << endl;
    cout << "Output: [";
    for (size_t i = 0; i < output3.size(); ++i) {
        cout << output3[i] << (i == output3.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl << endl;

    // Test Case 4: [3,5,-6,2,-1,4] -> Expected: [-6,2,4]
    vector<int> input4 = {3, 5, -6, 2, -1, 4};
    vector<int> output4 = sol.asteroidCollision(input4);
    cout << "Input: [3, 5, -6, 2, -1, 4]" << endl;
    cout << "Output: [";
    for (size_t i = 0; i < output4.size(); ++i) {
        cout << output4[i] << (i == output4.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;

    return 0;
}