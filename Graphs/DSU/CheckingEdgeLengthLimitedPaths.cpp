#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int find(int x, vector<int>& parent) {

        if(x == parent[x]) {

            return x;
        }

        return parent[x] = find(parent[x], parent);
    }

    void Union(int x, int y, vector<int>& parent, vector<int>& rank) {


        int x_parent = find(x, parent);
        int y_parent = find(y, parent);

        if(x_parent == y_parent) {

            return;
        }

        if(rank[x_parent] < rank[y_parent]) {

            parent[x_parent] = y_parent;
        }

        else if(rank[y_parent] < rank[x_parent]) {

            parent[y_parent] = x_parent;
        }

        else{

            parent[y_parent] = x_parent;
            rank[y_parent] ++;
        }
    }
    
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {

        vector<int> rank(n, 0);
        vector<int> parent(n);

        for(int i = 0; i < n ; i ++) {

            parent[i] = i;
        }
        
        
        
        for(int i = 0; i < queries.size(); i ++) {
            
            queries[i].push_back(i);
        }
        
        auto lambda = [&](const vector<int>& a, const vector<int>& b) {

            return a[2] < b[2];
        };

        sort(begin(edgeList), end(edgeList), lambda);
        sort(begin(queries), end(queries), lambda);

        vector<bool> result(queries.size(), false);
        int j = 0;

        for(vector<int>& query : queries) {

            int u = query[0];
            int v = query[1];
            int th = query[2];
            int idx = query[3];


            while(j < edgeList.size() && edgeList[j][2] < th) {

                Union(edgeList[j][0], edgeList[j][1], parent, rank);
                j ++;
            }

            if(find(u, parent) == find(v, parent)) {

                result[idx] = true;
            }
        }

        return result;

    }
};


// Helper function to print vectors
void printVector(const vector<bool>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << (vec[i] ? "true" : "false");
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Test Case 1
    cout << "Test Case 1:" << endl;
    int n1 = 3;
    vector<vector<int>> edgeList1 = {{0,1,2},{1,2,4},{2,0,8},{1,0,16}};
    vector<vector<int>> queries1 = {{0,1,2},{0,2,5}};
    
    cout << "Input: n = " << n1 << ", edgeList = ..., queries = ..." << endl;
    vector<bool> result1 = sol.distanceLimitedPathsExist(n1, edgeList1, queries1);
    cout << "Output: ";
    printVector(result1);
    cout << "Expected: [false, true]" << endl << endl;

    // Test Case 2
    cout << "Test Case 2:" << endl;
    int n2 = 5;
    vector<vector<int>> edgeList2 = {{0,1,10},{1,2,5},{2,3,9},{3,4,13}};
    vector<vector<int>> queries2 = {{0,4,14},{1,4,13}};

    cout << "Input: n = " << n2 << ", edgeList = ..., queries = ..." << endl;
    vector<bool> result2 = sol.distanceLimitedPathsExist(n2, edgeList2, queries2);
    cout << "Output: ";
    printVector(result2);
    cout << "Expected: [true, false]" << endl;

    return 0;
}



/*
    Time Complexity : O(E log E + Q log Q + (E + Q) * α(N))
    Space Complexity : O(N + Q)
*/