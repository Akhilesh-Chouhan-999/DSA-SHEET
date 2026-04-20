/*
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int memo[301][301];
    int solve(vector<int>& values, int i, int j) {

        if(j - i <= 1)
        return 0;

        if(memo[i][j] != -1)
        return memo[i][j];

        int minScore = INT_MAX;

        for(int k = i + 1; k <= j - 1; k ++) {

            int score = values[i] * values[k] * values[j]
                                  + solve(values, i, k)
                                  + solve(values, k, j);

            minScore = min(minScore, score);
        }

        return memo[i][j] = minScore;
    }
    int minScoreTriangulation(vector<int>& values) {
        
        int n = values.size();

        memset(memo, -1, sizeof(memo));
        
        return solve(values, 0, n -1);
    }
};


int main() {
    Solution sol;

    // { input, expected output }
    vector<pair<vector<int>, int>> testCases = {
        {{1, 2, 3},          6},
        {{3, 7, 4, 5},     144},
        {{1, 3, 1, 4, 1, 5}, 13},
    };

    int passed = 0;
    for (int t = 0; t < (int)testCases.size(); t++) {
        auto& values = testCases[t].first;
        int expected = testCases[t].second;

        // Reset memo for each test case
        memset(sol.memo, -1, sizeof(sol.memo));
    
     int result = sol.minScoreTriangulation(values);
        bool ok = (result == expected);
        if (ok) passed++;

        cout << "Test " << t + 1 << ": "
             << (ok ? "PASS" : "FAIL")
             << " | Got: " << result
             << " | Expected: " << expected
             << "\n";
    }

    cout << "\n" << passed << "/" << testCases.size() << " tests passed.\n";
    return 0;
}
    Top Down Approach :
    Time Complexity : O(n^3)
    Space Complexity : O(n^2)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int minScoreTriangulation(vector<int>& values) {
        
        int n = values.size();

        vector<vector<int>>t(n, vector<int>(n, 0));

        for(int i = n - 1; i >= 0; i --) {

            for(int j = i + 2; j < n ; j ++) {

                int minScore = INT_MAX;

                for(int k = i + 1; k <= j - 1; k ++) {

                    int score = values[i] * values[k] * values[j]
                                        + t[i][k]
                                        + t[k][j];

                    minScore = min(minScore, score);
                }

                t[i][j] = minScore;
            }
        }

        return t[0][n-1];
    }
};

int main() {
    Solution sol;

    // { input, expected output }
    vector<pair<vector<int>, int>> testCases = {
        {{1, 2, 3},          6},
        {{3, 7, 4, 5},     144},
        {{1, 3, 1, 4, 1, 5}, 13},
    };

    int passed = 0;
    for (int t = 0; t < (int)testCases.size(); t++) {
        auto& values = testCases[t].first;
        int expected = testCases[t].second;
    
     int result = sol.minScoreTriangulation(values);
        bool ok = (result == expected);
        if (ok) passed++;

        cout << "Test " << t + 1 << ": "
             << (ok ? "PASS" : "FAIL")
             << " | Got: " << result
             << " | Expected: " << expected
             << "\n";
    }

    cout << "\n" << passed << "/" << testCases.size() << " tests passed.\n";
    return 0;
}

//  Bottom Up :
//  Time Complexity : O(n^3)
//  Space Complexity : O(n^2)