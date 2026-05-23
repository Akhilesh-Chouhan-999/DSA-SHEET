#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    const int INF = INT_MAX;

    void floydWarshall(vector<vector<int>>& graph, int n) {

        for(int via = 0; via < n; via++) {

            for(int i = 0; i < n; i++) {

                for(int j = 0; j < n; j++) {

                    if(graph[i][via] != INF && graph[via][j] != INF) {

                        graph[i][j] = min(graph[i][j], graph[i][via] + graph[via][j]);
                    }
                }
            }
        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>> graph(n, vector<int>(n, INF));

        for(vector<int>& edge : edges) {

            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            graph[u][v] = min(graph[u][v], wt);
            graph[v][u] = min(graph[v][u], wt);
        }

        for(int i = 0; i < n; i++) {

            graph[i][i] = 0;
        }

        floydWarshall(graph, n);

        int smallestReachableCityFromNode = INT_MAX;
        int result = -1;

        for(int i = 0; i < n; i++) {

            int cntReachableCityFromNode = 0;

            for(int j = 0; j < n; j++) {

                if(i == j) {
                    continue;
                }

                int dist = graph[i][j];

                if(dist <= distanceThreshold) {

                    cntReachableCityFromNode++;
                }
            }

            if(cntReachableCityFromNode <= smallestReachableCityFromNode) {

                smallestReachableCityFromNode = cntReachableCityFromNode;
                result = i;
            }
        }

        return result;
    }
};



// --- Test Runner ---
void run_test(int n, vector<vector<int>> edges, int threshold, int expected) {
    Solution sol;
    int result = sol.findTheCity(n, edges, threshold);
    
    if (result == expected) {
        cout << "PASS: Result = " << result << endl;
    } else {
        cout << "FAIL: Expected " << expected << " but got " << result << endl;
    }
}

int main() {
    cout << "Running Test Suite..." << endl;
    cout << "---------------------" << endl;

    // Test Case 1: Standard Example (LeetCode 1334 Example 1)
    // Graph: 0-1 (3), 0-2 (1), 1-2 (2), 2-3 (1). Threshold = 4.
    // Distances from 0: 1(3), 2(1), 3(2) -> 3 cities
    // Distances from 1: 0(3), 2(2), 3(3) -> 3 cities
    // Distances from 2: 0(1), 1(2), 3(1) -> 3 cities
    // Distances from 3: 0(2), 1(3), 2(1) -> 3 cities
    // Ties: All have 3. Largest index is 3.
    run_test(4, {{0,1,3}, {0,2,1}, {1,2,2}, {2,3,1}}, 4, 3);


    // Test Case 3: Disconnected Components
    // 0-1 (1), 2-3 (1). No path between 1 and 2. Threshold = 5.
    // 0 reaches 1 (1). Count=1.
    // 1 reaches 0 (1). Count=1.
    // 2 reaches 3 (1). Count=1.
    // 3 reaches 2 (1). Count=1.
    // Tie: All have 1. Result should be 3.
    run_test(4, {{0,1,1}, {2,3,1}}, 5, 3);

    // Test Case 4: Single City
    // Only node 0. Threshold = 10.
    // 0 reaches 0 (but we skip i==j). Count=0.
    // Result should be 0.
    run_test(1, {}, 10, 0);

    // Test Case 5: Linear Chain
    // 0-1 (1), 1-2 (1), 2-3 (1), 3-4 (1). Threshold = 1.
    // 0 reaches: 1 (1). Count=1.
    // 1 reaches: 0, 2. Count=2.
    // 2 reaches: 1, 3. Count=2.
    // 3 reaches: 2, 4. Count=2.
    // 4 reaches: 3. Count=1.
    // Tie between 0 and 4 (both 1). Largest index is 4.
    run_test(5, {{0,1,1}, {1,2,1}, {2,3,1}, {3,4,1}}, 1, 4);

    // Test Case 6: Large Threshold (All connected)
    // Same linear chain, Threshold = 10.
    // Everyone can reach everyone else.
    // 0 reaches 4 cities.
    // 1 reaches 4 cities.
    // ...
    // 4 reaches 4 cities.
    // Tie: All have 4. Largest index is 4.
    run_test(5, {{0,1,1}, {1,2,1}, {2,3,1}, {3,4,1}}, 10, 4);

    cout << "---------------------" << endl;
    cout << "Test suite finished." << endl;

    return 0;
}