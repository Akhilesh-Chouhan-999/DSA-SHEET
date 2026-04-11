/*


#include <bits/stdc++.h>
using namespace std;

class Soln {
public:
    // Minium Weight required to make this value { valid = value which can be possible } . 

    const long long INF = 1e15 ; 
    long long memo[101][100001]; 

    long long solve(int idx , int currVal , vector<int>& wt, vector<long long>& val){

        // Base Case : 
        if(currVal == 0)
        return 0 ;

        if(idx == 0)
        return currVal == val[idx] ? wt[idx] : INF;

        if(memo[idx][currVal] != -1)
        return memo[idx][currVal] ; 


        long long skip = solve(idx - 1 , currVal , wt , val) ;

        long long take = INF ; 

        if(currVal - val[idx] >= 0){
            take = wt[idx] + solve(idx - 1 , currVal - val[idx] , wt , val) ; 
        }

        return memo[idx][currVal] = min(take , skip) ; 
        
    }


    long long knapsack(int N, int W, vector<int>& wt, vector<long long>& val) {

        const long long maxVal = 1e5  ; 
        long long ans ; 

        memset(memo , -1 , sizeof(memo)) ; 

        for(int i = maxVal ; i >= 0 ; i --){

            if(solve(N - 1, i, wt, val) <= W){
                ans = i ; 
                break;          
            }
        }

        return ans ; 
        
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
    Time Complexity : O(N*maxVal)
    Space Complexity : O(N*maxVal)
*/




#include <bits/stdc++.h>
using namespace std;

class Soln {
public:
    // Minium Weight required to make this value { valid = value which can be possible } . 

    const long long INF = 1e15 ; 

    long long knapsack(int N, int W, vector<int>& wt, vector<long long>& val) {

        vector<vector<long long>>dp(N+1 , vector<long long>(100001 , INF)) ; 

        for(int currVal = 0 ; currVal < 100001 ; currVal ++){
             dp[0][currVal] =  currVal == val[0] ? wt[0] : INF;
        }

        
        for(int idx = 0 ; idx < N ; idx ++){
            dp[idx][0] = 0 ; 
        }

        for(int idx = 1 ; idx < N ; idx ++){

            for(int currVal = 0 ; currVal < 100001 ; currVal ++){

                long long skip = dp[idx - 1][currVal] ;

                long long take = INF ; 

                if(currVal - val[idx] >= 0){
                    take = wt[idx] + dp[idx - 1] [currVal - val[idx]] ; 
                }

                 dp[idx][currVal] = min(take , skip) ; 
            
            }
        }

        const long long maxVal = 1e5  ; 
        long long ans ; 


        for(int i = maxVal ; i >= 0 ; i --){

            if(dp[N - 1][i] <= W){
                ans = i ; 
                break;          
            }
        }

        return ans ; 
        
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


// Bottom Up Approach :
// Time Complexity : O(N*maxVal)
// Space Complexity : O(N*maxVal)