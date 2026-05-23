#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    using ll = long long;
    const ll INF = 1e18;

    void floydWarshall(vector<vector<ll>>& graph) {

        for(int via = 0; via < 26; via++) {

            for(int i = 0; i < 26; i++) {

                for(int j = 0; j < 26; j++) {

                    if(graph[i][via] != INF && graph[via][j] != INF) {

                        graph[i][j] = min(graph[i][j], graph[i][via] + graph[via][j]);
                    }
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {

        vector<vector<ll>> graph(26, vector<ll>(26, INF));

        for(int i = 0; i < 26; i++) {

            graph[i][i] = 0;
        }

        int m = original.size();

        for(int i = 0; i < m; i++) {

            int u = original[i] - 'a';
            int v = changed[i] - 'a';

            graph[u][v] = min(graph[u][v], (ll)cost[i]);
        }

        floydWarshall(graph);

        ll minCost = 0;

        for(int i = 0; i < source.length(); i++) {

            int u = source[i] - 'a';
            int v = target[i] - 'a';

            if(graph[u][v] == INF) {

                return -1;
            }

            minCost += graph[u][v];
        }

        return minCost;
    }
};


// Helper function to print vectors
void printVector(const vector<char>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << "\"" << vec[i] << "\"";
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]";
}

int main() {
    Solution sol;

    // Test Case 1
    // Expected: 28
    {
        string source = "abcd";
        string target = "acbe";
        vector<char> original = {'a', 'b', 'c', 'c', 'e', 'd'};
        vector<char> changed  = {'b', 'c', 'b', 'e', 'b', 'e'};
        vector<int> cost      = {2, 5, 5, 1, 2, 20};

        cout << "Test Case 1:" << endl;
        cout << "Source: " << source << ", Target: " << target << endl;
        cout << "Original: "; printVector(original); cout << endl;
        cout << "Changed:  "; printVector(changed); cout << endl;
        cout << "Cost:     ["; 
        for(size_t i=0; i<cost.size(); ++i) cout << cost[i] << (i==cost.size()-1 ? "" : ", ");
        cout << "]" << endl;

        long long result = sol.minimumCost(source, target, original, changed, cost);
        cout << "Output: " << result << " (Expected: 28)" << endl << endl;
    }

    // Test Case 2
    // Expected: -1
    {
        string source = "abcd";
        string target = "abce";
        vector<char> original = {'a'};
        vector<char> changed  = {'e'};
        vector<int> cost      = {10000};

        cout << "Test Case 2:" << endl;
        cout << "Source: " << source << ", Target: " << target << endl;
        cout << "Original: "; printVector(original); cout << endl;
        cout << "Changed:  "; printVector(changed); cout << endl;
        cout << "Cost:     ["; 
        for(size_t i=0; i<cost.size(); ++i) cout << cost[i] << (i==cost.size()-1 ? "" : ", ");
        cout << "]" << endl;

        long long result = sol.minimumCost(source, target, original, changed, cost);
        cout << "Output: " << result << " (Expected: -1)" << endl << endl;
    }

    return 0;
}

/*
    Time Complexity : O(n)
    Space Complexity : O(1)
*/