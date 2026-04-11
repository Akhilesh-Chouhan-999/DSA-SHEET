/*
#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:

    pair<int ,int>memo[101][101] ; 
    bool visited[101][101] ; 

    pair<int , int> solve(vector<string>&boards, int i, int j){

        int n = boards.size() ; 

        if( i >= n || j >= n){
            return { -1, 0 } ; 
        }

        
        if(boards[i][j] == 'X'){
            return { -1 , 0} ; 
        }


        if( i == n - 1 && j == n - 1){
            return {0 , 1} ; 
        }

        if(visited[i][j])
        return memo[i][j] ; 

        pair<int, int> bottom   = solve(boards, i+1 ,  j) ; 
        pair<int, int> right    = solve(boards, i ,  j+1) ;
        pair<int, int> diagonal = solve(boards, i +1,j+1);

            
        int sum1 = bottom.first ; 
        int freq1 = bottom.second ; 

        int sum2 = right.first ;
        int freq2 = right.second ; 

        int sum3 = diagonal.first ; 
        int freq3 = diagonal.second ;


        int maxSum = max({sum1 , sum2 , sum3}) ; 


        if(maxSum == -1){
            visited[i][j] = true;
            return memo[i][j] = {-1, 0};
        }

        
        int ways = 0 ; 
        int MOD = 1e9 + 7;

        if(sum1 == maxSum) ways = (ways + freq1 ) %  MOD ; 
        if(sum2 == maxSum) ways = (ways + freq2 ) %  MOD ;
        if(sum3 == maxSum) ways = (ways + freq3 ) %  MOD ;
        
    

        int val = (boards[i][j] == 'E') ? 0 : boards[i][j] - '0';

        visited[i][j] = true ;
        return memo[i][j] = {maxSum + val, ways} ; 
        
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        
        memset(memo , -1 , sizeof(memo)) ; 
        memset(visited , 0 , sizeof(visited)) ;

        auto p = solve(board, 0, 0) ; 

        int sum  = p.first;
        int freq = p.second ; 

        if(sum == -1) return {0,0};

        return {sum , freq};
    }
};

int main() {

    Solution obj;

    // Test Case 1
    vector<string> board1 = {
        "E23",
        "2X2",
        "12S"
    };

    vector<int> res1 = obj.pathsWithMaxScore(board1);
    cout << "Output 1: [" << res1[0] << ", " << res1[1] << "]" << endl;  // Expected: [7,1]


    // Test Case 2
    vector<string> board2 = {
        "E12",
        "1X1",
        "21S"
    };

    vector<int> res2 = obj.pathsWithMaxScore(board2);
    cout << "Output 2: [" << res2[0] << ", " << res2[1] << "]" << endl;  // Expected: [4,2]


    // Test Case 3
    vector<string> board3 = {
        "E11",
        "XXX",
        "11S"
    };

    vector<int> res3 = obj.pathsWithMaxScore(board3);
    cout << "Output 3: [" << res3[0] << ", " << res3[1] << "]" << endl;  // Expected: [0,0]


    return 0;
}
    Top Down Approach :
    Time Complexity : O(n*n)
    Space Complexity : O(n*n)
*/