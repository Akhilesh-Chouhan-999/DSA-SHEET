#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(n, 0);
        vector<vector<int>> result(n);

        for(vector<int>& edge : edges) {

            int u = edge[0];
            int v = edge[1]; 

            // u --> v
            adj[u].push_back(v);
            inDegree[v] ++;
        }

        queue<int> que;

        for(int i = 0; i < n; i ++) {

            if(inDegree[i] == 0) {
                que.push(i);
            }
        }

        while(!que.empty()) {

            int u = que.front();
            que.pop();

            
            for(int &v : adj[u]) {
                
                vector<int> ancestor = result[u];

                for(int x : result[v]) 
                    ancestor.push_back(x);

                ancestor.push_back(u);

                sort(begin(ancestor), end(ancestor));

                ancestor.erase(unique(ancestor.begin(), ancestor.end()), ancestor.end());

                result[v] = ancestor;

                if(--inDegree[v] == 0) {
                    que.push(v);
                }
            }

        }


        return result;

    }
};
// Helper function to print the result vector
void printResult(const vector<vector<int>>& res) {
    cout << "[";
    for (size_t i = 0; i < res.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < res[i].size(); ++j) {
            cout << res[i] [j];
            if (j < res[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < res.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Test Case 1 from the screenshot
    int n1 = 8;
    vector<vector<int>> edges1 = {
        {0,3}, {0,4}, {1,3}, {2,4}, {2,7}, 
        {3,5}, {3,6}, {3,7}, {4,6}
    };

    cout << "Test Case 1:" << endl;
    cout << "Input: n = " << n1 << ", edges = ..." << endl;
    vector<vector<int>> result1 = sol.getAncestors(n1, edges1);
    printResult(result1);
    // Expected: [[],[],[],[0,1],[0,2],[0,1,3],[0,1,2,3,4],[0,1,2,3]]
    cout << endl;

    // Test Case 2 from the screenshot
    int n2 = 5;
    vector<vector<int>> edges2 = {
        {0,1}, {0,2}, {0,3}, {0,4}, 
        {1,2}, {1,3}, {1,4}, {2,3}, {2,4}, {3,4}
    };

    cout << "Test Case 2:" << endl;
    cout << "Input: n = " << n2 << ", edges = ..." << endl;
    vector<vector<int>> result2 = sol.getAncestors(n2, edges2);
    printResult(result2);
    // Expected: [[],,[0,1],[0,1,2],[0,1,2,3]]

    return 0;
}
