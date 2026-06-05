#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();

        vector<int> result(n, 0);
        stack<int> st;

        for(int i = n - 1; i >= 0; i --) {

            int currTemp = temperatures[i];

            while(!st.empty() && currTemp >= temperatures[st.top()]) {

                st.pop();
            }

            if(!st.empty()) {

                result[i] = st.top() - i;
            }

            st.push(i);
        }

        return result;
    }
};


// Helper function to print vectors
void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}



int main() {
    Solution sol;

    // Test Case 1 from the page
    vector<int> temperatures1 = {73, 74, 75, 71, 69, 72, 76, 73};
    cout << "Input: ";
    printVector(temperatures1);
    vector<int> output1 = sol.dailyTemperatures(temperatures1);
    cout << "Output: ";
    printVector(output1);
    cout << "Expected: [1,1,4,2,1,1,0,0]" << endl << endl;

    // Test Case 2 from the page
    vector<int> temperatures2 = {30, 40, 50, 60};
    cout << "Input: ";
    printVector(temperatures2);
    vector<int> output2 = sol.dailyTemperatures(temperatures2);
    cout << "Output: ";
    printVector(output2);
    cout << "Expected: [1,1,1,0]" << endl << endl;

    // Test Case 3 from the page
    vector<int> temperatures3 = {30, 60, 90};
    cout << "Input: ";
    printVector(temperatures3);
    vector<int> output3 = sol.dailyTemperatures(temperatures3);
    cout << "Output: ";
    printVector(output3);
    cout << "Expected: [1,1,0]" << endl;

    return 0;
}
