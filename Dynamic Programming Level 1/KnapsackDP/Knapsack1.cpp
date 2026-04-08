/*
#include <bits/stdc++.h>
using namespace std;

class Soln {
public:

    vector<vector<long long>>dp ;

    long long solve(vector<int>&wt , vector<long long>&val , int idx, int currCap){

        if(idx == 0){
            return (wt[idx] <= currCap ? val[idx] : 0) ;
        }

        if(dp[idx][currCap] != -1)
        return dp[idx][currCap] ; 


        long long skip = solve(wt, val, idx-1, currCap) ;
        long long take = LLONG_MIN ; 

        if(wt[idx] <= currCap){
            take = val[idx] + solve(wt, val, idx - 1 , currCap - wt[idx]) ;
        }

        return dp[idx][currCap] = max(skip , take) ; 

    }

    long long knapsack(int N, int W, vector<int>& wt, vector<long long>& val) {

        dp.resize(N + 1, vector<long long>(W + 1  , -1)) ; 

        return solve(wt, val, N-1 , W) ; 

    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, W;
    cin >> N >> W;

    vector<int> wt(N);
    vector<long long> val(N);

    for (int i = 0; i < N; i++) {
        cin >> wt[i] >> val[i];
    }

    Soln obj;

    long long ans = obj.knapsack(N, W, wt, val);

    cout << ans << "\n";

    return 0;
}

    Top Down Approach :
    Time Complexity : O(n*W)
    Space Complexity : O(n*W)
*/

#include <bits/stdc++.h>
using namespace std;

class Soln {
public:

    long long knapsack(int N, int W, vector<int>& wt, vector<long long>& val) {

        

    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, W;
    cin >> N >> W;

    vector<int> wt(N);
    vector<long long> val(N);

    for (int i = 0; i < N; i++) {
        cin >> wt[i] >> val[i];
    }

    Soln obj;

    long long ans = obj.knapsack(N, W, wt, val);

    cout << ans << "\n";

    return 0;
}