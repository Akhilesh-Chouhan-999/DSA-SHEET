#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    const int INF = 1e9;

    int n;
    int maxDist;
    vector<vector<int>> graph;
    int ans;

    bool isValid(vector<int>& subset) {

        vector<vector<int>> dist(n, vector<int>(n, INF));

        for(int i = 0; i < n; i++) {

            dist[i][i] = 0;
        }

        unordered_set<int> st(subset.begin(), subset.end());

        for(auto &road : graph) {

            int u = road[0];
            int v = road[1];
            int w = road[2];

            if(st.count(u) && st.count(v)) {

                dist[u][v] = min(dist[u][v], w);
                dist[v][u] = min(dist[v][u], w);
            }
        }

        for(int via = 0; via < n; via++) {

            for(int i = 0; i < n; i++) {

                for(int j = 0; j < n; j++) {

                    if(dist[i][via] == INF ||
                       dist[via][j] == INF)
                        continue;

                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }

        for(int u : subset) {

            for(int v : subset) {

                if(dist[u][v] > maxDist) {
                    return false;
                }
            }
        }

        return true;
    }

    void generateSubsets(int idx,vector<int>& curr) {

        if(idx == n) {

            if(isValid(curr)) {
                ans++;
            }

            return;
        }

   
        curr.push_back(idx);
        generateSubsets(idx + 1, curr);

        curr.pop_back();
        generateSubsets(idx + 1, curr);
    }

    int numberOfSets(int N, int maxDistance, vector<vector<int>>& r) {

        ans = 0;
        n = N;
        maxDist = maxDistance;
        graph = r;

        vector<int> curr;

        generateSubsets(0, curr);

        return ans;
    }
};


// Main function to run test cases
int main() {
    Solution sol;

    // Test Case 1
    int n1 = 3;
    int maxDist1 = 5;
    vector<vector<int>> roads1 = {{0,1,2},{1,2,10},{0,2,10}};
    cout << "Test 1 Output: " << sol.numberOfSets(n1, maxDist1, roads1) << " (Expected: 5)" << endl;

    // Test Case 2
    int n2 = 3;
    int maxDist2 = 5;
    vector<vector<int>> roads2 = {{0,1,20},{0,1,10},{1,2,2},{0,2,2}};
    cout << "Test 2 Output: " << sol.numberOfSets(n2, maxDist2, roads2) << " (Expected: 7)" << endl;

    // Test Case 3
    int n3 = 1;
    int maxDist3 = 10;
    vector<vector<int>> roads3 = {};
    cout << "Test 3 Output: " << sol.numberOfSets(n3, maxDist3, roads3) << " (Expected: 2)" << endl;

    return 0;
}

/*
    Time Complexity : O(2 ^ n)
    Space Complexity : O(n * n)
*/