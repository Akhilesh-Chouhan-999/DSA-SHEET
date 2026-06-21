#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {

        queue<pair<int, int>>que;
        unordered_set<int>st;
        que.push({x, 0});
        st.insert(x);

        while(!que.empty()) {

            int node = que.front().first;
            int level = que.front().second;
            que.pop();

            if(node == y) {
                return level;
            }

            if(node % 11 == 0) {
                
                int next = node / 11;

                if(st.find(next) == st.end()) {
                    st.insert(next);
                    que.push({next, level + 1});
                }

            }

            if(node % 5 == 0) {
                
                int next = node / 5;

                if(st.find(next) == st.end()) {
                    st.insert(next);
                    que.push({next, level + 1});
                }
            }

            if(node - 1 >= 0 && st.find(node - 1) == st.end()) {
                st.insert(node - 1);
                que.push({node - 1, level + 1});
            }

            if(node < 10001 && st.find(node + 1) == st.end()) {
                st.insert(node + 1);
                que.push({node + 1, level + 1});
            }
            
        }

        return 0;
    }
};

int main() {
    Solution sol;
    vector<pair<int, int>> testCases = {
        {26, 1},   // Expected: 3 
        {25, 30},  // Expected: 5 
        {1, 1},    // Expected: 0
        {10, 1}    // Expected: 2 
    };

    cout << "Running Test Cases:" << endl;
    for (const auto& tc : testCases) {
        int x = tc.first;
        int y = tc.second;
        int result = sol.minimumOperationsToMakeEqual(x, y);
        cout << "x = " << x << ", y = " << y << " => Result: " << result << endl;
    }

    return 0;
}

/*
    Time Complexity : O(V + E) = O(V + 4V) = O(V)
    Space Complexity : O(V)
*/